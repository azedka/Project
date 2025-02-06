pesos = int(input("What do you have left in pesos ? : "))
soles = int(input("What do you have left in soles ? : "))
reais = int(input("What do you have left in reais ? : "))

pesos_usd = pesos * 0.05 
soles_usd = soles * 0.26
reais_usd = reais * 0.16

total_amout = pesos_usd + soles_usd + reais_usd
print("you had", total_amout, "$ left.")