def add(x, y):
    return x + y

def sub(x, y):
    return x - y

def mul(x, y):
    return x * y

def div(x, y):
    return x / y

print("1. Add\n2. Sub\n3. Mul\n4. Div")

choice = input("Entrer an option :")

if choice == 0 or choice > 4:
    print("Eror")
    quit()

A = float(input("Entrer a number :"))
B = float(input("Entrer another number :"))

if choice == 1:
    print(A, '+', B, '=', add(A,B))
elif choice == 2:
    print(A, '-', B, '=', sub(A,B))
elif choice == 3:
    print(A, '*', B, '=', mul(A,B))
elif choice == 4:
    print(A, '/', B, '=', div(A,B))
