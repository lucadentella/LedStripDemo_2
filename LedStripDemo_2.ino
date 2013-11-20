#define ledPin        13
#define stripPin      2
#define analogInPin   A0

int outState = LOW;
long previousMillis = 0;

long interval = 1000;

void setup() {

  pinMode(ledPin, OUTPUT);
  pinMode(stripPin, OUTPUT);  
}

void loop()
{

  int potValue = analogRead(analogInPin);
  interval = map(potValue, 0, 1023, 50, 2000);  
  
  unsigned long currentMillis = millis();
 
  if(currentMillis - previousMillis > interval) {

    previousMillis = currentMillis;   

    if (outState == LOW)
      outState = HIGH;
    else
      outState = LOW;

    digitalWrite(ledPin, outState);
    digitalWrite(stripPin, outState);
  }
}

