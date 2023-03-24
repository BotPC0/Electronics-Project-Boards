import random
import time
a = 0
while a == 0:
	num1 = random.randrange(1, 11)
	num2 = random.randrange(1, 11)
	time.sleep(2)
	if num1 != num2:
		print "no son iguales :("
	else:
		print "acerto!!"
