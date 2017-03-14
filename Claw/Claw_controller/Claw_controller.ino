int buttonState = 1 //
                  int servoPosition

                  //this is nothing yet, working on it. ;)
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
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  analogRead (buttonState)
  servoposition = map(buttonState, 0, 1023, 0, 180) //" map(value, fromLow, fromHigh, toLow, toHigh)
}
