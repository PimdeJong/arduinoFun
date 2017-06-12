//komt vanaf:  _stagnated = Stagnation (_teller, _stand, _previousStand);
bool Stagnation(int teller, int stand, int previousStand)
{
  bool stagnated;
  if (stand == previousStand )
  {
    teller ++;
  }
  if (teller >= 100)
  {
    stagnated = true;
    teller = 0;
  }
  else
  {
  teller = 0;
  }
  return stagnated;
}
