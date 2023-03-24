
num1 = int(raw_input("Dame el primer num "))
num2 = int(raw_input("Dame el segundo num "))

def suma15(a, b):
	correcto = False
        while(correcto == False):
		if(a+b>=15):
			print"Todo Correcto"
			correcto = True;
		else:
			print"el segundo no llega a 15 si lo sumas con el primero, mete uno que si lo haga"
			b = int(raw_input("Repite el segundo num "))
	
suma15(num1, num2)
