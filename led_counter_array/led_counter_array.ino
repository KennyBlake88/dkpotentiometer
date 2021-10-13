const int LEDArray [10] = {2,3,4,5,6,7,8,9,10,11};
int x=0;

void setup() {
  for (int i : LEDArray){  
    pinMode(i, OUTPUT);
  }
  
  pinMode(13, INPUT);
}

void loop() {
  if(digitalRead(13)==HIGH){
    
    digitalWrite(LEDArray[x],HIGH);
    x++;
    
    if (x==12){
      x=0;
    }
    
  delay (300);
}





}
