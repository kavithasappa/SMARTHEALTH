#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_RESET D5
Adafruit_SSD1306 display(OLED_RESET);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

int switchPin = D3; 
int LedPin = D0; 
int switchValue;
void setup()   {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
  display.clearDisplay();  
  display.setTextSize(1);  
  display.setTextColor(WHITE);  
  pinMode(LedPin, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);
}

void loop() {
  ledglow();
  delay(1000);
 
}
void ledglow()
{
   switchValue = digitalRead(switchPin);
  digitalWrite(LedPin, !switchValue);
  writeOLED();

}
void writeOLED(){
  display.clearDisplay();  
  if(switchValue=digitalRead(switchPin))
  {
  drawStr(50, 10, "led off");
  }
  else{
    drawStr(50,10,"led on");
  }
  display.display();
}

void drawStr(uint8_t x, uint8_t y, char* str){
  display.setCursor(x, y);  /* Set x,y coordinates */
  display.println(str);
}
