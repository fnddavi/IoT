// C++ code
//
const int ldrPin = 2;  // Pino onde o LDR está conectado
const int ledPin = 13; // Pino do LED (usando o LED interno do Arduino)

void setup()
{
    pinMode(ldrPin, INPUT);  // Define o pino do LDR como entrada
    pinMode(ledPin, OUTPUT); // Define o pino do LED como saída
    Serial.begin(9600);      // Inicializa a comunicação serial para monitorar os valores lidos
}

void loop()
{
    int ldrValue = digitalRead(ldrPin); // Lê o valor do LDR (0 ou 1)

    // Imprime o valor lido no monitor serial
    Serial.println(ldrValue);

    // Verifica se o valor lido indica baixa luminosidade
    if (ldrValue == LOW)
    {
        digitalWrite(ledPin, HIGH); // Acende o LED
    }
    else
    {
        digitalWrite(ledPin, LOW); // Apaga o LED
    }

    delay(100); // Pequeno atraso para estabilizar a leitura
}
