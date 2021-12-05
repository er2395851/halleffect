const int relayPin = 10;
const int hallPin = 2;

int hallVal = 0;
int relayToggle = LOW;
int previousState = HIGH; 


void setup ()
{
  pinMode (relayPin, OUTPUT);
  pinMode (hallPin, INPUT);
  Serial.begin(9600);
}
 
void loop ()
{
  hallVal += digitalRead(hallPin);
  if (hallVal == LOW && previousState==HIGH && hallVal < 16)
  {
    relayToggle=!relayToggle;
    digitalWrite (relayPin, relayToggle);
    hallVal = 0;
  }
  previousState=hallVal;
  Serial.println(hallVal);

}