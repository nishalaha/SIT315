
int trigPin = 3;
int echoPin = 2;
long duration, distance;
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
  Serial.begin (9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(LED_BUILTIN,OUTPUT);
  
}

// the loop function runs over and over again forever
void loop() {
  
  digitalWrite(trigPin,LOW);
  delay(1000);
  digitalWrite(trigPin,HIGH);
  delay(1000);
  digitalWrite(trigPin,LOW);
  duration = pulseIn(echoPin,HIGH);
  distance = duration*0.034/2;
  if (distance < 10){
    digitalWrite(LED_BUILTIN,HIGH);// turn the LED on (HIGH is the voltage level)
    Serial.println("LED: ON");
    delay(1000); // wait for a second
  }
  else{
    digitalWrite(LED_BUILTIN,LOW);    // turn the LED off by making the voltage LOW
    Serial.println("LED: OFF");
    delay(1000); // wait for a second
  }

delay(500);
}
