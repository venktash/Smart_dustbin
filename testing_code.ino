void setup() {
pinMode(1,OUTPUT);  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(13,INPUT);

}

void loop() {
if(digiotalRread(13)==1)
{  digitalWrite(1,HIGH);}
  else{
  digitalWrite(1,LOW);
  digitalWrite(2,1);
  }  // put your main code here, to run repeatedly:

}
