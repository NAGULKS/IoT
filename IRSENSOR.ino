const int irSensorPin = 2;   // IR sensor connected to digital pin 2
const int ldrSensorPin = A0; // LDR sensor connected to analog pin A0
const int ledPin = 5;       // LED connected to digital pin 13

void setup() {
  pinMode(irSensorPin, INPUT); // Set IR sensor pin as input
  pinMode(ldrSensorPin, INPUT); // Set LDR sensor pin as input
  pinMode(ledPin, OUTPUT);     // Set LED pin as output
  digitalWrite(ledPin, LOW);  // Turn off the LED initially
  Serial.begin(9600);          // Initialize serial communication
}

void loop() {
  // Read values from the IR and LDR sensors
  int irSensorValue = digitalRead(irSensorPin);
  int ldrSensorValue = analogRead(ldrSensorPin);

  // Check if both conditions are met (you can adjust these thresholds)
  if (irSensorValue == LOW && ldrSensorValue > 500) {
    digitalWrite(ledPin, HIGH); // Turn on the LED
    Serial.println("Both sensors detected conditions.");
  } 
  else {
    digitalWrite(ledPin, LOW); // Turn off the LED
  }

  // Print sensor readings to the serial monitor
  Serial.print("IR Sensor Value: ");
  Serial.println(irSensorValue);
  Serial.print("LDR Sensor Value: ");
  Serial.println(ldrSensorValue);

  delay(1000); // Delay for 10 second (adjust as needed)
}