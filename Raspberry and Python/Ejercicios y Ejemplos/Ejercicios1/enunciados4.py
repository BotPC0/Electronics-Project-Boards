
num1 = int(raw_input("Dame el primer num "))
num2 = int(raw_input("Dame el segundo num "))

def esmayor(a, b):
	correcto = False
        while(correcto == False):
		if(a<b):
			print"Todo Correcto"
			correcto = True;
		else:
			print"el segundo es menor o igual, introduce uno mayor"
			b = int(raw_input("Repite el segundo num "))
	
#correcto = false
esmayor(num1, num2)
