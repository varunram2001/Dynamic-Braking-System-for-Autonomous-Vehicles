#include <stdio.h>
//Sensor info 100-19000 sensor data min-max
const int trigPin = 12;
const int echoPin = 11;
long duration;
int distanceCm;
// Motor A connections
int enA = 5;
int in1 = 10;
int in2 = 9;
void setup()
{
 // Set all the motor control pins to outputs
 pinMode(enA, OUTPUT);
 pinMode(in1, OUTPUT);
 pinMode(in2, OUTPUT);
 // pinmode of SCH-04 sensor
 Serial.begin(9600);
 pinMode(trigPin, OUTPUT);
 pinMode(echoPin, INPUT);
 
 // Turn off motors - Initial state
 digitalWrite(in1, LOW);
 digitalWrite(in2, LOW);
 //initialize communication with console
 Serial.begin(9600);
 delay(100);
}
void loop() 
{
 speedControl();
 delay(10);
 //read DISTANCE from Sensor
 delay(80); //delay new cycle sensor reading
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);
 duration = pulseIn(echoPin, HIGH); //EchoPin signal timing - ms
 distanceCm = duration*0.034/2; // Distance calculation in CM
 //Serial.print the distance & duration
 Serial.print("Distance : " );
 Serial.print(distanceCm);
 Serial.println(" cm ");
}
//Motor speed control based on "distanceCm"
void speedControl()
{
 // Turn on motors
 digitalWrite(in1, LOW);
 digitalWrite(in2, HIGH);
 
 if((distanceCm<=5))
 {
digitalWrite(in1, LOW);
digitalWrite(in2 , LOW);
delay(25);
}
if((distanceCm>=25))
XVI
 {
analogWrite(enA, 255);
delay(25);
}
else
{
analogWrite(enA, 100);
delay(25);
 }
}
