//komt vanaf:
void Calibrate()
{
  //  _infraredMin = 1023;
  //  _infraredMax = 0;
  //  int value;
  //  if callibrerende
  //
  //  unsigned long timestamp = millis();
  //  while (millis() - timestamp < 5000)
  //  {
  //    value = (analogRead(0) + analogRead(0) + analogRead(0) + analogRead(0)) / 4;
  //    _infraredMin = min(_infraredMin, value);
  //    _infraredMax = max(_infraredMax, value);
  //  }

  if (_callibrerende)
  {
    _infraredMin = min(_infrared, _infraredMin );
    _infraredMax = max(_infrared, _infraredMax );

    Rondjesteller();
    if (_rondjesteller >= 2) {

      _callibrerende = false;
      _rondjesteller = 0;
    }
  }
}

void Rondjesteller()
{
  if (_callibrerende)
  { Serial.println("test 1");
    if (_stand == 7 && _previousStand < _stand)

    { Serial.println("test 2");
      _rondjesteller ++;
    }
  }
  return _rondjesteller;
}

//void StartCalibratie ()
//{
//if (analogRead(6)
//
//  Calibrate()
//  }
