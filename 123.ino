int LEDPin = D6;
void setup() {
  Serial.begin(9600);
  analogWrite(LEDPin , 1024);
}

void loop() {
  int dutycycle = analogRead(A0);
  if(dutycycle > 1023) dutycycle=1023;
  Serial.print("Duty cycle: ");
  Serial.println(dutycycle);
  analogWrite(LEDPin, dutycycle);
  delay(100);

}
