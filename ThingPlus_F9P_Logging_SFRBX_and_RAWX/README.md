# Logging_RXM_SFRBX_and_RAWX

UBX フォーマットの RXM-SFRBX と RXM-RAWX を OpenLog へロギングを試みるサンプルコードです  
[SparkFun 社の Example](https://github.com/sparkfun/SparkFun_u-blox_GNSS_Arduino_Library/blob/main/examples/Data_Logging/DataLoggingExample3_RXM_SFRBX_and_RAWX/DataLoggingExample3_RXM_SFRBX_and_RAWX.ino)を参考にしています

## 使用機材

- [ESP32-WROOM-32D 搭載 SparkFun Thing Plus](https://www.switch-science.com/catalog/6229/)
- [Qwiic - ZED-F9P 搭載 GPS-RTK-SMA モジュール](https://www.switch-science.com/catalog/6365/)
  - [Qwiic - ZED-F9P 搭載 GPS-RTK2 モジュール](https://www.switch-science.com/catalog/5413/)でも対応可能
  - 上記いずれかのモジュールに対応するアンテナ
- [OpenLog](https://www.switch-science.com/catalog/2716/)
- それぞれをつなぐ Qwiic ケーブル
- SD カード

## 使い方

- SD カードの FAT 系統のフォーマットか確認する
  - PC に挿して確認できる
    - mac ならディスクユーティリティを開いて確認できる
  - 大体はそのままでそうなっているので大丈夫
- OpenLog に SD カードを差し込む
- ZED-F9P にアンテナを取り付ける
- それぞれを Qwiic ケーブルで繋ぐ
- Thing Plus を PC と繋げる
- 本ソースコードを ArduinoIDE 経由、またはそれに類似する開発環境で書き込む
- Serial Monitor に出てくる表示通りに操作する
  - 任意の入力を入れたらロギングが開始する。
    - 空文字でいいので Serial Monitor の入力欄をクリックして Enter(もしくは、command+Enter)を押す
  - 更に任意の入力を入れたらロギングが終了する。
- 止めたらケーブルを抜いて良い
- SD カードを抜いてデータがロギングできているのかを PC などに挿して確認する

## 注意事項

1. ESP32-WROOM-32D 搭載 SparkFun Thing Plus への書き込みの際に ESP32-WROOM-32D の不具合で自動書き込みモードが動作しない場合がある。その場合は手動書き込みを行う必要がある。
   1. 0 ボタンを押し続ける。
   2. REST ボタンを一回押す。
   3. ArduinoIDE の書き込みボタンを押す。
   4. Connecting...が出たら 0 ボタンを離す。

## 既知のバグ・問題点

issue に記載する
