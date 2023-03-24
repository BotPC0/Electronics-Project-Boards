import random
num = random.randrange(0, 11)
n=0
x = int(raw_input("Adivina el numero: "))
while x != num:
	x = int(raw_input("Adivina el numero: "))
	n = n + 1
	if n > 1:
		print("GAME OVER")
		break
