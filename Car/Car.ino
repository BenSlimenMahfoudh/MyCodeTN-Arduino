int led = 7;
int buz =2;
const int TRIGGER_PIN = 11;
const int ECHO_PIN = 10;

/* Constantes pour le timeout */
const unsigned long MEASURE_TIMEOUT = 25000UL; // 25ms = ~8m à 340m/s

/* Vitesse du son dans l'air en mm/us */
const float SOUND_SPEED = 340.0 / 1000;


float distance;
void setup() {
  
  pinMode(led, OUTPUT);      
  pinMode(buz, OUTPUT);
  
  
  pinMode(TRIGGER_PIN, OUTPUT);
  digitalWrite(TRIGGER_PIN, LOW); // La broche TRIGGER doit être à LOW au repos
  pinMode(ECHO_PIN, INPUT);
  
  
  Serial.begin(9600);// initialise le port serie
}
 
void loop(){
  /* 1. Lance une mesure de distance en envoyant une impulsion HIGH de 10µs sur la broche TRIGGER */
  digitalWrite(TRIGGER_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGGER_PIN, LOW);
  
  /* 2. Mesure le temps entre l'envoi de l'impulsion ultrasonique et son écho (si il existe) */
  long measure = pulseIn(ECHO_PIN, HIGH, MEASURE_TIMEOUT);
   
  /* 3. Calcul la distance à partir du temps mesuré */
  distance = measure / 2.0 * SOUND_SPEED;
  
  if(distance < 700){
    
   digitalWrite(led,HIGH);
    tone(buz,1000,800);
    delay(10);
  }
  else{
  digitalWrite(led,LOW);
    noTone(buz);
    delay(10);
  }
 
}
