def welcome():
    print("Hello, this is the menu")
    print("Say 1  for 🍔 Cheeseburger")
    print("Say 2  for 🍟 Fries")
    print("Say 3  for 🥤 Soda ")
    print("Say 4  for 🍦 Ice Cream") 
    print("Say 5  for 🍪 Cookies")

def drive(x):
    choice = x
    if choice == 1:
        print("You choose an 🍔 Cheeseburger ")
    elif choice == 2:
        print("You choose an 🍟 Fries ")
    elif choice == 3:
        print("You choose an 🥤 Soda ")
    elif choice == 4:
        print("You choose an 🍦 Ice Cream")
    elif choice == 5:
        print("You choose an 🍪 Cookies")
    else:
        print("This is an wrong input")


welcome()
s = int(input("What do you want to  order ?"))
drive(s)

