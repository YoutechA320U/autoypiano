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

## 必要な部品
|部品名|型番など|数量|
|:---|:--:|---:|
|トイピアノ|[KAWAI ミニピアノ P-25 (ローズレッド)](https://www.amazon.co.jp/%E6%B2%B3%E5%90%88%E6%A5%BD%E5%99%A8%E8%A3%BD%E4%BD%9C%E6%89%80-Musical-Instruments-Manufacturing-KTEC-cAGGT-ds-1108520/dp/B000BYM7FG/ref=pd_cp_21_2?_encoding=UTF8&pd_rd_i=B000BYM7FG&pd_rd_r=a6f02670-0b0c-11e9-a192-8ff15e5e6261&pd_rd_w=qE6rC&pd_rd_wg=mdpKR&pf_rd_p=2b3f7bc2-ce03-4854-a8c9-a9fbc069f595&pf_rd_r=NPJFDKF9H0WN2HTN49HK&psc=1&refRID=NPJFDKF9H0WN2HTN49HK)|1|
|ESP32-DevKitC||1|
|RaspberryPi 3B+||1|
|DIN-5ソケット(メス)|[KDJ103-5](http://akizukidenshi.com/catalog/g/gC-09565/)など|1|
|2.1ｍｍ標準ＤＣジャック|[2DC0005D100](http://akizukidenshi.com/catalog/g/gC-01604)など|1|
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
![SS](https://github.com/YoutechA320U/autoypiano/blob/master/ToyPiano.png "SS")

## 使い方

RaspberryPiは[UARTを有効にしてMIDI用に設定を変更し、](http://www.samplerbox.org/article/midiinwithrpi)I2Cを有効にしてから実行してください。
ESP32は実行するだけです

## 備考
電源の出力が足りないと複数のソレノイド同時にをONできません。ソレノイドによって必要な電源の出力は変わります。また、トランジスタやソレノイドに負担がかかるのであまり長時間ソレノイドをONのままにしないでください。

### 参考コード・資料
* <http://www.samplerbox.org/article/midiinwithrpi>  

## 履歴
    [2018/12/7] - 初回リリース
    [2018/12/29] - 部品表作りました