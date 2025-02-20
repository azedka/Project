import random

symbols = ['🍒', '🍇', '🍉', '7️⃣']
continuer = True

while continuer == True:
    result_1 = random.choice(symbols)
    result_2 = random.choice(symbols)
    result_3 = random.choice(symbols)

    print(result_1, "|",result_2, " |", result_3)
    if result_3 == result_2 == result_1:
        print("Jackpot! 💰")
    else: 
        print("Nice try")
    
    choice = input("Do you want to continue (Y/N) : ")
    if choice.upper == "N":
        break
