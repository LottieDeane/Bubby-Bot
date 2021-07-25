//pin A7 is used for the reading of the voltage of LDR 1 (v_L1)
//pin A6 is used for the reading og the voltage of LDR 2 (v_L2)
//pin A5 is used for the reading og the voltage of LDR 3 (v_L3)
//

#include <Arduino.h>

int spee = 200;
int v_L1;
int v_L2;
int v_L3;
float v_L1c; 
float v_L2c;
float v_L3c;
float difference; 
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); // setting up the serial monitor 
  
  // IN 1 - A2
  // IN 2 - A5
  // IN 3 - A1
  // IN 4 - A4
  pinMode(A4, OUTPUT);
  pinMode(A5, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A1, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Hello world");
  v_L1 = analogRead(A7); //getting the potential difference across LDR 1
  v_L2 = analogRead(A6); //getting the potential difference across LDR 2
  v_L1c = (v_L1 * (5.0/1023.0)); 
  v_L2c = (v_L2 * (5.0/1023.0)) +0.5 ; 
  Serial.print("Resistor 1 "); Serial.println(v_L1c);
  Serial.print("Resistor 2 "); Serial.println(v_L2c);
  delay(500);
  difference = v_L2c - v_L1c;
  Serial.println(difference);
  if (difference > 0.12)
  {
    Serial.println("Turn right");
   analogWrite(A4, 0);   // turn the LED on (HIGH is the voltage level)
  analogWrite(A5, spee); 
  analogWrite(A2, 0); 
  analogWrite(A1, 0); // turn the LED off by making the voltage LOWLOW
  }
  else if (difference < - 0.12)
  {
    Serial.println("Turn left");
                       // wait for a second
   analogWrite(A4, spee);   // turn the LED on (HIGH is the voltage level)
  analogWrite(A5, 0); 
  analogWrite(A2, 0); 
  analogWrite(A1, 0); // turn the LED off by making the voltage LOW
  }
  else if (-0.12 < difference && difference < 0.12)
  {
    Serial.println("Perfect");
   analogWrite(A4, 0);   // turn the LED on (HIGH is the voltage level)
  analogWrite(A5, 0); 
  analogWrite(A2, 0); 
  analogWrite(A1, 0); // turn the LED off by making the voltage LOW
  }
  else
  {
    Serial.println("AAAAAA I DON't KNOW WHAT IS HAPPENING REEEEEEEEEEEE");
  }
 
}
