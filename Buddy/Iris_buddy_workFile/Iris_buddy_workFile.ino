#include <Adafruit_NeoPixel.h>
#define ledPin 6                 /*ledjes*/
//#define _infrared (0)             //infrared cable 0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, ledPin, NEO_GRB + NEO_KHZ800); /* (total LED's,*/
byte ledPositions[3][2] = {
  {0, 5},
  {1, 4},
  {2, 3},
};


           

/*Dingen voor Herkenning dat er niets gebeurt*/
byte _teller;
int _previousStand;
bool _stagnated = false;
bool _backward;

byte _stand;
bool _changed;
byte _fadeValue;

void setup()
{
  Serial.begin(115200);
  strip.begin();
    strip.show(); // Initialize all pixels to 'off'
 // strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
  Serial.println(analogRead(0)); //0-1023
  int _infrared = analogRead(0);//
  //Serial.println( analogRead _infrared);
  //analogRead (_infrared);//0-1023  Serial.println(analogRead(0));
  _stand = Stand ( _infrared, _previousStand, _backward, _fadeValue, _changed);
  _stagnated = Stagnation (_teller, _infrared, _previousStand);    /*om te zorgen dat hij herkent dat alles stilstaat*/
  Airflow();
}
