import random

coins = 10

def play():
    global coins
    num = random.randint(1, 10)

    if num == 1:
        print("[-------]")
        print("[ 0     ]")
        print("[     0 ]")
        print("[   0   ]")
        print("[-------]")

    if num == 2:
        print("[-------]")
        print("[ 0 0   ]")
        print("[     0 ]")
        print("[       ]")
        print("[-------]")

    if num == 3:
        print("[-------]")
        print("[ 0     ]")
        print("[     0 ]")
        print("[ 0     ]")
        print("[-------]")

    if num == 4:
        print("[-------]")
        print("[ 0 0 0 ]")
        print("[       ]")
        print("[       ]")
        print("[-------]")

    if num == 5:
        print("[-------]")
        print("[       ]")
        print("[       ]")
        print("[ 0 0 0 ]")
        print("[-------]")

    if num == 6:
        print("[-------]")
        print("[ 0   0 ]")
        print("[       ]")
        print("[   0   ]")
        print("[-------]")

    if num == 7:
        print("[-------]")
        print("[     0 ]")
        print("[   0   ]")
        print("[ 0     ]")
        print("[-------]")

    if num == 8:
        print("[-------]")
        print("[ 0     ]")
        print("[   0   ]")
        print("[     0 ]")
        print("[-------]")

    if num == 9:
        print("[-------]")
        print("[ 0     ]")
        print("[   0 0 ]")
        print("[       ]")
        print("[-------]")

    if num == 10:
        print("[-------]")
        print("[       ]")
        print("[ 0 0 0 ]")
        print("[       ]")
        print("[-------]")
        coins += 20

while True:
    choice = input('Do you want to play again? (yes/no): ')
    
    if choice.lower() == "yes":
        if coins > 0:
            play()
            coins -= 1
            print("You have", coins, "coins")
        elif coins == 0:
            print("You don't have enough coins.")
            print("Goodbye!")
            break

    elif choice.lower() == "no":
        print("Goodbye!")
        break

    else:
        print("Goodbye!")
