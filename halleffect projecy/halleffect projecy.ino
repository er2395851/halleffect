const int relayPin = 10;
const int hallPin = 2;

int hallVal = 0;
int relayToggle = LOW;
int previousState = HIGH; 
int count = 0;

void setup ()
{
  pinMode (relayPin, OUTPUT);
  pinMode (hallPin, INPUT);
  Serial.begin(9600);
}
 
void loop ()
{
 // hallVal = digitalRead(hallPin);

  if(analogRead(A0) < 100)
  {
    hallVal++;
  }
  
  if (hallVal == 16)
  {
    //relayToggle=!relayToggle;
    delay(100);
    digitalWrite (relayPin, HIGH);
    delay(1000);
    hallVal = 0;
     digitalWrite (relayPin, LOW);
  }
  previousState=hallVal;
 

Serial.println(hallVal);
 delay(100);
 count++;
 Serial.print("loop ");
  Serial.print(count);
 Serial.print(" ");
  Serial.println(analogRead(A0)); 
}