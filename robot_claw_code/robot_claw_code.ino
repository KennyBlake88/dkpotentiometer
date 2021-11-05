/**
 * How to install VarSpeedServo.h:
 * 
 * Go to the following link: https://github.com/netlabtoolkit/VarSpeedServo
 * In the right corner of where all the files are, click the green code button, then click "Download Zip".
 * 
 * Then, come back into this arduino window, and in the upper left corner, click "Sketch".
 * Click "Include Library", "Add .ZIP Library", and navigate to where you just downloaded the Zip file.
 * 
 * Double click on the File Called "VarSpeedServo-master.zip". 
 * 
 * If you did this right, all of the references in this code to VarSpeedServo/VarSpeedServo.h should turn orange.
 * 
 * You have successfully installed VarSpeedServo.h
 */



#include <VarSpeedServo.h> //External Dependency: Exactly the same as servo.h, which is the arduino built in servo header file, except it allows you to control the speed of the movement.
                           //Explanation: The Arduino's built in servo header file only allows you to send angles to the servo, VarSpeedServos allows you to send speeds, and angles. 

VarSpeedServo claw;     //The servo that controls the claw hand
VarSpeedServo arm;      //The central servo, rotates the whole arm on the x and y axis 
VarSpeedServo shifter;  //The servo that changes the angle of the rocker- AKA the linkage that holds the claw. Like the kneecap.
int clawPot;            //The current value from the claw potentiometer - WILL BE MAPPED TO ANALOG 0 
int armPot;             //The current vale from the arm potentiometer - WILL BE MAPPED TO ANALOG 1
int shifterPot;         //The current value from the shifter potentiometer - WILL BE MAPPED TO ANALOG 2
int moveSpeed = 100;

/**
 * Declaring these functions before we actually code them, that way they can be coded below our 
 * void setup and void loop functions. 
 */
int moveClaw();      //The pre-made one by Kenny, use this one as a reference;
int moveArm();       //This one will be communicating with VarSpeedServo arm;
int moveShifter();   //This one will be communicating with VarSpeedServo shifterPot;



//ACTUAL CODE BELOW


void setup() {
  
  /*
   * Basic setup, attaching necessary components to their respective pins,
   * Starting the serial communication, etc. 
   */
  Serial.begin(9600); //Serial Communication is starting with 9600 of baudrate speed
  claw.attach(4);     //Attaching the claw servo to pin 4.
  arm.attach(5);      //Attaching the arm servo to pin 5.
  shifter.attach(7);  //Attaching the shifter servo to pin 7.
  
  
  if (moveClaw(180, moveSpeed) == -1)
  {
    Serial.println("Claw function not coded yet!");
  }  

  if(moveArm(180, moveSpeed) == -1)
  {
    Serial.println("Arm function not coded yet!");
  }

  if (moveShifter(180, moveSpeed) == -1)
  {
    Serial.println("Shifter function not coded yet!");
  }

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

  moveClaw(clawPot, moveSpeed);
  moveArm(armPot, moveSpeed);
  moveShifter(shifterPot, moveSpeed);
}

/**
 * Kenny's pre-coded claw movement function
 */
int moveClaw(int potVal, int movespeed)
{
  
  map(potVal, 0, 1023, 0, 180); //The map function maps the values from the potentiometer to the values for the servo. 
                                 //For Example: 560 from the potentiometer would map 76.2 in the servo. <--This may not be correct, but it's just an example showing what it would do.
  Serial.println("Moving claw servo to angle " + potVal);
                                 
  claw.write(potVal, movespeed, false); //Move the claw to the angle provided from the potentiometer, mapped using the map() function, at a speed of 100, and don't wait until it's done. We got multiple things to move.
  return 0;
}

int moveArm(int angle, int speed)
{
  return -1;
}

int moveShifter(int angle, int speed)
{
  return -1;
}
