#include <ESP8266WiFi.h>
#include <PubSubClient.h>

#define sensor A0
#define led D3
#define buz D4
 
//-------- Customise these values -----------
const char* ssid = "YOU";
const char* password = "sbvizag2019";
//String command;

 
#define ORG "5rxjjv"
#define DEVICE_TYPE "IOT"
#define DEVICE_ID "IOT0203"
#define TOKEN "17B91A0598"
//-------- Customise the above values --------
 
char server[] = ORG ".messaging.internetofthings.ibmcloud.com";
char topic[] = "iot-2/evt/Data/fmt/json";
char authMethod[] = "use-token-auth";
char token[] = TOKEN;
char clientId[] = "d:" ORG ":" DEVICE_TYPE ":" DEVICE_ID;
 
WiFiClient wifiClient;
PubSubClient client(server, 1883,wifiClient);

float mgL;

void setup() {
 Serial.begin(115200);
 Serial.println();
 Serial.print("Connecting to ");
 Serial.print(ssid);
 WiFi.begin(ssid, password);
 while (WiFi.status() != WL_CONNECTED) {
 delay(500);
 Serial.print(".");
 } 
 Serial.println("");
 
 Serial.print("WiFi connected, IP address: ");
 Serial.println(WiFi.localIP());
  Serial.print("Alcohol Detector");
  Serial.print(" Circuit Digest ");
  delay(2000);
  pinMode(sensor, INPUT);
  pinMode(buz, OUTPUT);
  pinMode(led, OUTPUT);
}
 
void loop() {
     float adcValue=0;
  for(int i=0;i<10;i++)
  {
    adcValue+= analogRead(sensor);
    delay(1000);
  }
    float v= (adcValue/10) * (5.0/1024.0);
    mgL= 0.67 * v;
    Serial.print("BAC:");
    Serial.print(mgL);
    Serial.print(" mg/L");
    if(mgL > 1.75)
    { 
      Serial.print("Drunk   ");
      Serial.println("    Drunk");
      digitalWrite(buz, HIGH);
      digitalWrite(led, HIGH);
    }
    else
    {
      Serial.print("Normal  ");
      Serial.println("    Normal");
      digitalWrite(buz, LOW);
      digitalWrite(led, LOW);
    }

    delay(1000);
 
PublishData(mgL);
 if (!client.loop()) {
    mqttConnect();
  }
delay(100);
}
void mqttConnect() {
  if (!client.connected()) {
    Serial.print("Reconnecting MQTT client to "); Serial.println(server);
    while (!client.connect(clientId, authMethod, token)) {
      Serial.print(".");
      delay(500);
    }
    initManagedDevice();
    Serial.println();
  }
}
void initManagedDevice() {
  if (client.subscribe(topic)) {
    Serial.println("subscribe to cmd OK");
  } else {
    Serial.println("subscribe to cmd FAILED");
  }
}

void PublishData(float mgL){
 if (!!!client.connected()) {
 Serial.print("Reconnecting client to ");
 Serial.println(server);
 while (!!!client.connect(clientId, authMethod, token)) {
 Serial.print(".");
 delay(500);
 }
 Serial.println();
 }
  String payload = "{\"d\":{\"mgL\":";
  payload += mgL;

  payload += "}}";
 Serial.print("Sending payload: ");
 Serial.println(payload);
  
 if (client.publish(topic, (char*) payload.c_str())) {
 Serial.println("Publish ok");
 } else {
 Serial.println("Publish failed");
 }
}
