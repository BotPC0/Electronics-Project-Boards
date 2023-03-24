lenght = 0
alfanumerico = 0
checkpass = 0

while lenght == 0 or alfanumerico == 0:

	user = raw_input("dime un usuario: ")

	if len(user)<6:
		print("El nombre de usuario debe contener al menos 6 caracteres")

	elif len(user)>12:
		print("El nombre de usuario no puede contener mas de 12 caracteres")

	else:
		lenght = 1

	if user.isalnum() == False:
		print("El nombre de usuario solo puede contener letras y numeros")

	else:
		alfanumerico = 1

print("Nombre de usuario valido")

while checkpass == 0:

	password = raw_input("dime tu contrasena: ")

	if len(password)<8 or password.isalnum() == True or password.islower() == True or password.isupper() == True:
		print("La contrasena elegida no es segura")

	else:
		print("Contrasena Correcta")
		checkpass = 1
