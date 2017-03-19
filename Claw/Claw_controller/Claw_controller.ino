/*class ClawClass
{
  public: int angle;
  public: int aantalKeerStilStaan;
  virtual bool StaatStil(){   }  
};*/

int _buttonState = 1 ;//
int _servoPosition;
int _grabCount;
int _teller;
int _vorigeStatus;
int _angle; //????

bool _grabdingStaatStil = false;
bool _claw = false;

//led setup:
int ledPin = 9;                            // LED connected to digital pin 9
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

  analogRead (_buttonState);
  _servoPosition = map(_buttonState, 0, 1023, 0, 180); //" map(value, fromLow, fromHigh, toLow, toHigh)

  Claw(_angle, _grabdingStaatStil, _claw,_grabCount);
  
  /*ClawClass *clawInstantie = new ClawClass();*/
  
  analogWrite (ledPin, LedLight()); /*Ledlight is een apparte methode () moeten wel altijd achter een methode staan, anders weet m computertje niet dat het om een methode gaat*/
  
  /*onderstaand is om te zorgen dat hij herkent dat de motor stilstaat*/
  if (_buttonState = _vorigeStatus )
  {
    _teller ++;
  }
  if (_teller >= 30)
  {
    _grabdingStaatStil = true;
  }
  _vorigeStatus = _buttonState;
}




