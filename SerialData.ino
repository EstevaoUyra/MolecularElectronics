#define pPin A1
#define bPin 7
#define sampledelay 100
void setup() {
  Serial.begin(9600);
  pinMode(pPin, INPUT);
  pinMode(bPin, INPUT);
}

void loop() {
  if(Serial.available()){//looks if there's a request
    Serial.read(); //throws the input away
    if(!digitalRead(bPin)) //read button
      Serial.print("1");
    else
      Serial.print("0");
    Serial.print(" ");
    Serial.println(analogRead(pPin)); //read trimpot
  }
}
