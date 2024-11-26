//C++ code

#include <Servo.h>

const int botao = 2;
const int pinoServo = 3;

Servo cancela_estacionamento; 

void setup() {
  pinMode(botao, INPUT);
  cancela_estacionamento.attach(pinoServo, 500, 2500);
  cancela_estacionamento.write(90);
}

void loop() {
  int estadoBotao = digitalRead(botao);
  if (estadoBotao == HIGH) {
    cancela_estacionamento.write(0);
    delay(2000);
    cancela_estacionamento.write(90);
    while (digitalRead(botao) == HIGH) {
      // Aguardar até o botão ser solto
    }
  }
}
