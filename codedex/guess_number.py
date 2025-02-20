guess = 0
tries = 0

while guess != 6 and tries < 5:
  guess = int(input("Guess the number:  "))
  tries += 1
  print(tries)

if guess != 6:
    print("You are enough of tries")
else:
   print("You find it !")
