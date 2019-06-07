int switchPin = D3; //d3
int LedPin1 = D0; //d0
int LedPin2 = D1;
int switchValue;
void setup() {
  pinMode(LedPin1, OUTPUT);
  pinMode(LedPin2, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);

}

void loop() {
  // read the switch value
  switchValue = digitalRead(switchPin);
  digitalWrite(LedPin1, !switchValue);
  digitalWrite(LedPin2, !switchValue);

}
