#include <Adafruit_NeoPixel.h>
#define PIN 6


Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

byte ledPositions[3][2] = {
  {0, 5},
  {1, 4},
  {2, 3},
};

void setup() {
  Serial.begin(115200);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}

void loop() {

  Serial.println(analogRead(0)); //0-1023
  int j = analogRead(0) / 4;

  for (int i = 0; i < 3; i++) {
    strip.setPixelColor(ledPositions[i][0], strip.Color(0, j, 0)); /*fellheid liniaire toename*/
  }

  for (int i = 0; i < 3; i++) {
    strip.setPixelColor(ledPositions[i][1], strip.Color(0, 0, j * j / 256));/* fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
  }
  strip.show();
  delay(10);

}

