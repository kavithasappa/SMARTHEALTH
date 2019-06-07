int switchPin = D3; //d3
int LedPin = D0; //d0
int switchValue;
void setup() {
  pinMode(LedPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);

}

void loop() {
  // read the switch value
  switchValue = digitalRead(switchPin);
  digitalWrite(LedPin, !switchValue);

}
