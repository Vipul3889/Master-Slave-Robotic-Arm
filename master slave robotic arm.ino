// Master Slave Robotic Arm using Arduino UNO
// by Vipul Deshbhratar
// This code is intended for use with Arduino Microcontrollers
// This basic version of the code is working and can be ported directly to the microcontrollers.
// Changes can be made as and when required without notifications.
// The link to the video of its working is <https://www.youtube.com/watch?v=O4XgOaa-ESM>

#include <Servo.h>

Servo base;       // create servo object to control base servo
Servo shoulder;   // create servo object to control shoulder servos
Servo elbow;      // create servo object to control elbow servo
Servo gripper;    // create servo object to control gripper servo

int potpin3 = 3; // analog pin used to connect the base potentiometer
int potpin2 = 2; // analog pin used to connect the shoulder potentiometer
int potpin1 = 1; // analog pin used to connect the elbow potentiometer
int potpin = 0;  // analog pin used to connect the gripper potentiometer

int val;  // variable to read the value from the base analog pin
int val1; // variable to read the value from the shoulder analog pin
int val2; // variable to read the value from the elbow analog pin
int val3; // variable to read the value from the gripper analog pin

void setup()
{
    base.attach(3);     // attaches the servo on pin 3 to the servo object
    shoulder.attach(5); // attaches the servo on pin 5 to the servo object
    elbow.attach(6);    // attaches the servo on pin 6 to the servo object
    gripper.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
    val = analogRead(potpin3);       // reads the value of the base potentiometer (value between 0 and 1023)
    val = map(val, 0, 1023, 0, 179); // scale it to use it with the base servo (value between 0 and 180)
    base.write(val);                 // sets the base servo position according to the scaled value
    delay(15);                       // waits for the base servo to get there
    
    val1 = analogRead(potpin2);        // reads the value of the shoulder potentiometer (value between 0 and 1023)
    val1 = map(val1, 0, 1023, 0, 179); // scale it to use it with the shoulder servo (value between 0 and 180)
    shoulder.write(val1);              // sets the shoulder servo position according to the scaled value
    delay(15);                         // waits for the shoulder servo to get there
    
    val2 = analogRead(potpin1);        // reads the value of the elbow potentiometer (value between 0 and 1023)
    val2 = map(val2, 0, 1023, 0, 179); // scale it to use it with the elbow servo (value between 0 and 180)
    elbow.write(val2);                 // sets the elbow servo position according to the scaled value
    delay(15);                         // waits for the elbow servo to get there
    
    val3 = analogRead(potpin);         // reads the value of the gripper potentiometer (value between 0 and 1023)
    val3 = map(val3, 0, 1023, 0, 179); // scale it to use it with the gripper servo (value between 0 and 180)
    gripper.write(val3);               // sets the gripper servo position according to the scaled value
    delay(15);                         // waits for the gripper servo to get there
}
