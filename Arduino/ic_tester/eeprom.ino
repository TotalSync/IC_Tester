/************************************

  Program File Serial Layout Example:

  8|S
  CKIO+E+-

  [Data in Hex]

  EOF
  ================

  (Number of Pins)|(Serial)   <= Pin Number and Type
  (Pin 1)(Pin 2)(Pin 3) etc.  <= Pin Declaration

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
      pins = new uint8_t[pinnum];// <------ HEAP ALLOCATION
      uint8_t pinnum = (uint8_t) dataFile
      

    }
  }

}
