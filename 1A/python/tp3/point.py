from math import sqrt 

class POINT:
    def __init__(self, x0 = 0, y0 =0):
        self.x = x0
        self.y = y0

    def __str__(self):
        return "({},{})".format(self.x, self.y)

    def DISTANCE_ORIGINE(self):
        return ((self.x ** 2) + (self.y ** 2)) **0.5

    def DISTANCE_POINT(self, other):
        dx = self.x - other.x
        dy = self.y - other.y

P1 = POINT(3, 4)
print(P1)
d = P1.DISTANCE_ORIGINE()
print("Distance d'origine = > ", d)
P2 = POINT(4, 3)
d1 = P1.DISTANCE_ORIGINE()
d2 = P2.DISTANCE_ORIGINE()
print("Distance entre P1 et P2", d1, d2)