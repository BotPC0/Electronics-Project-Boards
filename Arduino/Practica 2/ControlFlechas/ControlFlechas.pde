

color colorUp = color(0, 0, 0); //fill color of object R,G,B
color colorDown = color(0, 0, 0); //fill color of object R,G,B
color colorRight = color(0, 0, 0); //fill color of object R,G,B
color colorLeft = color(0, 0, 0); //fill color of object R,G,B


void setup() {
  size(400, 400);
}

void draw() {
  background(51, 102, 204);
  drawArrows();
}

void drawArrows() {
  fill(colorUp);
  triangle(200, 20, 160, 100, 240, 100);
  fill(colorLeft);
  triangle(140, 120, 140, 200, 60, 160);
  fill(colorRight);
  triangle(260, 120, 260, 200, 340, 160);
  fill(colorDown);
  triangle(200, 300, 160, 220, 240, 220);
}

void keyPressed() {
  if (key == CODED) {
    if (keyCode == UP) {
      colorUp = color(0, 204, 0);
      colorDown = color(0, 0, 0);
      colorLeft = color(0, 0, 0);
      colorRight = color(0, 0, 0);
    } else if (keyCode == DOWN) {
      colorUp = color(0, 0, 0);
      colorDown = color(204, 0, 0);
      colorLeft = color(0, 0, 0);
      colorRight = color(0, 0, 0);
    } else if (keyCode == LEFT) {
      colorUp = color(0, 0, 0);
      colorDown = color(0, 0, 0);
      colorLeft = color(255, 255, 0);
      colorRight = color(0, 0, 0);
    } else if (keyCode == RIGHT) {
      colorUp = color(0, 0, 0);
      colorDown = color(0, 0, 0);
      colorLeft = color(0, 0, 0);
      colorRight = color(255, 255, 0);
    }
  } else {
    colorUp = color(0, 0, 0);
    colorDown = color(0, 0, 0);
    colorLeft = color(0, 0, 0);
    colorRight = color(0, 0, 0);
  }
}
