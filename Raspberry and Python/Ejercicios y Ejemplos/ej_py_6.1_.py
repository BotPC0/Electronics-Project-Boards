#!usr/bin/env/python
import os
import random
import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)

GPIO.setup(14, GPIO.IN) ## PIR
GPIO.setup(3, GPIO.OUT) ## LED

contrasenas = {'color':'azul','flor':'amapola','animal':'perro','ciudad':'madrid','colegio':'salesianos'}

try:
	while True:
		i=0
		i=GPIO.input(14)
		if i==1:
			random1=random.randrange(0,5)
			clave=contrasenas.keys()[random1]
			respuesta=raw_input("Contrasena de " + clave + ": ")
			valor=contrasenas.values()[random1]
			if valor == respuesta:
				GPIO.output(3, 0)
				print "Respuesta Correcta"
			else:
				GPIO.output(3, 1)
				print "Epera la llamada"
				os.system('cp /root/otros/plantilla1.call llamada1.call')
				os.system('mv llamada1.call /var/spool/asterisk/outgoing')
except KeyboardInterrupt:
	print "Se ha interrupido el programa"
