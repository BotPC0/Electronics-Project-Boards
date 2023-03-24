import random
import time
a = 0
while a == 0:
	num1 = random.randrange(1, 11)
	num2 = random.randrange(1, 11)
	time.sleep(3)
	n=1
	while num1 != num2:
		print "no son iguales :("
		num2 = random.randrange(1, 11)
		n = n + 1
		if n==3:
			print "GAME OVER"
			break
	if num1 == num2:
		print "acerto!!"
