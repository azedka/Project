import random
dice1 = random.randint(1, 6)
dice2 = random.randint(1, 6)

total = dice1 + dice2 
print(total)

response = ""
while response != total:
    response = int(input("Guess the result : "))

print("GG you won")