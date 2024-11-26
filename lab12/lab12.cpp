//c++ code

// definindo as portas
int transistorPin = 2;
int potenciometroPin = A1;

// função setup
void setup() {
  Serial.begin(9600);
  pinMode(transistorPin, OUTPUT);
  pinMode(potenciometroPin, INPUT);
}
// função loop
void loop() {
  int valorPotenciometro = analogRead(potenciometroPin);
  int valorTransistor = map(valorPotenciometro, 0, 1023, 0, 255);
  
  analogWrite(transistorPin, valorTransistor);
  Serial.println(valorTransistor);
  delay(100);
}
