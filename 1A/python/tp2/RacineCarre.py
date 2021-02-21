num = input("Vous recherche la racine carree du nombre : ")
from math import *
if num < 0:
    num = num * -1
print(sqrt(num))