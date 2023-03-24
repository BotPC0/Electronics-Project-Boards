#!/usr/bin/env python3

import argparse
import signal
import sys
import time
import logging
from rpi_rf import RFDevice
rfdevice = None

import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)

GPIO.setup(2, GPIO.OUT) ## Led Amarillo
GPIO.setup(3, GPIO.OUT) ## Led Rojo

# pylint: disable=unused-argument
def exithandler(signal, frame):
    rfdevice.cleanup()
    sys.exit(0)

logging.basicConfig(level=logging.INFO, datefmt='%Y-%m-%d %H:%M:%S', format='%(asctime)-15s - [%(levelname)s] %(module)s: %(message)s', )

parser = argparse.ArgumentParser(description='Receives a decimal code via a 433/315MHz GPIO device')
parser.add_argument('-g', dest='gpio', type=int, default=27, help="GPIO pin (Default: 27)")
args = parser.parse_args()
signal.signal(signal.SIGINT, exithandler)
rfdevice = RFDevice(args.gpio)
rfdevice.enable_rx()
timestamp = None
logging.info("Listening for codes on GPIO " + str(args.gpio))
M30 = '11'
M15 = '22'
M0 = '33'
while True:
	if rfdevice.rx_code_timestamp != timestamp:
		timestamp = rfdevice.rx_code_timestamp
		if str(rfdevice.rx_code) == M30:
			print("menor a 30")
			GPIO.output(2, 1)
			GPIO.output(3, 0)
		elif str(rfdevice.rx_code) == M15:
			print("menor a 15")
			GPIO.output(2, 0)
			GPIO.output(3, 1)
		else: 
			print("mayor a 30")
			GPIO.output(2, 0)
			GPIO.output(3, 0)
	time.sleep(0.1)
rfdevice.cleanup()
