#include <Servo.h>

Servo keyserv;  // create servo object to control a servo
Servo doorserv;
// Yellow => GND
// Red => 5V
// Orange => Pin9

int pos = 0;
// variable to store the servo position

int LED = 13;

int BUTTON = 3;
// Blue => GND
// Yellow => 5V
// Green => Pin3

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON,INPUT);
  keyserv.attach(9);  // attaches the servo on pin 9 to the servo object
  doorserv.attach(10);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(BUTTON) == LOW)
  {
    digitalWrite(LED,HIGH);
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
      keyserv.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 5ms for the servo to reach the position
    }
    digitalWrite(LED,LOW);
    delay(100); 
    digitalWrite(LED,HIGH);
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      keyserv.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 5ms for the servo to reach the position
    }
    digitalWrite(LED,LOW);
    delay(100); 
    digitalWrite(LED,HIGH);
    delay(200);
    digitalWrite(LED,LOW);
    delay(100); 
    digitalWrite(LED,HIGH);
    for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
      doorserv.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 5ms for the servo to reach the position
    }
    digitalWrite(LED,LOW);
    delay(100); 
    digitalWrite(LED,HIGH);
    for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
      doorserv.write(pos);              // tell servo to go to position in variable 'pos'
      delay(5);                       // waits 5ms for the servo to reach the position
    }
    digitalWrite(LED,LOW);
    
   
  }else
  {
    digitalWrite(LED,LOW);
    delay(5);
  }
  
}
