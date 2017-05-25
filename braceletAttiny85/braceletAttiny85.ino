int ledPinR = 0;    // LED connected to digital pin 9 
int ledPinB = 2;
int ledPinV = 1; 

byte colorLed(int red, int green, int blue) {
  analogWrite(ledPinR, red);         
  analogWrite(ledPinV, green);         
  //analogWrite(ledPinB, blue);

  if ((micros()%2550)<(10*blue)) {
    digitalWrite(ledPinB,HIGH);
  } else {
    digitalWrite(ledPinB,LOW);
  }
    //digitalWrite(ledPinB,HIGH);
   
   return 0;
}
unsigned long top=0;

uint32_t Wheel() {

int i = ((millis()-top)/50)% 256;

//for (int i=0;i<256;i++) {
// delay(50);

 
 int   WheelPos = 255 - i;
  if(WheelPos < 85) {
     colorLed(255 - WheelPos * 3, 0, WheelPos * 3);
  } else 
  if(WheelPos < 170) {
    WheelPos -= 85;
     colorLed(0, WheelPos * 3, 255 - WheelPos * 3);
  } else { 
  WheelPos -= 170;
   colorLed(WheelPos * 3, 255 - WheelPos * 3, 0);
  }
//}
}


void setup() {
  // put your setup code here, to run once:

  top=millis();
  pinMode(ledPinB,OUTPUT);
}

void loop() {
  
 Wheel();
}
