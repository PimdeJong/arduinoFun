void LED(int offset)
{
int ledPin = 9;                              // LED connected to digital pin 9
int fadevalue;


  if ( claw == true);
  {
    LED = 255 // need to blink lights
  }
  else ;
  {
    LED = map(degrees, 0, 180, 0, 255);     //
    analogWrite(ledPin, LED);
  }
  
  time = millis;
}

