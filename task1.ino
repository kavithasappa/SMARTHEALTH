
int LedPin1 = D4;
int LedPin2 = D5;
int analogvalue;
void setup() {
 
  Serial.begin(9600);// put your setup code here, to run once:
 pinMode(LedPin1,OUTPUT);
 pinMode(LedPin2,OUTPUT);
}

void loop() {
  analogvalue = analogRead(A0);
  // put your main code here, to run repeatedly:
Serial.println(analogvalue);
if(analogvalue<=300)
{
  digitalWrite(LedPin1,HIGH);
 digitalWrite(LedPin2,LOW);
  }
  else
{
  digitalWrite(LedPin1,LOW );
  digitalWrite(LedPin2,HIGH);
  }
}
