void setup_spot_monitoring(){
  for (int pin: trigPins)
    pinMode(pin, OUTPUT);
  for (int pin: echoPins)
    pinMode(pin, INPUT);
  for (int pin: ledPins){
    pinMode(pin, OUTPUT);
    digitalWrite(pin, HIGH);
  }
  myLCD.begin(16, 2);   // Set up the number of columns and rows on the LCD
  myLCD.print("Open Spaces:");
  pinMode(monitorPIN, INPUT);
  
}

void setup_Json(){
  doc["spaces"] = 0;
  doc["red"] = 42;
  doc["green"] = 69;
  doc["blue"] = 13;
}

float get_dist(int trigPin, int echoPin){
  float dist = 0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  dist = (pulseIn(echoPin, HIGH)/1000000.0)*343/2;
  
  return dist;
}

void monitor_spots(){
  // Get Distances
  for (int i = 0; i<total_spots; i+=1){
    distances[i] = get_dist(trigPins[i], echoPins[i]);
    if (distances[i] < openSpaceDist){
    	spots_available -= 1;
  	}
  }
  doc["spaces"] = spots_available;
}

void flashLED(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}