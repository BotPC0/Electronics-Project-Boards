#!usr/bin/env/python

import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)

GPIO.setup(14, GPIO.OUT)
contador = 0

while(contador<10):

	GPIO.output(14,True)
	time.sleep(1)
	GPIO.output(14,False)
	time.sleep(1)
	contador = contador + 1

print "Acaba"
GPIO.cleanup()

