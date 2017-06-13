
void HiepHoiServo()
{

  if (_backward == 1)
  {
    if (_infrared >= _infraredMin && _infrared <= _infraredMax)
    {
      servoStand = map(_infrared, _infraredMin, _infraredMax, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    }
    else
    {
      servoStand = map(_infrared, 0, 1023, 0, 180);                        // scale it(value between 0 and 1023) to use it with the servo (value between 0 and 180)
    }
  }
  else // if (_backward == 1)
  {
    if ((_infrared >= _infraredMin) && (_infrared <= _infraredMax))
    {
      servoStand = map(_infrared, _infraredMax, _infraredMin, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
    }
    else
    { 
      servoStand = map(_infrared, 1023, 0, 0, 180);                        //
    }


  }
  hiepHoiServo.write(servoStand);                                         // sets the servo position according to the mapped value
  delay(15);
}

