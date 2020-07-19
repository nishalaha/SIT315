
const uint8_t buttonPin = 2; //define pins
const uint8_t ledRPin = 8;
const int motionPin = 3;

  
volatile uint8_t ledRPinState = LOW; //gobals

void setup()
{
   
  pinMode(ledRPin, OUTPUT);		//initializing pins 
  pinMode(LED_BUILTIN,OUTPUT); 
  pinMode(motionPin,INPUT_PULLUP);
  pinMode(buttonPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(buttonPin), Btntoggle, FALLING);
  attachInterrupt(digitalPinToInterrupt(motionPin), motionToggle, FALLING);
  Serial.begin(9600);
  
}

void loop(){
 	digitalWrite(LED_BUILTIN,LOW);    // turn the LED off by making the voltage LOW
 	Serial.println("LED: OFF");
  	delay(1000); // wait for a second
  
  	digitalWrite(LED_BUILTIN,HIGH);    // turn the LED off by making the voltage LOW
 	Serial.println("LED: ON");
  	delay(1000); // wait for a second
  }
  
void Btntoggle(){ //toggle function
   ledRPinState = HIGH;
   digitalWrite(ledRPin, ledRPinState);
   Serial.println("Button interrupt detected");
   delay(2000);
   ledRPinState = LOW;
   digitalWrite(ledRPin, ledRPinState);
   
  }

 void motionToggle(){
   ledRPinState = HIGH;
   digitalWrite(ledRPin, ledRPinState);
   Serial.println("Motion interrupt detected");
   delay(2000);
   ledRPinState = LOW;
   digitalWrite(ledRPin, ledRPinState);
   
}