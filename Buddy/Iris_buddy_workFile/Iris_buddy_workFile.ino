#include <Adafruit_NeoPixel.h>
#define ledPin 6                 /*ledjes*/
//#define _infrared (0)             //infrared cable 0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(27, ledPin, NEO_GRB + NEO_KHZ800); /* (total LED's,*/
byte ledPositions[7][4] = {
  { 0, 12, 13, 26},
  { 1, 11, 14, 25},
  { 2, 10, 15, 24},
  { 3, 9, 16, 23},
  { 4, 8, 17, 22},
  { 5, 7, 18, 21},
  { 27, 6, 19, 20} ,
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
