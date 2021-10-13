/*
 * Array Based Potentiomic LED Array 
 * Credit: Kenny Blake
 * Version: 0.0.1
 */

const int LEDArray [6] = {8, 9, 10, 11, 12, 13};

void setup() {
  for (int i = 0; i < sizeof(LEDArray); i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);

}

void changeState(int upToWhat, bool state)
{
    for (int i = 0; i <= upToWhat; i++)
    {
      Serial.println(i);
      if (state)
      {
        digitalWrite(LEDArray[i], HIGH);
      }
      else
      {
        digitalWrite(LEDArray[i], LOW);
      }
    }

    for (int i = 0; i > upToWhat; i++)
    {
      digitalWrite(LEDArray[i], LOW);
    }
}

void loop() {
  int x=(analogRead(A0));
  Serial.println(x);

  if(x<10)
  {
    changeState(6, false);
  }
  else if (x >= (1023/6) && x < (2 * (1023/6)))
  {
    changeState(1, true);
  }

  else if (x >= (2 * (1023/6)) && x < (3 *(1023/6)))
  {
    changeState(2, true);
  }

  else if (x >= (3 * (1023/6)) && x < (4* (1023/6)))
  {
    changeState(3, true);
  }

  else if (x >= (4 * (1023/6)) && x < (5* (1023/6)))
  {
    changeState(4, true);
  }

  else if (x >= (5 * (1023/6)) && x < 1010)
  {
    changeState(5, true);
  }

  else if (x >= 1010)
  {
    changeState(6, true);
  }
}
