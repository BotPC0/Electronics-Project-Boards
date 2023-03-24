#!usr/bin/env/ python
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)

GPIO.setup(17, GPIO.OUT)

def blink():
        x=0
        while x<10:
                GPIO.output(17, True)
                time.sleep(1)
                GPIO.output(17, False)
                time.sleep(1)
                x=x+1
        print "THE END"
        GPIO.cleanup()

blink()
