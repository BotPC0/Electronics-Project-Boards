
lista = [1,2,3,4,5]
valor = 1
contador = 0
while valor > 0:
	print lista
	contador = 0
	valor = int(raw_input("Anade un numero que no este en la lista, y 0 para salir" + '\n'))
	for numero in lista:
		if valor  == numero:
			print("Ese numero no se puede meter")
			contador = 1
	if contador == 0: 
		print("Ese numero si entra")
		print("El contador vale" and  contador)
		lista.append(valor)
	print lista
