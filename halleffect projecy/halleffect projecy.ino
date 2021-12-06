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
  if(hallVal > 20)
  {
    hallVal = 0;
  }
  delay(500);
  if (hallVal == 16)
  {
    relayToggle=!relayToggle;
    digitalWrite (relayPin, relayToggle);
    delay(1000);
    hallVal = 0;
  }
  previousState=hallVal;
  Serial.println(hallVal);

}