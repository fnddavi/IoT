// Usando o Arduino ONE apresentar a mensagem "Ola Mundo!" no monitor serial

void setup()
{
    Serial.begin(9600);
}
void loop()
{
    Serial.println("Ola Mundo!");
}