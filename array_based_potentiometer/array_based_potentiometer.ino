/*
 * Array Based Potentiomic LED Array 
 * Credit: Kenny Blake
 * Version: 0.0.1
 */

const int[6] LEDArray = {8, 9, 10, 11, 12, 13};

void setup() {
  for (int i = 0; i < sizeof(LEDArray.length()); i++;)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);

}

void changeState(int upToWhat, bool state)
{
    for (int i = 0; i <= upToWhat; i++;)
    {
      if (state)
      {
        digitalWrite(LEDArray[i], HIGH)
      }
      else
      {
        digitalWrite(LEDArray[i], LOW)
      }
    }
}

void loop() {
  int x=(analogRead(A0));
  Serial.println(x);

  if(x<10)
  {
    changeState(6, false);
  }
  else if (x >= (1023/1) && x < (1023/2))
  {
    changeState(1, true);
  }

  else if (x >= (1023/2) && x < (1023/3))
  {
    changeState(2, true);
  }

  else if (x >= (1023/3) && x < (1023/4))
  {
    changeState(3, true);
  }

  else if (x >= (1023/4) && x < (1023/5))
  {
    changeState(4, true);
  }

  else if (x >= (1023/5) && x < (1023/6))
  {
    changeState(5, true);
  }

  else
  {
    changeState(6, true);
  }
}
