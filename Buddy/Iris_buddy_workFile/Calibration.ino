void calibrate() {
  _infraredMin = 1023;
  _infraredMax = 0;
  int value;
  unsigned long timestamp = millis();
  while (millis() - timestamp < 5000) {
    value = (analogRead(0) + analogRead(0) + analogRead(0) + analogRead(0)) / 4;
    _infraredMin = min(_infraredMin, value);
    _infraredMax = max(_infraredMax, value);
  }
}

