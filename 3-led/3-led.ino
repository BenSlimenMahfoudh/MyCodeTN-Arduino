int pinLedR=2; //led rouge
int pinLedO=3; //led orongé
int pinLedG=4; //led vert 
void setup() {
  pinMode(pinLedR,OUTPUT);
  pinMode(pinLedO,OUTPUT);
  pinMode(pinLedG,OUTPUT);
}

void loop() {
  /*
  GREEN   +
  ORONGE  -
  RED     -
  */
  digitalWrite(pinLedG,HIGH);
  digitalWrite(pinLedO,LOW);
  digitalWrite(pinLedR,LOW);
  delay(1000);
  

    /*
  GREEN  -
  ORONGE +
  RED    -
  */
  
  digitalWrite(pinLedG,LOW);
  digitalWrite(pinLedO,HIGH);
  digitalWrite(pinLedR,LOW);
  delay(500);
  
    /*
  GREEN  -
  ORONGE -
  RED    +
  */
  
  digitalWrite(pinLedG,LOW);
  digitalWrite(pinLedO,LOW);
  digitalWrite(pinLedR,HIGH);
  delay(1000);
  
    /*
  GREEN  -
  ORONGE +
  GREEN  -
  */
  
  digitalWrite(pinLedG,LOW);
  digitalWrite(pinLedO,HIGH);
  digitalWrite(pinLedR,LOW);
  delay(500);
  

}
