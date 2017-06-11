#include <Adafruit_NeoPixel.h>
#define ledPin 6                 /*ledjes*/
//#define _infrared (0)             //infrared cable 0

Adafruit_NeoPixel strip = Adafruit_NeoPixel(80, ledPin, NEO_GRB + NEO_KHZ800); /* (total LED's,*/
byte ledPositions[7][10] = {
  { 0, 12, 13, 26, 27, 40, 41, 54, 55, 67},
  { 1, 11, 14, 25, 28, 39, 42, 53, 56, 66},
  { 2, 10, 15, 24, 29, 38, 43, 52, 57, 65},
  { 3,  9, 16, 23, 30, 37, 44, 51, 58, 64},
  { 4,  8, 17, 22, 31, 36, 45, 50, 59, 63},
  { 5,  7, 18, 21, 32, 35, 46, 49, 60, 62},
  { 255, 6, 19, 20, 33, 34, 47, 48, 61, 255} ,
};
byte channelFreedom[6] =
{ 76, 75, 74, 70, 69, 68};
byte channelBlue[3] =
{ 73, 72, 71};
byte channelGreen[3] =
{ 77, 78, 79};

/*Dingen voor Herkenning dat er niets gebeurt*/
byte _teller;
int _previousStand = 0 ;
bool _stagnated = false;

bool _backward;

byte _stand;
bool _changed;
byte _fadeValue;

int _infrared = 0;
int _infraredMin = 100;
int _infraredMax = 450;


void setup()
{
  Serial.begin(115200);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  // strip.show(); // Initialize all pixels to 'off'
}

void loop()
{
 _stand = Stand ( _infrared, _previousStand, _backward, _fadeValue, _changed);
 _backward = Direction ( _stand, _previousStand, _changed );
  //_stagnated = Stagnation (_teller, _infrared, _previousStand);    /*om te zorgen dat hij herkent dat alles stilstaat*/
  //Airflow();

  for (int i = 0; i < 8; i++) _infrared += analogRead(0);
  _infrared /= 8;
  Serial.println(_infrared);
  ValueToLedScale(map(_infrared, _infraredMin, _infraredMax, 0, 1023));
}

void ValueToLedScale(int value) {
  int calc = map(value, 0, 1023, 0, 8 * 256 - 1);

  for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][0], strip.Color(0, 255, 0));
  for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][9], strip.Color(0, 0, 255));

  for (int j = 0; j < 8; j++) for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][1 + j], strip.Color(0, constrain(calc - 256 * j, 0, 255), 255 - constrain(calc - 256 * j, 0, 255)));
  for (int i = 0; i < 6; i++) strip.setPixelColor(channelFreedom[i], strip.Color(255, 0, 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
  for (int i = 0; i < 3; i++) strip.setPixelColor(channelBlue[i], strip.Color(0, 0, 255));
  for (int i = 0; i < 3; i++) strip.setPixelColor(channelGreen[i], strip.Color(0, 255, 0));

  strip.show();
}

