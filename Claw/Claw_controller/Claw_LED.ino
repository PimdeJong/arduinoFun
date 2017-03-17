void LED(int fadeValue)
{
int ledPin = 9;                              // LED connected to digital pin 9
int blinkValue = 500;

  if ( claw == true)                        /* Case 1 The claw has grabbed*/
  {
    if (time >= (time2 + blinkValue) && blinkState == true)
    {
      time2 = time;
      analogWrite (ledPin, fadeValue);
      blinkState = false;
    }
    else if (time >= (time2 + blinkValue) && blinkState == false)
    {
      time2 = time;
      blinkState = 0;
      analogWrite (ledPin, fadeValue);
      blinkState = true;
    }
  } else                                    /* Case 2, The claw is moving or has not started yet*/
  {
    fadeValue = map(angle, 0, 180, 0, 255);     //
    analogWrite(ledPin, LED);
  }
  time = millis;
}

