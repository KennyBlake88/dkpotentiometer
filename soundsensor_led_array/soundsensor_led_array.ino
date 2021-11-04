const int LEDArray [6] = {8, 9, 10, 11, 12, 13};
int soundsensorReading = 0;

void setup() {
  // put your setup code here, to run once:
    for (int i = 0; i < sizeof(LEDArray); i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);

}

void changeState(int index, bool state)
{
    //Turns on the leds up to index. 
    //Example: if index = 2, it will turn on 0, 1, 2 LED. 
    for (int i = 0; i < index; i++)
    {
      if (state)
      {
        digitalWrite(LEDArray[i], HIGH);
      }
      else
      {
        digitalWrite(LEDArray[i], LOW);
      }
    }

    //Turns off the leds WITHIN THE BOUNDS OF THE SIZE OF THE ARRAY, past the index. 
    //Example: if index is 2, it will turn off 3, 4, 5.
    for (int i = index; i < 7; i++)
    {
      digitalWrite(LEDArray[i], LOW);
    }
}

void loop() {
  // put your main code here, to run repeatedly:
  soundsensorReading = analogRead(A0);

}
