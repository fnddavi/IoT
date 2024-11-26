#include <LiquidCrystal.h>
#define TEMPO_ATUALIZACAO 500

LiquidCrystal lcd_1(12, 11, 5, 4, 3, 2);
const int sensorPin = 8;
const int lcdPin = 7;
String nome = "Movimento Detectado !";
int inicio = 0, tamanho = 1;
boolean alterar = false;

void setup()
{
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  pinMode(lcdPin, OUTPUT);
}
	
void loop()
{
	int sensorValue = digitalRead(sensorPin);
  	if (sensorValue == HIGH) {
      	lcd_1.clear();
      	if (tamanho < 16)
		{
			lcd_1.setCursor(16 - tamanho, 0);
			lcd_1.print(nome.substring(inicio, tamanho));
			tamanho++;
		}
      	else
		{
			if (!alterar)
			{
				alterar = !alterar;
				tamanho = 16;
				lcd_1.setCursor(0, 0);
			}
			lcd_1.print(nome.substring(inicio, inicio + tamanho)); inicio++;
		}

		if (inicio > nome.length())
		{
			inicio = 0;
			tamanho = 1;
			alterar = !alterar;
		}
		delay(TEMPO_ATUALIZACAO);
	}
}