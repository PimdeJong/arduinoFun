bool ClawStagnation(int &teller, int buttonState, int &vorigeStatus, bool grabdingStaatStil)
{
  if (buttonState = vorigeStatus )
  {
    teller ++;
  }
  if (teller >= 30)
  {
    grabdingStaatStil = true;
  }
  vorigeStatus = buttonState;
  return grabdingStaatStil;
}
