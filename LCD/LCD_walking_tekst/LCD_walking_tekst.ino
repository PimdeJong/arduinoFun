/*
  The circuit'setup:
 * LCD RS pin to digital pin 12
 * LCD Enable pin to digital pin 11
 * LCD D4 pin to digital pin 5
 * LCD D5 pin to digital pin 4
 * LCD D6 pin to digital pin 3
 * LCD D7 pin to digital pin 2
 * LCD R/W pin to ground
 * LCD VSS pin to ground
 * LCD VCC pin to 5V
 * 10K resistor:
 * ends to +5V and ground
 * wiper to LCD VO pin (pin 3)

 I Iris Edelsmid and Bas ter Bogt wrote this code, after inspiration from this tutorial:
 http://www.arduino.cc/en/Tutorial/LiquidCrystal
 */
#include <LiquidCrystal.h>                                      /* include the library code:*/

    LiquidCrystal lcd(12, 11, 5, 4, 3, 2);                      /* initialize the library with the numbers of the interface pins*/
    int screenWidth = 16;                                       /* Because this value is used more than once we'll make it a variable. so you onlye have to change this value*/
    String line1 = (" Bas is cool! <3 ");                           /*This is the displayed tekst, lateron in the code we'll call it line1 or line2*/
    String line2 = ("Iris is normaal.");
    int startPosition = -line1.length();                        /* We want it to look like the tekst scrolls into the screen rather than start and disapear to the right*/
    int currentPosition = startPosition;

void setup() 
{
  // set up the LCD's number of columns and rows:
  lcd.begin(screenWidth, 2);
}

void loop() 
{
    lcd.clear();
    bas(currentPosition);
    currentPosition = (++currentPosition<=screenWidth ) ?  currentPosition : startPosition;
}


