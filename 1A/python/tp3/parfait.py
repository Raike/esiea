def ESTPARFAIT(n):
    S=0
    for i in range(1, N):
        if N%i==0:
            S=S+i
    if S==N:
        print(True)
    else:
        print(False)
N = int(input("Entrez une valeur : "))
ESTPARFAIT(N)
