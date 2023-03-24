import random
num = random.randrange(0, 11)
x = int(raw_input("Adivina el numero: "))
while x != num:
	x = int(raw_input("Adivina el numero: "))
	n = n + 1
