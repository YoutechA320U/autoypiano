#include <MIDI.h>
#include <Wire.h>
#include "Adafruit_MCP23017.h"

Adafruit_MCP23017 mcp1;
Adafruit_MCP23017 mcp2;

MIDI_CREATE_DEFAULT_INSTANCE();

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

void handleNoteOn(byte channel, byte note) {
  note = AdjustNote(note);

  if (note == 77) {
    mcp1.digitalWrite(0, HIGH);
  } else if (note == 78) {
    mcp1.digitalWrite(1, HIGH);
  } else if (note == 79) {
    mcp1.digitalWrite(2, HIGH);
  } else if (note == 80) {
    mcp1.digitalWrite(3, HIGH);
  } else if (note == 81) {
    mcp1.digitalWrite(4, HIGH);
  } else if (note == 82) {
    mcp1.digitalWrite(5, HIGH);
  } else if (note == 83) {
    mcp1.digitalWrite(6, HIGH);
  } else if (note == 84) {
    mcp1.digitalWrite(7, HIGH);
  } else if (note == 85) {
    mcp1.digitalWrite(8, HIGH);
  } else if (note == 86) {
    mcp1.digitalWrite(9, HIGH);
  } else if (note == 87) {
    mcp1.digitalWrite(10, HIGH);
  } else if (note == 88) {
    mcp1.digitalWrite(11, HIGH);
  } else if (note == 89) {
    mcp1.digitalWrite(12, HIGH);
  } else if (note == 90) {
    mcp1.digitalWrite(13, HIGH);
  } else if (note == 91) {
    mcp1.digitalWrite(14, HIGH);
  } else if (note == 92) {
    mcp1.digitalWrite(15, HIGH);
  } else if (note == 93) {
    mcp2.digitalWrite(0, HIGH);
  } else if (note == 94) {
    mcp2.digitalWrite(1, HIGH);
  } else if (note == 95) {
    mcp2.digitalWrite(2, HIGH);
  } else if (note == 96) {
    mcp2.digitalWrite(3, HIGH);
  } else if (note == 97) {
    mcp2.digitalWrite(4, HIGH);
  } else if (note == 98) {
    mcp2.digitalWrite(5, HIGH);
  } else if (note == 99) {
    mcp2.digitalWrite(6, HIGH);
  } else if (note == 100) {
    mcp2.digitalWrite(7, HIGH);
  } else if (note == 101) {
    mcp2.digitalWrite(8, HIGH);
  } else {
  }
}

void handleNoteOff(byte channel, byte note) {
  note = AdjustNote(note);

  if (note == 77) {
    mcp1.digitalWrite(0, LOW);
  } else if (note == 78) {
    mcp1.digitalWrite(1, LOW);
  } else if (note == 79) {
    mcp1.digitalWrite(2, LOW);
  } else if (note == 80) {
    mcp1.digitalWrite(3, LOW);
  } else if (note == 81) {
    mcp1.digitalWrite(4, LOW);
  } else if (note == 82) {
    mcp1.digitalWrite(5, LOW);
  } else if (note == 83) {
    mcp1.digitalWrite(6, LOW);
  } else if (note == 84) {
    mcp1.digitalWrite(7, LOW);
  } else if (note == 85) {
    mcp1.digitalWrite(8, LOW);
  } else if (note == 86) {
    mcp1.digitalWrite(9, LOW);
  } else if (note == 87) {
    mcp1.digitalWrite(10, LOW);
  } else if (note == 88) {
    mcp1.digitalWrite(11, LOW);
  } else if (note == 89) {
    mcp1.digitalWrite(12, LOW);
  } else if (note == 90) {
    mcp1.digitalWrite(13, LOW);
  } else if (note == 91) {
    mcp1.digitalWrite(14, LOW);
  } else if (note == 92) {
    mcp1.digitalWrite(15, LOW);
  } else if (note == 93) {
    mcp2.digitalWrite(0, LOW);
  } else if (note == 94) {
    mcp2.digitalWrite(1, LOW);
  } else if (note == 95) {
    mcp2.digitalWrite(2, LOW);
  } else if (note == 96) {
    mcp2.digitalWrite(3, LOW);
  } else if (note == 97) {
    mcp2.digitalWrite(4, LOW);
  } else if (note == 98) {
    mcp2.digitalWrite(5, LOW);
  } else if (note == 99) {
    mcp2.digitalWrite(6, LOW);
  } else if (note == 100) {
    mcp2.digitalWrite(7, LOW);
  } else if (note == 101) {
    mcp2.digitalWrite(8, LOW);
  } else {
  }
}

void setup() {
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

  MIDI.setHandleNoteOn(handleNoteOn);
  MIDI.setHandleNoteOff(handleNoteOff);

  MIDI.begin(1);
}

void loop() {

  MIDI.read();

}
