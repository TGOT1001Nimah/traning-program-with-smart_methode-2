#define echopin  9 // echo pin
#define trigpin 4 // Trigger pin
#include<Servo.h> //laibrary for servomotor 

Servo myservo;


long duration, distance; //becuse the values from ultrasonic is changeable in are extended size variables for number storage, and store 32 bits (4 bytes), from -2,147,483,648 to 2,147,483,647.

//int maximumRange = 30;





void setup() {
  pinMode (trigpin, OUTPUT);//The Trig is sending waves to reflected and the Eco receiving it
  pinMode (echopin, INPUT );//
  myservo.attach(13);//servo pin 

//H-bridge motors pins
pinMode(11, OUTPUT);
pinMode(6, OUTPUT);

pinMode(10, OUTPUT);
pinMode(5, OUTPUT);

pinMode(3, OUTPUT);




}

void loop() {
  {
    // make sure that the trigPin is clear so you have to set that pin on a LOW State for just 2 µs
    digitalWrite(trigpin,LOW);
    delayMicroseconds(2);
    //Now for generating the Ultra sound wave we have to set the trigPin on HIGH State for 10 µs
    digitalWrite(trigpin,HIGH);
    delayMicroseconds(10);
    //Using the pulseIn() function you have to read the travel time and put that value into the variable “duration”
    duration=pulseIn (echopin,HIGH);
    distance = duration * 0.034 / 2;//her to receve the value of pulse as cm value 
   
    delay (50);
    
  }  
if (distance <= 40 ){
    digitalWrite(11,LOW);
    digitalWrite(6,LOW);
    
    digitalWrite(5,HIGH);
    digitalWrite(10,HIGH);

    delay (200);
    digitalWrite(11,HIGH);
    
    digitalWrite(6,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(10,LOW);
   
  myservo.write(90);
  delay(1000);
  myservo.write(180);
  delay(1000);
  myservo.write(0);
  delay(1000);
  
    digitalWrite(11,HIGH);
    
    digitalWrite(6,LOW);
    digitalWrite(5,LOW);
    digitalWrite(10,HIGH);
}

  else if (distance >= 40 ){
    
    digitalWrite(11,LOW);
   
    digitalWrite(6,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(10,LOW);
    
   myservo.write(90);
  }
 
}
