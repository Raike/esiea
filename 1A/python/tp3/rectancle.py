import tkinter
import turtle
class RECTANGLE:
    def __init__(self, Hleft0 = 0, longueur0 = 0, largeur0 = 0):
        self.Hleft = Hleft0
        self.longueur = longueur0
        self.largeur = largeur0

    def __str__(self):
        return "({},{},{})".format(self.Hleft, self.longueur,self.largeur)

    def SURFACE_RECTANGLE(self):
        return self.longueur * self.largeur

    def DESSIN_RECTANGLE(self):
        t = turtle.Turtle()
        t.pencolor("red")
        t.fillcolor("yellow")
        t.pensize(5)
        t.begin_fill()
        t.goto(self.Hleft, self.Hleft)
        t.forward(self.longueur)
        t.left(90)
        t.forward(self.largeur)
        t.left(90)
        t.forward(self.longueur)
        t.left(90)
        t.forward(self.largeur)
        t.left(90)
        t.end_fill()
Hleft = abs(int(input("Coordonne en haut a gauche : ")))
longueur = abs(int(input("Longueur du rectangle : ")))
largeur = abs(int(input("Largeur du rectangle : ")))
R1 = RECTANGLE(Hleft,longueur,largeur)
R2 = RECTANGLE(Hleft,longueur,largeur)
print("Surface rectangle 1 : ", R1.SURFACE_RECTANGLE())
print("Surface rectangle 1 : ", R2.SURFACE_RECTANGLE())

print(R1.DESSIN_RECTANGLE())