edad = int(raw_input("Que edad tienes?"))
print edad
if edad >= 18:
	print ("Eres mayor de edad")
elif edad < 0:
	print("No se puede tener una edad negativa")
else:
	print("Eres menor de edad")
