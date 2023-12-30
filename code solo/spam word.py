import keyboard
import time

word = input("enter the word to spam  : ")
many = int(input("Please enter how many times the word will be written : "))
delay = float(input("Please enter how often, in seconds, the word will be written : "))
def spam():
    time.sleep(3)

    for _ in range(many):
        keyboard.write(word)

        keyboard.press_and_release("enter")

        time.sleep(delay)

spam()
