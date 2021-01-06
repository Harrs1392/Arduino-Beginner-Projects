const int sensorPin = A0;
const float baselineTemp = 20.0;


void setup() {
  Serial.begin(9600); //Open serial port
  for(int pinNum = 3; pinNum < 6; ++pinNum){
    pinMode(pinNum, OUTPUT);
    digitalWrite(pinNum, LOW);
  }
}

void loop() {
  int sensorVal = analogRead(sensorPin);
  Serial.print("Sensor Value: ");
  Serial.print(sensorVal);

  //convert the ADC reading to voltage
  float voltage = (sensorVal/1024.0) * 5.0;
  Serial.print(", Volts: ");
  Serial.print(voltage);
  Serial.print(", degrees C: ");
  //convert the voltage to tempreture in deg C
  float temp = (voltage - .5) * 100;
  Serial.print(temp);
  Serial.print("\n");
  if(temp < baselineTemp + 2){
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  } else if(temp >= baselineTemp + 2 && temp < baselineTemp + 4){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
  } else if(temp >= baselineTemp + 4 && temp < baselineTemp + 6){
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
  } else if (temp >= baselineTemp +6){
    digitalWrite(3,HIGH);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
  }
  delay(1);
  
}
