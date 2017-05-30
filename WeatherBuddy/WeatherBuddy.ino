// Code Bas, 

int pinSwitch = 12;  //Pin Reed
int regenSensor = A1; // Regensensor aan analoge ingang 1, als regensor dan gaat led 9 (rood) branden
int LED = 9; // LED aan pen 9 gaat aan als het sneeuwt of refent
int reedLed = 10; // LED a
int val = 0;  // = dus de regensensorwaarde
int StatoSwitch = 0;


void setup()
{
  Serial.begin(115200);//Serial.begin(9600);
  pinMode(reedLed, OUTPUT);
  pinMode(pinSwitch, INPUT);
  pinMode(LED, OUTPUT);


}
void loop() {
  Serial.print("hoi");
  val = analogRead(regenSensor);
  if (val > 700) {
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(LED, HIGH);
  }
  Serial.print("Neerslaghoeveelheid: " );
  Serial.print(val);
  delay(400);

  
  StatoSwitch = digitalRead(pinSwitch);
  if (StatoSwitch == HIGH)
  {
    Serial.println(" Magnet near Reed Switch detected! ");
    digitalWrite(reedLed, HIGH);
  }
  else
  {
    Serial.println(" No Magnet Detected ");
    digitalWrite(reedLed, LOW);
  }

}

