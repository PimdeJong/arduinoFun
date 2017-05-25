#include <Adafruit_NeoPixel.h>
#define ledPin 6                 /*ledjes*/

Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, ledPin, NEO_GRB + NEO_KHZ800); /* (total LED's,*/
byte ledPosities[3][2] = {
  {0, 5},
  {1, 4},
  {2, 3},
};                                /* niet zeker of ik dit zo moet doen, het is handig voor de grid van de accordeon maar voor de luchtkanalen is het een ander verhaal.*/


int _infrarood = 0;               //infrarood cable op 0

/*Dingen voor Herkenning dat er niets gebeurt*/
int _teller;
int _vorigeStatus;
bool _staatStil = false;


void setup()
{


}

void loop()
{

  AnalogRead (_infrared);

  _staatStil = Stagnatie (_teller, _infrarood, _vorigeStatus);    /*om te zorgen dat hij herkent dat alles stilstaat*/
}
