#include <SoftwareSerial.h> 
/*
Setup.
Upload this to board without the modem attached
-Make sure the baud rate is 115200 as that is what the bluetooth is (and serial port)
*/
int GRND = 2;
int VCC = 4;
int bluetoothTx = 3;  // TX-O pin of bluetooth mate, Arduino D2
int bluetoothRx = 2;
SoftwareSerial bluetooth(bluetoothTx, bluetoothRx);
int counter = 0;
int incomingByte;

void setup() {
  Serial.begin(9600);
  pinMode(bluetoothTx, OUTPUT);
  pinMode(bluetoothRx, INPUT);
  digitalWrite(GRND, LOW);
  digitalWrite(VCC, HIGH);
}

void loop() {
  // see if there's incoming serial data:
  
  //Read from usb serial to bluetooth
if(Serial.available())
{
char toSend = (char)Serial.read();
bluetooth.write(toSend);
if (incomingByte == 'R') {
      Serial.println("RESET");
      counter=0;
    }
}
 
  //only count to 100 then stop aka don't count to infinity
  //if(counter<100){
  Serial.println(counter); //displays the ACSII number/letter
  //Serial.write(counter); //writes the data AS IS
  counter++;
  delay(250);
  }


