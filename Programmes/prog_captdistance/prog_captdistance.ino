const int trig=9;
const int echo=8;
float distance = 0;
float temps =0;


void setup() {
  Serial.begin(9600);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  // put your setup code here, to run once:

}

void loop() {
  digitalWrite(trig, HIGH); // génération de l'impulsion Trig de 10 µs 
  delayMicroseconds(10); 
  digitalWrite(trig, LOW);
  temps=pulseIn(echo,HIGH);
  distance=temps*0.034/2;
  Serial.println(distance);
  delayMicroseconds(60);
  // put your main code here, to run repeatedly:

}
