#include <Adafruit_NeoPixel.h>
#define PIN 6

Adafruit_NeoPixel strip = Adafruit_NeoPixel(6, PIN, NEO_GRB + NEO_KHZ800);

// IMPORTANT: To reduce NeoPixel burnout risk, add 1000 uF capacitor across
// pixel power leads, add 300 - 500 Ohm resistor on first pixel's data input
// and minimize distance between Arduino and first pixel.  Avoid connecting
// on a live circuit...if you must, connect GND first.

// float is een commagetal, ndig als je getallen achter de comma
// byte is 0 tot 255
// int -32000 tot 32000 ofzo
// unsigned int 0 65000 ofzo, voro  als je niet in negatief hoeft of hoger
// long -2miljard/joen tot ''plus
// long long nog groter

byte ledPositions[3][2] = {
  {0, 5},
  {1, 4},
  {2, 3},
};

void setup() {
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
}



void loop() {
  //    for (int i = 0; i < strip.numPixels(); i++) {
  //      strip.setPixelColor(i, strip.Color(i*32, 0, 0));
  //    }
  //    strip.show();
  //    delay(1000);

  /* Hoe fade ik rijen ledstrips van links naar rechts?
      - Array (spreadsheet) maken waar info instaat welke stap wat betekent
      - variabele maken voor een waarde van 'vulling', if schuivende beweging dan ledjesfade exponentieel
      -

  */

  for (int j = 0; j < 256; j++) {
    for (int i = 0; i < 3; i++) {
      strip.setPixelColor(ledPositions[i][0], strip.Color(0, j, 0)); /*fellheid liniaire toename*/
    }

    for (int i = 0; i < 3; i++) {
      strip.setPixelColor(ledPositions[i][1], strip.Color(0, 0, j * j / 256));/* fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
    }
    strip.show();
    delay(10);
  }

  //  strip.setPixelColor(ledPositions[0][0], strip.Color(0, 255, 255));
  //  strip.setPixelColor(ledPositions[1][0], strip.Color(255, 0, 255));
  //  strip.setPixelColor(ledPositions[2][0], strip.Color(255, 255, 0));
  //  strip.setPixelColor(ledPositions[0][1], strip.Color(255, 0, 0));
  //  strip.setPixelColor(ledPositions[1][1], strip.Color(0, 0, 255));
  //  strip.setPixelColor(ledPositions[2][1], strip.Color(0, 255, 0));


}







// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}



void rainbow(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256; j++) {
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel((i + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle(uint8_t wait) {
  uint16_t i, j;

  for (j = 0; j < 256 * 5; j++) { // 5 cycles of all colors on wheel
    for (i = 0; i < strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    delay(wait);
  }
}

//Theatre-style crawling lights.
void theaterChase(uint32_t c, uint8_t wait) {
  for (int j = 0; j < 10; j++) { //do 10 cycles of chasing
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, c);  //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

//Theatre-style crawling lights with rainbow effect
void theaterChaseRainbow(uint8_t wait) {
  for (int j = 0; j < 256; j++) {   // cycle all 256 colors in the wheel
    for (int q = 0; q < 3; q++) {
      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, Wheel( (i + j) % 255)); //turn every third pixel on
      }
      strip.show();

      delay(wait);

      for (uint16_t i = 0; i < strip.numPixels(); i = i + 3) {
        strip.setPixelColor(i + q, 0);      //turn every third pixel off
      }
    }
  }
}

// Input a value 0 to 255 to get a color value.
// The colours are a transition r - g - b - back to r.
uint32_t Wheel(byte WheelPos) {
  WheelPos = 255 - WheelPos;
  if (WheelPos < 85) {
    return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  }
  if (WheelPos < 170) {
    WheelPos -= 85;
    return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
  WheelPos -= 170;
  return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
}
