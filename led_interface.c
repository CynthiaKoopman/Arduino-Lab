#LED interface Arduino
int temperature;
void setup () { // use pins 11, 12 and 13 for the LEDs
Serial . begin (9600) ;
pinMode(13, OUTPUT);
pinMode(12, OUTPUT);
pinMode(11, OUTPUT);

}
void loop () { // conditions for LED on high or low according to temperature
if (Serial.available()>0)
  temperature = Serial.read();
if (temperature < 20)
  {	digitalWrite(13, HIGH);
  	digitalWrite(12, LOW);
  	digitalWrite(11, LOW);
  }
  else if (20 < temperature < 25)
   {	digitalWrite(12, HIGH);
 	digitalWrite(13, LOW);
  	digitalWrite(11, LOW);}
  else 
  {	digitalWrite(11, HIGH);
  	digitalWrite(13, LOW);
  	digitalWrite(12, LOW);}
delay(500);
}
