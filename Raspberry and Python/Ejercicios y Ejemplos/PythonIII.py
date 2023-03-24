
import time
try:
	i = 0
	while i < 100:
		print i
		time.sleep(0.5)
		i = i +1
except KeyboardInterrupt:
	print("has cortado el bucle")
