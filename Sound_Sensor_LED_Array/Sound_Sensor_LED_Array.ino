/**
 * Sound Sensor LED Array
 * Author: Kenny Blake
 * Version: 0.0.1
 * 
 * The following code takes analog input from a KY-037 Sound board module, 
 * it then translate that input into led's turning on and off in an array. 
 */

//Pin Declarations
const int LEDArray [6] = {8, 9, 10, 11, 12, 13};
const int SoundBoardDigitalPin = 3;
int currVal = 0;

/**
 * Changes the state of the led's in the array, up to index index, to HIGH if state is true, and low if state is false, and changes the rest of them to be LOW.
 * @param index (int):   The index of the LED in the array. (For example, 0 -> 8, 1 -> 9, 2 -> 10)
 * @param state    (bool):  Whether we want to have them change to on or off. true for on, false for off. 
 * 
 */
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


//Runs once when the code first gets to the arduino/the arduino resets. 
void setup() {

  //Begins serial communication with a baud rate of 9600
  Serial.begin(9600);
  //Sets all the LED pins in the array to be OUTPUT.
  for (int i : LEDArray)
  {
    pinMode(i, OUTPUT); 
  }

  //Sets the Soundboards Digital pin, or D0, to be INPUT.
  pinMode(SoundBoardDigitalPin, INPUT);
  delay(100);
}



//Runs repeatedly 
void loop() {
  currVal = analogRead(A0);
  Serial.println(currVal);

  if (currVal < 1000/6) {
    Serial.println("here!");
    changeState(6, false);
  }
  else if (currVal > (1000/6) && currVal < (2* (1000/6)))
  {
    changeState(1, true);
  }
  else if (currVal > (2* (1000/6)) && currVal < (3* (1000/6)))
  {
    changeState(2, true);
  }
  else if (currVal > (3* (1000/6)) && currVal < (4* (1000/6)))
  {
    changeState(3, true);
  }
  else if (currVal > (4* (1000/6)) && currVal < (5* (1000/6)))
  {
    changeState(4, true);
  }
  else if (currVal > (5* (1000/6)) && currVal < (6* (1000/6)))
  {
    changeState(5, true);
  }
  else
  {
    changeState(6, true);
  }
}
