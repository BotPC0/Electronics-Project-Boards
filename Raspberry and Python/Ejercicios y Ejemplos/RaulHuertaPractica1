import random
try:

	while(True):
		
		print"1. Cadenas"
		print"2. Listas"
		print"3. Diccionarios"
		print"4. Juego"	
		opcion = int(raw_input("Elige una opcion: "))
		if opcion == 1:
			cadena = raw_input("Escribe una cadena de caracteres: ")
			print len(cadena)
			print cadena.upper()
		elif opcion == 2:
			cadena = raw_input("Escribe una cadena de caracteres: ")
			lista = []
			for letra in cadena:
				lista.append(letra)
			lista.pop(1)
			lista.insert(2, "Atocha")
			print lista
		elif opcion == 3:
			diccionario = {"A1":"derecha", "B2":"izquierda", "C3":"abajo"}
			clave = raw_input("Dime una clave: ")
			print diccionario.get(clave)
		elif opcion == 4:
			num = random.randrange(20,30)
			jugador = 0
			while(num!=jugador):
				jugador = int(raw_input("Dime un numero entre el 20 y el 30: "))
				if(num < jugador):
					print "El numero tiene que ser menor"
				elif(num > jugador):
					print "El numero tiene que ser mayor"
				else:
					print "Numero Correcto!!"
		else:
			print "Opcion incorrecta"

except KeyboardInterrupt:
	print("Ha habido una interrupcion")
