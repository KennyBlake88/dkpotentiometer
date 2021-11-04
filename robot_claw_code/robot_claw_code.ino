#include <VarSpeedServo.h> //External Dependency: Exactly the same as servo.h, which is the arduino built in servo header file, except it allows you to control the speed of the movement.
                           //Explanation: The Arduino's built in servo header file only allows you to send angles to the servo, VarSpeedServos allows you to send speeds, and angles. 

VarSpeedServo claw;     //The servo that controls the claw hand
VarSpeedServo arm;      //The central servo, rotates the whole arm on the x and y axis 
VarSpeedServo shifter;  //The servo that changes the angle of the rocker- AKA the linkage that holds the claw. Like the kneecap.
int clawPot;            //The current value from the claw potentiometer - WILL BE MAPPED TO ANALOG 0 
int armPot;             //The current vale from the arm potentiometer - WILL BE MAPPED TO ANALOG 1
int shifterPot;         //The current value from the shifter potentiometer - WILL BE MAPPED TO ANALOG 2

void setup() {
  
  /*
   * Basic setup, attaching necessary components to their respective pins,
   * Starting the serial communication, etc. 
   */
  Serial.begin(9600); //Serial Communication is starting with 9600 of baudrate speed
  claw.attach(4);     //Attaching the claw servo to pin 4.
  arm.attach(5);      //Attaching the arm servo to pin 5.
  shifter.attach(7);  //Attaching the shifter servo to pin 7.
  

  
  map(clawPot, 0, 1023, 0, 180); //The map function maps the values from the potentiometer to the values for the servo. 
                                 //For Example: 560 from the potentiometer would map 76.2 in the servo. <--This may not be correct, but it's just an example showing what it would do.
  map(armPot, 0, 1023, 0, 180);
  map(shifterPot, 0, 1023, 0, 180);

  

  
  
  
  


}

void loop() {

  /*Declaring what each analog pin will map to.
  *   0 to claw
  *   1 to arm
  *   2 to shifter
  */
  clawPot = analogRead(0);
  armPot = analogRead(1);
  shifterPot = analogRead(2);
  

}
