int LedLight()
{
  // LED connected to digital pin 9
  int blinkValue = 500;         // hoe lang het knipperen duurt
  int ledLight = 0;

  if ( claw == true)                        /* Case 1 The claw has grabbed*/
  {
    if (time >= (time2 + blinkValue))
    {
      time2 = time;

      if (blinkState == true)
      {
        blinkState = false;
        ledLight = 255;
      }
      else                                  // gezien een bool maar 2 waarden kan hebben hoeft dit dus geen else if te zijn maar gewoon een else waarbij je de 2e voorwaarde dus dan niet hoeft neer te zeggen
      {
        blinkState = true;
        ledLight = 0;
      }

    }
    else                                    // (eerst had ik deze else niet) deze else heb ik nodig omdat, wat gebeurt er als hij niet voldoet aan voorwaarde ''(time >= (time2 + blinkValue) maar wel aan claw = true?, dan is het lampje uit, dus dan zie je nooit dat hij aan uiaan uit knippert.
    {
      if (blinkState == false)
      {
        ledLight = 255;
      }
      else
      {
        ledLight = 0;
      }
    }
  }
}
else                                    /* Case 2, The claw is moving or has not started yet*/
{
  ledLight = map(angle, 0, 180, 0, 255);     //
}
time = millis;

return ledLight;
}

