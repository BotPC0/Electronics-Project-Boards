print("Cree su usuario y contrasena\n")
usuarioCorrecto = False
contrasenaCorrecta = False
while (usuarioCorrecto == False):
	print("El nombre de usuario debe tener minimo 6 y maximo 12 caracteres\n")
	print("Debe ser alfanumerico")

	usuario = raw_input("Usuario: ")
	contador = 0
	print contador
	if((len(usuario)<6) or (len(usuario)>=12)):
		print("El nombre de usuario debe contener al menos 6 caracteres y no mas de 12")
	else:
		print("Tamano correcto")
		contador = contador + 1

	if(usuario.isalnum()== False):
		print("El usuario solo puede contener letras y numeros")
	else:
		print("Sintaxis correcta")
		contador = contador + 1
	if(contador == 2):
		print("Usuario correcto")
		usuarioCorrecto = True

print("Cree su contrasena\n")

while(contrasenaCorrecta == False):
	print("La contrasena debe tener minimo 8 caracteres\n")
	print("Debe contener al menos una mayuscula, 1 minuscula y un caracter no alfanumerico\n")

	contrasena = raw_input("Contrasena: ")
	contador = 0
	if(len(contrasena)<8):

		print("Contrasena debe tener 8 o mas caracteres\n")
	else:
		print("Tamano correcto")
		contador = contador + 1
	if(contrasena.islower()== True):
		print("Te falta 1 mayuscula")
	else:
		print("Hay alguna mayus\n")
		contador = contador + 1
	if(contrasena.isupper() == True):
		print("Te falta 1 minuscula\n")
	else:
		print("Hay alguna minuscula\n")
		contador = contador + 1
	if(contrasena.isalnum()== True):
		print("Te falta un simbolo")
	else:
		print("No es alfanum")
		contador = contador + 1
	if(contador == 4):
		print("Contrasena correcta")
		contrasenaCorrecta = True
