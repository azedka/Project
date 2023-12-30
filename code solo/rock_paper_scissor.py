import random
print("                            ROCK, PAPER, SCISSORS GAME ")
print("                                  Here are the rules:")
print("                                 Paper beats rock")
print("                                 Rock beats scissors")
print("                                 Scissors beat paper")

score_bot = 0
score_player = 0

def play_game():
    global score_bot
    global score_player
    comp_choice = random.randint(1, 3)
    user_choice = int(input("Please enter your move (paper = 1 / rock = 2 / scissors = 3): "))
    
    if (comp_choice == 1) and (user_choice == 1):
        print("IT'S A TIE (paper-paper)")

    if (comp_choice == 1) and (user_choice == 2):
        print("COMPUTER WINS (paper-rock)")
        score_bot += 1

    if (comp_choice == 1) and (user_choice == 3):
        print("YOU WIN (paper-scissors)")
        score_player += 1

    if (comp_choice == 2) and (user_choice == 1):
        print("YOU WIN (rock-paper)")
        score_player += 1

    if (comp_choice == 2) and (user_choice == 2):
        print("IT'S A TIE (rock-rock)")

    if (comp_choice == 2) and (user_choice == 3):
        print("COMPUTER WINS (rock-scissors)")
        score_bot += 1

    if (comp_choice == 3) and (user_choice == 1):
        print("COMPUTER WINS (scissors-paper)")
        score_bot += 1

    if (comp_choice == 3) and (user_choice == 2):
        print("YOU WIN (scissors-rock)")
        score_player += 1

    if (comp_choice == 3) and (user_choice == 3):
        print("IT'S A TIE (scissors-scissors)")

while True:
    play_game()
    print("Score: Computer", score_bot, "- Player", score_player)
