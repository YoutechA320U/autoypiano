# autoypiano

ESP32 MicroPython及びRaspberryPi Python2.7用自動演奏トイピアノプログラム。25鍵,ノートON,ノートOFFのみ対応

 ## 概要
このプログラムは、UARTとI2Cでソレノイド25個を制御しトイピアノを自動演奏します。
![Picture](https://github.com/YoutechA320U/autoypiano/blob/master/picture.png "Picture")

## 開発環境
    RaspberryPi 3B+, Raspbian　stretch, Python2.7
    ESP32-DevKitC, MicroPython

## インストールが必要なライブラリ
    Python：pyserial,　smbus　argparse
    MicroPython：machine

## 回路図
![SS](https://github.com/YoutechA320U/autoypiano/blob/master/ToyPiano.png "SS")

## 使い方

RaspberryPiは[UARTを有効にしてMIDI用に設定を変更し、](http://www.samplerbox.org/article/midiinwithrpi)I2Cを有効にしてから実行してください。
ESP32は実行するだけです

## 備考
ソレノイドの電源は12V2AのACアダプターを使ってください。また、トランジスタやソレノイドに負担がかかるのであまり長時間ソレノイドをONのままにしないでください。

### 参考コード・資料
* <http://www.samplerbox.org/article/midiinwithrpi>  

## 履歴
    [2018/12/7] - 初回リリース