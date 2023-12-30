import keyboard
import time

def spam_number():
    time.sleep(5)

    for number in range(1, 301):
        keyboard.write(str(number))
        keyboard.press_and_release("enter")

        time.sleep(0.001)

spawn_number()
