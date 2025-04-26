# Captive_Portal_Monitor
Arduino library for monitor any string on captive portal.
Works with Raspberry Pico W, Pico 2W and ESP32.

このArduinoライブラリを利用すると，キャプティブポータル上で任意の文字列を簡単に表示することができます．
Raspberry Pico W, Pico 2W および ESP32 を搭載するWiFiデバイスでコンパイルが可能です．
ログの取得や動作確認など，あらゆるプロジェクトに応用が可能です．

## Methods | メソッド
インスタンス化することにより，利用可能になります．
インスタンス化する際には，char文字列の先頭ポインタを渡す必要があります．

ここでは，以下のようにインスタンス化したとします．

```cpp
static char data[256];
Captive_Portal_Monitor monitor(data);
```

### monitor.begin()
setup()内で実行します．
FreeRTOSのxTaskCreateStaticが内部で実行され，WebServerが開始します．

```cpp
void setup() {
  monitor.begin();
}
```

### ~~monitor.update(char *p)~~ 廃止
### 更新方法
monitorインスタンスに渡したポインタが指すchar文字列（ここでは「data」）の内容を更新することで表示される内容が変わります．

```cpp
void loop() {
  uint32_t now = millis(); // Returns the number of milliseconds passed since the Arduino board began running the current program.
  sprintf(data, "%d", now);
  delay(100);
}
```
