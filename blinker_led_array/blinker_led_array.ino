const int led [6] = {8,9,10,11,12,13};

void setup() {
  for (int i : led){  
  pinMode(i, OUTPUT);
  }
}

void loop() {

  for(int i=-1;i<6;i++){
    int x=led[i];
    digitalWrite(x,HIGH);
    delay (500);
    digitalWrite(x,LOW);
    if(i==5){
      i=-1;
      } 
    }
}
