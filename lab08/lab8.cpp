// Definindo as portas e constantes
const int sensorPin = A0;    // Porta onde o sensor de temperatura está conectado
const int buzzerPin = A2;    // Porta onde o buzzer (piezo) está conectado

// Ajuste as constantes de calibração conforme necessário
const float voltageAtZeroC = 0.5; // Tensão no sensor a 0°C (ajuste conforme necessário)
const float temperaturePerVolt = 100.0; // Fator de conversão (ajuste conforme necessário)

// Temperaturas de referência para o alarme
const float baselineTemp = 30.0;  // Temperatura para gerar mensagem na serial
const float alarmTemp = 90.0;     // Temperatura para tocar o alarme

void setup() {
  Serial.begin(9600);       // Inicia a comunicação serial
  pinMode(sensorPin, INPUT); // Define a porta do sensor como entrada
  pinMode(buzzerPin, OUTPUT);// Define a porta do buzzer como saída
}

void loop() {
  // Leitura do valor analógico do sensor de temperatura
  int sensorValue = analogRead(sensorPin);

  // Converte o valor lido para tensão (assumindo 5V de referência)
  float voltage = sensorValue * (5.0 / 1023.0);

  // Ajuste a fórmula de conversão para o sensor usado
  float temperature = (voltage - voltageAtZeroC) * temperaturePerVolt;

  // Verifica se a temperatura é maior que 30°C e imprime mensagem na serial
  if (temperature > baselineTemp) {
    Serial.print("Temperatura: ");
    Serial.print(temperature);
    Serial.println(" °C");
  }

  // Verifica se a temperatura é maior que 90°C e ativa o alarme
  if (temperature > alarmTemp) {
    tone(buzzerPin, 1000);  // Toca o buzzer a 1000Hz
  } else {
    noTone(buzzerPin);      // Desativa o buzzer
  }

  delay(1000); // Aguarda 1 segundo antes de repetir a leitura
}
