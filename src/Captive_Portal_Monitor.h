//Webサーバーに関するクラスの定義

#ifndef CAPTIVE_PORTAL_MONITOR_H
#define CAPTIVE_PORTAL_MONITOR_H

#define WIFI_SSID "Captive_Portal_Monitor"
#define WIFI_PASSWORD "12345678"

#include <Arduino.h>

#ifdef ARDUINO_ARCH_RP2040 //RP2040及びRP2350のチェックに対応
#include <FreeRTOS.h>
#include <task.h>
#endif

#include <WiFi.h>
#include <DNSServer.h>
#include <WebServer.h>

class Captive_Portal_Monitor {
  public:
    Captive_Portal_Monitor();
    void begin();
    void update(char *p);

  private:
    static char data[10*1024];
    static void handleRoot();
    static void getData();
    static void loop(void *param);
};

#endif // CAPTIVE_PORTAL_MONITOR_H
