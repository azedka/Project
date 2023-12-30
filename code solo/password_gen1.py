import random
import string

def generate_password():
    include_letters = input("Do you want letters in your password? (yes/no): ").lower()

    if include_letters == "yes":
        num_letters = int(input("How many letters do you want in your password: "))
        random_letters = [random.choice(string.ascii_letters) for _ in range(num_letters)]

        include_digits = input("Do you want digits in your password? (yes/no): ").lower()

        if include_digits == "yes":
            num_digits = int(input("How many digits do you want in your password: "))
            random_digits = [random.randint(0, 9) for _ in range(num_digits)]
        else:
            random_digits = []

        random_strings = [''.join(random_letters + [str(digit) for digit in random_digits])]
        print("Random strings:", random_strings)
    else:
        print("You need to specify whether you want letters in your password.")

# Function to ask the user if they want to rerun the program
def rerun():
    return input("Do you want to generate another password? (yes/no)").lower() == "yes"

# Main loop
while True:
    generate_password()

    # Ask the user if they want to rerun
    if not rerun():
        break


