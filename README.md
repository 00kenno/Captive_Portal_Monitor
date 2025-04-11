# Captive_Portal_String_Monitor
Arduino library for monitor any string on captive portal.
Works with Raspberry Pico W, Pico 2W and ESP32.

このArduinoライブラリを利用すると，キャプティブポータル上で任意の文字列を簡単に表示することができます．
Raspberry Pico W, Pico 2W および ESP32 を搭載するWiFiデバイスでコンパイルが可能です．
ログの取得や動作確認など，あらゆるプロジェクトに応用が可能です．

## Methods | メソッド
インスタンス化することにより，利用可能になります．
ここでは，以下のようにインスタンス化したとします．

```cpp
Captive_Portal_String_Monitor monitor;
```

### monitor.begin()
setup()内で実行します．
FreeRTOSのxTaskCreateが内部で実行され，WebServerが開始します．

```cpp
void setup() {
  monitor.begin();
}
```

### monitor.update(char *p)
任意の場所で実行できます．
monitorインスタンスが持つ長さが256のchar型の配列にその内容がコピーされます．
