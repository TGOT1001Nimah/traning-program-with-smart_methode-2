
//her i connecting between tow Arduino one of them for the motor controller by the other Arduino with tow LED 
//i defined these tow LED  tow color red as heat and blue for cold
//if the light is red means it's hot then the motor will move forward, but if it changes to blue means cold it will move backward

int red =6;
int blue =7;

void setup() {
  // initialize digital pin LED_BUILTIN as an output.
 pinMode(red, OUTPUT);
 pinMode(blue, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(red, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);// wait for a second
   digitalWrite(red, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
   digitalWrite(blue, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);// wait for a second
  digitalWrite(blue, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
}
