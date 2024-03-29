/*
  Roomba 4000 board Arduino Conversation project
  Materials;
  Arduino Mega
  L298D Motor Driver
  IR Sensor
  Relay module
  Several resistors,transistÄ±rs vs.

  Pinout of Arduinone Mega;

  Analog Pins
  A0 Main Voltage Sensor
  A15 Charger Voltage Sensor
  A11 Thermistor
  A8 Sharp IR Wall Sensor

  Motor Driver Pins
  53 IN4
  51 IN3
  41 IN2
  47 IN1
  6 ENA
  5 ENB

  Bump Sensors
  4 Bump Left
  31 Bump Right

  Speaker
  7 Speaker

  Brush and Fan
  10 Brush PWM
  11 Side Brush PWM
  12 Fan PWM

  IR Remote
  22 IR Remote Sensor

  Whell Supplies
  2 Whell Encoder Right
  3 Whell Encoder Left
  26 Whell Drop Sensor Right
  50 Whell Drop Sensor Left

  Charging System
  44 Charger Relay

  User Interface
  48 Clean Button
  40 Spot Button
  46 Max Button
  42 Power Button
  39 Clean Led
  36 Spot Led
  37 Max Led
  38 power Led

*/

//Libraries

#include <RBD_Timer.h>
#include <RBD_Light.h>
#include <Button.h>


// Encoder Variables
const byte interruptpinleft = 3;
const byte interruptpinright = 2;
unsigned long revcountleft = 0;
unsigned long revcountright = 0;
unsigned long revcountleftrpm = 0;
unsigned long revcountrightrpm = 0;
float rpmleft = 0;
float rpmright = 0;
unsigned long rpmlastmillis = 0;
int leftwhellvelocity = 0;
int rightwhellvelocity = 0;

//User Interface
#define maxledpin = 37;
#define cleanledpin = 39;
#define powerledpin = 38;
#define spotledpin = 36;
//#define cleanbuttonpin = 48;
#define spotbuttonpin = 40;
#define maxbuttonpin = 46;
#define powerbuttonpin = 42;
unsigned long cleanmaxduration = 7200000;
unsigned long cleanduration = 3600000;

Button cleanbutton = Button(48, HIGH);
Button powerbutton = Button(42, HIGH);

// Led Library

RBD::Light maxled(37);
RBD::Light cleanled(39);
RBD::Light spotled(36);
RBD::Light powerled(38);


//Bump and Sharp Sensor Variables
int leftbumppin = 4;
int rightbumppin = 31;
int sharpsensorpin = A8;
int leftbump = 1;
int rightbump = 1;
int walldistance;
int whelldropleft = 1;
int whelldropright = 1;
int whelldroppinleft = 1;
int whelldroppinright = 1;
Button leftbumpc = Button(4, LOW);
Button rightbumpc = Button(31, LOW);
int bumpnumber=0;


//Battery Variables
int batteryvoltagepin = A0;
int chargervoltagepin = A15;
float vout1 = 0.0;
float vin1 = 0.0;
float vout2 = 0.0;
float vin2 = 0.0;
float R1 = 30000.0;
float R2 = 7500.0;
float R3 = 10000.0;
float R4 = 1000.0;
float batteryvoltage = 0;
float chargervoltage = 0;
int chargerstatus = 0;
float batterytempres = 0;
int minbatterylevel = 0;
int maxbatterylevel = 0;
int maxbatterytemp = 0;
int chargerpin = 44;
float R5 = 10000.00;
int thermistorpin = A11;
int tempnominal = 25;
int bcoefficient = 3950;
int thermistornominal = 10000;
float batterytemp;



//Navigation Parameters

int turntime;

//Movement Variables
int movespeed = 255; // navigation speed
int turnspeed = 200; // turn speed
int ENA = 5;
int ENB = 6;
int IN1 = 47;
int IN2 = 41;
int IN3 = 51;
int IN4 = 53;

//Cleaning Brush
int brushpin = 10; // Brush pin connection
int sidebrushpin = 11; // sidebrush pin connection
int fanpin = 12; // vacuum fan connection


// Wall Follow Variables
int wallbumpnumber=10; // number of bumps for enter wall follow loop
unsigned long wallfollowtime=0; // wall follow timer
int wallfollowtimeset=30000; // Duration of wall following cycle as ms



