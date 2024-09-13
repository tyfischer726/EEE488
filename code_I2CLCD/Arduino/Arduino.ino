#include <LiquidCrystal_I2C.h>
#include <ArduinoJson.h>

///// Spot Monitoring /////
int spots_available;
bool spot_monitoring = false;
const int total_spots = 1;
const float openSpaceDist = 0.1;
int monitorPIN = 2;
int trigPins[] =  {3};
int echoPins[] = {4};
int ledPins[] = {5};
float distances[total_spots];
LiquidCrystal_I2C myLCD(0x27,16,2);

///// Arduino to ESP8266 /////
StaticJsonDocument<1024> doc;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500); 
  
  pinMode(LED_BUILTIN, OUTPUT);
  setup_spot_monitoring();
  setup_Json();

  setup_lcd();
}

void loop() {
  // When we have enough physical sensors
  // for every spot, it should be:
  // spots_available = total_spots;
  spots_available = 5;
  spot_monitoring = digitalRead(monitorPIN);
  if (spot_monitoring == HIGH){
    digitalWrite(ledPins[0], HIGH);
    monitor_spots();
  }
  else{
    //turn off LEDs
    digitalWrite(ledPins[0], LOW);
  }
  
  myLCD.setCursor(0, 1);
  myLCD.print(spots_available);
  serializeJson(doc, Serial);
  flashLED();
}