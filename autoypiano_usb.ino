#include <Wire.h>
#include <MIDIUSB.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp1;
Adafruit_MCP23017 mcp2;

int AdjustNote (int note) {
  if (note <= 101 && note >= 77) {
  } else if (note > 101) {
    do {
      note = note - 12;
    } while (note > 101);
  } else if (note < 77) {
    do {
      note = note + 12;
    } while (note < 77);
  }
  return note;
}

void setup() {
  Serial.begin(31250);
  mcp1.begin(0);      //  MCP23017-1 use default address 0
  Wire.write(0x14);
  Wire.write(0x00); //0~7Pin LOW
  Wire.endTransmission();
  Wire.beginTransmission(0x20);
  Wire.write(0x15);
  Wire.write(0x00); //8~15Pin LOW
  Wire.endTransmission();
  mcp1.pinMode(0, OUTPUT);
  mcp1.pinMode(1, OUTPUT);
  mcp1.pinMode(2, OUTPUT);
  mcp1.pinMode(3, OUTPUT);
  mcp1.pinMode(4, OUTPUT);
  mcp1.pinMode(5, OUTPUT);
  mcp1.pinMode(6, OUTPUT);
  mcp1.pinMode(7, OUTPUT);
  mcp1.pinMode(8, OUTPUT);
  mcp1.pinMode(9, OUTPUT);
  mcp1.pinMode(10, OUTPUT);
  mcp1.pinMode(11, OUTPUT);
  mcp1.pinMode(12, OUTPUT);
  mcp1.pinMode(13, OUTPUT);
  mcp1.pinMode(14, OUTPUT);
  mcp1.pinMode(15, OUTPUT);
  mcp2.begin(1);      // MCP23017-2 use address 1
  Wire.beginTransmission(0x21);
  Wire.write(0x14);
  Wire.write(0x00); //0~7Pin LOW
  Wire.endTransmission();
  Wire.beginTransmission(0x21);
  Wire.write(0x15);
  Wire.write(0x00); //8~15Pin LOW
  Wire.endTransmission();
  mcp2.pinMode(0, OUTPUT);
  mcp2.pinMode(1, OUTPUT);
  mcp2.pinMode(2, OUTPUT);
  mcp2.pinMode(3, OUTPUT);
  mcp2.pinMode(4, OUTPUT);
  mcp2.pinMode(5, OUTPUT);
  mcp2.pinMode(6, OUTPUT);
  mcp2.pinMode(7, OUTPUT);
  mcp2.pinMode(8, OUTPUT);
}

void loop() {
  midiEventPacket_t rx;
  do {
    rx = MidiUSB.read();
    rx.byte2 = AdjustNote(rx.byte2);
    if (rx.header != 0 ) {
      Serial.println(rx.byte1);
      //Serial.println(rx.byte2);
      //Serial.println(rx.byte3);
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 77 and rx.byte3 !=0) {
      mcp1.digitalWrite(0, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 77 and rx.byte3 ==0) {
      mcp1.digitalWrite(0, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 78 and rx.byte3 !=0) {
      mcp1.digitalWrite(1, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 78 and rx.byte3 ==0) {
      mcp1.digitalWrite(1, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 79 and rx.byte3 !=0) {
      mcp1.digitalWrite(2, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 79 and rx.byte3 ==0) {
      mcp1.digitalWrite(2, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 80 and rx.byte3 !=0) {
      mcp1.digitalWrite(3, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 80 and rx.byte3 ==0) {
      mcp1.digitalWrite(3, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 81 and rx.byte3 !=0) {
      mcp1.digitalWrite(4, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 81 and rx.byte3 ==0) {
      mcp1.digitalWrite(4, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 82 and rx.byte3 !=0) {
      mcp1.digitalWrite(5, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 82 and rx.byte3 ==0) {
      mcp1.digitalWrite(5, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 83 and rx.byte3 !=0) {
      mcp1.digitalWrite(6, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 83 and rx.byte3 ==0) {
      mcp1.digitalWrite(6, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 84 and rx.byte3 !=0) {
      mcp1.digitalWrite(7, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 84 and rx.byte3 ==0) {
      mcp1.digitalWrite(7, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 85 and rx.byte3 !=0) {
      mcp1.digitalWrite(8, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 85 and rx.byte3 ==0) {
      mcp1.digitalWrite(8, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 86 and rx.byte3 !=0) {
      mcp1.digitalWrite(9, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 86 and rx.byte3 ==0) {
      mcp1.digitalWrite(9, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 87 and rx.byte3 !=0) {
      mcp1.digitalWrite(10, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 87 and rx.byte3 ==0) {
      mcp1.digitalWrite(10, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 88 and rx.byte3 !=0) {
      mcp1.digitalWrite(11, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 88 and rx.byte3 ==0) {
      mcp1.digitalWrite(11, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 89 and rx.byte3 !=0) {
      mcp1.digitalWrite(12, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 89 and rx.byte3 ==0) {
      mcp1.digitalWrite(12, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 90 and rx.byte3 !=0) {
      mcp1.digitalWrite(13, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 90 and rx.byte3 ==0) {
      mcp1.digitalWrite(13, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 91 and rx.byte3 !=0) {
      mcp1.digitalWrite(14, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 91 and rx.byte3 ==0) {
      mcp1.digitalWrite(14, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 92 and rx.byte3 !=0) {
      mcp1.digitalWrite(15, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 92 and rx.byte3 ==0) {
      mcp1.digitalWrite(15, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 93 and rx.byte3 !=0) {
      mcp2.digitalWrite(0, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 93 and rx.byte3 ==0) {
      mcp2.digitalWrite(0, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 94 and rx.byte3 !=0) {
      mcp2.digitalWrite(1, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 94 and rx.byte3 ==0) {
      mcp2.digitalWrite(1, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 95 and rx.byte3 !=0) {
      mcp2.digitalWrite(2, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 95 and rx.byte3 ==0) {
      mcp2.digitalWrite(2, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 96 and rx.byte3 !=0) {
      mcp2.digitalWrite(3, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 96 and rx.byte3 ==0) {
      mcp2.digitalWrite(3, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 97 and rx.byte3 !=0) {
      mcp2.digitalWrite(4, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 97 and rx.byte3 ==0) {
      mcp2.digitalWrite(4, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 98 and rx.byte3 !=0) {
      mcp2.digitalWrite(5, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 98 and rx.byte3 ==0) {
      mcp2.digitalWrite(5, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 99 and rx.byte3 !=0) {
      mcp2.digitalWrite(6, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 99 and rx.byte3 ==0) {
      mcp2.digitalWrite(6, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 100 and rx.byte3 !=0) {
      mcp2.digitalWrite(7, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 100 and rx.byte3 ==0) {
      mcp2.digitalWrite(7, LOW); 
    } if (rx.header != 0 and rx.byte1 == 144 and rx.byte2 == 101 and rx.byte3 !=0) {
      mcp2.digitalWrite(8, HIGH);
    } if (rx.header != 0 and rx.byte1 == 128 and rx.byte2 == 101 and rx.byte3 ==0) {
      mcp2.digitalWrite(8, LOW); 
    } else {
    }
  } while (rx.header != 0);
}
