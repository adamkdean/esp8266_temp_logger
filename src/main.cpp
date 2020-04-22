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
  pinMode(LED_BUILTIN, OUTPUT);

  // Wait for 3 seconds at startup for
  // a serial connection to be attached.
  while (!Serial) {
    blink(20, 50, 100);
  }

  // Begin the WiFi connection procedure.
  connect_to_wifi();
}

//
// Main loop function
//
void loop()
{
  char msg[64];
  sprintf(msg, "%s %s",
    wl_status_to_string(WiFi.status()),
    WiFi.localIP().toString().c_str());
  Serial.println(msg);
  // blink(2, 100, 900);
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
    blink(5, 50, 50);
    delay(500);
  }

  sprintf(msg, "WiFi connected with IP %s", WiFi.localIP().toString().c_str());
  Serial.println(msg);
}

//
// Blink very fast like something exciting is
// happening and you want everyone to know!
//
void blink(int count, int on, int off) {
  for (int i = 0; i < count; i++) {
    digitalWrite(LED_BUILTIN, LOW);
    delay(on);
    digitalWrite(LED_BUILTIN, HIGH);
    delay(off);
  }
}

//
// WiFi status helper.
//
const char* wl_status_to_string(wl_status_t status) {
  switch (status) {
    case WL_NO_SHIELD: return "WL_NO_SHIELD";
    case WL_IDLE_STATUS: return "WL_IDLE_STATUS";
    case WL_NO_SSID_AVAIL: return "WL_NO_SSID_AVAIL";
    case WL_SCAN_COMPLETED: return "WL_SCAN_COMPLETED";
    case WL_CONNECTED: return "WL_CONNECTED";
    case WL_CONNECT_FAILED: return "WL_CONNECT_FAILED";
    case WL_CONNECTION_LOST: return "WL_CONNECTION_LOST";
    case WL_DISCONNECTED: return "WL_DISCONNECTED";
  }
}
