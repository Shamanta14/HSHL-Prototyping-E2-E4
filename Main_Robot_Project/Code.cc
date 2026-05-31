// Digital input pin connected to IR sensor
int leftSensor = 8;
int rightSensor = 7;

// ==========================
// Function: detectTrack()
// Reads both sensors and prints
// the detected track position
// ==========================
void detectTrack() {
  // Read sensor value
  // LOW  = Black line detected
  // HIGH = White surface detected
  int leftValue = digitalRead(leftSensor);
  int rightValue = digitalRead(rightSensor);

  // Both sensors detect the black line
  if (leftValue == LOW && rightValue == LOW) {
    Serial.println("Track Centered");
  }

  // Left sensor detects the line and Right sensor sees white
  else if (leftValue == LOW && rightValue == HIGH) {
    Serial.println("Move Left");
  }

  // Right sensor detects the line and Left sensor sees white
  else if (leftValue == HIGH && rightValue == LOW) {
    Serial.println("Move Right");
  }

  // Neither sensor detects the line
  else {
    Serial.println("Track Lost");
  }
}


void setup() {
  // Configure IR sensor pins as inputs
  pinMode(leftSensor, INPUT);
  pinMode(rightSensor, INPUT);

  // Ultra sonic sensor function code



  // Motor driver function code

  
  
  // Start serial communication
  // Used to display sensor status
  Serial.begin(9600);
}

void loop() {
 // Call track detection function
  detectTrack();

  // Ultra sonic sensor function call



  // Motor driver function call

  

  // Small delay for readable output
  delay(200);
}
