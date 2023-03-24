import time
import random
num = 0
num2 = -1
program = True
while(True):
	contador = 0
	#time.sleep(100)
	num = random.randrange(0,10)
	print "el primero numero es: "
	print num
	num2 = random.randrange(0,10)
	print "El segundo numero es: "
	print num2
	if(num != num2):
		print "Error, repetimos"
		while(num!= num2) and (contador <3):
			num2 = random.randrange(0,10)
			print num2
			if(num == num2):
				print("Acierto")
				break
			else:
				contador = contador + 1
	if(contador>=3):
		print "Game Over"
	else:
		break	
