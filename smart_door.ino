/*
* Ultrasonic Sensor HC-SR04 interfacing with Arduino.
*/

#include <LiquidCrystal.h>

// defining the pins
const int trigPin1 = 9;
const int echoPin1 = 8;
const int trigPin2 = 11;
const int echoPin2 = 10;

// defining variables
int count =0;
long duration1;
long duration2;
int distance1;
int distance2;
LiquidCrystal lcd (2,3,4,5,6,7);

void in()
{
    count++;
    lcd.clear();
    lcd.print("Persons Inside :");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(5000);
}

void out()
{ if(count>=1)
   {count--;}
    lcd.clear();
    lcd.print("Persons Inside :");
    lcd.setCursor(0,1);
    lcd.print(count);
    delay(5000);
}

void setup()
{
lcd.begin(16, 2);
pinMode(trigPin1, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin1, INPUT); // Sets the echoPin as an Input

pinMode(trigPin2, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin2, INPUT); // Sets the echoPin as an Input

  lcd.clear();
  lcd.print("    ARDUINIO   ");
  lcd.setCursor(0,1);
  lcd.print("    PROJECT    ");
  delay(5000);
  lcd.clear();
  lcd.print("   Smart Door");
  lcd.setCursor(0,1);
  lcd.print("  Bi-Direction");
  delay(5000);
  lcd.clear();
  lcd.print("By TE-IT Student");
  lcd.setCursor(0,1);
  lcd.print("  Group No - 7 ");
  delay(5000);
  lcd.setCursor(0,1);
  lcd.clear();
  lcd.print(" Kate Jay Vilas");
}

void loop() {
//For first (Enter) Ultrasonic sensor
// Clears the trigPin
digitalWrite(trigPin1, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin1, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin1, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration1 = pulseIn(echoPin1, HIGH);
// Calculating the distance
distance1= duration1 *0.034/2;

if (distance1 <= 150){
   in();
   }   
 else {
  //Serial.println("off");   not needed.
  }


//For second (Exit) Ultrasonic sensor
digitalWrite(trigPin2, LOW);
delayMicroseconds(2);
// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin2, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin2, LOW);
// Reads the echoPin, returns the sound wave travel time in microseconds
duration2 = pulseIn(echoPin2, HIGH);
// Calculating the distance
distance2= duration2 *0.034/2;

if (distance2 <= 150){
   out();
   }
   
else {
  //Serial.println("off");   not needed.
     }

}
