
import processing.serial.*; // Importamos la libreria Serial

// Definimos las variables color para las flechas
color colorUp = color(0, 0, 0); //fill color of object R,G,B
color colorDown = color(0, 0, 0); //fill color of object R,G,B
color colorRight = color(0, 0, 0); //fill color of object R,G,B
color colorLeft = color(0, 0, 0); //fill color of object R,G,B
int y=0; // es el valor de la velocidad

Serial myPort;                       // Creamos el objeto Serial


void setup() {
// Definimos el tamaño de la pantalla de la aplicacion
  size(400, 400);

// Imprimimos una lista con todos los puertos series del ordena:
  printArray(Serial.list());

// Elegimos el puerto serie adecuado de la lista para el HC-06 en mi caso es el Nº11
  String portName = Serial.list()[11];
  myPort = new Serial(this, portName, 9600); 
  myPort.clear();          // Vacia el buffer de serial
}

void draw() {
  background(51, 102, 204); // Creamos un color para el fondo
  drawArrows(); // Ejecutamos la funcion que nos dibuja las flechas en pantalla
  fill(0, 50, 153); // Color del texto
  textSize(15); // Tamaño del texto
  text("Velocidad: " + y, 10, 80); // texto y posicion del mismo
}

void drawArrows() { // Se dibuja las flechas
  fill(colorUp);
  triangle(200, 20, 160, 100, 240, 100); // Posicion de cada punto del triangulo
  fill(colorLeft);
  triangle(140, 120, 140, 200, 60, 160);
  fill(colorRight);
  triangle(260, 120, 260, 200, 340, 160);
  fill(colorDown);
  triangle(200, 300, 160, 220, 240, 220);
}

void keyPressed() { // Funcion de cuando se presiona una tecla
  if (key == CODED) { // Identificamos las teclas correspondientes
    if (keyCode == UP) { 
      colorUp = color(0, 204, 0); // Cambio de color de la flecha de arriba
      colorDown = color(0, 0, 0);
      colorLeft = color(0, 0, 0);
      colorRight = color(0, 0, 0);
      println("ADELANTE"); 
      myPort.write('A'); // Se manda la letra A al puerto bluetooth
    } else if (keyCode == DOWN) {
      colorUp = color(0, 0, 0);
      colorDown = color(204, 0, 0);
      colorLeft = color(0, 0, 0);
      colorRight = color(0, 0, 0);
      println("ATRAS");
      myPort.write('B');
    } else if (keyCode == LEFT) {
      colorUp = color(0, 0, 0);
      colorDown = color(0, 0, 0);
      colorLeft = color(255, 255, 0);
      colorRight = color(0, 0, 0);
      println("IZQUIERDA");
      myPort.write('I');
    } else if (keyCode == RIGHT) {
      colorUp = color(0, 0, 0);
      colorDown = color(0, 0, 0);
      colorLeft = color(0, 0, 0);
      colorRight = color(255, 255, 0);
      println("DERECHA");
      myPort.write('D');
    }
  } else {
    colorUp = color(0, 0, 0);
    colorDown = color(0, 0, 0);
    colorLeft = color(0, 0, 0);
    colorRight = color(0, 0, 0);
    println("STOP");
    myPort.write('S');    
  }
}

void mouseDragged()  // Cuando arrastramos el raton cambia el valor de "y" y por tanto varia la velocidad
{
  y = pmouseX;
  if (y > 255) {
    y = 255;
  }
  if (y < 0) {
    y = 0;
  }
  redraw(); // Sirve para actualizar el texto cada vez que varia "y" 
}

void mouseReleased() { // Cuando soltamos el raton se envia el valor de "y"
  println(y);
  String c = str(y); // Transformamos el numero entero "y" a string
  myPort.write('N'); // Mandamos una N para que el codigo de arduino sepa que le va a llegar una velocidad
  delay(100); // Creamos un Delay porque se manda muy rapido el siguiente valor y el arduino no lo procesa
  myPort.write(c); // Enviamos el valor de la velocidad
}
