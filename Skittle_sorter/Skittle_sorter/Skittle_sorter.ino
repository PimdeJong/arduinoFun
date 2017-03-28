/*Button
 * LED attached from pin 13 to ground
 * pushbutton attached to pin 2 from +5V
 * 10K resistor attached to pin 2 from ground
 */

const int buttonPin = 2;     
const int ledPin =  13;     
int buttonState = 0;         // variable for reading pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(buttonPin);

  // check if the pushbutton is pressed.
  // if it is, the buttonState is HIGH:
  if (buttonState == HIGH) {
    // LED on:
    digitalWrite(ledPin, HIGH);
  } else {
    // LED off:
    digitalWrite(ledPin, LOW);
  }
}
