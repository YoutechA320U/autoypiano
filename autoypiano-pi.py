# -*- coding: utf-8 -*-
# RaspberryPi用
import serial
import smbus
import argparse
# パーサーを作る
parser = argparse.ArgumentParser(
            add_help=True, # -h/?help オプションの追加
            )

# 引数の追加
parser.add_argument('-d', '--debug', help='show midi message',
                    action='store_true') #デバッグモード追加

# 引数を解析する
args = parser.parse_args()

# MCP23017の設定
i2c = smbus.SMBus(1)
i2c.write_byte_data(0x20,0x00,0x00) # 0x20のバンクAを出力ポートに設定
i2c.write_byte_data(0x20,0x01,0x00) # 0x20のバンクBを出力ポートに設定
i2c.write_byte_data(0x21,0x00,0x00) # 0x21のバンクAを出力ポートに設定
i2c.write_byte_data(0x21,0x01,0x00) # 0x21のバンクBを出力ポートに設定
i2c.write_byte_data(0x20,0x14,0x00) 
i2c.write_byte_data(0x20,0x15,0x00)
i2c.write_byte_data(0x21,0x14,0x00)
i2c.write_byte_data(0x21,0x15,0x00)

# MIDIポート設定
ser = serial.Serial('/dev/ttyAMA0', baudrate=38400) #シリアル読み取り, ボーレート38400bps

note1a = list(bin(i2c.read_byte_data(0x20, 0x14)).replace('0b', '').zfill(8))
note1b = list(bin(i2c.read_byte_data(0x20, 0x15)).replace('0b', '').zfill(8))
note2a = list(bin(i2c.read_byte_data(0x21, 0x14)).replace('0b', '').zfill(8))
note2b = list(bin(i2c.read_byte_data(0x21, 0x15)).replace('0b', '').zfill(8))

while True:
  data1 = ord(ser.read(1)) #1バイト目
  if data1 == 247:
     continue
  else:
      data2 = ord(ser.read(1)) #2バイト目
      if data1 >= 192 and data1 <= 208 or data2 == 247:
         continue
      else:
         data3 = ord(ser.read(1)) #3バイト目
         message = [data1,data2,data3]
         if args.debug:
            print ('[{}, {}, {}]'.format(data1, data2, data3))
         if message[0] == 144 and message[2] != 0:
            if message[1] ==77:
               note1a[7] = 1
            if message[1] ==78:
               note1a[6] = 1
            if message[1] ==79:
               note1a[5] = 1
            if message[1] ==80:
               note1a[4] = 1
            if message[1] ==81:
               note1a[3] = 1
            if message[1] ==82:
               note1a[2] = 1
            if message[1] ==83:
               note1a[1] = 1
            if message[1] ==84:
               note1a[0] = 1
            note1a = int(hex(int("0b"+("".join(map(str, note1a))) ,2)),16)
            i2c.write_byte_data(0x20,0x14,note1a)
            note1a = list(bin(note1a).replace('0b', '').zfill(8))
            
            if message[1] ==85:
               note1b[7] = 1
            if message[1] ==86:
               note1b[6] = 1
            if message[1] ==87:
               note1b[5] = 1
            if message[1] ==88:
               note1b[4] = 1
            if message[1] ==89:
               note1b[3] = 1
            if message[1] ==90:
               note1b[2] = 1
            if message[1] ==91:
               note1b[1] = 1
            if message[1] ==92:
               note1b[0] = 1
            note1b = int(hex(int("0b"+("".join(map(str, note1b))) ,2)),16)
            i2c.write_byte_data(0x20,0x15,note1b)
            note1b = list(bin(note1b).replace('0b', '').zfill(8))
            
            if message[1] ==93:
               note2a[7] = 1
            if message[1] ==94:
               note2a[6] = 1
            if message[1] ==95:
               note2a[5] = 1
            if message[1] ==96:
               note2a[4] = 1
            if message[1] ==97:
               note2a[3] = 1
            if message[1] ==98:
               note2a[2] = 1
            if message[1] ==99:
               note2a[1] = 1
            if message[1] ==100:
               note2a[0] = 1
            note2a = int(hex(int("0b"+("".join(map(str, note2a))) ,2)),16)
            i2c.write_byte_data(0x21,0x14,note2a)
            note2a = list(bin(note2a).replace('0b', '').zfill(8))
            if message[1] ==101:
               note2b[7] = 1
               note2b = int(hex(int("0b"+("".join(map(str, note2b))) ,2)),16)
               i2c.write_byte_data(0x21,0x15,note2b)
               note2b = list(bin(note2b).replace('0b', '').zfill(8))
               
         if message[0] == 128 and message[2] == 0 :
            if message[1] ==77:
               note1a[7] = 0
            if message[1] ==78:
               note1a[6] = 0
            if message[1] ==79:
               note1a[5] = 0
            if message[1] ==80:
               note1a[4] = 0
            if message[1] ==81:
               note1a[3] = 0
            if message[1] ==82:
               note1a[2] = 0
            if message[1] ==83:
               note1a[1] = 0
            if message[1] ==84:
               note1a[0] = 0
            note1a = int(hex(int("0b"+("".join(map(str, note1a))) ,2)),16)
            i2c.write_byte_data(0x20,0x14,note1a)
            note1a = list(bin(note1a).replace('0b', '').zfill(8))
            
            if message[1] ==85:
               note1b[7] = 0
            if message[1] ==86:
               note1b[6] = 0
            if message[1] ==87:
               note1b[5] = 0
            if message[1] ==88:
               note1b[4] = 0
            if message[1] ==89:
               note1b[3] = 0
            if message[1] ==90:
               note1b[2] = 0
            if message[1] ==91:
               note1b[1] = 0
            if message[1] ==92:
               note1b[0] = 0
            note1b = int(hex(int("0b"+("".join(map(str, note1b))) ,2)),16)
            i2c.write_byte_data(0x20,0x15,note1b)
            note1b = list(bin(note1b).replace('0b', '').zfill(8))
            
            if message[1] ==93:
               note2a[7] = 0
            if message[1] ==94:
               note2a[6] = 0
            if message[1] ==95:
               note2a[5] = 0
            if message[1] ==96:
               note2a[4] = 0
            if message[1] ==97:
               note2a[3] = 0
            if message[1] ==98:
               note2a[2] = 0
            if message[1] ==99:
               note2a[1] = 0
            if message[1] ==100:
               note2a[0] = 0
            note2a = int(hex(int("0b"+("".join(map(str, note2a))) ,2)),16)
            i2c.write_byte_data(0x21,0x14,note2a)
            note2a = list(bin(note2a).replace('0b', '').zfill(8))
            if message[1] ==101:
               note2b[7] = 0
               note2b = int(hex(int("0b"+("".join(map(str, note2b))) ,2)),16)
               i2c.write_byte_data(0x21,0x15,note2b)
               note2b = list(bin(note2b).replace('0b', '').zfill(8))
         continue