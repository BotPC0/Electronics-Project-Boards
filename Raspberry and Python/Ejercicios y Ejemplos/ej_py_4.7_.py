agenda = {}
a=0
while a == 0:
	name = raw_input("Dime el nombre: ")
	NombreEnAgenda = agenda.has_key(name)
	if NombreEnAgenda == False:
		tlf = raw_input("Dime su telefono para no llamarte: ")
		Digitos = tlf.isdigit()
		while Digitos == False:
			print "Eso no es un numero"
			tlf = raw_input("Dime su telefono de verdad: ")
			Digitos = tlf.isdigit()
		agenda.update({name: tlf})
		print agenda
	else:
		print "Ya esta en la agenda, no te acuerdas?"
