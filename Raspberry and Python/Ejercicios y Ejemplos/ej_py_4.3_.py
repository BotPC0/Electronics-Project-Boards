cadena = raw_input("Escribe algo: ")
lista = list()
for i in cadena:
	lista.append(i)
lista=sorted(lista, key=str.lower)
lista.pop()
print lista
