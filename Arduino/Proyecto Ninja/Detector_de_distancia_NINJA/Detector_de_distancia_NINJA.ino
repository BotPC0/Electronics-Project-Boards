
int EchoPin[] = {31, 33, 35, 37, 39, 41};
int TriggerPin[] = {43, 45, 47, 49, 51, 53};
int A[] = {1, 1, 1, 1 , 1 , 1}; //Distancia maxima
int a[] = {0, 0, 0, 0, 0, 0}; //Distancia minima

int cm[5];


int ping(int TriggerPin, int EchoPin) { //FUNCION DETECTOR DE DISTANCIA
  long duration, distanceCm;

  digitalWrite(TriggerPin, LOW);  //para generar un pulso limpio ponemos a LOW 4us
  delayMicroseconds(4);
  digitalWrite(TriggerPin, HIGH);  //generamos Trigger (disparo) de 10us
  delayMicroseconds(10);
  digitalWrite(TriggerPin, LOW);

  duration = pulseIn(EchoPin, HIGH);  //medimos el tiempo entre pulsos, en microsegundos

  distanceCm = duration * 10 / 292 / 2;  //convertimos a distancia, en cm
  return distanceCm;
}

void setup() {

  for (int j = 0; j <= 5; j++) {

    pinMode (TriggerPin[j], OUTPUT);
    pinMode (EchoPin[j], INPUT);

  }


  Serial.begin(9600);

}

void loop() {

  for (int i = 0; i <= 5; i++) {

    cm[i] = ping(TriggerPin[i], EchoPin[i]);

    Serial.print("Distancia: ");
    Serial.println(cm[i]);
    delay(10);
  }

  for (int i = 0; i <= 5; i++) {

    if ((cm[i] < A[i]) && (cm[i] > a[i]) && (led == HIGH))
    {
      // LED LOW
    }
    else if ((cm[i] < A[i]) && (cm[i] > a[i]) && (led == LOW))
    {
      // LED HIGH
    }
    else
    {
      delay(10); // no hace nada
    }
  }


  delay(1000);

}


