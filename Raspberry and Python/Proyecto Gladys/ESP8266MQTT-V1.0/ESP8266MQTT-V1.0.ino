
//Incluimos las librerias

#include <ESP8266WiFi.h> //Libreria usada para modulo WiFi
#include <PubSubClient.h> //Libreria usada para conexion mqtt

//Conexion de modulo a Red WiFi

const char* ssid = "KJJJJ"; // Rellena con el nombre de tu red WiFi
const char* password = "WIFIFORYOUrL0v3"; // Rellena con la contraseña de tu red WiFi

//Conexion a servidor mqtt
//const char* mqtt_server = "192.168.2.6";
const char* mqtt_server = "192.168.1.52";

//Especificamos el cliente WiFi
WiFiClient espClient;
PubSubClient client(espClient);


long lastMsg = 0;
char msg[50];
int value = 0;
String bateria;

void setup() {
  pinMode(BUILTIN_LED, OUTPUT);     // Initialize the BUILTIN_LED pin as an output
  Serial.begin(9600);

  setup_wifi(); // LLamamos a la funcion para conectarnos al WiFi
  client.setServer(mqtt_server, 1883); // Definimos el servidor mqtt y su puerto estandar 1883
  client.setCallback(callback); // Definimos una funcion de respuesta
}

void setup_wifi() {

  delay(10);
  // Empezamos conectando el WiFi, durante el proceso imprimos ciertos parametros utiles por pantalla.
  Serial.println();
  Serial.print("Conectando a ");
  Serial.println(ssid);

  /* Configuramos el ESP8266 como cliente WiFi. Si no lo hacemos
    se configurará como cliente y punto de acceso al mismo tiempo
    WiFi.mode(WIFI_STA); // Modo cliente WiFi
  */

  WiFi.begin(ssid, password);

  // Esperamos a que estemos conectados a la red WiFi
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi conectado");
  Serial.println("IP: ");
  Serial.println(WiFi.localIP());
}

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Mensaje recibido [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }

  if ((char)payload[0] == 't') {
    Serial.println('E'); // Encendido

  } else if (((char)payload[0] == 'f')) {
    Serial.println('A'); // Apagado

  }
  else {
    Serial.print("error en estado");
  }

}


//Funcion de reconectar mqtt
void reconnect() {
  // Loop hasta reconectar
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Intento de conexion
    if (client.connect("ESP8266Client")) {
      Serial.println("connected");
      // Cuando se conecta publicamos un mensaje
      client.publish("/gladys", "ya estoy conectado");
      // ... y se resuscribe, este es el topico al que se suscribe
      client.subscribe("/gladys/modo");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Espera 5 segundos hasta volver a reconectar
      delay(5000);
    }
  }
}

void loop() {

  if (!client.connected()) { //Si no esta conectado se reconecta
    reconnect();
  }
  client.loop();

 
  if (Serial.available() > 0) { // Primero inicializamos la lectura
    bateria = readSerialMessage(); // Leemos el valor de la bateria
    Serial.println(bateria);
    delay(100);
  }
  long now = millis(); // Creamos una funcion para que se envie mediante mqtt cada 5 segundos el valor de la bateria
  if (now - lastMsg > 5000) {
    lastMsg = now;
    char charBuf[bateria.length() + 1]; // Es necesario crear un buffer y transformarlo a un array de char para poder usar la funcion client.publish
    bateria.toCharArray(charBuf, bateria.length() + 1);
    client.publish("/gladys/bateria", charBuf); // Se publica el valor en el topico correspondiente
  }

}



/*
  Nombre: sendToArduino
  Descripcion: Funcion usada para enviar data al arduino y esperar respuesta
  Parametros: command - el data o comando a enviar; timeout - el tiempo de espera a respuesta; debug - imprime en la pantalla de Serial?(true = si, false = no)
  Devolucion: La respuesta del arduino (si es que existe)
*/
String sendToArduino(String command, const int timeout, boolean debug) {
  String response = "";
  Serial.println(command); // Envia el data al Arduino
  long int time = millis();
  while ( (time + timeout) > millis())
  { //Espera a respuesta
    while (Serial.available())
    {
      // Lee la respuesta
      char c = Serial.read(); // Lee el siguiente caracter.
      response += c;
    }
  }
  if (debug)
  { // Imprime la respuesta
    Serial.println(response);
  }
  return response; // Devuelve la respuesta
}

/*
  Nombre: readSerialMessage
  Descripcion: Funcion usada para leer data del Serial del WiFi.
  Parametros:
  Devolucion: Lectura de el data (si es que existe)
*/
String  readSerialMessage() {
  char value[100]; // Un valor maximo de 100
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
