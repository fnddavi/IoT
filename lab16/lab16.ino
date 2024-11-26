#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd1(0x20, 16, 2); 
LiquidCrystal_I2C lcd2(0x21, 16, 2);

int pir = 10; 
int led = 2;  

void setup() {
  pinMode(pir, INPUT);
  pinMode(led, OUTPUT);

  Serial.begin(9600); 

  lcd1.init();
  lcd1.backlight(); 
  lcd2.init();
  lcd2.backlight(); 
}

void loop() {
  int pirState = digitalRead(pir);

  if (pirState == HIGH) {  
    Serial.println("Movimento detectado!");  
    digitalWrite(led, HIGH);

    lcd1.clear();
    lcd1.setCursor(0, 0);
    lcd1.print("Detectado!");

    lcd2.clear();
    lcd2.setCursor(0, 0);
    lcd2.print("Detectado!");

    delay(500);  
    digitalWrite(led, LOW);  
    delay(500);  
  } else {
    digitalWrite(led, LOW);
  }
}
