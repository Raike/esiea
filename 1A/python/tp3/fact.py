def FACT(n):
    a=1
    for i in range(1,n+1):
        a=a*i
    return a

n = int(input("Entrez une valeur : "))
print("Factorrielle", n, "est :", FACT(n))