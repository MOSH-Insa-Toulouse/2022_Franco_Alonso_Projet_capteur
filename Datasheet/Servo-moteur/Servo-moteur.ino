// Sweep by BARRAGAN
#include <Servo.h>

Servo myservo;  // create servo object to control a servo
                // a maximum of eight servo objects can be created

int pos = 0;    // variable to store the servo position

void setup()
{
  Serial.begin(9600);
  myservo.attach(9);  // attaches the servo on pin 9 to the servo object
}

void loop()
{
  for(pos = 30; pos <= 150; pos += 1)  // goes from 30 degrees to 150 degrees
  {                                  // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(5);                       // waits 5ms for the servo to reach the position
  }
  for(pos = 150; pos>=31; pos-=1)     // goes from 150 degrees to 30 degrees
  {                                
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    Serial.println(pos);
    delay(5);                       // waits 5ms for the servo to reach the position
  }
} 
