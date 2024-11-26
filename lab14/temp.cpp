// #include <Wire.h> // lib para I2C (usar essa linha na simulação)
#include <LiquidCrystal_I2C.h>

// Inicializa o LCD no endereço 0x27 com 16 colunas e 2 linhas
LiquidCrystal_I2C lcd(0x27, 16, 2);

int pirPin = 2;  // Pino do sensor PIR
int ledPin = 13; // Pino do LED

void setup()
{
    pinMode(pirPin, INPUT);  // Configura o pino do PIR como entrada
    pinMode(ledPin, OUTPUT); // Configura o pino do LED como saída

    lcd.init();      // Inicializa o LCD
    lcd.backlight(); // Liga a luz de fundo do LCD
}

void loop()
{
    if (digitalRead(pirPin) == HIGH)
    {                               // Se o PIR detectar movimento
        digitalWrite(ledPin, HIGH); // Liga o LED
        lcd.setCursor(0, 0);        // Posição inicial no LCD
        lcd.print("Presenca!");
        delay(1000);
        lcd.clear();
    }
    else
    {
        digitalWrite(ledPin, LOW); // Desliga o LED se não houver movimento
        lcd.setCursor(0, 0);       // Posição inicial no LCD*/
        lcd.print("Aguardando ");
        delay(1000);
        lcd.clear(); // Exibe a mensagem de aguardando
    }

    delay(500); // Pequeno atraso para estabilidade
}
