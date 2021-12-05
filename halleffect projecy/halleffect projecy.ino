const int relayPin = 10;
const int hallPin = 2;

int hallVal = 0;
int relayToggle = LOW;
int previousState = HIGH; 

int triggerState = 16;

void setup ()
{
  pinMode (relayPin, OUTPUT);
  pinMode (hallPin, INPUT);
}
 
void loop ()
{/**
  hallVal = digitalRead(hallPin);
  if (hallVal == LOW && previousState==HIGH)
  {
    relayToggle=!relayToggle;
    digitalWrite (relayPin, relayToggle);
  }
  previousState=hallVal;
  */
  if(digitalRead(hallPin))
  {
    hallVal++;
  }
  
  if(   (hallVal > triggerState)  )
  {
    digitalWrite(relayPin, HIGH);
    delay(2000);
    digitalWrite(relayPin,LOW);
  }
}