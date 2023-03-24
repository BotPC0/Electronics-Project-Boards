lista = [1,2,3,4,5]

while len(lista)<=15:
    numero = int(raw_input("dime un numero: "))

    if numero not in lista:
        lista.append(numero)
    else:
        print "error: ya se encuentra en la lista"
print lista
