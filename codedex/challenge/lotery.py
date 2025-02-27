import random

number = []
my_number = []
for i in range(0, 5): 
    number.append(random.randint(0, 69))
    my_number.append(random.randint(0, 69))

number.append(random.randint(0, 26))
my_number.append(random.randint(0, 26))



print("My number : ", my_number)
print("Wining number : ", number)
if my_number == number:
    print("You are a goat")
else: 
    print('noob')
