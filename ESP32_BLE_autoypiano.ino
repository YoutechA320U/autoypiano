#include "BleMidi.h"
#include <Wire.h>
#include <MIDI.h>
#include <Adafruit_MCP23017.h>

BLEMIDI_CREATE_INSTANCE(bm);
MIDI_CREATE_INSTANCE(HardwareSerial, Serial2, MIDI);

Adafruit_MCP23017 mcp1;
Adafruit_MCP23017 mcp2;

int sole_sum = 0;
int sole_limit = 4; //ソレノイド発音数制限。作者の環境では4
int sole_on[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

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
// -----------------------------------------------------------------------------
//
// -----------------------------------------------------------------------------
void setup(){
  Serial.begin(31250);
  //Serial.begin(115200);
  bm.begin("AuToyPiano");
  bm.setHandleNoteOn(OnBleMidiNoteOn);
  bm.setHandleNoteOff(OnBleMidiNoteOff);
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
  MIDI.begin(1);
}


void OnBleMidiNoteOn(byte channel, byte note, byte velocity) {
  //Serial.print(channel);
  //Serial.print(note);
  //Serial.print(velocity);
  note = AdjustNote(note);
  if (note == 77 and sole_sum < sole_limit and sole_on[0] ==0) {
    mcp1.digitalWrite(0, HIGH);
    sole_on[0] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 78 and sole_sum < sole_limit and sole_on[1] ==0) {
    mcp1.digitalWrite(1, HIGH);
    sole_on[1] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 79 and sole_sum < sole_limit and sole_on[2] ==0) {
    mcp1.digitalWrite(2, HIGH);
    sole_on[2] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 80 and sole_sum < sole_limit and sole_on[3] ==0) {
    mcp1.digitalWrite(3, HIGH);
    sole_on[3] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 81 and sole_sum < sole_limit and sole_on[4] ==0) {
    mcp1.digitalWrite(4, HIGH);
    sole_on[4] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 82 and sole_sum < sole_limit and sole_on[5] ==0) {
    mcp1.digitalWrite(5, HIGH);
    sole_on[5] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 83 and sole_sum < sole_limit and sole_on[6] ==0) {
    mcp1.digitalWrite(6, HIGH);
    sole_on[6] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 84 and sole_sum < sole_limit and sole_on[7] ==0) {
    mcp1.digitalWrite(7, HIGH);
    sole_on[7] =1;
    sole_sum = sole_sum + 1;    
  } else if (note == 85 and sole_sum < sole_limit and sole_on[8] ==0) {
    mcp1.digitalWrite(8, HIGH);
    sole_on[8] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 86 and sole_sum < sole_limit and sole_on[9] ==0) {
    mcp1.digitalWrite(9, HIGH);
    sole_on[9] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 87 and sole_sum < sole_limit and sole_on[10] ==0) {
    mcp1.digitalWrite(10, HIGH);
    sole_on[10] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 88 and sole_sum < sole_limit and sole_on[11] ==0) {
    mcp1.digitalWrite(11, HIGH);
    sole_on[11] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 89 and sole_sum < sole_limit and sole_on[12] ==0) {
    mcp1.digitalWrite(12, HIGH);
    sole_on[12] =1;
    sole_sum = sole_sum + 1;    
  } else if (note == 90 and sole_sum < sole_limit and sole_on[13] ==0) {
    mcp1.digitalWrite(13, HIGH);
    sole_on[13] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 91 and sole_sum < sole_limit and sole_on[14] ==0) {
    mcp1.digitalWrite(14, HIGH);
    sole_on[14] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 92 and sole_sum < sole_limit and sole_on[15] ==0) {
    mcp1.digitalWrite(15, HIGH);
    sole_on[15] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 93 and sole_sum < sole_limit and sole_on[16] ==0) {
    mcp2.digitalWrite(0, HIGH);
    sole_on[16] =1;
    sole_sum = sole_sum + 1;    
  } else if (note == 94 and sole_sum < sole_limit and sole_on[17] ==0) {
    mcp2.digitalWrite(1, HIGH);
    sole_on[17] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 95 and sole_sum < sole_limit and sole_on[18] ==0) {
    mcp2.digitalWrite(2, HIGH);
    sole_on[18] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 96 and sole_sum < sole_limit and sole_on[19] ==0) {
    mcp2.digitalWrite(3, HIGH);
    sole_on[19] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 97 and sole_sum < sole_limit and sole_on[20] ==0) {
    mcp2.digitalWrite(4, HIGH);
    sole_on[20] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 98 and sole_sum < sole_limit and sole_on[21] ==0) {
    mcp2.digitalWrite(5, HIGH);
    sole_on[21] =1;
    sole_sum = sole_sum + 1;    
  } else if (note == 99 and sole_sum < sole_limit and sole_on[22] ==0) {
    mcp2.digitalWrite(6, HIGH);
    sole_on[22] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 100 and sole_sum < sole_limit and sole_on[23] ==0) {
    mcp2.digitalWrite(7, HIGH);
    sole_on[23] =1;
    sole_sum = sole_sum + 1;
  } else if (note == 101 and sole_sum < sole_limit and sole_on[24] ==0) {
    mcp2.digitalWrite(8, HIGH);
    sole_on[24] =1;
    sole_sum = sole_sum + 1;     
  } else {
  }
}

void OnBleMidiNoteOff(byte channel, byte note, byte velocity) {
  //Serial.print(channel);
  //Serial.print(note);
  //Serial.print(velocity);
  note = AdjustNote(note);
  if (note == 77 and sole_on[0] ==1) {
    mcp1.digitalWrite(0, LOW);
    sole_on[0] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 78 and sole_on[1] ==1) {
    mcp1.digitalWrite(1, LOW);
    sole_on[1] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 79 and sole_on[2] ==1) {
    mcp1.digitalWrite(2, LOW);
    sole_on[2] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 80 and sole_on[3] ==1) {
    mcp1.digitalWrite(3, LOW);
    sole_on[3] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 81 and sole_on[4] ==1) {
    mcp1.digitalWrite(4, LOW);
    sole_on[4] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 82 and sole_on[5] ==1) {
    mcp1.digitalWrite(5, LOW);
    sole_on[5] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 83 and sole_on[6] ==1) {
    mcp1.digitalWrite(6, LOW);
    sole_on[6] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 84 and sole_on[7] ==1) {
    mcp1.digitalWrite(7, LOW);
    sole_on[7] =0;
    sole_sum = sole_sum - 1;    
  } else if (note == 85 and sole_on[8] ==1) {
    mcp1.digitalWrite(8, LOW);
    sole_on[8] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 86 and sole_on[9] ==1) {
    mcp1.digitalWrite(9, LOW);
    sole_on[9] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 87 and sole_on[10] ==1) {
    mcp1.digitalWrite(10, LOW);
    sole_on[10] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 88 and sole_on[11] ==1) {
    mcp1.digitalWrite(11, LOW);
    sole_on[11] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 89 and sole_on[12] ==1) {
    mcp1.digitalWrite(12, LOW);
    sole_on[12] =0;
    sole_sum = sole_sum - 1;    
  } else if (note == 90 and sole_on[13] ==1) {
    mcp1.digitalWrite(13, LOW);
    sole_on[13] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 91 and sole_on[14] ==1) {
    mcp1.digitalWrite(14, LOW);
    sole_on[14] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 92 and sole_on[15] ==1) {
    mcp1.digitalWrite(15, LOW);
    sole_on[15] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 93 and sole_on[16] ==1) {
    mcp2.digitalWrite(0, LOW);
    sole_on[16] =0;
    sole_sum = sole_sum - 1;    
  } else if (note == 94 and sole_on[17] ==1) {
    mcp2.digitalWrite(1, LOW);
    sole_on[17] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 95 and sole_on[18] ==1) {
    mcp2.digitalWrite(2, LOW);
    sole_on[18] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 96 and sole_on[19] ==1) {
    mcp2.digitalWrite(3, LOW);
    sole_on[19] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 97 and sole_on[20] ==1) {
    mcp2.digitalWrite(4, LOW);
    sole_on[20] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 98 and sole_on[21] ==1) {
    mcp2.digitalWrite(5, LOW);
    sole_on[21] =0;
    sole_sum = sole_sum - 1;    
  } else if (note == 99 and sole_on[22] ==1) {
    mcp2.digitalWrite(6, LOW);
    sole_on[22] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 100 and sole_on[23] ==1) {
    mcp2.digitalWrite(7, LOW);
    sole_on[23] =0;
    sole_sum = sole_sum - 1;
  } else if (note == 101 and sole_on[24] ==1) {
    mcp2.digitalWrite(8, LOW);
    sole_on[24] =0;
    sole_sum = sole_sum - 1;     
  } else {
  }    
}

void loop(){
  //MIDI.read();
  int rx;
  int rx1;
  int rx2;
  int rx3;
  do {
    rx =  MIDI.read();
    rx1 = MIDI.getType();
    rx2 = MIDI.getData1();
    rx3 = MIDI.getData2();
    rx2 = AdjustNote(rx2);
    if (rx !=0) {  
      //Serial.println(rx1);
      //Serial.println(rx2);
      //Serial.println(rx3);
    } if (rx != 0 and rx1 == 144 and rx2 == 77 and rx3 !=0 and sole_sum < sole_limit and sole_on[0] ==0) { //MIDIでNoteOnの時
      mcp1.digitalWrite(0, HIGH);
      sole_on[0] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 78 and rx3 !=0 and sole_sum < sole_limit and sole_on[1] ==0) {
      mcp1.digitalWrite(1, HIGH);
      sole_on[1] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 79 and rx3 !=0 and sole_sum < sole_limit and sole_on[2] ==0) {
      mcp1.digitalWrite(2, HIGH);
      sole_on[2] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 80 and rx3 !=0 and sole_sum < sole_limit and sole_on[3] ==0) {
      mcp1.digitalWrite(3, HIGH);
      sole_on[3] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 81 and rx3 !=0 and sole_sum < sole_limit and sole_on[4] ==0) {
      mcp1.digitalWrite(4, HIGH);
      sole_on[4] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 82 and rx3 !=0 and sole_sum < sole_limit and sole_on[5] ==0) {
      mcp1.digitalWrite(5, HIGH);
      sole_on[5] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 83 and rx3 !=0 and sole_sum < sole_limit and sole_on[6] ==0) {
      mcp1.digitalWrite(6, HIGH);
      sole_on[6] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 84 and rx3 !=0 and sole_sum < sole_limit and sole_on[7] ==0) {
      mcp1.digitalWrite(7, HIGH);
      sole_on[7] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 85 and rx3 !=0 and sole_sum < sole_limit and sole_on[8] ==0) {
      mcp1.digitalWrite(8, HIGH);
      sole_on[8] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 86 and rx3 !=0 and sole_sum < sole_limit and sole_on[9] ==0) {
      mcp1.digitalWrite(9, HIGH);
      sole_on[9] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 87 and rx3 !=0 and sole_sum < sole_limit and sole_on[10] ==0) {
      mcp1.digitalWrite(10, HIGH);
      sole_on[10] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 88 and rx3 !=0 and sole_sum < sole_limit and sole_on[11] ==0) {
      mcp1.digitalWrite(11, HIGH);
      sole_on[11] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 89 and rx3 !=0 and sole_sum < sole_limit and sole_on[12] ==0) {
      mcp1.digitalWrite(12, HIGH);
      sole_on[12] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 90 and rx3 !=0 and sole_sum < sole_limit and sole_on[13] ==0) {
      mcp1.digitalWrite(13, HIGH);
      sole_on[13] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 91 and rx3 !=0 and sole_sum < sole_limit and sole_on[14] ==0) {
      mcp1.digitalWrite(14, HIGH);
      sole_on[14] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 92 and rx3 !=0 and sole_sum < sole_limit and sole_on[15] ==0) {
      mcp1.digitalWrite(15, HIGH);
      sole_on[15] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 93 and rx3 !=0 and sole_sum < sole_limit and sole_on[16] ==0) {
      mcp2.digitalWrite(0, HIGH);
      sole_on[16] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 94 and rx3 !=0 and sole_sum < sole_limit and sole_on[17] ==0) {
      mcp2.digitalWrite(1, HIGH);
      sole_on[17] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 95 and rx3 !=0 and sole_sum < sole_limit and sole_on[18] ==0) {
      mcp2.digitalWrite(2, HIGH);
      sole_on[18] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 96 and rx3 !=0 and sole_sum < sole_limit and sole_on[19] ==0) {
      mcp2.digitalWrite(3, HIGH);
      sole_on[19] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 97 and rx3 !=0 and sole_sum < sole_limit and sole_on[20] ==0) {
      mcp2.digitalWrite(4, HIGH);
      sole_on[20] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 98 and rx3 !=0 and sole_sum < sole_limit and sole_on[21] ==0) {
      mcp2.digitalWrite(5, HIGH);
      sole_on[21] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 99 and rx3 !=0 and sole_sum < sole_limit and sole_on[22] ==0) {
      mcp2.digitalWrite(6, HIGH);
      sole_on[22] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 100 and rx3 !=0 and sole_sum < sole_limit and sole_on[23] ==0) {
      mcp2.digitalWrite(7, HIGH);
      sole_on[23] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and rx1 == 144 and rx2 == 101 and rx3 !=0 and sole_sum < sole_limit and sole_on[24] ==0) {
      mcp2.digitalWrite(8, HIGH);
      sole_on[24] =1;
      sole_sum = sole_sum + 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 77) or (rx1 == 144 and rx2 == 77 and rx3 ==0) and sole_on[0] ==1) { //MIDIでNoteOffの時
      mcp1.digitalWrite(0, LOW); 
      sole_on[0] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 78) or (rx1 == 144 and rx2 == 78 and rx3 ==0) and sole_on[1] ==1) {
      mcp1.digitalWrite(1, LOW); 
      sole_on[1] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 79) or (rx1 == 144 and rx2 == 79 and rx3 ==0) and sole_on[2] ==1) {
      mcp1.digitalWrite(2, LOW); 
      sole_on[2] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 80) or (rx1 == 144 and rx2 == 80 and rx3 ==0) and sole_on[3] ==1) {
      mcp1.digitalWrite(3, LOW);
      sole_on[3] =0;
      sole_sum = sole_sum - 1; 
    } if (rx != 0 and (rx1 == 128 and rx2 == 81) or (rx1 == 144 and rx2 == 81 and rx3 ==0) and sole_on[4] ==1) {
      mcp1.digitalWrite(4, LOW);
      sole_on[4] =0;
      sole_sum = sole_sum - 1; 
    } if (rx != 0 and (rx1 == 128 and rx2 == 82) or (rx1 == 144 and rx2 == 82 and rx3 ==0) and sole_on[5] ==1) {
      mcp1.digitalWrite(5, LOW); 
      sole_on[5] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 83) or (rx1 == 144 and rx2 == 83 and rx3 ==0) and sole_on[6] ==1) {
      mcp1.digitalWrite(6, LOW); 
      sole_on[6] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 84) or (rx1 == 144 and rx2 == 84 and rx3 ==0) and sole_on[7] ==1) {
      mcp1.digitalWrite(7, LOW); 
      sole_on[7] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 85) or (rx1 == 144 and rx2 == 85 and rx3 ==0) and sole_on[8] ==1) {
      mcp1.digitalWrite(8, LOW); 
      sole_on[8] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 86) or (rx1 == 144 and rx2 == 86 and rx3 ==0) and sole_on[9] ==1) {
      mcp1.digitalWrite(9, LOW); 
      sole_on[9] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 87) or (rx1 == 144 and rx2 == 87 and rx3 ==0) and sole_on[10] ==1) {
      mcp1.digitalWrite(10, LOW); 
      sole_on[10] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 88) or (rx1 == 144 and rx2 == 88 and rx3 ==0) and sole_on[11] ==1) {
      mcp1.digitalWrite(11, LOW); 
      sole_on[11] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 89) or (rx1 == 144 and rx2 == 89 and rx3 ==0) and sole_on[12] ==1) {
      mcp1.digitalWrite(12, LOW); 
      sole_on[12] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 90) or (rx1 == 144 and rx2 == 90 and rx3 ==0) and sole_on[13] ==1) {
      mcp1.digitalWrite(13, LOW); 
      sole_on[13] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 91) or (rx1 == 144 and rx2 == 91 and rx3 ==0) and sole_on[14] ==1) {
      mcp1.digitalWrite(14, LOW); 
      sole_on[14] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 92) or (rx1 == 144 and rx2 == 92 and rx3 ==0) and sole_on[15] ==1) {
      mcp1.digitalWrite(15, LOW); 
      sole_on[15] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 93) or (rx1 == 144 and rx2 == 93 and rx3 ==0) and sole_on[16] ==1) {
      mcp2.digitalWrite(0, LOW); 
      sole_on[16] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 94) or (rx1 == 144 and rx2 == 94 and rx3 ==0) and sole_on[17] ==1) {
      mcp2.digitalWrite(1, LOW); 
      sole_on[17] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 95) or (rx1 == 144 and rx2 == 95 and rx3 ==0) and sole_on[18] ==1) {
      mcp2.digitalWrite(2, LOW); 
      sole_on[18] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 96) or (rx1 == 144 and rx2 == 96 and rx3 ==0) and sole_on[19] ==1) {
      mcp2.digitalWrite(3, LOW); 
      sole_on[19] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 97) or (rx1 == 144 and rx2 == 97 and rx3 ==0) and sole_on[20] ==1) {
      mcp2.digitalWrite(4, LOW); 
      sole_on[20] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 98) or (rx1 == 144 and rx2 == 98 and rx3 ==0) and sole_on[21] ==1) {
      mcp2.digitalWrite(5, LOW); 
      sole_on[21] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 99) or (rx1 == 144 and rx2 == 99 and rx3 ==0) and sole_on[22] ==1) {
      mcp2.digitalWrite(6, LOW); 
      sole_on[22] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 100) or (rx1 == 144 and rx2 == 100 and rx3 ==0) and sole_on[23] ==1) {
      mcp2.digitalWrite(7, LOW); 
      sole_on[23] =0;
      sole_sum = sole_sum - 1;
    } if (rx != 0 and (rx1 == 128 and rx2 == 101)  or (rx1 == 144 and rx2 == 101 and rx3 ==0)and sole_on[24] ==1) {
      mcp2.digitalWrite(8, LOW);
      sole_on[24] =0;
      sole_sum = sole_sum - 1;
    } if (sole_sum < 0) { 
      sole_sum = 0;
    } else {
    }
  } while (rx !=0);
}
