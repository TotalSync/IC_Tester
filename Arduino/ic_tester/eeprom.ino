/************************************

  Program File Serial SPI Layout Example:

  8|SPI
  CKIO+E+-
  0x01|400ns|100ns
  %[Data in Hex]

  EOF
  ================

  (Number of Pins)|(Serial)   <= Pin Number and Type
  (Pin 1)(Pin 2)(Pin 3) etc.  <= Pin Declaration

  [Hex Number for write instruction (0-F)]
  [Programming High Time]|[Programming Low time]

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
      byte promWrite[2];
      if(buf[0] == "0" && buf[1] == "x") {
        if(isHexadecimalDigit(buf[2]) && isHexadecimalDigit(buf[3])) {
          promWrite[0] = (byte)buf[2];
          promWrite[1] = (byte)buf[3];
        }
      }
      
      

    }
  }

}
