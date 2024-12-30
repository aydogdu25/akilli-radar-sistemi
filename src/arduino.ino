#include <Servo.h>

#define TRIG_PIN 2
#define ECHO_PIN 3

Servo myServo;
int duration;
int distance;

void setup() {
  Serial.begin(9600); 
  myServo.attach(9);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
}

void loop() {
  for (int angle = 0; angle <= 180; angle+=5) {
    myServo.write(angle);
    delay(10);
    distance = measureDistance();
    if (distance >= 0)
    {
      sendNodemcu(distance, angle);
    }
    delay(100); 
  }

  for (int angle = 180; angle >= 0; angle-=5) {
    myServo.write(angle);
    delay(10);
    distance = measureDistance();
    if (distance >= 0)
    {
      sendNodemcu(distance, angle);
    }
    delay(100); 
  }
}

float measureDistance() {
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  return (duration * 0.034) / 2;
}

void sendNodemcu(int distance, int angle) {
  Serial.print(distance);
  Serial.print(",");
  Serial.println(angle);
}
