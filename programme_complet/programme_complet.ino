//bluetooth
#include<SoftwareSerial.h> 
const int RX=12;
const int TX=13;
SoftwareSerial BlueT(RX,TX);
String data;
int i=0;

//moteur droit
int ENA=10;
int IN1=16;
int IN2=17;

//moteur gauche
int ENB=11;
int IN3=18;
int IN4=19;

//capteur avant, gauche et droit
int captg=4;
int capta=3;
int captd=2;
int captG=0;
int captA=0;
int captD=0;

//capteur de distance
const int trig=6;
const int echo=5;
float distance=0;
float temps=0;

void setup() {
  Serial.begin(9600);

  //bluetooth
  BlueT.begin(9600);
  delay(200);
 
  //deplacements
  pinMode(ENA,OUTPUT);
  pinMode(ENB,OUTPUT);
  pinMode(IN1,OUTPUT);
  pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
  pinMode(IN4,OUTPUT);
  analogWrite(ENA,0);
  analogWrite(ENB,0);
  
  //sens rotation moteur D
  digitalWrite(IN1,HIGH);
  digitalWrite(IN2,LOW);
 
  //sens rotation moteur G 
  digitalWrite(IN3,HIGH);
  digitalWrite(IN4,LOW);

  //capt distance
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
}

String lireBT(){
  int n;
  char cBT;
  String rBT="";
  String rBT2="";
  if (BlueT.available()){
    if ((char)BlueT.read()=='X'){
      while (true){ 
        cBT = (char)BlueT.read();
        if (cBT=='X') {
          break;
         }
        rBT+=cBT;
       }
      }
    Serial.println(rBT);
    return rBT;
    }
}

void loop() {
  data=lireBT();

  if(data=="m"){
    i=2;
  }
  if(data=="o"){
    i=1;
  }
  while(i==1){
   captG=digitalRead(captg);
   captA=digitalRead(capta);
   captD=digitalRead(captd);
   
   digitalWrite(trig, HIGH);
   delayMicroseconds(10); 
   digitalWrite(trig, LOW);
   temps=pulseIn(echo,HIGH);
   distance=temps*0.034/2;
   delayMicroseconds(60);
   if (distance<=10){
    analogWrite(ENA,0);
    analogWrite(ENB,0);}
    else if (captG==0 && captA==0 && captD==1){
                                     digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);               //robot va à DROITE
                                     analogWrite(ENA,180);
                                     analogWrite(ENB,0);} 
    
    else if (captG==0 && captA==1 && captD==0){
                                     digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);               //robot va tout droit
                                     analogWrite(ENA,160);
                                     analogWrite(ENB,190);}
        
    else if (captG==1 && captA==0 && captD==0){
                                     digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);               //robot va à GAUCHE
                                     analogWrite(ENA,0);
                                     analogWrite(ENB,180);}
    
    else if (captG==0 && captA==1 && captD==1){
                                     digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);              //robot va à DROITE 
                                     analogWrite(ENA,180);
                                     analogWrite(ENB,0);}
    
    else if (captG==1 && captA==0 && captD==1){
                                     digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);              //robot va à DROITE 
                                     analogWrite(ENA,180);
                                     analogWrite(ENB,0);}
   
    else if (captG==1 && captA==1 && captD==0){
                                     digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);              //robot va a DROITE
                                     analogWrite(ENA,180);
                                     analogWrite(ENB,0);}
    
    else if (captG==1 && captA==1 && captD==1){
                                     digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,HIGH);
                                     digitalWrite(IN4,LOW);              // robot va à DROITE 
                                     analogWrite(ENA,180);
                                     analogWrite(ENB,0);}
    
    else if (captG==0 && captA==0 && captD==0){
                                     digitalWrite(IN1,HIGH);
                                     digitalWrite(IN2,LOW);
                                     digitalWrite(IN3,LOW);
                                     digitalWrite(IN4,HIGH);             // robot fait demi-tour
                                     analogWrite(ENA,160);
                                     analogWrite(ENB,190);}
    data=lireBT();
    if(data=="o"){
      i=2;
    }
  }

  while(i==2){
    data=lireBT();
   if(data=="h"){
    Serial.println("Avance");
    data="a";
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);              //robot va tout droit
    analogWrite(ENA,160);
    analogWrite(ENB,190);
    }

   if(data=="b"){  
    Serial.println("Recule");
    data="a";
    digitalWrite(IN1,LOW);
    digitalWrite(IN2,HIGH);
    digitalWrite(IN3,LOW);
    digitalWrite(IN4,HIGH);             // robot fait demi-tour
    analogWrite(ENA,160);
    analogWrite(ENB,190);
    }

   if(data=="d"){
    Serial.println("Droite");
    data="a";
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);               //robot va à droite
    analogWrite(ENA,180);
    analogWrite(ENB,0);
    }

   if(data=="g"){
    Serial.println("Gauche");
    data="a";
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);               //robot va à gauche
    analogWrite(ENA,0);
    analogWrite(ENB,180);
    }

   if(data=="s"){
    Serial.println("stop");
    data="a";
    digitalWrite(IN1,HIGH);
    digitalWrite(IN2,LOW);
    digitalWrite(IN3,HIGH);
    digitalWrite(IN4,LOW);               //robot s'arrete
    analogWrite(ENA,0);
    analogWrite(ENB,0);
    }

   data=lireBT();
   if(data=="m");{
    i=1;
   }
  }
}
