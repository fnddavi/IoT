// C++ code
//
// Com Arduino UNO Montar:
//• Alerta de Presença
//• Gerar uma mensagem na serial e piscar LED se detectado presença
//• Sensor PIR

// Definindo as portas e constantes
const int sensorPin = 2;    // Porta onde o sensor PIR está conectado
const int ledPin = 5;      // Porta onde o LED está conectado

// Função para inicializar o código
void setup() {
  Serial.begin(9600);       // Inicia a comunicação serial
  pinMode(sensorPin, INPUT); // Define a porta do sensor como entrada
  pinMode(ledPin, OUTPUT);  // Define a porta do LED como saída
}

// Função para executar repetidamente
void loop() {
  // Leitura do valor digital do sensor PIR
  int sensorValue = digitalRead(sensorPin);

  // Verifica se o sensor detectou presença
  if (sensorValue == HIGH) {
    // Imprime mensagem na serial
    Serial.println("Presenca detectada!");

    // Acende o LED
    digitalWrite(ledPin, HIGH);

    // Aguarda 1 segundo
    delay(1000);

    // Apaga o LED
    digitalWrite(ledPin, LOW);
  }
}
