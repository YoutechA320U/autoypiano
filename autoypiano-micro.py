# -*- coding: utf-8 -*-
# ESP32 MicroPython用
from machine import UART, Pin, I2C
uart = UART(2, 31250)
uart.init(31250, bits=8, parity=None, stop=1)
i2c = I2C(scl=Pin(22), sda=Pin(21), freq=100000)
i2c.writeto(0x20, b'\x00\x00')
i2c.writeto(0x20, b'\x01\x00')
i2c.writeto(0x21, b'\x00\x00')
i2c.writeto(0x21, b'\x01\x00')
i2c.writeto(0x20, b'\x14\x00')
i2c.writeto(0x20, b'\x15\x00')
i2c.writeto(0x21, b'\x14\x00')
i2c.writeto(0x21, b'\x15\x00')
note1a = 0
note1b = 0
note2a = 0
note2b = 0
buf1a = bytearray(2)
buf1b = bytearray(2)
buf2a = bytearray(2)
buf2b = bytearray(2)
buf1a[0] = buf2a[0] = 0x14
buf1b[0] = buf2b[0] = 0x15 
while True:
      try:
         data1 = list(uart.read(1))
      except TypeError:
         continue
      if data1[0] >= 246 :
         continue
      try:
         data2 = list(uart.read(1))
      except  TypeError:
         continue
      else:
         data1.extend(data2)
         if 192 <= data1[0] <= 208 or data1[1] >= 246 or data1[0] == 241 or data1[0] == 243: 
            continue
         try:
            data3 = list(uart.read(1))
         except  TypeError:
            continue
         else:
            data1.extend(data3)
            if data1[0] == 144 and data1[2] != 0:
               if data1[1] ==77:
                  note1a = bin(note1a | 0b1)
               if data1[1] ==78:
                  note1a = bin(note1a | 0b10)
               if data1[1] ==79:
                  note1a = bin(note1a | 0b100)
               if data1[1] ==80:
                  note1a = bin(note1a | 0b1000)
               if data1[1] ==81:
                  note1a = bin(note1a | 0b10000)
               if data1[1] ==82:
                  note1a = bin(note1a | 0b100000)
               if data1[1] ==83:
                  note1a = bin(note1a | 0b1000000)
               if data1[1] ==84:
                  note1a = bin(note1a | 0b10000000)
               note1a = int(note1a) 
               buf1a[1] = note1a
               i2c.writeto(0x20, buf1a)
               if data1[1] ==85:
                  note1b = bin(note1b | 0b1)
               if data1[1] ==86:
                  note1b = bin(note1b | 0b10)
               if data1[1] ==87:
                  note1b = bin(note1b | 0b100)
               if data1[1] ==88:
                  note1b = bin(note1b | 0b1000)
               if data1[1] ==89:
                  note1b = bin(note1b | 0b10000)
               if data1[1] ==90:
                  note1b = bin(note1b | 0b100000)
               if data1[1] ==91:
                  note1b = bin(note1b | 0b1000000)
               if data1[1] ==92:
                  note1b = bin(note1b | 0b10000000)
               note1b = int(note1b) 
               buf1b[1] = note1b
               i2c.writeto(0x20, buf1b)           
               if data1[1] ==93:
                  note2a = bin(note2a | 0b1)
               if data1[1] ==94:
                  note2a = bin(note2a | 0b10)
               if data1[1] ==95:
                  note2a = bin(note2a | 0b100)
               if data1[1] ==96:
                  note2a = bin(note2a | 0b1000)
               if data1[1] ==97:
                  note2a = bin(note2a | 0b10000)
               if data1[1] ==98:
                  note2a = bin(note2a | 0b100000)
               if data1[1] ==99:
                  note2a = bin(note2a | 0b1000000)
               if data1[1] ==100:
                  note2a = bin(note2a | 0b10000000)
               note2a = int(note2a) 
               buf2a[1] = note2a
               i2c.writeto(0x21, buf2a)
               if data1[1] ==101:
                  note2b = bin(note2b | 0b1)
                  note2b = int(note2b) 
                  buf2b[1] = note2b
                  i2c.writeto(0x21, buf2b)        
            if data1[0] == 128 and data1[2] == 0 :
               if data1[1] ==77:
                  note1a = bin(note1a & 0b11111110)
               if data1[1] ==78:
                  note1a = bin(note1a & 0b11111101)
               if data1[1] ==79:
                  note1a = bin(note1a & 0b11111011)
               if data1[1] ==80:
                  note1a = bin(note1a & 0b11110111)
               if data1[1] ==81:
                  note1a = bin(note1a & 0b11101111)
               if data1[1] ==82:
                  note1a = bin(note1a & 0b11011111)
               if data1[1] ==83:
                  note1a = bin(note1a & 0b10111111)
               if data1[1] ==84:
                  note1a = bin(note1a & 0b01111111)
               note1a = int(note1a) 
               buf1a[1] = note1a
               i2c.writeto(0x20, buf1a)
               if data1[1] ==85:
                  note1b = bin(note1b & 0b11111110)
               if data1[1] ==86:
                  note1b = bin(note1b & 0b11111101)
               if data1[1] ==87:
                  note1b = bin(note1b & 0b11111011)
               if data1[1] ==88:
                  note1b = bin(note1b & 0b11110111)
               if data1[1] ==89:
                  note1b = bin(note1b & 0b11101111)
               if data1[1] ==90:
                  note1b = bin(note1b & 0b11011111)
               if data1[1] ==91:
                  note1b = bin(note1b & 0b10111111)
               if data1[1] ==92:
                  note1b = bin(note1b & 0b01111111)
               note1b = int(note1b) 
               buf1b[1] = note1b
               i2c.writeto(0x20, buf1b)           
               if data1[1] ==93:
                  note2a = bin(note2a & 0b11111110)
               if data1[1] ==94:
                  note2a = bin(note2a & 0b11111101)
               if data1[1] ==95:
                  note2a = bin(note2a & 0b11111011)
               if data1[1] ==96:
                  note2a = bin(note2a & 0b11110111)
               if data1[1] ==97:
                  note2a = bin(note2a & 0b11101111)
               if data1[1] ==98:
                  note2a = bin(note2a & 0b11011111)
               if data1[1] ==99:
                  note2a = bin(note2a & 0b10111111)
               if data1[1] ==100:
                  note2a = bin(note2a & 0b01111111)
               note2a = int(note2a) 
               buf2a[1] = note2a
               i2c.writeto(0x21, buf2a)
               if data1[1] ==101:
                  note2b = bin(note2b & 0b11111110)
                  note2b = int(note2b) 
                  buf2b[1] = note2b
                  i2c.writeto(0x21, buf2b)