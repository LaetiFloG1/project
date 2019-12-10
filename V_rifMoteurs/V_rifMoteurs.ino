//-- MOTEUR A -
int ENA=9; //Connecté à Arduino pin 9(sortie PWM) 
int IN1=4; //Connecté à Arduino pin 4 
int IN2=5; //Connecté à Arduino pin 5

//-- MOTEUR B -
int ENB=10; //Connecté à Arduino pin 10(Sortie PWM) 
int IN3=6; //Connecté à Arduino pin 6 
int IN4=7; //Connecté à Arduino pin 7

void setup() { 
  pinMode(ENA,OUTPUT); // Configurer 
  pinMode(ENB,OUTPUT); // les broches 
  pinMode(IN1,OUTPUT); // comme sortie 
  pinMode(IN2,OUTPUT); 
  pinMode(IN3,OUTPUT); 
  pinMode(IN4,OUTPUT); 
  digitalWrite(ENA,LOW);// Moteur A - Ne pas tourner 
  digitalWrite(ENB,LOW);// Moteur B - Ne pas tourner

  // Direction du Moteur A 
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  // Direction du Moteur B  
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
}

void loop() { 
  //Test moteur sens 1 
  analogWrite(ENA,150);
  analogWrite(ENB,150);
  delay(1000);
  analogWrite(ENA,LOW);
  analogWrite(ENB,LOW);

  // Inversion direction du Moteur A
  digitalWrite(IN1,LOW); 
  digitalWrite(IN2,HIGH);
  // Inversion direction du Moteur B
  digitalWrite(IN3,LOW); 
  digitalWrite(IN4,HIGH);

  //Test moteur sens 2
  analogWrite(ENA,150);
  analogWrite(ENB,150);
  delay(1000);
  analogWrite(ENA,LOW);
  analogWrite(ENB,LOW);

  // On remet les moteurs a l'endroit
  // Inversion direction du Moteur A
  digitalWrite(IN1,HIGH); 
  digitalWrite(IN2,LOW);
  // Inversion direction du Moteur B
  digitalWrite(IN3,HIGH); 
  digitalWrite(IN4,LOW);
}
