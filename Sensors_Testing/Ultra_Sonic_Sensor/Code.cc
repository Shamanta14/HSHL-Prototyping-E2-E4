// ================================
// Ultrasonic Sensor Obstacle Detection
// ================================

// Arduino UNO + 2 HC-SR04 Sensors
// Battery powered system with Slide switch
// Both sensor collectively work together to detect an obstacle


// Ultra Sonic Sensor 1
const int trig1 = 11;
const int echo1 = 10;

// Ultra Sonic Sensor 2
const int trig2 = 5;
const int echo2 = 4;

// ================================
// Detection Threshold
// ================================
// Any object at or below this distance
// will be considered detected
const int threshold = 20;

void setup() {

  // Start serial monitor communication
  Serial.begin(9600);


  // Sensor 1 Configuration
  pinMode(trig1, OUTPUT);
  pinMode(echo1, INPUT);


  // Sensor 2 Configuration
  pinMode(trig2, OUTPUT);
  pinMode(echo2, INPUT);
}

// ================================
// FUNCTION: readDistance()
// ================================
// Reads distance from the HC-SR04 ultrasonic sensor
int readDistance(int trigPin, int echoPin) {

  // Clear trigger pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);

  // Send 10 microsecond pulse
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read time taken for echo to return
  long duration = pulseIn(echoPin, HIGH);

  // Convert time into distance (cm)
  int distance = duration * 0.034 / 2;

  // Return calculated distance
  return distance;
}

void loop() {
  // Read distance from Sensor 1
  int distance1 = readDistance(trig1, echo1);

  // Read distance from Sensor 2
  int distance2 = readDistance(trig2, echo2);
  
  // =====================================
  // DISPLAY SENSOR VALUES
  // =====================================
  // Sensor 1
  Serial.print("Sensor 1 Distance: ");
  Serial.print(distance1);
  Serial.println(" cm");

  // Sensor 2
  Serial.print("Sensor 2 Distance: ");
  Serial.print(distance2);
  Serial.println(" cm");

  // =====================================
  // OBSTACLE DETECTION LOGIC
  // =====================================
  // If ANY sensor detects an object
  // at or below threshold distance,
  // display "Detected"
  if (distance1 <= threshold || distance2 <= threshold) {
    Serial.println("Detected");
  }

  // If BOTH sensors are above threshold,
  // display "Not Detected"
  else {
    Serial.println("Not Detected");
  }

  // Divider line for readability
  Serial.println("------------------------");

  // Small delay before next reading
  delay(500);
}
