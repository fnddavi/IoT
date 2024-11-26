#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
int pirPin = 2;
int ledPin = 13;

void setup() {
    pinMode(pirPin, INPUT);
    pinMode(ledPin, OUTPUT);
   	lcd.begin(16,2);      // Inicializa o LCD
    lcd.backlight(); // Liga a luz de fundo do LCD
}

void loop() {
    if (digitalRead(pirPin) == HIGH) {
        digitalWrite(ledPin, HIGH);  // Liga o LED se houver movimento
      	lcd.setCursor(0, 0);        // Posição inicial no LCD
        lcd.print("Presenca!");
        delay(1000);
        lcd.clear();
    } else {
        digitalWrite(ledPin, LOW);   // Desliga o LED se não houver movimento
    }
}
