void setup()
{
    pinMode(8,OUTPUT);
    
}
void loop()
{
    int i;
      while(1)
      {
        i=analogRead(5);
        if(i>200)
        {
           digitalWrite(8,HIGH);
        }
        else
        {
            digitalWrite(8,LOW);
        }
      }
}
