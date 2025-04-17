//Captive_Portal_Monitor
//WiFiを利用したスマートフォンやPCで確認できるデバッグ用モニターです．

//ライブラリをインクルードする必要があります．
//GitHubから「Download ZIP」した場合には
//以下の手順でインクルードできます
//「スケッチ」
//→「ライブラリのインクルード」
//→「.ZIP形式のライブラリをインストール...」

//「ログインが必要です」などと表示される画面（キャプティブポータル）で
//任意の文字列（改行コードを含む）をモニターできます．

//WiFiのSSIDは Captive_Portal_Monitor
//WiFiのPASSWORDは 12345678 です．

//2025.04.07時点で以下のマイコンでコンパイルが可能です．
//ESP32C3
//Raspberry Pi Pico W
//Raspberry Pi Pico 2W

#include <Captive_Portal_Monitor.h>

static char data[256]; // 静的メモリ領域に配列を作成
Captive_Portal_Monitor monitor(data);

void setup() {
  monitor.begin();
}

void loop() {
  uint32_t now = millis();
  sprintf(data, "改行コードが使用可能です．\n\n以下は実行を開始してからの時間をミリ秒で表示しています．\n%d", now);
  delay(100);
}
