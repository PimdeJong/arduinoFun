//komt vanaf:  _stagnated = Stagnation (_teller, _stand, _previousStand);
bool Stagnation(int &teller, int stand, int &previousStand)
{
  bool stagnated;
  if (stand = previousStand )
  {
    teller ++;
  }
  if (teller >= 30)
  {
    stagnated = true;
  }
  
  return stagnated;
}
