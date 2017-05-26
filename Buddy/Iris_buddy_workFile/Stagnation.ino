
//komt vanaf:  _stagnated = Stagnation (_teller, _infrared, _previousStatus);
bool Stagnation(int &teller, int infrared, int &previousStatus)
{
  bool stagnated;
  if (infrared == previousStatus )
  {
    teller ++;
  }
  if (teller >= 30)
  {
    stagnated = true;
  }
  previousStatus = infrared;
  return stagnated;
}
