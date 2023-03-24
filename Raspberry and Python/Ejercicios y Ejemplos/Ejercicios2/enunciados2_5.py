import time
import random
num = 0
num2 = -1
program = True

while(program):
	#time(100)
	contador = 0
	num = random.randrange(0,10)
	print "el primer numero es: "
	print num
	num2 = random.randrange(0,10)
	print "El segundo numero es: "
	print num2
	if(num != num2):
		print "Error, repetimos"
		while(num!= num2) or (contador<3) :
			print"Aleert!!"
			num2 = random.randrange(0,10)
			print "otro intento"
			print num2
			contador = contador + 1
			if(contador <3):
				break
			if(num == num2):
				print("Acierto")
