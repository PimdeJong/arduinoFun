#include <Adafruit_NeoPixel.h>
#define ledPin 6                 /*ledjes*/

Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, ledPin, NEO_GRB + NEO_KHZ800); /* (total LED's,*/
byte ledPositions[3][2] = {
  {0, 5},
  {1, 4},
  {2, 3},
};                                /* niet zeker of ik dit zo moet doen, het is handig voor de grid van de accordeon maar voor de luchtkanalen is het een ander verhaal.*/


int _infrared = 0;               //infrarood cable op 0

/*Dingen voor Herkenning dat er niets gebeurt*/
int _teller;
int _previousStand;
bool _stagnated = false;


void setup()
{


}

void loop()
{
  analogRead (_infrared);//0-1023
  _stand = Stand ( _infrared, _previousStand, _continue);
  _stagnated = Stagnation (_teller, _infrared, _previousStand);    /*om te zorgen dat hij herkent dat alles stilstaat*/
}
