#include <Adafruit_NeoPixel.h>
#define ledPin 6                 /*ledjes*/

//#define _infrared (0)             //infrared cable 0
#define knopPin 5

/*Servo*/
#include <Servo.h>
Servo hiepHoiServo;  // create servo object to control a servo

/*Ledjes*/
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

/*Calibratie*/
byte _teller;
int _previousRed = 0 ;
int _previousPreviousRed = 0;
bool _stagnated = false;
bool _callibrerende;
byte _rondjesteller;

/*Direcion*/
int _backward = 1;

/*Stand*/
byte _stand = 0 ;
bool _changed;
byte _fadeValue;
byte _previousStand;

/*Infrared sensor*/
int _infrared = 0;
int _infraredMin = 105;
int _infraredMax = 940;
int _infraredArea;
int _teller2;


void setup()
{
  Serial.begin(115200);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  // strip.show(); // Initialize all pixels to 'off'
    hiepHoiServo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{

  for (int i = 0; i < 8; i++) _infrared += analogRead(0);
  _infrared /= 8;
  
  if (digitalRead(knopPin) == HIGH) {    _callibrerende = true;  }
  Calibrate();
  
  Serial.println("ding: " + String(digitalRead(knopPin)));
  Serial.println("minimum: " + String(_infraredMin));
  Serial.println("Maximum: " + String(_infraredMax));
    Serial.println("_callibrerende: " + String(_callibrerende));
      Serial.println("rondjesteller: " + String(_rondjesteller));
  
  //_infrared = analogRead(0);
  Serial.println("Infrarood waarde: " + String(_infrared));

  _stand = Stand ( _infrared, _backward, _fadeValue ); //_previousStand, _changed
  Serial.println("Huidige stand: " + String(_stand));
    Serial.println("previousstand: " + String(_previousStand));

  _backward = Direction ( _backward, _stand, _infrared);
  Serial.println("Backwards: " + String(_backward));
  Serial.println("fadeValue: " + String(_fadeValue));
  //_stagnated = Stagnation (_teller, _infrared, _previousStand);    /*om te zorgen dat hij herkent dat alles stilstaat*/
  Airflow();

  Serial.println("peviouspreviousred" + String (_previousPreviousRed));
  Serial.println("");
HiepHoiServo();







  delay (150);
}


// ValueToLedScale(map(_infrared, _infraredMin, _infraredMax, 0, 1023));

//void ValueToLedScale(int value) {
//  int calc = map(value, 0, 1023, 0, 8 * 256 - 1);
//
//  for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][0], strip.Color(0, 255, 0));
//  for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][9], strip.Color(0, 0, 255));
//
//  for (int j = 0; j < 8; j++) for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][1 + j], strip.Color(0, constrain(calc - 256 * j, 0, 255), 255 - constrain(calc - 256 * j, 0, 255)));
//  for (int i = 0; i < 6; i++) strip.setPixelColor(channelFreedom[i], strip.Color(255, 0, 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
//  for (int i = 0; i < 3; i++) strip.setPixelColor(channelBlue[i], strip.Color(0, 0, 255));
//  for (int i = 0; i < 3; i++) strip.setPixelColor(channelGreen[i], strip.Color(0, 255, 0));
//
//  strip.show();
//}

