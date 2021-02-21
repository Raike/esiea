def Maximum(A, B):
    if A > B:
        return A
    else:
        return B
def Minimum(A, B):
    if A < B:
        return A
    else:
        return B
def Classement(A, B, C):
    if  C > Maximum(A, B):
        if A > B:
            print(B, A, C)
        else:
            print(A, B, C)
    elif C < Minimum(A, B):
        if A < B:
            print(C, A, B)
        else:
            print(C, B, A)
    else:
        if A > B:
            print(B, C, A)
        else:
            print(A, C, B)
A = input("Donnez la valeur de A : ")
B = input("Donnez la valeur de B : ")
C = input("Donnez la vlauer de C : ")
Classement(A, B, C)