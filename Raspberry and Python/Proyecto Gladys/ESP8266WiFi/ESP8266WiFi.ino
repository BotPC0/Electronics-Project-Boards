// Esta es la librería para utilizar las funciones de red del ESP8266
#include <ESP8266WiFi.h>

/*
  const char* ssid = "KJJJJ"; // Rellena con el nombre de tu red WiFi
  const char* password = "WIFIFORYOUrL0v3"; // Rellena con la contraseña de tu red WiFi
*/

const char* ssid = "iPhoneX"; // Rellena con el nombre de tu red WiFi
const char* password = "wm94gdycmkqi2"; // Rellena con la contraseña de tu red WiFi

/*
  const char* ssid = "MOVISTAR_E570"; // Rellena con el nombre de tu red WiFi
  const char* password = "D7BE82D44C37813AC37813AC7B3"; // Rellena con la contraseña de tu red WiFi
*/

void setup() {
  Serial.begin(9600);
  delay(10);

  // Conectamos a la red WiFi

  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  /* Configuramos el ESP8266 como cliente WiFi. Si no lo hacemos
     se configurará como cliente y punto de acceso al mismo tiempo */
  WiFi.mode(WIFI_STA); // Modo cliente WiFi
  WiFi.begin(ssid, password);

  // Esperamos a que estemos conectados a la red WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP()); // Mostramos la IP
}



void loop() {
  // put your main code here, to run repeatedly:

  sendToArduino("LedOn0", 10, false);
  delay(3000);
  sendToArduino("LedOff0", 10, false);
  delay(3000);

}

/*
  Name: sendToArduino
  Description: Function used to send data to ARDUINO and wait for response?
  Params: command - the data/command to send; timeout - the time to wait for a response; debug - print to Serial window?(true = yes, false = no)
  Returns: The response from the UNO (if there is a response)
*/

String sendToArduino(String command, const int timeout, boolean debug) {
  String response = "";
  Serial.println(command); // send the read character to the Arduino
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

/*
  Name: readSerialMessage
  Description: Function used to read data from WiFi Serial.
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
