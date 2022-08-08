//Prateek
//www.prateeks.in

#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 8, 7);

int ir_pin = 5;
int counter = 0;
int hitObject = false;

void setup() {
  Serial.begin(9600);
  pinMode(ir_pin, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("  WelCome To");
  lcd.setCursor(0, 1);
  lcd.print(" Our Projects");
  delay(3000);
  lcd.clear();
}

void loop() {

  int val = digitalRead(ir_pin);

  if ( (val == 0) && (hitObject == false) ) {
    counter++;
    hitObject = true;
    Serial.print("Counter = ");
    Serial.println( counter);
    lcd.setCursor(1, 1);
    lcd.print("Counter =");
    lcd.setCursor(11, 1);
    lcd.print(counter);
  } else if ( (val == 1) && (hitObject == true) ) {
    hitObject = false;
  }
}
