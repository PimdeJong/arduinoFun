//komt vanaf:
bool Direction ( int stand , int previousStand, int changed )
{
  int backward;
  if (previousStand == 4 || 3 && stand == 5 || 6 )
  {
    backward = true;
  }
  if (previousStand == 8 || 7 && stand == 1 || 2 )
  {
    backward = false;
  }

  if (previousStand = ! stand) //deze alleen nodig als ik dat wil koppelen aan het opnieuw tellen van milis
  {
    changed = true;
  }
  else
  {
    changed = false;          // ^ ""
  }
  previousStand = stand;
  return backward;
}
