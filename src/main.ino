#include <WiFi.h>
#include <Adafruit_MQTT.h>
#include <Adafruit_MQTT_Client.h>

// Pin Definitions
#define PIR_PIN 13
#define LDR_PIN 34
#define LIGHT_LED_PIN 2
#define SECURITY_LED_PIN 4  // This is your system status/security LED

// WiFi Credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// Adafruit IO Credentials
#define AIO_SERVER      "io.adafruit.com"
#define AIO_SERVERPORT  1883
#define AIO_USERNAME    "your_username"  // Replace with your Adafruit IO username
#define AIO_KEY         "your_aio_key"  // Replace with your Adafruit IO key
// Note: Make sure to replace the above with your actual Adafruit IO credentials

// WiFi & MQTT
WiFiClient client;
Adafruit_MQTT_Client mqtt(&client, AIO_SERVER, AIO_SERVERPORT, AIO_USERNAME, AIO_KEY);

// Feeds
Adafruit_MQTT_Publish motionFeed = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/motion-detected");
Adafruit_MQTT_Publish lightLevelFeed = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/light-level");
Adafruit_MQTT_Publish securityAlertFeed = Adafruit_MQTT_Publish(&mqtt, AIO_USERNAME "/feeds/security-alert");

// Variables
bool motionDetected = false;
bool isDark = false;
bool lightState = false;
bool securityAlertState = false;
bool lastPublishedMotion = false;
bool lastPublishedLightState = false;  // Track last published light state

unsigned long lastMotionTime = 0;
unsigned long lastPublishTime = 0;
const unsigned long MOTION_DELAY = 5000;
const unsigned long PUBLISH_INTERVAL = 15000;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(LDR_PIN, INPUT);
  pinMode(LIGHT_LED_PIN, OUTPUT);
  pinMode(SECURITY_LED_PIN, OUTPUT);
  digitalWrite(LIGHT_LED_PIN, LOW);
  digitalWrite(SECURITY_LED_PIN, LOW);

  connectToWiFi();
  Serial.println("System Ready!");
}

void loop() {
  MQTT_connect();

  readSensors();
  processMotionLogic();

  // Publish data every 15 seconds OR when light state changes
  if (millis() - lastPublishTime > PUBLISH_INTERVAL || lightState != lastPublishedLightState) {
    publishData();
    lastPublishTime = millis();
    lastPublishedLightState = lightState;
  }

  mqtt.processPackets(100);
  delay(100);
}

void connectToWiFi() {
  Serial.print("Connecting to WiFi: ");
  Serial.println(ssid);
  WiFi.begin(ssid, password, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected! IP: " + WiFi.localIP().toString());
}

void readSensors() {
  motionDetected = digitalRead(PIR_PIN);
  // Read LDR - assuming HIGH = dark, LOW = bright from LDR circuit
  bool ldrReading = digitalRead(LDR_PIN);
  isDark = ldrReading;  // Adjust this based on your LDR circuit logic
}

void processMotionLogic() {
  if (motionDetected) {
    lastMotionTime = millis();

    // Publish motion state change
    if (!lastPublishedMotion) {
      publishMotionState(true);
      lastPublishedMotion = true;
    }

    // Turn on security LED when motion detected
    if (!securityAlertState) {
      digitalWrite(SECURITY_LED_PIN, HIGH);
      securityAlertState = true;
      String alertMessage = isDark ? "Motion detected in DARK" : "Motion detected in BRIGHT";
      publishSecurityAlert(alertMessage);
    }

    // Turn on light LED only if it's dark AND motion is detected
    if (isDark && !lightState) {
      digitalWrite(LIGHT_LED_PIN, HIGH);
      lightState = true;
      Serial.println("💡 Light turned ON (Motion + Dark detected)");
    }

  } else if (millis() - lastMotionTime > MOTION_DELAY) {
    // Turn off security LED after delay
    if (securityAlertState) {
      digitalWrite(SECURITY_LED_PIN, LOW);
      securityAlertState = false;
    }
    
    // ALWAYS turn off light LED when no motion (regardless of light condition)
    if (lightState) {
      digitalWrite(LIGHT_LED_PIN, LOW);
      lightState = false;
      Serial.println("💡 Light turned OFF (No motion)");
    }
    
    // Publish motion stopped
    if (lastPublishedMotion) {
      publishMotionState(false);
      lastPublishedMotion = false;
    }
  }
}

void publishData() {
  Serial.println("📡 Publishing data...");
  
  int lightLevelValue = lightState ? 1 : 0;
  
  lightLevelFeed.publish((int32_t)lightLevelValue);
}

void publishMotionState(bool state) {
  if (motionFeed.publish((int32_t)state)) {
    Serial.print("Motion state published: ");
    Serial.println(state ? "1 (Motion detected)" : "0 (No motion)");
  } else {
    Serial.println("❌ Failed to publish motion state");
  }
}

void publishSecurityAlert(String message) {
  String alertMsg = message + " | Time: " + String(millis()/1000) + "s";
  if (securityAlertFeed.publish(alertMsg.c_str())) {
    Serial.println("✅ Security alert published: " + message);
  } else {
    Serial.println("❌ Failed to publish alert");
  }
}

void MQTT_connect() {
  if (mqtt.connected()) return;

  Serial.print("Connecting to MQTT... ");
  int8_t ret;
  uint8_t retries = 3;
  while ((ret = mqtt.connect()) != 0) {
    Serial.println(mqtt.connectErrorString(ret));
    mqtt.disconnect();
    delay(5000);
    retries--;
    if (retries == 0) while (1);
  }
  Serial.println("MQTT Connected!");
}