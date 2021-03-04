/************************************

  Program File Serial SPI Layout Example:
  Example is for the 23A1024
  8|SPI
  CO--IKX+
  0x02|0x000000
  %[Data in Hex]

  EOF
  ================

  (Number of Pins)|(Serial)   <= Pin Number and Type
  (Pin 1)(Pin 2)(Pin 3) etc.  <= Pin Declaration
  [Hex Number for write instruction (0-F)]|[Start Address]
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
      uint8_t* pins = new uint8_t[pinnum];// <------ HEAP ALLOCATION
      String promType = dataFile.readStringUntil('\n');
      String promPinData = dataFile.readStringUntil('\n');
      for (int c = 0; c < promPinData.length(); c++ ){
        pins[c] = promPinData.c_str()[c]; // May cause issues int the future
      }
      String promWriteString = dataFile.readStringUntil('|');
      int promWrite = StringHex_to_int(promWriteString.c_str(), promWriteString.length());
      String promAddressStart = dataFile.readStringUntil('\n');
      int promAddress = StringHex_to_int(promAddressStart.c_str(), promAddressStart.length());



    }
  }

}

//Works in 8-bit increments.
//Can only take 2 hex values at a time
//Ex. 0xAA or 0x0 works but not 0x023
//Address must shift out 24 bits regardless of whether they are filled or not
void writeToProm(int value, int address, int promWrite, uint8_t DI, uint8_t CLK) {
  shiftOut(DI, CLK, MSBFIRST, promWrite); 
  for (int i = 2; i >= 0; i--) {
    shiftOut(DI, CLK, MSBFIRST, (address >> (i * 8)));
  }
  shiftOut(DI, CLK, MSBFIRST, value);
}
