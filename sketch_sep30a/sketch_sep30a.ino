int LEDPin;
int actuatorLEDPin;
int TriggerPin;
int EchoPin;
int distance;
int duration;
int counter;
int actuatorCounter;
bool hasBeenTurnedOn;
bool primed;


void setup() {
  // put your setup code here, to run once:
  LEDPin = 11;
  TriggerPin = 6;  
  EchoPin = 3;
  actuatorLEDPin = 9; 
  distance = 0;
  duration = 0;
  counter = 1;
  actuatorCounter = 1;
  hasBeenTurnedOn = false;
  primed = false;
  pinMode(TriggerPin, OUTPUT);
  pinMode(EchoPin, INPUT);
  pinMode(LEDPin, OUTPUT);
  pinMode(actuatorLEDPin, OUTPUT);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(TriggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TriggerPin, HIGH);
  duration = pulseIn(EchoPin, HIGH);
  distance = duration * 0.034/2;

  if (distance < 30 and distance > 10)
  {
    if(!hasBeenTurnedOn)
    {
      hasBeenTurnedOn = true;
      Serial.println(distance);
      if(counter == 3)
      {
        digitalWrite(LEDPin, HIGH);
        primed = true;
      }
      else if(counter == 6)
      {
        digitalWrite(LEDPin, LOW);
        digitalWrite(actuatorLEDPin, LOW);
        primed = false;
        counter = 1;
      }
      else
      {
        counter++;
      }
    }
    
  }
  else if (distance < 10)
  {
    Serial.println(distance);
    if (actuatorCounter == 30 and primed)
    {
      digitalWrite(actuatorLEDPin, HIGH);
      actuatorCounter = 0;
    }
    else
    {
      actuatorCounter++;
    }
  }
  else
  {
    if(hasBeenTurnedOn)
    {
      hasBeenTurnedOn = false;
    }
  }
  delay(100);
  
}
