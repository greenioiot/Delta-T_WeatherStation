/*
  Software serial multple serial test

  Receives from the hardware serial, sends to software serial.
  Receives from software serial, sends to hardware serial.

  The circuit:
   RX is digital pin 10 (connect to TX of other device)
   TX is digital pin 11 (connect to RX of other device)

  Note:
  Not all pins on the Mega and Mega 2560 support change interrupts,
  so only the following can be used for RX:
  10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69

  Not all pins on the Leonardo and Micro support change interrupts,
  so only the following can be used for RX:
  8, 9, 10, 11, 14 (MISO), 15 (SCK), 16 (MOSI).

  created back in the mists of time
  modified 25 May 2012
  by Tom Igoe
  based on Mikal Hart's example

  This example code is in the public domain.

*/
HardwareSerial mySerial(2);
#define SERIAL1_RXPIN 26
#define SERIAL1_TXPIN 25


//SoftwareSerial mySerial(8, 9); // RX, TX
//#define RESET_PIN 13 //true

void setup() {
  // Open serial communications and wait for port to open:
  //AIS_Start
  pinMode(15, OUTPUT);
  digitalWrite(15, HIGH);
  //  delay(100);
  //  digitalWrite(RESET_PIN, LOW);
  //AIS_End
  Serial.begin(115200);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }


  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200, SERIAL_8N1, SERIAL1_RXPIN, SERIAL1_TXPIN);

  //  mySerial.begin(9600);
  //  mySerial.println("Hello, world?");
}
void readSensor() {
  String hexString = "";
  uint8_t cc;
  while (mySerial.available())
  {
    cc = mySerial.read();

     
   // Serial.print(cc, HEX);
    hexString +=  String(cc, HEX);
  }
  if(hexString.length() > 1)
    Serial.println(hexString);
}
void loop() { // run over and over
  readSensor();
}
