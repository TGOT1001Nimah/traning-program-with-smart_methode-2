int sensePin = A0;  //This is the Arduino Pin that will read the sensor output
int sensorInput;    //The variable we will use to store the sensor input
double temp ;        //The variable we will use to store temperature in degrees.

void setup()
{
  Serial.begin(9600); //Start the Serial Port at 9600 baud (default)
  pinMode(A0, INPUT);//define the potentiometer as input
  pinMode(4, OUTPUT);//difine the pin in relay 1 for right direction
  pinMode(5, OUTPUT);//difine the pin in relay 2 for left direction
   
}

void loop()
{
    // put your main code here, to run repeatedly: 
  sensorInput = analogRead(A0);    //read the analog sensor and store it
  temp = (double)sensorInput / 1024;       //find percentage of input reading
  temp = temp * 5;                 //multiply by 5V to get voltage
  temp = temp - 0.5;               //Subtract the offset 
  temp = temp * 100;               //Convert to degrees 
 
  Serial.print("Current Temperature: ");
  Serial.println(temp);
  
  
  if (temp > 100)//her if the value equal 125 poth relay pin will be open
  {
    digitalWrite(4, HIGH);
    digitalWrite(5, HIGH);
  }
 else
  {
    if (temp < 100) //but if the value less than 125 the motor will be in right direction
    {
      digitalWrite(4, LOW);
      digitalWrite(5, HIGH);
    }
    else ////els mean  if it is  more than 125 the motor will be in left direction
    {
      digitalWrite(4, HIGH);
      digitalWrite(5, LOW);
    }
  }
}
