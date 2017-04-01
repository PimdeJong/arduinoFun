#include <Servo.h>

Servo servo;

// consisent
const int buttonPin = 2;                      //
const int trigPin = 6;                        //
const int echoPin = 7;                        //
const int servoPin = 13;                      //

// Variable
int buttonPushCounter = 0;                  // counter for the number of button presses
int buttonState = 0;                        // current state of the button
int lastButtonState = 0;                    // previous state of the button
int pos = 0;                                //
int cm;                                     //
int duration;                               //


void setup () {
  pinMode(buttonPin, INPUT);
  pinMode(servoPin, OUTPUT);
  servo.attach(9);
  Serial.begin(9600);
}

void loop() {
  long duration, cm;
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  cm = microsecondsToCentimeters(duration);
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();

  buttonState = digitalRead(buttonPin);
  if (buttonState != lastButtonState)
  {
    if (buttonState == HIGH)
    {
      buttonPushCounter++;                            // (Dit is hetzelfde als buttonPushCounter = buttonPushCounter +1;)
    }                                                 // else bottonstate == LOW
    
    delay(50);
  }                                                   // else buttonstate niet gelijk aan vorige

  /* servo */
  if (cm <= 10) {
    SweepForward(3);
  }
  else if (cm >= 24) {
    servo.write(pos);
  }
  delay(100);
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

/*voidsweep moet nog aangeroepen worden*/
void SweepForward(int NUM_OF_CYCLES) {
  for (int j = 1; j < NUM_OF_CYCLES; j++)
    for (pos = 0; pos = 170; pos += 1)
    {
      servo.write(pos);
      delay(100);
    } 
}

lastButtonState = buttonState;
 if (buttonPushCounter % 2 == 0) // moet misschien een keer drukken zijn
  { 
    digitalWrite(servoPin, HIGH);
  } else {
    digitalWrite(servoPin, LOW);
 }