#define CLEAN 1 // Clean state
#define STANDBY 2 // Standby state, robot start with this state
#define CHARGE 3 // charging state
#define WALLFOLLOW 4 //Wall following state

int state=2; // Robot start with standby state









void setup() {

  Serial.begin(9600); // Start serial communication for debugging
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(brushpin, LOW); // Set pin as LOW at startup
  digitalWrite(sidebrushpin, LOW); // Set pin as LOW at startup
  digitalWrite(fanpin, LOW); // Set pin as LOW at startup
  pinMode(leftbump, INPUT);
  pinMode(rightbump, INPUT);
  pinMode(whelldroppinleft, INPUT);
  pinMode(whelldroppinright, INPUT);

  pinMode(chargerpin, OUTPUT);

 // pinMode(brushpin, OUTPUT);
 // pinMode(sidebrushpin, OUTPUT);
 // pinMode(fanpin, OUTPUT);

  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);

  pinMode(interruptpinleft, INPUT_PULLUP); // Left wheel encoder 
  pinMode(interruptpinright, INPUT_PULLUP); // Right whell encoder
  attachInterrupt(digitalPinToInterrupt(interruptpinleft), countleft, RISING );
  attachInterrupt(digitalPinToInterrupt(interruptpinright), countright, RISING );

 //rightbumpc.setDebounceDelay(1);
 //leftbumpc.setDebounceDelay(1);
 
 
  

  maxled.on();  // all leds are on position)
  spotled.on();
  cleanled.on();
  powerled.on();
  batterycheck();
  Serial.println("Roomba is starting");
  Serial.print("Battery Voltage="); //it shows battery voltage and battery temperature at startup
  Serial.println(batteryvoltage);
  Serial.print("Battery Temperature");
  Serial.println(batterytemp); //it shows battery voltage and battery temperature at startup
  

  delay(2000);

 

}

void loop()
{
  //cleanbutton.listen();
  //leftbumpc.listen();
  //rightbumpc.listen();
  batterycheck();
  updatesensor();
  maxled.update();
  powerled.update();
  cleanled.update();
  spotled.update();
if (cleanbutton.isPressed())
{
    state=2;
  }  
else { 
  if (bumpnumber>wallbumpnumber)
    {
      state=4;
      
    }
    else
    {
      state=1;
    }
 }

if (chargervoltage>4 or batteryvoltage<13)//batteryvoltage menor a 13V se considera descargada
{
  state=3;
}

 

  



 //Serial.print("State:");
//Serial.println(state);
 // delay(100);

  switch (state)
  {
    /*case SLEEP:
      break;
*/

    case 2:
      standby(); // wait for state change from user interface or ir remote
      break;


    case 1:
      cleanled.blink(1000, 1000);
      updatesensor();
  
      navigation();
      break;
/*

    case CLEANMAX:
      maxled.blink(1000, 1000);
      navigation();
      break;


    case SPOT:
    spotled.blink(1000,1000);
      break;

*/
    case 4:
    wallfollowtime=millis(); 

 while(millis()<wallfollowtime+wallfollowtimeset)
    {
      cleanled.update();
      cleanled.blink(1000, 1000);
  //cleanbutton.listen();
  if(cleanbutton.isPressed())
  {
    state=2;
  }
  //leftbumpc.listen();
  //rightbumpc.listen();
  updatesensor();
  wallfollownavigation();
      
    }
    
    state=1;
    bumpnumber=0;
       
break;


    case 3:
      charge();
      powerled.blink(1000,1000);
      break;
/*
    case REMOTECONTROL:
      break;

    case FINDCHARGER:
      break;
*/
  }



}





void navigation()

{

 updatesensor();

    digitalWrite(brushpin, HIGH);
    digitalWrite(sidebrushpin, HIGH);
    digitalWrite(fanpin, HIGH);

    if (leftbump == LOW and rightbump == LOW)
    {
      forward();
    }
    else if (leftbump == LOW and rightbump == HIGH)
    {
      turnleft90();
    }
    else if (leftbump == HIGH and rightbump == LOW)
    {
      turnright90();
    }
    else if (leftbump == HIGH and rightbump == HIGH)
    {
      reverse();
    }
  }
 

