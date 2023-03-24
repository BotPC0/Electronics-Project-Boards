lista2=list()
x=0
while x==0:
	frase=raw_input("Dime algo: ")
	lista1=frase.split(" ")
	size = int(len(lista1))
	for n in range(size):
		if lista2.count(lista1[n]) == 0:
			lista2.append(lista1[n])
	print lista2
