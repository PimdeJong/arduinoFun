void Airflow ()
{
  for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][0], strip.Color(0, 255, 0));
  for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][9], strip.Color(0, 0, 255));

  //  for (int i = 0; i < 6; i++) strip.setPixelColor(channelFreedom[i], strip.Color(255, 0, 0));/* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
  for (int i = 0; i < 3; i++) strip.setPixelColor(channelBlue[i], strip.Color(0, 0, 255));
  for (int i = 0; i < 3; i++) strip.setPixelColor(channelGreen[i], strip.Color(0, 255, 0));
  switch ( _stand )
  {
    case 1: /*(Blauw =vol, uitgang = groen*/
      {
        BlueChamberIsFull();
        for (int i = 0; i < 6; i++) strip.setPixelColor(channelFreedom[i], strip.Color(0, 255, 0));
        /* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
      }      break;

    case 2:/* stop leeglopen groene kanaal*/
      {
        BlueChamberIsFull();
        for (int i = 0; i < 6; i++) strip.setPixelColor(channelFreedom[i], strip.Color(0, 0, 0));

      }
      break;

    case 3: /* start lopen kanaal ingroen, groene kamer vullen*/

      {
        GreenChamberFilling();        
        for (int i = 0; i < 6; i++) strip.setPixelColor(channelFreedom[i], strip.Color(0, 0, 255));
      //  for (int i = 0; i < 6; i++) strip.setPixelColor(channelFreedom[i], strip.Color(0, 0, 255));
      }      break;
      

    case 5:
      {
        GreenChamberIsFull();
        for (int i = 0; i < 6; i++) strip.setPixelColor(channelFreedom[i], strip.Color(0, 0, 255));
      }
      break;
    case 6:
      {
        GreenChamberIsFull();
      }

      break;
    case 7:/* */
      {
        BlueChamberFilling();
        for (int i = 0; i < 6; i++) strip.setPixelColor(channelFreedom[i], strip.Color(0, 255, 0));
      }
break;
    default: /* */
      {
        //for (int i = 0; i < 3; i++ )
        // Variabel om een rij te printen

        /* (0, 0, j * j / 256)fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
        Serial.print (" Default ");

      }
      break;

      Serial.print ("Geen airflowding ");


  } strip.show();
}

void BlueChamberIsFull()
{
  for (int j = 0; j < 8; j++) for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][1 + j], strip.Color( 0, 0, 255));
}
void BlueChamberFilling()
{
  int calc = map(_fadeValue, 255, 0, 8 * 256 - 1,0);
  for (int j = 0; j < 8; j++) for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][1 + j], strip.Color(0, constrain(calc - 256 * j, 0, 255), 255 - constrain(calc - 256 * j, 0, 255)));
}

void GreenChamberFilling()
{
  int calc = map(_fadeValue, 255, 0, 8 * 256 - 1,0);
  for (int j = 0; j < 8; j++) for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][1 + j], strip.Color(0, constrain(calc - 256 * j, 0, 255), 255 - constrain(calc - 256 * j, 0, 255)));
}

void GreenChamberIsFull()
{
  for (int j = 0; j < 8; j++) for (int i = 0; i < 7; i++) strip.setPixelColor(ledPositions[i][1 + j], strip.Color( 0, 255, 0));
}
// variable om te zien of forward of backward is veranderd, deze koppelen aan milis opnieuw tellen
// of de waarde  van de led coppelen aan een map waarde van de range tussen twee standen.



