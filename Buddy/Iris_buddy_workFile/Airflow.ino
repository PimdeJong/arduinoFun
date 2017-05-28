void Airflow ()
{
  switch ( _stand )
  {
    case 1:
      // {
      // if ( _backward = true)
      {
        for (int i = 0; i < 3; i++ ) { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][0], strip.Color(_fadeValue, 0, 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("Ik ga je in mijn serial monitor plotter antwoorden");
      }      break;
    case 2:
      // {
      // if ( _backward = true)
      {
        for (int i = 0; i < 3; i++ ) { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][1], strip.Color(0, _fadeValue , 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("Het is voor yolo dat ik heel slim voor school weet te gebruiken");
      }      break;
    case 3:
      // {
      // if ( _backward = true)
      {
        for (int i = 0; i < 3; i++ ) 
        { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][0], strip.Color(0, 0 , _fadeValue));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("zonnepanelen op je tuinslang");
      }      break;
    case 4:
      // {
      // if ( _backward = true)
      {
        for (int i = 0; i < 3; i++ ) 
        { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][1], strip.Color(_fadeValue, _fadeValue , 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("Facking briljant idee");
      }
            break;

    case 5:
      // {
      // if ( _backward = true)
      {
        for (int i = 0; i < 3; i++ )
        { // Variabel om een rij te printen
          strip.setPixelColor(ledPositions[i][0], strip.Color(0, _fadeValue , _fadeValue));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        }
        Serial.print ("vooral omdat het hilarisch is");
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
        Serial.print ("hahahha");
        strip.show();
      }
      break;
  }
  _previousStand = _stand;
  Serial.print ("want verder is het echt zwaar ineffectief :p ");
  strip.show();

}
// variable om te zien of forward of backward is veranderd, deze koppelen aan milis opnieuw tellen
// of de waarde  van de led coppelen aan een map waarde van de range tussen twee standen.


