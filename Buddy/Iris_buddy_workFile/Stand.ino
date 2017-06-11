// komt van: _stand = Stand (_infrared, _previousStand, _backward);
byte Stand ( int infrared, int &previousStand , bool &backward, byte &fadeValue, bool changed)
{
  byte stand;
  int minGebied = (( _infraredMax - _infraredMin) * 0.03 + _infraredMin );
  int a = (( _infraredMax - _infraredMin) * 0.20 + _infraredMin );
  int b = (( _infraredMax - _infraredMin) * 0.40 + _infraredMin );
  int c = (( _infraredMax - _infraredMin) * 0.60 + _infraredMin );
  int d = (( _infraredMax - _infraredMin) * 0.80 + _infraredMin );
  int maxgGebied = (( _infraredMax - _infraredMin) * 0.97 + _infraredMin );

  while (backward == false)
  {
    if (infrared <= a )
    {
      stand = 1;
      fadeValue = map(infrared,  _infraredMin, a, 0, 255); /**/
    }
    else if (infrared <= c )
    {
      stand = 2;
      fadeValue = map(infrared, b, c, 0, 255);
    }
    else if (infrared <= d )
    {
      stand = 3;
      fadeValue = map(infrared, c, d, 0, 255);
    }
    else //if (infrared > d)
    {
      stand = 4;
      fadeValue = map(infrared, d, _infraredMax, 0, 255);
    }
  }
  while (backward == true)
    if (infrared > d)
    {
      stand = 5;
      fadeValue = map(infrared, _infraredMax, d, 0, 255);
    }
    else if (infrared >= c )
    {
      stand = 6;
      fadeValue = map(infrared, d, c, 0, 255);
    }
    else if (infrared >= b )
    {
      stand = 7;
      fadeValue = map(infrared, c, b, 0, 255);
    }
    else if (infrared >= a )
    {
      stand = 8;
      fadeValue = map(infrared, c, b, 0, 255);
    }
  

  return stand;
}
}
