# autoypiano

ESP32　MicroPython及び　RaspberryPi Python2.7用自動演奏トイピアノプログラム。25鍵,ノートON,ノートOFFのみ対応

## 概要
このプログラムは、UARTとI2Cでソレノイド25個を制御します。

## 開発環境
    OS : Raspbian　stretch
    RaspberryPi : RaspberryPi 3B+
    Python : ver2.7
    ESP32：ESP32-DevKitC

## インストールが必要なライブラリ
    Python：pyserial,　smbus　argparse
    MicroPython：無し
## 回路図
![SS](https://github.com/YoutechA320U/autoypiano/blob/master/ToyPiano.png "SS")
## 使い方
RaspberryPiはUARTのMIDIを有効にしてから実行してください。
ESP32は実行するだけです

## 備考
ソレノイドの電源は12V2AのACアダプターを使ってください。また、トランジスタやソレノイドに負担がかかるのであまり長時間ソレノイドをONのままにしないでください。
 

## 履歴
    [2018/12/7] - 初回リリース

