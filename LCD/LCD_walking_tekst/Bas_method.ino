void bas(int offset)
{

                                                                /* Print a message to the LCD.*/
  lcd.setCursor(offset, 0);                                     /* where the cursur wil be*/
  lcd.print(line1.substring((offset<0)? offset * -1: 0));       /* The stubstring is a function that removes characters from your string so it works negative('removing') by itself,
                                                                 * if you'd give it a nagative value it can't work, so if the given variable, called offset(coming from the startposition)
                                                                 * is smaller than 0, it will make it positive for the substring. If not it will make it 0, meaning it wont delete characters
                                                                 * from the string(line). Please mind that substring is one word, not two! (sub - string). So no camelcasing here */
  lcd.setCursor(offset, 1);                                     /* (note: line 1 is the second row, since counting begins with 0):*/
  lcd.print(line2.substring((offset<0)? offset * -1: 0));       /* same as explanation above O lcd.print line 1''*/
  delay(700);
}
