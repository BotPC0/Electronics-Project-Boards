/*
#include <SoftwareSerial.h>
SoftwareSerial wifiSerial(10, 11);      // RX, TX for ESP8266; se define wifiSerial; RX=11 y TX=10 para arduino

  Not all pins on the Mega and Mega 2560 support change interrupts,
  so only the following can be used for RX:
  10, 11, 12, 13, 50, 51, 52, 53, 62, 63, 64, 65, 66, 67, 68, 69
*/

void setup() {
  // put your setup code here, to run once:
  pinMode(12, OUTPUT); //LED
  // Open serial communications and wait for port to open esp8266:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for Leonardo only
  }
  /*
    wifiSerial.begin(115200);
    while (!wifiSerial) {
    ; // wait for serial port to connect. Needed for Leonardo only
    }
  */
    Serial1.begin(9600);

}

void loop() {
  delay(100); //lo necesita para leer el string.
  // put your main code here, to run repeatedly:
  if (Serial1.available() > 0) {

    String message = readWifiSerialMessage();


    if (find(message, "LedOn0")) {
      digitalWrite(12, HIGH);
    } else if (find(message, "LedOff0")) {
      digitalWrite(12, LOW);
    }
    else {
      Serial.print(message);                 //Command ERROR CODE for UNABLE TO READ, hace print de caracteres inservibles
    }
  }
  //Serial.print("serial no avalible");
}

/*
  Name: sendData
  Description: Function used to send string to tcp client using cipsend
  Params:
  Returns: void
*/
void sendData(String str) {
  String len = "";
  len += str.length();
  int responseTime;
  boolean DEBUG;
  sendToWifi("AT+CIPSEND=0," + len, responseTime, DEBUG);
  delay(100);
  sendToWifi(str, responseTime, DEBUG);
  delay(100);
  sendToWifi("AT+CIPCLOSE=5", responseTime, DEBUG);
}
/*
  Name: find
  Description: Function used to match two string
  Params:
  Returns: true if match else false
*/
boolean find(String string, String value) {
  if (string.indexOf(value) >= 0)
    return true;
  return false;
}
/*
  Name: readSerialMessage
  Description: Function used to read data from Arduino Serial.
  Params:
  Returns: The response from the Arduino (if there is a reponse)
*/
String  readSerialMessage() {
  char value[100];
  int index_count = 0;
  while (Serial.available() > 0) {
    value[index_count] = Serial.read();
    index_count++;
    value[index_count] = '\0'; // Null terminate the string
  }
  String str(value);
  str.trim();
  return str;
}
/*
  Name: readWifiSerialMessage
  Description: Function used to read data from ESP8266 Serial.
  Params:
  Returns: The response from the esp8266 (if there is a reponse)
*/
String  readWifiSerialMessage() {
  char value[100];
  int index_count = 0;
  while (Serial1.available() > 0) {
    value[index_count] = Serial1.read();
    index_count++;
    value[index_count] = '\0'; // Null terminate the string
  }
  String str(value);
  str.trim();
  return str;
}
/*
  Name: sendToWifi
  Description: Function used to send data to ESP8266.
  Params: command - the data/command to send; timeout - the time to wait for a response; debug - print to Serial window?(true = yes, false = no)
  Returns: The response from the esp8266 (if there is a response)
*/
String sendToWifi(String command, const int timeout, boolean debug) {
  String response = "";
  Serial1.println(command); // send the read character to the esp8266
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (Serial1.available())
    {
      // The esp has data so display its output to the serial window
      char c = Serial1.read(); // read the next character.
      response += c;
    }
  }
  if (debug)
  {
    Serial.println(response);
  }
  return response;
}
/*
  Name: sendToUNO
  Description: Function used to send data to UNO.
  Params: command - the data/command to send; timeout - the time to wait for a response; debug - print to Serial window?(true = yes, false = no)
  Returns: The response from the UNO (if there is a response)
*/
String sendToUno(String command, const int timeout, boolean debug) {
  String response = "";
  Serial.println(command); // send the read character to the esp8266
  long int time = millis();
  while ( (time + timeout) > millis())
  {
    while (Serial.available())
    {
      // The esp has data so display its output to the serial window
      char c = Serial.read(); // read the next character.
      response += c;
    }
  }
  if (debug)
  {
    Serial.println(response);
  }
  return response;
}
