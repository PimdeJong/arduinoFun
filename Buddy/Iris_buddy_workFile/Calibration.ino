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
    int value;
    _infraredMin = min(_infrared,_infraredMin );
    _infraredMax = max(_infrared, _infraredMax );

    Rondjesteller(_rondjesteller);

    if (_rondjesteller > 2) {

      _callibrerende = false;
      _rondjesteller = 0;
    }
  }

}

byte Rondjesteller(int rondjesteller)
{
  if (_callibrerende)
  {
    if (_stand == 8 && _previousStand == 7)

    {
      rondjesteller ++;
    }
  }
  return rondjesteller;
}

//void StartCalibratie ()
//{
//if (analogRead(6) 
//
//  Calibrate()
//  }
