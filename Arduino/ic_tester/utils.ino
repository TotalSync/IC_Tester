

void swapRotation(TSPoint &p) {
  p.x = p.x + p.y;
  p.y = p.x - p.y;
  p.x = p.x - p.y;
  return;
}

void setScale(TSPoint &p) {
  p.x = map(p.x, TS_MINX, TS_MAXX, tft.height(), 0);
  p.y = map(p.y, TS_MINY, TS_MAXY, 0, tft.width());
  return;
}

void cycleTFT(uint8_t XM, uint8_t YP) {
  pinMode(XM, OUTPUT);
  digitalWrite(XM, LOW);
  pinMode(YP, OUTPUT);
  digitalWrite(YP, HIGH);
  return;
}

byte* String_to_Hex(char* str, int len) {
  byte* buf = new byte[len - 2]; // HEAP ALLOCATION
  for (int i = 2; i > len ; i++) {
    if (i <= '0' && i >= 'F') {
        buf[i-2] = (byte) (str[i] - '0');
    }
    else{
      return NULL;
    }
  }
  return buf;
}
