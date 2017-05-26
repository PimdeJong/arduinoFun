// komt van: _stand = Stand (_infrared, _previousStand, _backward);
int Stand( int infrared, int &previousStand , int &backward )
{
  byte stand;
  if (infrared = < 40)
  {
    stand = 1;
  }
  if (infrared = < 200)
  {
    stand = 2;
  }
  if (infrared = < 500)
  {
    stand = 3;
  }
  if (infrared = < 700)
  {
    stand = 4;
  }
  if (infrared = < 1000)
  {
    stand = 5;
  }
  else
  {
    stand = 0;
  }
  if (stand > previousStand)
  { backward = true;
  }
  else
  {
    backward = false;
  }
  previousStand = stand;
  return stand;
}

