/*Het had ook zo gekund:
 * bool Claw()
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

