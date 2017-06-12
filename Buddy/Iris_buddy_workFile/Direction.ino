//komt vanaf:
int Direction ( int backward, int stand, int infrared)
{
  if ((stand == 2) || (stand == 1) && backward == 1)
  {
    _previousPreviousRed = 0;
  }
  if (stand == 3 && backward == 1)
  {
    if (infrared + 1 < _previousRed )
    {
      if ((infrared + 15 < _previousRed ) || (infrared + 3 < _previousPreviousRed )) //(previousStand == 4 || 3 && stand == 5 || 6 )
      {
        backward = 0;
      }
      _previousPreviousRed = infrared;
    }

  }
  if ((stand == 5) || (stand == 6) && backward == 0)
  {
    _previousPreviousRed = 1200;
  }

  if (stand == 7 && backward == 0)
  {
    if (infrared - 1 > _previousRed )
    {
      if ((infrared - 20 > _previousRed) || ( infrared - 3 > _previousPreviousRed )) //(previousStand == 8 || 7 && stand == 1 || 2 )
      {
        backward = 1;
      }
      _previousPreviousRed = infrared;
    }

  }

  _previousRed = infrared;
  return backward;
}






//  if (previousStand = ! stand) //deze alleen nodig als ik dat wil koppelen aan het opnieuw tellen van milis
//  {
//    changed = true;
//  }
//  else
//  {
//    changed = false;          // ^ ""
//  }
