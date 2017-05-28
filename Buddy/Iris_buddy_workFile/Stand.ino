// komt van: _stand = Stand (_infrared, _previousStand, _backward);
byte Stand ( int infrared, int &previousStand , bool &backward, byte &fadeValue, bool changed)
{
  byte stand;
  if (infrared < 40)
  {
    stand = 1;
    fadeValue = map(infrared, 0, 20, 0, 255); /**/
  }
  else if (infrared < 200)
  {
    stand = 2;
    fadeValue = map(infrared, 20, 80, 0, 255);
  }
  else if (infrared < 500)
  {
    stand = 3;
    fadeValue = map(infrared, 80, 200, 0, 255);
  }
  else if (infrared < 700)
  {
    stand = 4;
    fadeValue = map(infrared, 200, 500, 0, 255);
  }
  else if (infrared < 800)
  {
    stand = 5;
    fadeValue = map(infrared, 500, 1020, 0, 255);
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

