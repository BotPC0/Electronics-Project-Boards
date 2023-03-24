cadena = raw_input("Introduce una cadena de caracteres: ")

ncad = len(cadena)

lista = []
for letra in cadena:
	lista.append(letra)
	
lista.sort()
lista.pop(len(lista) - 1)
print lista 
