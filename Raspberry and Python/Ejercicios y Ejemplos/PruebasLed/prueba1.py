#!usr/bin/env/python

import RPi.GPIO as GPIO
import time
GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(18,GPIO.OUT)
GPIO.setup(23,GPIO.OUT)
GPIO.setup(14, GPIO.OUT)
GPIO.setup(15, GPIO.IN)
contador = 0

while(True):
	
	if((GPIO.input(15))and(contador==0)):
		GPIO.output(14, True)
		contador = contador + 1
		print"verde"
		time.sleep(3)
	if((GPIO.input(15))and(contador == 1)):
		GPIO.output(14, False)
		GPIO.output(18, True)
		contador = contador + 1
		print"amarillo"
		time.sleep(3)
	if((GPIO.input(15))and(contador == 2)):
		GPIO.output(18, False)
		GPIO.output(23, True)
		print "zumbador "
		time.sleep(5)
		GPIO.output(23,False)
		alarma = raw_input("Pon la clave de la alarma:  ")
		if(alarma == '1234'):
			print"Alarma Desactivada"
		else:
			print"HEY MISTER POLIIIIIIICEMAN"	
			break
	
print "Acaba"
GPIO.cleanup()

