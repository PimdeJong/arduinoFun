//   _stand = Stand ( _infrared, _backward, _fadeValue );
byte Stand ( int infrared , int backward, byte &fadeValue ) // , bool changed, int &previousStand
{
  byte stand;
  int minGebied = (( _infraredMax - _infraredMin) * 0.03 + _infraredMin );//
  int a =  (_infraredMin + (( _infraredMax - _infraredMin) * 0.20  )); //334
  int mid = (( _infraredMax - _infraredMin) * 0.25 + _infraredMin );//370//381
  int c = (( _infraredMax - _infraredMin) * 0.60 + _infraredMin );//711
  int maxgGebied = (( _infraredMax - _infraredMin) * 0.97 + _infraredMin );//

  Serial.println("a: " + String(a) + "| mid: " + String(mid) + "| c: " + String(c));
  if (_backward == 1)
  {
    if (infrared <= a )
    {
      stand = 1;
      //fadeValue = 2; //= map(infrared,  _infraredMin, a, 0, 255); /**/
    }
    else if (infrared <= mid )
    {
      stand = 2;
      //fadeValue = map(infrared, a, mid, 0, 255);
    }
    else //if (infrared <= d )
    {
      stand = 3;
      if (infrared >= mid && infrared <= _infraredMax)
      {
        fadeValue = map(infrared, mid, _infraredMax, 0, 255);
      }
      else
      {
        fadeValue = 255;
      }
    }

  }

  if (_backward == 0)
  {
    if (infrared >= c)
    {
      stand = 5;
      //fadeValue = map(infrared, _infraredMax, c, 0, 255);
    }
    else if (infrared > mid )
    {
      stand = 6;
      //fadeValue = map(infrared, c, mid, 0, 255);
    }
    else //if (infrared >= b )
    {
      stand = 7;
      if (infrared >= _infraredMin && infrared <= mid)
      {
        fadeValue = map(infrared, _infraredMin, mid, 0, 255);
      }
      else
      {
        fadeValue = 0;
      }
    }

  }
  _previousStand = stand;
  return stand;
}
