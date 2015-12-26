#include <LiquidCrystal.h>

#define ROW 2
#define COL 16

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);           // select the pins used on the LCD panel

String ip;

void setup(){
  Serial.begin(9600);
  lcd.begin(COL, ROW);               // start the library
  lcd.setCursor(0,0);             // set the LCD cursor   position 
  lcd.print("IPv4 ADDRESS");
  lcd.setCursor(0,1);  
}

void loop() {
  if (Serial.available()) {
    ip = Serial.readString();
  }
  lcd.print(ip);
  delay(2000);
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);
}
