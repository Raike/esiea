def Fibo(n):
    if n==1:
        return(0)
    elif n==2:
        return(1)
    else:
        return Fibo(n-1)+Fibo(n-2)

n = int(input("Entrez une valeur: "))
for i in range(1,n+1):
    print(Fibo(i))