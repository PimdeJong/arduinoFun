
//komt vanaf: _staatStil = Stagnatie (_teller, _infrarood, _vorigeStatus);
bool Stagnatie(int &teller, int infrarood, int &vorigeStatus)
{
  bool staatStil;
  if (infrarood == vorigeStatus )
  {
    teller ++;
  }
  if (teller >= 30)
  {
    staatStil = true;
  }
  vorigeStatus = infrarood;
  return staatStil;
}
