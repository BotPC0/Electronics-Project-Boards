cadena = raw_input("Introduce una cadena de caracteres: ")

ncad = len(cadena)

lista = []
for letra in cadena:
	print lista.count(letra)
	if(lista.count(letra)==0):
		lista.append(letra)
	

print lista 
