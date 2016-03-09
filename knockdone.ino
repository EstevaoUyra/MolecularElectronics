// these constants won't change:
const int ledPin = 13;      // led connected to digital pin 13
const int knockSensor = A0; // the piezo is connected to analog pin 0
const int threshold = 1;  // threshold value to decide when the detected sound is a knock or not


// these variables will change:
int sensorReading = 0;      // variable to store the value read from the sensor pin
bool flag = false;

void setup() {
  Serial.begin(9600);       // use the serial port
}

void loop() {
  // read the sensor and store it in the variable sensorReading:
  sensorReading = analogRead(knockSensor);
  //Serial.println(sensorReading);
  // if the sensor reading is greater than the threshold:
  if (sensorReading >= threshold) {
    sensorReading = analogRead(knockSensor);
    delay(500);
    int start = millis();
    long delta = 0;
    while(delta<500){
      sensorReading = analogRead(knockSensor);
      if(sensorReading >= threshold){
        Serial.println("B");
        flag = true;
        break;
      }
      delta = millis() - start;
    }
    if(!flag)
      Serial.println("A");
    
  }
  delay(1000);
  flag = false;
}
