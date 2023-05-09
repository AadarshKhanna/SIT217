#include <Wire.h> 
#include <LiquidCrystal_I2C.h> // We will include the library for I2C LCD
LiquidCrystal_I2C lcd(0x27, 16, 2); // initialize the LCD with I2C address 0x27, 16 columns and 2 rows

char i;

void setup() {
  pinMode(13, OUTPUT);   // It will move the left motors forward
  pinMode(12, OUTPUT);   // It will move the left motors reverse
  pinMode(11, OUTPUT);   // It will move the right motors forward
  pinMode(10, OUTPUT);   // It will move the right motors reverse
  pinMode(9, OUTPUT);    // It would be used for led
  Serial.begin(9600);
  lcd.init();            // It will be used to initialize the LCD
  lcd.backlight();       // It will turn the backlight of the LCD
  lcd.setCursor(0, 0);   // It will set the cursor to the top left corner
  lcd.print("Arduino Car"); // It will print the name of the car on the LCD
}

void loop() {
  if (Serial.available()) {
    i = Serial.read();
    Serial.println(i);
    lcd.setCursor(0, 1); // set the cursor to the second row
    switch (i) {
      case 'F': //For moving forward
        lcd.print("Forward");
        digitalWrite(13, HIGH);
        digitalWrite(11, HIGH);
        break;
      case 'B': //For moving backward
        lcd.print("Backward");
        digitalWrite(12, HIGH);
        digitalWrite(10, HIGH);
        break;
      case 'L': // For turning right
        lcd.print("Right");
        digitalWrite(11, HIGH);
        break;
      case 'R': // For turning left
        lcd.print("Left");
        digitalWrite(13, HIGH);
        break;
      case 'W': //It will turn the led on
        lcd.print("Led On");
        digitalWrite(9, HIGH);
        break;
      case 'w': // To turn led off
        lcd.print("Led Off");
        digitalWrite(9, LOW);
        break;
      case 'S': // It will make the car stop
        lcd.print("Stop");
        digitalWrite(13, LOW);
        digitalWrite(12, LOW);
        digitalWrite(11, LOW);
        digitalWrite(10, LOW);
        break;
    }
  }
  delay(100);
}