// C++ code
//
//
int red=11;
int ylw=10;
int grn=7;
void setup()
{
	pinMode(red, OUTPUT);
  	pinMode(ylw, OUTPUT);
  	pinMode(grn, OUTPUT);
  
}
void loop()
{
	digitalWrite(red, HIGH);
  	digitalWrite(ylw, LOW);
  	digitalWrite(grn, LOW);
	delay(3000);
	digitalWrite(red, LOW);
  	digitalWrite(ylw, LOW);
  	digitalWrite(grn, HIGH);
	delay(3000);
  	digitalWrite(red, LOW);
  	digitalWrite(ylw, HIGH);
  	digitalWrite(grn, LOW);
	delay(500);
}