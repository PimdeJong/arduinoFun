void Airflow ()
{
  if ( _backward == true)
  switch ( _stand )
  {
    case 1:
      // {
      // 
      {
        for (int i = 0; i < 3; i++ ) { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][0], strip.Color(_fadeValue, 0, 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("case 1");
      }      break;
    case 2:
      // {
      {
        for (int i = 0; i < 4; i++ ) { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][1], strip.Color(0, _fadeValue , 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("case 2");
      }      break;
    case 3:
      // {
      {
        for (int i = 0; i < 5; i++ ) 
        { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][0], strip.Color(0, 0 , _fadeValue));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("case 3");
      }      break;
    case 4:
      // {
      {
        for (int i = 0; i < 6; i++ ) 
        { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][1], strip.Color(_fadeValue, _fadeValue , 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("case 4");
      }
            break;

    case 5:
      // {
      // if ( _backward == true)
      {
        for (int i = 0; i < 7; i++ )
        { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][0], strip.Color(0, _fadeValue , _fadeValue));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("case 5");
      }
      strip.show();
      // }
      break;
    default:
      {
        for (int i = 0; i < 3; i++ )
        { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][1], strip.Color(_fadeValue, _fadeValue, _fadeValue));
        }/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        Serial.print ("Default");
        strip.show();
      }
      break;
  }
  _previousStand = _stand;
  Serial.print ("Geen airflowding ");
  strip.show();

}
// variable om te zien of forward of backward is veranderd, deze koppelen aan milis opnieuw tellen
// of de waarde  van de led coppelen aan een map waarde van de range tussen twee standen.


