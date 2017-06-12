/*
 * MotorKnob
 *
 * A stepper motor follows the turns of a potentiometer
 * (or other sensor) on analog input 0.
 *
 * http://www.arduino.cc/en/Reference/Stepper
 * This example code is in the public domain.
 */

#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 1024

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to
Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;


void setup() {
  // set the speed of the motor to 30 RPMs
  stepper.setSpeed(10);
}

void loop() {
  // get the sensor value
  int _infrared = analogRead(0);
  int val;
  val = map(_infrared,0,1020,0,STEPS);

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val);

  // remember the previous value of the sensor
  previous = val;
}
