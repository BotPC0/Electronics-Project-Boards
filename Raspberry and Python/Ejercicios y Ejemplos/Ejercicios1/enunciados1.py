
num1 = int(raw_input("Dame el primer num "))
num2 = int(raw_input("Dame el segundo num "))

def suma(a, b):
        resul = a + b
        return resul

def resta(num1, num2):
        resul = num1 - num2
        print resul
        return resul

def mult(num1, num2):
        result = num1 * num2
        print result
        return result



def div(num1, num2):
        resul = num1/num2
        print resul
        return resul


print num1
print num2
print num1 + num2
print "La suma es :"
lasuma = suma(num1, num2)
print lasuma
print "La resta es :"
laresta = resta(num1, num2)
print laresta
print "La multiplicacion es: "
lamult = mult(num1, num2)
print "La division es : "
ladiv = div(num1, num2)
