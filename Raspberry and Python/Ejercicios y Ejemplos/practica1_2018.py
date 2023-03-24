import random
try:
	a=0
	while a==0:
		print "1. Cadenas"
		print "2. Listas"
		print "3. Diccionarions"
		print "4. Juego"
		opcion = int(raw_input("Dime una opcion: "))
		if opcion==1:
			cadena1=raw_input("Dime una frase: ")
			l=len(cadena1)
			cadena1=cadena1.upper()
			print l
			print cadena1
		elif opcion==2:
			lista1 = list()
			cadena2=raw_input("Dime una frase: ")
			for i in cadena2:
				lista1.append(i)
			lista1.pop(1)
			lista1.insert(2, "Atocha")
			print lista1
		elif opcion==3:
			diccionario1 = {"A1": "Derecha", "B2": "Izquierda", "C3": "abajo"}
			clave=raw_input("Dime una clave: ")
			print diccionario1.get(clave)
		elif opcion==4:
			num1 = random.randrange(20, 31)
			num2 = int(raw_input("Dime un numero entre el 20 y el 30: "))
			while num1!=num2:
				if num1<num2:
					print "El numero tiene que ser menor"
					num2 = int(raw_input("Dime un numero entre el 20 y el 30: "))
				elif num1>num2:
					print "El numero tiene que ser mayor"
					num2 = int(raw_input("Dime un numero entre el 20 y el 30: "))
			print "Numero correcto"
		else:
			print "Opcion Incorrecta"

except KeyboardInterrupt:
	print "Ha habido una interrupcion"
