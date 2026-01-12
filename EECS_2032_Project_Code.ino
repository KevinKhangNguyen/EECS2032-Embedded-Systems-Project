/* EECS 2032 Final Project 
 * By Kevin Nguyen, 217228255
 * This code will measure distance and turns on the fan and LEDs depending on the distance of the object.
 */

// includes the LiquidCrystal Library
#include <LiquidCrystal.h> 

// Creates an LCD object. Parameters: (rs, enable, d4, d5, d6, d7)
LiquidCrystal lcd(5, 4, 3, 2, 1, 0); 

const int trigPin = 12;
const int echoPin = 13;
long duration;
int distance;
int motorPin = 11;

void setup() 
{
  //LCD display
  lcd.begin(16,2); // Initializes the interface to the LCD screen

  //HC-SR04 Ultrasonic Sensor
  pinMode(trigPin, OUTPUT); // trigPin is OUTPUT
  pinMode(echoPin, INPUT);  // echoPin is INPUT

  //DC motor
  pinMode(motorPin, OUTPUT);// motorPin is OUTPUT
  
  //LEDs
  for (int i = 6; i <= 10; i++) 
  {
    pinMode(i, OUTPUT);    // // LEDs pin is OUTPUT
  }
}

void loop() 
{ 
  // Write a pulse to the HC-SR04 Trigger Pin
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  // Measure the response from the HC-SR04 Echo Pin
  duration = pulseIn(echoPin, HIGH);
  
  // Determine distance from duration
  // Use 343 m/s as speed of sound
  distance= duration*0.034/2;
  
  // Prints "Target Distance: " on the first line of the LCD 
  // Set cursor to first column of first row
  lcd.setCursor(0,0);
  lcd.print("Target Distance: ");
  //Print blanks on the second line of the LCD to clear the line 
  // Set cursor to first column of second row
  lcd.setCursor(0,1);
  lcd.print("                "); // to clear the distance value
  // Prints "<value>" on the second line of the LCD
  // Set cursor to first column of second row
  lcd.setCursor(0,1);
  lcd.print(distance);
  lcd.print(" cm");
  delay(800);       // longer delay would cause less flickering

  //For DC motor
  if (distance <= 15){   // Turn DC motor on if distance is 15cm or less
    digitalWrite(motorPin, HIGH);
  }
  else{
    digitalWrite(motorPin, LOW);
  }

  // For LED
  if (distance <= 5) {   //Turn LED on if distance is 5cm or less
    digitalWrite(6, LOW);
  }
  else{
    digitalWrite(6, HIGH);
  }
  
  if (distance <= 10) {  //Turn LED on if distance is 10cm or less
    digitalWrite(7, LOW);
  }
  else{
    digitalWrite(7, HIGH);
  }
  
  if (distance <= 15) {  //Turn LED on if distance is 15cm or less
    digitalWrite(8, LOW);
  }
  else{
    digitalWrite(8, HIGH);
  }
  
  if (distance <= 20) {  //Turn LED on if distance is 20cm or less
    digitalWrite(9, LOW);
  }
  else{
    digitalWrite(9, HIGH);
  }

  if (distance <= 25) {  //Turn LED on if distance is 25cm or less
    digitalWrite(10, LOW);
  }
  else{
    digitalWrite(10, HIGH);
  }
}
