const int leftSensor = 8;
const int rightSensor = 7;

// =========================
// L298N PINS
// =========================
const int ENA = 6;
const int IN1 = 3;
const int IN2 = 2;
const int ENB = 5;
const int IN3 = 12;
const int IN4 = 13;

// =========================
// SPEED SETTINGS
// =========================
const int forwardSpeed = 180;
const int turnSpeed = 165;
const int slowSpeed = 20;
const int searchSpeed = 90;

// 0 = straight
// 1 = left
// 2 = right
int lastDirection = 0;

void setup() {
  // Increase PWM frequency on D5 and D6
  TCCR0B = TCCR0B & B11111000 | B00000010;
  
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  Serial.begin(9600);
  stopMotors();
}

// =========================
// MOTOR FUNCTIONS
// =========================
void moveForward() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, forwardSpeed);
  analogWrite(ENB, forwardSpeed);
}

void turnLeft() {
  // Left wheel slower
  // Right wheel faster
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, slowSpeed);
  analogWrite(ENA, turnSpeed);
}

void turnRight() {
  // Left wheel faster
  // Right wheel slower
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENB, turnSpeed);
  analogWrite(ENA, slowSpeed);
}

void searchLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, searchSpeed);
  analogWrite(ENB, searchSpeed);
}

void searchRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, searchSpeed);
  analogWrite(ENB, searchSpeed);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
}

// =========================
// MAIN LOOP
// =========================
void loop() {
  int L = digitalRead(leftSensor);
  int R = digitalRead(rightSensor);
  
  Serial.print("Left = ");
  Serial.print(L);
  Serial.print(" | Right = ");
  Serial.println(R);
  
  // ===================================
  // SENSOR LOGIC
  // ===================================
  // Black line = 1
  // White area = 0
  // L = 0, R = 0 -> Forward
  // L = 1, R = 0 -> Turn Left
  // L = 0, R = 1 -> Turn Right
  // L = 1, R = 1 -> Search last direction
  
  if (L == 1 && R == 1) {
    moveForward();
    Serial.println("Forward");
  } 
  else if (L == 1 && R == 0) {
    turnLeft();
    lastDirection = 1;
    Serial.println("Turn Left");
  } 
  else if (L == 0 && R == 1) {
    turnRight();
    lastDirection = 2;
    Serial.println("Turn Right");
  } 
  else if (L == 1 && R == 1) {
    if (lastDirection == 1) {
      searchLeft();
      Serial.println("Search Left");
    } 
    else if (lastDirection == 2) {
      searchRight();
      Serial.println("Search Right");
    } 
    else {
      moveForward();
      Serial.println("Search Forward");
    }
  }
  
  delay(10);
}
