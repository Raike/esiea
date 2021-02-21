Ps = 2.3
Vs = 7.4
Pc = input("Entrez la pression courante : ")
Vc = input("Entrez la voulume courante : ")
if Pc > Ps and Vc > Vs:
    print("Arret immediat")
elif Pc > Ps and Vc < Vs :
    print("Augmenter le volume de lenceinte")
elif Pc < Ps and Vc > Vs:
    print("Diminuer  le  volume  de lenceinte")
else:
    print("Tout vas bien")