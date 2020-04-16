//  __ __  __   __  __   __   __
// |_ (__ |__) (__)  _) /__  /__
// |__ __)|    (__) /__ \__) \__)
//
// (C) Copyright 2020 Adam K Dean

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "WiFiCredentials.h"
#include "main.h"

//
// Initial entry point
//
void setup()
{
  Serial.begin(9600);
  Serial.println("Starting in 5s...");

  // Initial delay so I can connect to
  // serial and start monitoring.
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);
  delay(5000);
  digitalWrite(LED_BUILTIN, HIGH);

  // Begin the WiFi connection procedure.
  connect_to_wifi();
}

//
// Main loop function
//
void loop()
{
  char msg[64];
  sprintf(msg, "Status: %d", WiFi.status());
  Serial.println(msg);
  digitalWrite(LED_BUILTIN, LOW);
  delay(100);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(900);
}

//
// Connect to WiFi while blinking.
//
void connect_to_wifi() {
  char msg[64];
  sprintf(msg, "Connecting to %s", WIFI_SSID);
  Serial.println(msg);

  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.println("Connecting...");
    blink_excitedly(20);
    delay(500);
  }

  Serial.println("WiFi connected with IP " + WiFi.localIP());
}

//
// Blink very fast like something exciting is
// happening and you want everyone to know!
//
void blink_excitedly(int count) {
  for (int i = 0; i < count; i++) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(50);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(50);
  }
}
