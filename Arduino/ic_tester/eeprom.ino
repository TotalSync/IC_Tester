/************************************

  Program File Serial SPI Layout Example:
  Example is for the 23A1024
  8|SPI
  CO--IKX+
  0x02|400ns|100ns
  0x
  %[Data in Hex]

  EOF
  ================

  (Number of Pins)|(Serial)   <= Pin Number and Type
  (Pin 1)(Pin 2)(Pin 3) etc.  <= Pin Declaration

  [Hex Number for write instruction (0-F)]|[Programming High Time]|[Programming Low time]
  [Start Address]
  %[Data to Write]

  C: Chip Select
  K: Clock Signal
  I: Data In
  O: Data Out
  +: Connect to VCC
  -: Connect to Ground
  X: Do not care / Leave floating

  EOF must not be included in the main program file
*************************************/


boolean ProgramEEPROM() {
  File dataFile = SD.open(eeprom);

  if (dataFile) {
    while (dataFile.available()) {
      uint8_t pinnum = (uint8_t) dataFile.readStringUntil('|').c_str();
      uint8_t pins = new uint8_t[pinnum];// <------ HEAP ALLOCATION
      String promType = dataFile.readStringUntil('\n');
      String promPinData = dataFile.readStringUntil('\n');
      String buf = dataFile.readStringUntil('|');
      int promWrite = StringHex_to_int(buf.c_str(), buf.length());
      int address = 0x0;



    }
  }

}

void writeToProm(int value, int address, int promWrite, uint8_t DI, uint8_t CLK) {
  shiftOut(DI, CLK, MSBFIRST, promWrite); //Works in 8-bit increments. May need bit manip to make full solution.
  shiftOut(DI, CLK, MSBFIRST, address);
  shiftOut(DI, CLK, MSBFIRST, value);
}
