/*Het had ook zo gekund:
 * bool Claw()
{
  if (_angle <= 30 && _grabdingStaatStil)
  {
    if (_claw == false)
    {
      _claw = true;
      _grabCount ++;
    }
  } else
  {
    _claw = false;
  }
}*/
bool Claw (int angle, bool grabdingStaatStil, bool claw, int &grabCount)
{
  if (angle <= 30 && grabdingStaatStil)
  {
    if (claw == false)
    {
      claw = true;
      grabCount ++;
    }
  } else
  {
    claw = false;
  }
  return claw;
}

