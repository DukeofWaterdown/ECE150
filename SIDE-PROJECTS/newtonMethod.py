print("Hey there Newton!")

from sympy import *
x = Symbol('x')

xo = int(input("Value of xo? ")) 
xn = 0
terms = int(input("Number of terms? ")) + 1 

#f = 2*x-x**2-(1-x**2)**(1/2) - THE O.G. FUNCTION
f = x**4 -4*x -1
f_prime = f.diff(x)

fL = lambdify(x, f)
fL_prime = lambdify(x, f_prime)

print("Base function:",  f)
print("First Derivative:", f_prime)


for i in range(1, terms):
    print('\n', "Term Number:", i)
    xn = xo - (fL(xo) / fL_prime(xo))

    print('x',i, 'is equal to', xn)
    xo = xn

