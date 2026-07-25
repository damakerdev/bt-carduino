#include <Arduino.h>
#include <Servo.h>
int ena = 3;  // PWM pin for speed control
int in1 = 5;  
int in2 = 6;  
int in3 = 7;  
int in4 = 8;  
int enb = 11;  // PWM pin for speed control
const int trigPin = 2;
const int echoPin = 10;

Servo myServo;
const int servoPin = 4;
long duration;
int distance = 0;
const int safetyDistance = 25; // Distance in cm to trigger obstacle avoidance

void forward();
void backward();
void left();
void right();
void stopCar();
int getDistance();
int lookLeft();
int lookRight();

void setup() {
  Serial.begin(9600); 

  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  myServo.attach(servoPin);
  myServo.write(90); // Look straight ahead initially
  delay(2000);       // Wait 2 seconds for the system to boot up safely
}

void loop() {
  int distanceAhead = getDistance();

  if (distanceAhead <= safetyDistance && distanceAhead > 0) {
    stopCar();
    delay(300);
    
    backward();
    delay(400);
    stopCar();
    delay(300);

    int distanceRight = lookRight();
    delay(300);
    int distanceLeft = lookLeft();
    delay(300);

    if (distanceRight >= distanceLeft) {
      right();
      delay(500); // Adjust this delay to get a perfect ~90 degree turn
    } else {
      left();
      delay(500);
    }
    stopCar();
    delay(300);
  } else {
    forward();
  }
  
  delay(50); // Small delay before scanning again
}

int getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;
  
  if (distance == 0) return 200; 
  return distance;
}

int lookRight() {
  myServo.write(10); 
  delay(500);        
  int dist = getDistance();
  myServo.write(90); 
  return dist;
}

int lookLeft() {
  myServo.write(170); 
  delay(500);
  int dist = getDistance();
  myServo.write(90);  
  return dist;
}

void forward() {
  analogWrite(ena, 180);
  analogWrite(enb, 180);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward() {
  analogWrite(ena, 180);
  analogWrite(enb, 180);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  analogWrite(ena, 180);
  analogWrite(enb, 180);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {
  analogWrite(ena, 180);
  analogWrite(enb, 180);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void stopCar() {
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}