int switchPin1 = D3; //d3
int switchPin2 = D2; //d0
int LedPin = D0;
int switchValue1;
int switchValue2;
void setup() {
  pinMode(LedPin, OUTPUT);
  pinMode(switchPin1, INPUT_PULLUP);
  pinMode(switchPin2, INPUT_PULLUP);

}

void loop() {
  // read the switch value
  switchValue1 = digitalRead(switchPin1);
  switchValue2 = digitalRead(switchPin2);
  digitalWrite(LedPin, switchValue1);
  digitalWrite(LedPin, !switchValue2);

}
