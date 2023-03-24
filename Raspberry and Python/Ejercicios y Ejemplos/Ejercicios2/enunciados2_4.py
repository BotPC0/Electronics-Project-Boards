cadena = raw_input("Introduce una cadena de caracteres: ")

lista = []
for letra in cadena:
	lista.append(letra)
lista.pop(3)
print lista

while(True):
	num = raw_input("Que caracter quieres comprobar: ")
	print lista.count(num)
	print lista 
