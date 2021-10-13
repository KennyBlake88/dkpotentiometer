

void setup() {
  pinMode (8,OUTPUT);
  pinMode (9,OUTPUT);
  pinMode (10,OUTPUT);
  pinMode (11,OUTPUT);
  pinMode (12,OUTPUT);
  pinMode (13,OUTPUT);
  
  Serial.begin(9600);

}

void loop() {
int x=(analogRead(A0));
 Serial.println(x);



if (x<10){
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }

  
  if( x>10 && x>=(1023/6)){

  digitalWrite(8,HIGH);
  digitalWrite(9, LOW);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  }
  
  
  if( x>(1023/6) && x>=(2*1023/6)){

  digitalWrite(8,HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  } 

if( x>(2*1023/6) && x>=(3*1023/6)){

  digitalWrite(8,HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,LOW);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  } 

if( x>(3*1023/6) && x>=(4*1023/6)){

  digitalWrite(8,HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
  digitalWrite(13,LOW);
  } 

  if( x>(4*1023/6) && x>=(5*1023/6)){

  digitalWrite(8,HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,LOW);
  } 

  if(x>1010){

  digitalWrite(8,HIGH);
  digitalWrite(9, HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);
  } 


  
 /* digitalWrite(8,HIGH);
  digitalWrite(9,HIGH);
  digitalWrite(10,HIGH);
  digitalWrite(11,HIGH);
  digitalWrite(12,HIGH);
  digitalWrite(13,HIGH);*/

}
