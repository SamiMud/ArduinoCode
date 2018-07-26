const int trigPin = 9;
const int echoPin = 10;
const int redPin = 12;
const int bluePin = 13;
const int redtwoPin = 7;
const int bluetwoPin = 8;
const int buzzerPin = 6; // NOTE: Buzzer didn't make it into my final product but is in the code if you want to add it in.

long duration;
int distance;
int safetyDistance;

void setup() {
  // put your setup code here, to run once:
pinMode(trigPin, OUTPUT); 
pinMode(echoPin, INPUT); 
pinMode(buzzerPin, OUTPUT);
pinMode(redPin, OUTPUT);
pinMode(bluePin, OUTPUT);
pinMode(redtwoPin, OUTPUT);
pinMode(bluetwoPin, OUTPUT);
Serial.begin(9600); 
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

duration = pulseIn(echoPin, HIGH);

distance= duration*0.034/2;

safetyDistance = distance; 
float beep = safetyDistance*10;
if (safetyDistance <= 100) {
  digitalWrite(redPin, HIGH);
  digitalWrite(bluetwoPin, HIGH);
  digitalWrite(buzzerPin, HIGH);
  delay(beep);
  digitalWrite(redPin, LOW);
  digitalWrite(bluetwoPin, LOW);
  digitalWrite(bluePin, HIGH);
  digitalWrite(redtwoPin, HIGH);
  digitalWrite(buzzerPin, LOW);
  delay(beep);
  digitalWrite(bluePin, LOW);
  digitalWrite(redtwoPin, LOW);
}
else 
  digitalWrite(redPin, LOW);
  digitalWrite(bluePin, LOW);
  digitalWrite(bluetwoPin, LOW);
  digitalWrite(redtwoPin, LOW);
  digitalWrite(buzzerPin, LOW);
}
