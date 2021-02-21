def EstPremier(A):
    test=0
    for i in range(1,A+1):
        if A%i==0:
            test=test+1
    if test==2:
        c=0
        return c
    else:
        c=1
        return c

def Sum_Prem(P, G):
    S=0
    for i in range(P, G+1):
        if EstPremier(i)==0:
            S=S+i
    return S

A = int(input("Entrez une valeur : "))
P = int(input("Entrez la valeur la plus petites: "))
G = int(input("Entrez la valeur la plus grandes: "))

if EstPremier(A)==0:
    print(A, "est premier")
else:
    print(A, "n'est pas premier")
print("La somme des nombres premier entre" , P, "et" , G, "est", Sum_Prem(P,G))