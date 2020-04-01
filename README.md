# autoypiano

ESP32 & RaspberryPi & MachiKania typeM & Arduino用自動演奏トイピアノプログラム。ノートNo.77~101まで、ノートON,ノートOFFのみ対応

 ## 概要
このプログラムは、UARTとI2Cでソレノイド25個を制御しトイピアノを自動演奏します。

![Picture](https://github.com/YoutechA320U/autoypiano/blob/master/picture1.jpg "RaspberryPi版") ![Picture](https://github.com/YoutechA320U/autoypiano/blob/master/picture2.jpg "ESP32版") ![Picture](https://github.com/YoutechA320U/autoypiano/blob/master/picture3.jpg "MachiKania TypeM版")![Picture](https://github.com/YoutechA320U/autoypiano/blob/master/picture4.jpg "ArduinoProMicro版")
## 開発環境
    RaspberryPi 3B+: Raspbian　stretch, Python3.7
    ESP32-DevKitC: MicroPython
    MachiKania typeM: KM-1301
    Arduino：ArduinoIDE

## インストールが必要なライブラリ
    Python3.7：pyserial, smbus, argparse, Python-RtMidi
    MicroPython：machine
    Arduino：Adafruit_MCP23017, MIDI
    ArduinoLeonardo：Adafruit_MCP23017, MIDIUSB,
    ESP32：Arduino-BLE-MIDI

## 必要な部品
|部品名|型番など|数量|
|:---|:--:|---:|
|トイピアノ|[KAWAI ミニピアノ P-25 (ローズレッド)](https://www.amazon.co.jp/%E6%B2%B3%E5%90%88%E6%A5%BD%E5%99%A8%E8%A3%BD%E4%BD%9C%E6%89%80-Musical-Instruments-Manufacturing-KTEC-cAGGT-ds-1108520/dp/B000BYM7FG/ref=pd_cp_21_2?_encoding=UTF8&pd_rd_i=B000BYM7FG&pd_rd_r=a6f02670-0b0c-11e9-a192-8ff15e5e6261&pd_rd_w=qE6rC&pd_rd_wg=mdpKR&pf_rd_p=2b3f7bc2-ce03-4854-a8c9-a9fbc069f595&pf_rd_r=NPJFDKF9H0WN2HTN49HK&psc=1&refRID=NPJFDKF9H0WN2HTN49HK)|1|
|①[RaspberryPi 3B+](http://akizukidenshi.com/catalog/g/gM-13470/) ||
|②[ESP32-DevKitC](http://akizukidenshi.com/catalog/g/gM-11819/)||
|③[MachiKania typeM](https://store.shopping.yahoo.co.jp/orangepicoshop/pico-a-006.html)|||
|④Arduinoシリーズ1つ|||
|⑤[M5Stack](https://www.switch-science.com/catalog/3647/)||①~⑤いずれか1|
|DIN-5ソケット(メス)|[KDJ103-5](http://akizukidenshi.com/catalog/g/gC-09565/)など|1|
|2.1ｍｍ標準DCジャック|[2DC0005D100](http://akizukidenshi.com/catalog/g/gC-01604)など|1|
|1/4Wカーボン抵抗|220Ω|1|
||270Ω|1|
||470Ω|50|
|スイッチングダイオード|[1N1418](http://akizukidenshi.com/catalog/g/gI-00941/)など|1|
|ショットキーダイオード|[1S4](http://akizukidenshi.com/catalog/g/gI-00127/)|25|
|フォトカプラ|[TLP785](http://akizukidenshi.com/catalog/g/gI-07554/)|1|
|トランジスタ|[2SC2655](http://akizukidenshi.com/catalog/g/gI-08746/)|25|
|I/Oエキスパンダ|[MCP23017](http://akizukidenshi.com/catalog/g/gI-09486/)|2|
|ソレノイド|[H10-0630-PUSH-12](https://www.marutsu.co.jp/pc/i/838037/)など12V1.2W程度のもの|25|
|ACアダプター|[AD-D120P200](http://akizukidenshi.com/catalog/g/gM-10659/)など12V2A程度のもの|1|

## 回路図
![SS](https://github.com/YoutechA320U/autoypiano/blob/master/ToyPiano.png "回路図")

## 使い方
RaspberryPiが[autoypiano-pi.py](https://github.com/YoutechA320U/autoypiano/blob/master/autoypiano-pi.py)、ESP32(MIcroPython)が[autoypiano-micro.py](https://github.com/YoutechA320U/autoypiano/blob/master/autoypiano-micro.py)、MachiKania typeMが[TOYPIANO.BAS](https://github.com/YoutechA320U/autoypiano/blob/master/TOYPIANO.BAS)、ArduinoLeonardo以外が[autoypiano.ino](https://github.com/YoutechA320U/autoypiano/blob/master/autoypiano.ino)、ArduinoLeonardo USB-MIDI対応が[autoypiano_usb.ino](https://github.com/YoutechA320U/autoypiano/blob/master/autoypiano_usb.ino)、M5Stackが[M5autoypiano.ino](https://github.com/YoutechA320U/autoypiano/blob/master/M5autoypiano.ino)、ESP32(Arduino系) BLE-MIDI対応(※試験的)が[ESP32_BLE_autoypiano.ino](https://github.com/YoutechA320U/autoypiano/blob/master/ESP32_BLE_autoypiano.ino)です。

RaspberryPiは[UARTを有効にしてMIDI用に設定を変更し、](http://www.samplerbox.org/article/midiinwithrpi)I2Cを有効にしてから実行してください。

Arduino系は最大同時発音数が設定されています(デフォルトで4)

## 備考
電源の出力が足りないと複数のソレノイドを同時にONできません。ソレノイドによって必要な電源の出力は変わります。また、トランジスタやソレノイドに負担がかかるのであまり長時間ソレノイドをONのままにしないでください。

USB-MIDI、BLE-MIDI対応版は通常のMIDI-INも使用可能です。

### 参考コード・資料
* <http://www.samplerbox.org/article/midiinwithrpi>  
* <https://github.com/nezumi-tech/Hamoron-Firmware>
* <https://github.com/adafruit/Adafruit-MCP23017-Arduino-Library>
* <https://github.com/arduino-libraries/MIDIUSB>
* <https://github.com/lathoub/Arduino-BLE-MIDI>

## 履歴
    [2018/12/7] - 初回リリース
    [2018/12/29] - 部品表作りました
    [2018/12/29] - MachiKaniaに対応
    [2019/08/08] - Arduino,ArduinoLeonardo,M5Stackに対応
    [2019/11/15] - 発音数制限を追加(Arduino系のみ)
    [2020/03/24] - BLE-MIDIに対応(ESP32のみ、試験的)
    [2020/04/01] - 仮想MIDIポート版を追加(RaspberryPi用)