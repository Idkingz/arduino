
#include <IRremote.h>

//Pin 11 Digital
int PinRx = 11;

//Pin 10 Digital
int Rele = 10;

//State initial Off
boolean state = false;

//STB Key in Samsung Controler (Hexadecimal)
int SamsungSTBKey = 0x2D25D203;

IRrecv irrecv(PinRx);
decode_results results;

void setup()
{
  Serial.begin(9600);
  
  //Set the pin modo for Rele
  pinMode(Rele,OUTPUT);
  
  // Start the receiver
  irrecv.enableIRIn(); 
}

void loop() {
  if (irrecv.decode(&results)) {
    if (results.value == SamsungSTBKey) state = !state;
    changeState(state);
    irrecv.resume(); // Receive the next value
  }
}

boolean changeState(boolean state){
  if (state) digitalWrite(Rele, HIGH);
  else digitalWrite(Rele, LOW);
}

