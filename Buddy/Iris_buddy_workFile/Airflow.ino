void Airflow()
{
  switch ( _stand )
  {
    case 5:
     // {
       // if ( _backward = true)
        {
          for (int i = 0; i < 3; i++ ){ // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][1], strip.Color(0, 255, 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
          }
          delay (200);
          Serial.print ("case 1");
strip.show();
        }
     // }
      break;
    default:
    for (int i = 0; i < 3; i++ ){ // Variabel om een rij te printen
      strip.setPixelColor(ledPositions[i][1], strip.Color(0, 0, 255));
    }/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
      delay (200);
      Serial.print ("default");
      strip.show();
      break;
      _previousStand = _stand;
      Serial.print ("pimisleuk");
      strip.show();
  }
}
// variable om te zien of forward of backward is veranderd, deze koppelen aan milis opnieuw tellen
// of de waarde  van de led coppelen aan een map waarde van de range tussen twee standen.


