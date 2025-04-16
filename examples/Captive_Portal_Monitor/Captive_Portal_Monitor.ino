//Captive_Portal_Monitor
//WiFiを利用したスマートフォンやPCで確認できるデバッグ用モニターです．

//ライブラリをインクルードする必要があります．
//GitHubから「Download ZIP」した場合には
//以下の手順でインクルードできます
//「スケッチ」
//→「ライブラリのインクルード」
//→「.ZIP形式のライブラリをインストール...」

//「ログインが必要です」などと表示される画面（キャプティブポータル）で
//10KB以下の任意の文字列（改行コードを含む）をモニターできます．

//WiFiのSSIDは Captive_Portal_String_Monitor
//WiFiのPASSWORDは 12345678 です．

//2025.04.07時点で以下のマイコンでコンパイルが可能です．
//ESP32C3
//Raspberry Pi Pico W
//Raspberry Pi Pico 2W

#include <Captive_Portal_Monitor.h>

Captive_Portal_Monitor monitor;

void setup() {
  monitor.begin();
}

void loop() {
  uint32_t now = millis();
  char str[128];
  sprintf(str, "改行コードが使用可能です．\n\n以下は実行を開始してからの時間をミリ秒で表示しています．\n%d", now);
  monitor.update(str);
  delay(100);
}
