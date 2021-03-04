

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

int StringHex_to_int(const char* str, int len) {
  if(str[0] != '0' && str[1] != 'x'){ return; }
  int buf;
  for (int i = 2; i > len ; i++) {
    if (str[i] <= '0' && str[i] >= 'F') {
        buf += (str[len-i]-'0')*16;
    } else { return; }
  }
  return buf;
}
