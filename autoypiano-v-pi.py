# -*- coding: utf-8 -*-
#!/usr/bin/env python

import rtmidi
import time
import smbus

midiin = rtmidi.MidiIn()
midiin.open_virtual_port("AuToyPiano_in") # 仮想MIDI入力ポートの名前
midiin.ignore_types(sysex=False)

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

note1a = 0
note1b = 0
note2a = 0
note2b = 0

sole_sum = 0
sole_limit = 4 #ソレノイド発音数制限。作者の環境では4
sole_on = [0]*25

def AdjustNote(note) :
  while (note > 101):
      note -= 12
      if note <= 101:
         break
      if note > 101:
         continue
  while (note < 77) :
      note += 12
      if note >=77:
         break
      if note < 77:
         continue
  return note

while True:
 time.sleep(0.0001)
 msg = midiin.get_message()
 if msg is None:
    message, deltatime = None,None 
    sole_sum =0
 if msg is not None:
    message, deltatime = msg
    if message == ([240, 65, 16, 66, 18, 64, 0, 127, 0, 65, 247]) or message ==([240, 67, 16, 76, 0, 0, 126, 0, 247]) or message == ([240, 126, 127, 9, 1, 247]) or message == ([240, 126, 127, 9, 3, 247]) :
       i2c.write_byte_data(0x20,0x14,0x00) 
       i2c.write_byte_data(0x20,0x15,0x00)
       i2c.write_byte_data(0x21,0x14,0x00)
       i2c.write_byte_data(0x21,0x15,0x00)
    message[1]=AdjustNote(message[1])
    #print(message)
    #print(note1a)
    #print(note1b)
    #print(note2a)
    #print(note1b)
    print(sole_sum)
    if message[0] == 144 and message[2] != 0 and sole_sum < sole_limit:
       if message[1] ==77 and sole_sum < sole_limit:
          note1a = (note1a | 0b1)
          #print(note1a)
          sole_on[0] =1
          sole_sum +=1
       if message[1] ==78 and sole_sum < sole_limit:
          note1a = (note1a | 0b10)
          sole_on[1] =1
          sole_sum +=1
       if message[1] ==79 and sole_sum < sole_limit:
          note1a = (note1a | 0b100)
          sole_on[2] =1
          sole_sum +=1
       if message[1] ==80 and sole_sum < sole_limit:
          note1a = (note1a | 0b1000)
          sole_on[3] =1
          sole_sum +=1
       if message[1] ==81 and sole_sum < sole_limit:
          note1a = (note1a | 0b10000)
          sole_on[4] =1
          sole_sum +=1
       if message[1] ==82 and sole_sum < sole_limit:
          note1a = (note1a | 0b100000)
          sole_on[5] =1
          sole_sum +=1
       if message[1] ==83 and sole_sum < sole_limit:
          note1a = (note1a | 0b1000000)
          sole_on[6] =1
          sole_sum +=1
       if message[1] ==84 and sole_sum < sole_limit:
          note1a = (note1a | 0b10000000)
          sole_on[7] =1
          sole_sum +=1
       if message[1] ==85 and sole_sum < sole_limit:
          note1b = (note1b | 0b1)
          sole_on[8] =1
          sole_sum +=1
       if message[1] ==86 and sole_sum < sole_limit:
          note1b = (note1b | 0b10)
          sole_on[9] =1
          sole_sum +=1
       if message[1] ==87 and sole_sum < sole_limit:
          note1b = (note1b | 0b100)
          sole_on[10] =1
          sole_sum +=1
       if message[1] ==88 and sole_sum < sole_limit:
          note1b = (note1b | 0b1000)
          sole_on[11] =1
          sole_sum +=1
       if message[1] ==89 and sole_sum < sole_limit:
          note1b = (note1b | 0b10000)
          sole_on[12] =1
          sole_sum +=1
       if message[1] ==90 and sole_sum < sole_limit:
          note1b = (note1b | 0b100000)
          sole_on[13] =1
          sole_sum +=1
       if message[1] ==91 and sole_sum < sole_limit:
          note1b = (note1b | 0b1000000)
          sole_on[14] =1
          sole_sum +=1
       if message[1] ==92 and sole_sum < sole_limit:
          note1b = (note1b | 0b10000000)
          sole_on[15] =1
          sole_sum +=1
       if message[1] ==93 and sole_sum < sole_limit:
          note2a = (note2a | 0b1)
          sole_on[16] =1
          sole_sum +=1
       if message[1] ==94 and sole_sum < sole_limit:
          note2a = (note2a | 0b10)
          sole_on[17] =1
          sole_sum +=1
       if message[1] ==95 and sole_sum < sole_limit:
          note2a = (note2a | 0b100)
          sole_on[18] =1
          sole_sum +=1
       if message[1] ==96 and sole_sum < sole_limit:
          note2a = (note2a | 0b1000)
          sole_on[19] =1
          sole_sum +=1
       if message[1] ==97 and sole_sum < sole_limit:
          note2a = (note2a | 0b10000)
          sole_on[20] =1
          sole_sum +=1
       if message[1] ==98 and sole_sum < sole_limit:
          note2a = (note2a | 0b100000)
          sole_on[21] =1
          sole_sum +=1
       if message[1] ==99 and sole_sum < sole_limit:
          note2a = (note2a | 0b1000000)
          sole_on[22] =1
          sole_sum +=1
       if message[1] ==100 and sole_sum < sole_limit:
          note2a = (note2a | 0b10000000)
          sole_on[23] =1
          sole_sum +=1
       if message[1] ==101 and sole_sum < sole_limit:
          note2b = (note2b | 0b1)
          sole_on[24] =1
          sole_sum +=1
       i2c.write_byte_data(0x20,0x14,note1a)
       i2c.write_byte_data(0x20,0x15,note1b)
       i2c.write_byte_data(0x21,0x14,note2a)
       i2c.write_byte_data(0x21,0x15,note2b)

    if message[0] == 128 and message[2] ==0:
       if message[1] ==77 and sole_on[0] ==1:
          note1a = (note1a & 0b11111110)
          sole_on[0] =0
          sole_sum -=1
       if message[1] ==78 and sole_on[1] ==1:
          note1a = (note1a & 0b11111101)
          sole_on[1] =0
          sole_sum -=1
       if message[1] ==79 and sole_on[2] ==1:
          note1a = (note1a & 0b11111011)
          sole_on[2] =0
          sole_sum -=1
       if message[1] ==80 and sole_on[3] ==1:
          note1a = (note1a & 0b11110111)
          sole_on[3] =0
          sole_sum -=1
       if message[1] ==81 and sole_on[4] ==1:
          note1a = (note1a & 0b11101111)
          sole_on[4] =0
          sole_sum -=1
       if message[1] ==82 and sole_on[5] ==1:
          note1a = (note1a & 0b11011111)
          sole_on[5] =0
          sole_sum -=1
       if message[1] ==83 and sole_on[6] ==1:
          note1a = (note1a & 0b10111111)
          sole_on[6] =0
          sole_sum -=1
       if message[1] ==84 and sole_on[7] ==1:
          note1a = (note1a & 0b01111111)
          sole_on[7] =0
          sole_sum -=1
       if message[1] ==85 and sole_on[8] ==1:
          note1b = (note1b & 0b11111110)
          sole_on[8] =0
          sole_sum -=1
       if message[1] ==86 and sole_on[9] ==1:
          note1b = (note1b & 0b11111101)
          sole_on[9] =0
          sole_sum -=1
       if message[1] ==87 and sole_on[10] ==1:
          note1b = (note1b & 0b11111011)
          sole_on[10] =0
          sole_sum -=1
       if message[1] ==88 and sole_on[11] ==1:
          note1b = (note1b & 0b11110111)
          sole_on[11] =0
          sole_sum -=1
       if message[1] ==89 and sole_on[12] ==1:
          note1b = (note1b & 0b11101111)
          sole_on[12] =0
          sole_sum -=1
       if message[1] ==90 and sole_on[13] ==1:
          note1b = (note1b & 0b11011111)
          sole_on[13] =0
          sole_sum -=1
       if message[1] ==91 and sole_on[14] ==1:
          note1b = (note1b & 0b10111111)
          sole_on[14] =0
          sole_sum -=1
       if message[1] ==92 and sole_on[15] ==1:
          note1b = (note1b & 0b01111111)
          sole_on[15] =0
          sole_sum -=1
       if message[1] ==93 and sole_on[16] ==1:
          note2a = (note2a & 0b11111110)
          sole_on[0] =0
          sole_sum -=1
       if message[1] ==94 and sole_on[17] ==1:
          note2a = (note2a & 0b11111101)
          sole_on[1] =0
          sole_sum -=1
       if message[1] ==95 and sole_on[18] ==1:
          note2a = (note2a & 0b11111011)
          sole_on[2] =0
          sole_sum -=1
       if message[1] ==96 and sole_on[19] ==1:
          note2a = (note2a & 0b11110111)
          sole_on[3] =0
          sole_sum -=1
       if message[1] ==97 and sole_on[20] ==1:
          note2a = (note2a & 0b11101111)
          sole_on[4] =0
          sole_sum -=1
       if message[1] ==98 and sole_on[21] ==1:
          note2a = (note2a & 0b11011111)
          sole_on[5] =0
          sole_sum -=1
       if message[1] ==99 and sole_on[22] ==1:
          note2a = (note2a & 0b10111111)
          sole_on[6] =0
          sole_sum -=1
       if message[1] ==100 and sole_on[23] ==1:
          note2a = (note2a & 0b01111111)
          sole_on[7] =0
          sole_sum -=1
       if message[1] ==101 and sole_on[24] ==1:
          note2b = (note2b & 0b11111110)
          sole_on[24] =0
          sole_sum -=1
       i2c.write_byte_data(0x20,0x14,note1a)
       i2c.write_byte_data(0x20,0x15,note1b)
       i2c.write_byte_data(0x21,0x14,note2a)
       i2c.write_byte_data(0x21,0x15,note2b)