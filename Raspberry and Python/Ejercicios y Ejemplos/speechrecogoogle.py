#!/usr/bin/env python3
# Requires PyAudio and PySpeech.
import time
import os
import speech_recognition as sr
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)  # mode to Broadcom

GPIO.setup(17, GPIO.OUT)  # Pin 17 como salida

dia = time.strftime("/%Y/%m/%d") # utilizamos esta funcion para crear la fecha de hoy

data_path = "/var/spool/asterisk/rec" + dia
audio_path = os.path.join(data_path, 'rec1.wav')
# print(data_path)
r = sr.Recognizer()

while True: # bucle infinito
	if os.path.isfile(audio_path): 
# preguntamos si existe el archivo de audio, en este caso la grabacion de freepbx
		print("Procesando Llamada")
		time.sleep(12) # esperar a que acabe la llamada
		try:
# for testing purposes, we're just using the default API key
# to use another API key, use `r.recognize_google(audio, key="GOOGLE_SPEECH_RECOGNITION_API_KEY")`
# instead of `r.recognize_google(audio)`
			with sr.AudioFile(audio_path) as source: # seleccionamos el archivo audio
				audio = r.listen(source)  # leemos el audio entero
				text = r.recognize_google(audio) # google empieza el reconocimiento
				print("Google Speech Recognition thinks you said " + text)
				os.remove(audio_path)
		except sr.UnknownValueError:
			print("Google Speech Recognition could not understand audio")
		except sr.RequestError as e:
			print("Could not request results from Google Speech Recognition service; {0}".format(e))
		if text == "lights on":
			print("Encendiendo luces")
			GPIO.output(17, 1)
		elif text == "lights off":
			print("Apagando luces")
			GPIO.output(17, 0)
		else:
			print("No es una opcion posible")
	else:
		print("Esperando llamada")
		time.sleep(15)
