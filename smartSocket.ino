#define BLYNK_TEMPLATE_ID   "TMPL3dV2PNg_B"
#define BLYNK_TEMPLATE_NAME "Smart Socket"

#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#include "secrets.h"

// Relay pin (change if you wired a different GPIO)
const int relayPin = 2;

// Button widget on V0 (mode: Switch, 0/1)
BLYNK_WRITE(V0) {
  int value = param.asInt();   // 1 = ON, 0 = OFF

  if (value == 1) {
    digitalWrite(relayPin, HIGH);   // relay ON (active-HIGH)
  } else {
    digitalWrite(relayPin, LOW);    // relay OFF
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);      // start OFF

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

  Blynk.run();
}
