#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial BTSerial(2, 4); 

int ena = 3;
int in1 = 5;  
int in2 = 6;  
int in3 = 7;  
int in4 = 8;  
int enb = 11;

char command;

void forward();
void backward();
void left();
void right();
void stopCar();
void handleCommand(char cmd);

void setup() {
  Serial.begin(9600);   
  BTSerial.begin(9600); 
  pinMode(ena, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(enb, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  stopCar(); 
}

void loop() {
  if (BTSerial.available()) {
    command = BTSerial.read();
    while (BTSerial.available() > 0) {
      char extra = BTSerial.peek();
      if (extra == '\r' || extra == '\n' || extra == ' ') {
        BTSerial.read();
      } else {
        break;
      }
    }
    handleCommand(command);
  }
}

void handleCommand(char cmd) {
  switch (cmd) {
    case 'F': forward(); break;
    case 'B': backward(); break;
    case 'L': left(); break;
    case 'R': right(); break;
    case 'S': stopCar(); break;
    default: break; 
  }
}

void forward() {
  analogWrite(ena, 160); 
  analogWrite(enb, 160);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void backward() {
  analogWrite(ena, 160);
  analogWrite(enb, 160);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
}

void left() {
  analogWrite(ena, 160);
  analogWrite(enb, 160);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
}

void right() {
  analogWrite(ena, 160);
  analogWrite(enb, 160);
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