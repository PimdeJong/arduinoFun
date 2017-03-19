int buttonState = 1 ;//
int servoPosition;
int grabCount;
int teller;
int vorigeStatus;
int angle;

bool grabdingStaatStil = false;
bool claw = false;

//led setup:
int ledPin = 9;
bool blinkState = false;
unsigned long time;
unsigned long time2 = 0 ;

/*
  Een grijper die open of dicht gaat naar aanleiding van de waarde die middels een draaiknop wordt gegeven (en middels MAP functie omgevormd tot een bruikbare waarde)
  Als een object gegrepen is,
  dan luidt er een buzzer.
  En
  Het ledje gaat knipperen
  Als hoe kleiner de hoek is van de grijper, hoe feller het ledje gaat branden

  Op de LCD wordt weergeven:
  de hoek van de motor(dus de grijper) = Vraagt de waarde op van de huidige grijperwaarde
  Hoe vaak een object is gepakt = Telt
  En geeft weer indien een object wordt vastgehouden.*/

void setup() {

}

void loop() {

  analogRead (buttonState);
  servoPosition = map(buttonState, 0, 1023, 0, 180); //" map(value, fromLow, fromHigh, toLow, toHigh)

  if (angle <= 30 && grabdingStaatStil)
  {
    if (claw == false)
    {
      claw = true;
      grabCount ++;
    }
  } else
  {
    claw = false;
  }
  analogWrite (ledPin, ledlight); /*ledlight is een apparte methode*/

  
  /*onderstaand is om te zorgen dat hij herkent dat de motor stilstaat*/
  
  if (buttonState = vorigeStatus )
  {
    teller ++;
  }
  if (teller >= 30)
  {
    grabdingStaatStil = true;
  }
  vorigeStatus = buttonState;
}
