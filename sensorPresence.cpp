int led = 12;
int sensor = 7;
int sinal = 0;
int time = 500;
int time2 = 10000;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(sensor, INPUT);
  Serial.begin(9600);
}

void loop() {   
  sinal = digitalRead(sensor);
  Serial.println(sinal);
  
  if (sinal > 0) {
    digitalWrite(led, HIGH);
    delay(time2); 
  } else {
    digitalWrite(led, LOW);
    delay(time);
  }
}
