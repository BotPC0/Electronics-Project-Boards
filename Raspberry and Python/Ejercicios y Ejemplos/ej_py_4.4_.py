cadena = raw_input("Escribe algo: ")
lista = list()
for i in cadena:
	lista.append(i)
lista.pop(3)
print lista
a=0
while a==0:
	elemento = raw_input("Dime un caracter: ")
	c = lista.count(elemento)
	print c
