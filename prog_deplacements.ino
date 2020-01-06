//moteur D 
int END=8;
int IN1=4;
int IN2=5;

//moteur G 
int ENG=9;
int IN3=6;
int IN4=7;

void setup() {
  pinMode(END,OUTPUT);
  pinMode(ENG,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  digitalWrite(END,LOW);//on initialise
  digitalWrite(ENG,LOW);//on initialise

  //sens rotation moteur D 
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  //sens rotation moteur G 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);
  
  // put your setup code here, to run once:

}

void loop() {
  // robot va tout droit 
  analogWrite(END,150);
  analogWrite(ENG,150);

  //robot tourne à droite
  analogWrite(END,0); //on stoppe le moteur droit pour tourner 
  analogWrite(ENG,150);

  //robot tourne à gauche 
  analogWrite(END,150);
  analogWrite(ENG,0);

  //robot s'arrête 
  analogWrite(END,0);
  analogWrite(ENG,0); 
  // put your main code here, to run repeatedly:

}
