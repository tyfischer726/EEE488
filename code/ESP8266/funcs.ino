void setup_spot_monitoring(){
  spots_available = 0;
  spot_monitoring = false;
  pinMode(monitorPIN, OUTPUT);
  digitalWrite(monitorPIN, LOW);
}

void updateSpotMonitoring(){
  if (spot_monitoring){
    digitalWrite(monitorPIN, HIGH);
  }
  else{
    digitalWrite(monitorPIN, LOW);
  }
}

void updateData(){
  spots_available = doc["spaces"];
  red = doc["red"];
  green = doc["green"];
  blue = doc["blue"];
}

void printData(){
  Serial.print("Spots available: ");
  Serial.println(spots_available);
}

void flashLED(){
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
}