//C++ CODE
//

const int transistorPin = 2;
const int botaoPin = A1;

void setup() {
  Serial.begin(9600);
  pinMode(transistorPin, OUTPUT);
  pinMode(botaoPin, INPUT);
}

void loop() {
  int estadoBotao = digitalRead(botaoPin);

  if (estadoBotao == HIGH) {
    digitalWrite(transistorPin, HIGH);
    Serial.println("Botão pressionado");
  } else {
    digitalWrite(transistorPin, LOW);
    Serial.println("Botão não pressionado");
  }
}
