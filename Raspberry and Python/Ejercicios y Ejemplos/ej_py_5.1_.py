#!usr/bin/env/python
import time
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)

GPIO.setup(2, GPIO.OUT) ## Zumbador
GPIO.setup(3, GPIO.OUT) ## Led Amarillo
GPIO.setup(4, GPIO.OUT) ## Led Rojo
GPIO.setup(14, GPIO.IN) ## PIR
z=0
movimiento=0
while z==0:
    i=GPIO.input(14)
    if i == 1:
        if movimiento == 0:
            GPIO.output(3, 1)
            movimiento = movimiento + 1
            time.sleep(3)
        elif movimiento == 1:
            GPIO.output(3, 0)
            GPIO.output(4, 1)
            movimiento = movimiento + 1
            time.sleep(3)
        else:
            GPIO.output(4, 0)
            GPIO.output(2, 1)
            time.sleep(2)
            GPIO.output(2, 0)
            movimiento=0;
            clave = raw_input("Clave para desactivar ALARMA: ")
            if clave == "1234":
                print "ALARMA DESACTIVADA"
            else:
                print "DANDO AVISO A LA POLICIA"
