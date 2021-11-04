const int led [10] = { 2,3,4,5,6,7,8,9,10,11};
int x=0;

void setup() {
  for (int i : led){  
    pinMode(i, OUTPUT);
  }
  
  pinMode(12, INPUT);
Serial.begin(9600);
}

void loop() {
    if(digitalRead(12)==HIGH){
    digitalWrite(led[x],HIGH);
   x++;
      if (x==11){
        x=0;
    for (int i : led){  
   digitalWrite(i,LOW);
  }
      }
    delay (300); 
  Serial.println(digitalRead(13))  ;
}





}
