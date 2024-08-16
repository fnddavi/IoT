// C++ code
//
//
int red=11;
int blu=10;
void setup()
{
	pinMode(red, OUTPUT);
  	pinMode(blu, OUTPUT);
}
void loop()
{
	digitalWrite(red, HIGH);
  	digitalWrite(blu, LOW);
	delay(500);
	digitalWrite(red, LOW);
  	digitalWrite(blu, HIGH);
	delay(500);
}