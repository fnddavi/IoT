int red = 11;
int ylw = 10;
int grn = 7;
int button = 2;
unsigned long extraTime = 0; // Tempo adicional para o LED vermelho

void setup()
{
    pinMode(red, OUTPUT);
    pinMode(ylw, OUTPUT);
    pinMode(grn, OUTPUT);
    pinMode(button, INPUT);
}

void loop()
{
    // Verifica se o botão foi pressionado
    if (digitalRead(button) == HIGH)
    {
        extraTime += 10000; // Adiciona 5 segundos ao tempo extra
        delay(50);          // Debounce para evitar múltiplas leituras
    }

    // Ciclo do semáforo
    digitalWrite(red, HIGH);
    digitalWrite(ylw, LOW);
    digitalWrite(grn, LOW);
    delay(2000 + extraTime); // Aplica o tempo adicional

    digitalWrite(red, LOW);
    digitalWrite(ylw, LOW);
    digitalWrite(grn, HIGH);
    delay(2000);
    digitalWrite(grn, LOW);
    digitalWrite(ylw, HIGH);
    delay(1000);
    digitalWrite(ylw, LOW);

    // Reseta o tempo adicional para o próximo ciclo
    extraTime = 0;
}
