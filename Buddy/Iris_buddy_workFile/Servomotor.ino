
void HiepHoiServo()
{
  byte servoStand = 0 ;
  _infraredArea = _infraredMax - _infraredMin;
  int infraredServo = _infrared;
  int infraredServoMin = _infraredMin;
  infraredServoMin = (infraredServoMin + (_infraredArea * 0, 01));
  int infraredServoMax = _infraredMax;
  infraredServoMax = infraredServoMax - (_infraredArea * 0, 02);

  if (infraredServo <= infraredServoMin)
  {
    infraredServo = infraredServoMin;
  }
  if (infraredServo >= infraredServoMax)
  {
    infraredServo = infraredServoMax;
  }

  servoStand = map(infraredServo, infraredServoMax,infraredServoMin, 0, 180); // scale it to use it with the servo (value between 0 and 180)

  Serial.println("servostand " + String(servoStand));
  Serial.println("ServoMin: " + String(infraredServoMin));
  Serial.println("ServoMax: " + String(infraredServoMax));
  hiepHoiServo.write(servoStand);                                         // sets the servo position according to the mapped value
  delay(1);
}

