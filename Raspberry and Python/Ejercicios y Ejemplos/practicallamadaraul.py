import os
import RPi.GPIO as GPIO
import time
import random

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(19, GPIO.OUT)
GPIO.setup(15, GPIO.IN)

contador = 0
contrasena = {'color':'azul', 'flor':'amapola','animal':'perro', 'ciudad':'madrid', 'colegio':'salesianos'}
lista = ["color","flor","animal","ciudad","colegio"]

try:
	while(True):
		if(GPIO.input(15) or True):
			GPIO.output(18, True)
			aleatorio = random.randint(0,5) - 1
			print ("Dime la contrasena de : ")
			print (lista[aleatorio])
			pregunta = raw_input(" ")
			clave = contrasena.get(lista[aleatorio])
			#print clave
			if (pregunta == clave):
				GPIO.output(18, False)
				print ("contrasena correcta")
			else:
				GPIO.output(19, True)
				print ("llama")
				os.system('cp plantillaraul.call llamadaraul.call')
				os.system('mv llamadaraul.call /var/spool/asterisk/outgoing')
		else:
			print("No hay movimiento")
except KeyboardInterrupt:
	print("Ha habido una interrupcion")
