import random

num = random.randrange(0,10)
print num
contador = 0
user = -1
while (user!= num) and (contador<3):
	user = int(raw_input("Introduce un numero: ")) 
	contador = contador + 1
