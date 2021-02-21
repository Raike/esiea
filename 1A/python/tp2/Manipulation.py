import random 
def Ecriture(name):
    fichier = open(name, "w")
    fichier.write(str(random.randint(0,9)))
    fichier.write(str(random.randint(0,9)))
    fichier.write(str(random.randint(0,9)))
    fichier.write(str(random.randint(0,9)))
    fichier.write(str(random.randint(0,9)))
    fichier.close()
def Lecture(name):
    fichier = open(name, "r")
    print(fichier.read())
    fichier.close()
Ecriture("py.txt")
Lecture("py.txt")