//  __ __  __   __  __   __   __
// |_ (__ |__) (__)  _) /__  /__
// |__ __)|    (__) /__ \__) \__)
//
// (C) Copyright 2020 Adam K Dean

#include <Arduino.h>
#include <ESP8266WiFi.h>
#include "WifiCredentials.h"

void setup()
{
  Serial.begin(9600);
  // WiFi.begin(ssid, password);
}

void loop()
{
  Serial.println(WIFI_SSID);
  delay(1000);
}