//moteur droit
int ENA=10;
int IN1=6;
int IN2=7;

//moteur gauche
int ENB=11;
int IN3=8;
int IN4=9;

//capteur avant, gauche et droit
int capt1=2;
int capt2=3;
int capt3=4;

//detecteur de distance
const int trig=12;
const int echo=13;
float distance = 0;
float temps =0;

//module bluetooth;
#include<SoftwareSerial.h> ;
//#define RX ;
//#define TX ;
//SoftwareSerial BlueT(RX,TX);


void setup() {
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  digitalWrite(ENA,LOW);
  digitalWrite(ENB,LOW);

  //sens rotation moteur D 
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);

  //sens rotation moteur G 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  analogWrite(ENA,255);
  analogWrite(ENB,255);

  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);

  Serial.begin(9600); 
  delay(500); 
  Serial.println("Bonjour -Pret pour les commandes AT"); 
//  BlueT.begin(9600); 
  delay(500);
  }

void loop() { 
  if (capt1==1 && capt2==0 && capt3==0){digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);
                                     analogWrite(ENA,0);
                                     analogWrite(ENB,150);}
    //robot va à gauche 
  if (capt1==0 && capt2==1 && capt3==0){digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);
                                     analogWrite(ENA,150);
                                     analogWrite(ENB,150);}
    //robot va tout droit 
  if (capt1==0 && capt2==0 && capt3==1){digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);
                                     analogWrite(ENA,150);
                                     analogWrite(ENB,150);}
    //robot va à droite 
  if (capt1==1 && capt2==1 && capt3==0){digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);
                                     analogWrite(ENA,150);
                                     analogWrite(ENB,150);}
    //robot va à gauche 
  if (capt1==1 && capt2==0 && capt3==1){digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);
                                     analogWrite(ENA,150);
                                     analogWrite(ENB,150);}
    //robot va à gauche 
  if (capt1==0 && capt2==1 && capt3==1){digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);
                                     analogWrite(ENA,150);
                                     analogWrite(ENB,150);}
    //robot va tout droit  
  if (capt1==1 && capt2==1 && capt3==1){digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);
                                     analogWrite(ENA,150);
                                     analogWrite(ENB,150);}
    // robot fait demi-tour, il s'agit d'un cul-de-sac 


  //lancement detecteur de distance pour arret
  digitalWrite(trig, HIGH); // génération de l'impulsion Trig de 10 µs 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  temps=pulseIn(echo,HIGH);
  distance=temps*0.034/2;
  Serial.println(distance);
  delayMicroseconds(60);
  if (distance<=10){
    analogWrite(ENA,0);
    analogWrite(ENB,0);
  }


  //connexion bluetooth
//  while (BlueT.available()) { 
  //  Serial.print(char(BlueT.read())); } 
    //while (Serial.available()) { 
      //BlueT.write(char(Serial.read())); }
