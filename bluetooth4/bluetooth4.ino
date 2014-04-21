
int incomingByte;
int counter = 0;

void setup() 
{
Serial.begin(115200);
}

void loop() 
{
// increase counter every frame
  counter++;
// see if there’s incoming serial data:
if (Serial.available() > 0)
{
// read the oldest byte in the serial buffer:
incomingByte = Serial.read();
// if the incoming byte is equal = R reset the counter
if (incomingByte == 'r')
{
Serial.println("RESET");
counter = 0;
//digitalWrite(53, LOW);
}
}
if(counter == 100)
	{
		counter = 0;
	}
Serial.println(counter);
delay(250);
}
