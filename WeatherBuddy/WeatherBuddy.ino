const int pinSwitch = 12;  //Pin Reed
const int pinLed    = 10;  //Pin LED
int REGENSENSOR = A1; // Regensensor aan analoge ingang 1
int LED = 9; // LED aan pen 8 gaat aan als het sneeuwt of refent

int val = 0;
int data = 0;


int StatoSwitch = 0;

void setup()
{
  Serial.begin(9600);
  pinMode(pinLed, OUTPUT);
  pinMode(pinSwitch, INPUT);
  pinMode(LED, OUTPUT);


}
void loop() {
  val = analogRead(REGENSENSOR);
  if (val > 700) {
    digitalWrite(LED, LOW);
  }
  else {
    digitalWrite(LED, HIGH);
  }
  data = val;
  Serial.print("Neerslaghoeveelheid: " );
  Serial.print(data);
  delay(400);



  StatoSwitch = digitalRead(pinSwitch);
  if (StatoSwitch == HIGH)
  {
    Serial.println("Magnet near Reed Switch detected!");
    digitalWrite(pinLed, HIGH);
  }
  else
  {
    Serial.println("No Magnet Detected");
    digitalWrite(pinLed, LOW);
  }

}

