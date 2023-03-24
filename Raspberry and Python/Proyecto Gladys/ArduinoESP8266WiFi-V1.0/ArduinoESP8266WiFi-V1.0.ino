

void setup() {
  pinMode(50, OUTPUT); //LED
  // Habilitamos los puertos serial
  Serial.begin(9600);
  Serial1.begin(9600); // Para el modulo WiFi
}

void loop() {
  delay(100); //lo necesita para leer el string.

  if (Serial1.available() > 0) { // Si esta disponible el puerto serie del WiFi

    String message = readWifiSerialMessage(); //Leemos el mensaje del WiFi


    if (find(message, "LedOn0")) {
      digitalWrite(50, HIGH);
    }
    else if (find(message, "LedOff0")) {
      digitalWrite(50, LOW);
    }
    else {
      Serial.print(message);                 // hace print de caracteres inservibles
    }
  }
  Serial.print("serial no avalible");
}


/*
  Nombre: find
  Descripcion: Funcion usada para comparar dos string
  Parametros: string = mensaje recibido, value = valor con el que comparar
  Devolucion: true si coincide, de lo contrario false
*/
boolean find(String string, String value) {
  if (string.indexOf(value) >= 0)
    return true;
  return false;
}

/*
  Nombre: readSerialMessage
  Descripcion: Funcion usada para leer data del Serial del Arduino.
  Parametros:
  Devolucion: Lectura de el data del Arduino (si es que existe)
*/
String  readSerialMessage() {
  char value[100];
  int index_count = 0;
  while (Serial.available() > 0) {
    value[index_count] = Serial.read();
    index_count++;
    value[index_count] = '\0'; // 0 termina el String
  }
  String str(value);
  str.trim();
  return str;
}

/*
  Nombre: readWifiSerialMessage
  Descripcion: Funcion usada para leer data del Serial del WiFi.
  Parametros:
  Devolucion: Lectura de el data del WiFi (si es que existe)
*/
String  readWifiSerialMessage() {
  char value[100];
  int index_count = 0;
  while (Serial1.available() > 0) {
    value[index_count] = Serial1.read();
    index_count++;
    value[index_count] = '\0'; // 0 termina el String
  }
  String str(value);
  str.trim();
  return str;
}

/*
  Nombre: sendToWifi
  Descripcion: Funcion usada para enviar data al WiFi y esperar respuesta
  Parametros: command - el data o comando a enviar; timeout - el tiempo de espera a respuesta; debug - imprime en la pantalla de Serial?(true = si, false = no)
  Devolucion: La respuesta del WiFi (si es que existe)
*/
String sendToWifi(String command, const int timeout, boolean debug) {
  String response = "";
  Serial1.println(command); // Envia el data al esp8266
  long int time = millis();
  while ( (time + timeout) > millis())
  { //Espera a respuesta
    while (Serial1.available())
    {
      // Lee la respuesta
      char c = Serial1.read();// Lee el siguiente caracter.
      response += c;
    }
  }
  if (debug)
  { // Imprime la respuesta
    Serial.println(response);
  }
  return response;// Devuelve la respuesta
}


