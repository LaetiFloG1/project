const int capt1=2;
const int capt2=3;
const int capt3=4;


void setup() {
  pinMode(capt1, INPUT);
  pinMode(capt2, INPUT);
  pinMode(capt3, INPUT);
  
  // put your setup code here, to run once:

}

void loop() {
  if (capt1=1 && capt2=0 && capt3=0){
    //robot va à gauche }
  if (capt1=0 && capt2=1 && capt3=0){
    //robot va tout droit }
  if (capt1=0 && capt2=0 && capt3=1){
    //robot va à droite }
  if (capt1=1 && capt2=1 && capt3=0){
    //robot va à gauche }
  if (capt1=1 && capt2=0 && capt3=1){
    //robot va à gauche }
  if (capt1=0 && capt2=1 && capt3=1){
    //robot va tout droit  }
  if (capt1=1 && capt2=1 && capt3=1){
    // robot fait demi-tour, il s'agit d'un cul-de-sac }

  // put your main code here, to run repeatedly:

}
