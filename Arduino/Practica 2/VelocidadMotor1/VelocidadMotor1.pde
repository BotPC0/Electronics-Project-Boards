
int y=0;

void setup() {
  size(200, 200);
  noLoop();
}

void draw() {
  background(204);
  fill(0, 50, 153);
  textSize(15);
  text("Velocidad: " + y, 10, 80);
}


void mouseDragged() 
{
  y = pmouseX;
  if (y > 255) {
    y = 255;
  }
  if (y < 0) {
    y = 0;
  }
  redraw();
}

void mouseReleased() {
  println(y);
}
