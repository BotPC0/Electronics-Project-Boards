agenda = {"raul":"608484585", "dogaru":"000000000"}
while(True):
	print "Introduce un nombre para meter en la agenda"

	nombre = raw_input("nombre: ")

	if(agenda.has_key(nombre)):
		print "Ese nombre ya esta"
	else:
		print("Nombre nuevo, introduce su numero de tlf")
		numero = raw_input("Numero: ")
		nuevo = {nombre:numero}
		agenda.update(nuevo)

	print agenda
