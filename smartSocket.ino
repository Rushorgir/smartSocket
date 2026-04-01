#define BLYNK_TEMPLATE_ID   "TMPL3dV2PNg_B"
#define BLYNK_TEMPLATE_NAME "Smart Socket"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "secrets.h"

// Relay pin (change if you wired a different GPIO)
const int relayPin = 2;

// Scheduler config
const int maxScheduleMinutes = 1440;  // 24 hours

bool isScheduleActive = false;
unsigned long scheduledTurnOnAt = 0;

void setRelay(bool turnOn) {
  digitalWrite(relayPin, turnOn ? HIGH : LOW);
  Blynk.virtualWrite(V0, turnOn ? 1 : 0);
}

void cancelScheduledTurnOn() {
  isScheduleActive = false;
  scheduledTurnOnAt = 0;
}

// Button widget on V0 (mode: Switch, 0/1)
BLYNK_WRITE(V0) {
  int value = param.asInt();   // 1 = ON, 0 = OFF

  // Manual action cancels pending scheduled turn-on to avoid conflicts.
  cancelScheduledTurnOn();
  setRelay(value == 1);
}

// Number input widget on V1 (minutes). Set value to schedule relay ON after X minutes.
BLYNK_WRITE(V1) {
  int minutes = param.asInt();

  if (minutes <= 0) {
    cancelScheduledTurnOn();
    Serial.println("Schedule cleared");
    return;
  }

  if (minutes > maxScheduleMinutes) {
    minutes = maxScheduleMinutes;
  }

  isScheduleActive = true;
  scheduledTurnOnAt = millis() + (unsigned long)minutes * 60000UL;

  Serial.print("Relay ON scheduled in minutes: ");
  Serial.println(minutes);
}

void setup()
{
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);
  setRelay(false);      // start OFF

  WiFi.begin(ssid, pass);
  Blynk.config(auth);
  Blynk.connect();
}

void loop()
{
  if (WiFi.status() != WL_CONNECTED) {
    WiFi.reconnect();
  }

  if (!Blynk.connected()) {
    Blynk.connect();
  }

  if (isScheduleActive && (long)(millis() - scheduledTurnOnAt) >= 0) {
    setRelay(true);
    cancelScheduledTurnOn();
    Serial.println("Scheduled ON executed");
  }

  Blynk.run();
}
