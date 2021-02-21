from math import *
print ("Entre les parametres de l equation du second degre")
A = input("A=")
B = input("B=")
C = input("C=")
delta=B*B-4*A*C
print ("Delta=", delta)
if delta < 0 :
    print ("Pas de solutions")
if delta == 0:
    print ("La solution est :")
    x = -B / 2 * A
    print ("X=",x)
if delta > 0:
    print ("Deux solutions")
    racine_carre_delta = sqrt(delta)
    k = -B -racine_carre_delta
    l= -B + racine_carre_delta
    m = 2 * A
    x1 = k / m
    x2 = l / m
    print ("X1=", x1)
    print ("X2=", x2)