void wallfollownavigation()
{
updatesensor();
digitalWrite(brushpin, HIGH);
    digitalWrite(sidebrushpin, HIGH);
    digitalWrite(fanpin, HIGH);
  if(leftbump==LOW and rightbump==LOW)
  {
    wallforward();
  }
 else if (leftbump==HIGH or rightbump==HIGH)
    {
      turnleft10();
    }   
}



void countleft()
{
  revcountleft++;
  revcountleftrpm++;
}
void countright()
{
  revcountright++;
  revcountrightrpm ++;
}
void batterycheck()
{

  //Temperature of Battery
  batterytempres = analogRead(thermistorpin);
  batterytempres = (1023 / batterytempres)  - 1;
  batterytempres = R5 / batterytempres;

  batterytemp = batterytempres / thermistornominal;     // (R/Ro)
  batterytemp = log(batterytemp);                  // ln(R/Ro)
  batterytemp /= bcoefficient;                   // 1/B * ln(R/Ro)
  batterytemp += 1.0 / (tempnominal + 273.15); // + (1/To)
  batterytemp = 1.0 / batterytemp;                 // Invert
  batterytemp -= 273.15;                         // convert to C

  //Voltage of Battery
  vin1 = analogRead(batteryvoltagepin);
  vout1 = (vin1 * 5.00) / 1024.0;
  batteryvoltage = vout1 / (R2 / (R1 + R2));

  //Voltage of Charger Input
  vin2 = analogRead(chargervoltagepin);
  vout2 = (vin2 * 5.00) / 1024.0;
  chargervoltage = vout2 / (R4 / (R3 + R4));

  //Status of Charger

  
}

void updatesensor()

{
  
  //leftbumpc.listen();
  //rightbumpc.listen();
  leftbump = digitalRead(leftbumppin);
  rightbump = digitalRead(rightbumppin);
  walldistance = analogRead(sharpsensorpin);
  whelldropleft = digitalRead(whelldroppinleft);
  whelldropright = digitalRead(whelldroppinright);

    if (rightbumpc.isPressed() or leftbumpc.isPressed())
  {
  bumpnumber++;
  Serial.print("Bump Number:");
  Serial.println(bumpnumber);
  
  }
  
  
}


void forward()
{ digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, movespeed);
  analogWrite(ENB, movespeed);
 
}

void wallforward()
{ 
  
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 70);
 
}

void turnleft90()
{
 
 
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, movespeed);
  analogWrite(ENB, movespeed);
 delay(turntime);
  
}

void turnright90()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, movespeed);
  analogWrite(ENB, movespeed);
 // Serial.print("RIGHT");
    delay(turntime);
}
void turnleft10()
{
    digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 150);
  analogWrite(ENB, 150);
 delay(1);

}
void turnright10()
{
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, movespeed);
  analogWrite(ENB, movespeed);
  Serial.print("RIGHT");
  delay(10);
}

void reverse()
{

  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, movespeed);
  analogWrite(ENB, movespeed);
  delay(350);
  //turn right
  turntime = random(200, 900);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, movespeed);
  analogWrite(ENB, movespeed);
  delay(turntime);
}


void charge()

{
  powerled.blink(1000, 1000);
  unsigned long chargetime = millis;

  if (millis - chargetime > 9000000 or batterytemp>46 or batteryvoltage>18)
  
  {
    Serial.println("Charging finished by time or voltage or temperature");
    delay(1000);
    state = 2;
  }
  if (chargervoltage > 2 and batteryvoltage < 18)
  {
    digitalWrite(chargerpin, LOW);
  }
  else
  {
    digitalWrite(chargerpin, HIGH);
    state = 2;
  }

  Serial.println("State is charging");
  Serial.print("Battery Voltage:");
  Serial.println(batteryvoltage);
  Serial.print("Charger Volatge:" );
  Serial.println(chargervoltage);
  Serial.print("Battery temperature:" );
  Serial.println(batterytemp);
  delay(1500);
}



void standby()
{
  maxled.off();
  spotled.off();
  cleanled.off();
  powerled.on();
 
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);

  digitalWrite(brushpin, LOW);
  digitalWrite(sidebrushpin, LOW);
  digitalWrite(fanpin, LOW);

}
