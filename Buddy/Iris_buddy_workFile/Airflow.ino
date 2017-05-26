switch (_stand,)
{ 
  1 && previousStand==2 || 1 && _backward = true
  {
    strip.setPixelColor(ledPositions[1][0], strip.Color(0, 0, j * j / 256));/* fellheid exponentiele toename (wordt opgevat als liniaire toename)*/
    delay 20;
    
  }
  break;


  previousStand = stand;
}

// nu nog een variable om te zien of forward of backward is veranderd, deze coppelen aan milis opnieuw tellen
// of de waarde  van de led coppelen aan een map waarde van de range tussen twee standen.


