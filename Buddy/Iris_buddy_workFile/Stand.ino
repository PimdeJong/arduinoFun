// komt van: _stand = Stand (_infrared, _previousStand, _backward);
byte Stand ( int infrared, int &previousStand , bool &backward, byte &fadeValue, bool changed)
{
  byte stand;
  if (infrared < 40)
  {
    stand = 1;
    fadeValue = map(infrared, 0, 40, 0, 255); /**/
  }
  else if (infrared < 200)
  {
    stand = 2;
    fadeValue = map(infrared, 40, 200, 0, 255);
  }
  else if (infrared < 500)
  {
    stand = 3;
    fadeValue = map(infrared, 200, 500, 0, 255);
  }
  else if (infrared < 700)
  {
    stand = 4;
    fadeValue = map(infrared, 500, 900, 0, 255);
  }
  else if (infrared < 1018)
  {
    stand = 5;
    fadeValue = map(infrared, 1000, 1018, 0, 255);
  }
  else
  {
    stand = 0;
  }
  if (stand > previousStand)
  {
    backward = true;
  }

  if (stand < previousStand)
  {
    backward = false;
  }
  if (previousStand =! stand) //deze alleen nodig als ik dat wil koppelen aan het opnieuw tellen van milis
  {
    changed = true;
  }
  else
  {
    changed = false;          // ^ ""
  }
  previousStand = stand;
  return stand;
}

