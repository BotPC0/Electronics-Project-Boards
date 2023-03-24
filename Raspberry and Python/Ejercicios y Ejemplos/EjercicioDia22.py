menu =["Mostrar numero","Generar aleatorio", "Decir contrasena", "Decir usuario"]


for i in menu:
	print(i)

eleccion = 0

while(eleccion <1 or eleccion >4):
	print "Elige tu opcion con los numeros del 1 al 4"
	eleccion = int(raw_input("opcion: "))

	if (eleccion == 1):
		print "Numero mostrado : 7"
	elif(eleccion ==2):
		num = random(0,10)
		print num
	elif(eleccion ==3):
		print "La contrasena es alskjfd"
	elif(eleccion == 4):
		print "el usuario es huehue45"
	else:
		print "Opcion incorrecta"

