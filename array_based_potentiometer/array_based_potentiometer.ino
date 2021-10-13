/*
 * Array Based Potentiomic LED Array 
 * Credit: Kenny Blake
 * Version: 1.0.0
 */

const int LEDArray [6] = {8, 9, 10, 11, 12, 13};

/**
 * Sets all the arrays the be on, begins the serial reading. 
 */
void setup() {
  for (int i = 0; i < sizeof(LEDArray); i++)
  {
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);

}

/**
 * Changes the state of the led's in the array, up to index upToWhat, to HIGH if state is true, and low if state is false, and changes the rest of them to be LOW.
 * @param upToWhat (int):   The index of the LED in the array. (For example, 0 -> 8, 1 -> 9, 2 -> 10)
 * @param state    (bool):  Whether we want to have them change to on or off. true for on, false for off. 
 * 
 */
void changeState(int upToWhat, bool state)
{
    for (int i = 0; i < upToWhat; i++)
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

    for (int i = upToWhat; i < 7; i++)
    {
      digitalWrite(LEDArray[i], LOW);
    }
}

/**
 * Reads data from analog port 0 from the potentiometer, and calls the changeState function based on the passed data.
 */
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
