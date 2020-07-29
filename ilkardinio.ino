/*
 * gungor 03/05/2018
*/

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

const int PinCLK = 2;
const int PinDT = 3; 
const int PinSW = 4; 
int sayac = 0;
int durum;
int sondurum;

void setup() {
   pinMode(PinCLK,INPUT);
   pinMode(PinDT,INPUT);  
   pinMode(PinSW,INPUT);
   Serial.begin (9600);
   sondurum = digitalRead(PinCLK);

  lcd.init(); // initialize the lcd 
 
  // Print a message to the LCD.
  lcd.backlight();
}

void loop() {
  if (digitalRead(PinSW)==LOW)
  {

 }
  durum = digitalRead(PinCLK);
  if (durum != sondurum){
    if (digitalRead(PinDT) !=durum)    {
      sayac++;
    } else {
      sayac--;
    }
    Serial.print("Sayac: ");
    Serial.println(sayac);
    lcd.clear();
    lcd.print(sayac);
  }
  sondurum = durum;
  
}
