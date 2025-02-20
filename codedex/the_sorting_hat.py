# Write a program that asks the user some questions with the int() and input() functions:

# Q1) Do you like Dawn or Dusk?
#     1) Dawn
#     2) Dusk

# If answer is equal to 1, Gryffindor and Ravenclaw both get a +1.
# Else if answer is equal to 2, Hufflepuff and Slytherin both get a +1.
# Else, output the message "Wrong input."

# Q2) When I’m dead, I want people to remember me as:
#     1) The Good
#     2) The Great
#     3) The Wise
#     4) The Bold

# If the answer is 1, Hufflepuff +2.
# Else if answer is 2, Slytherin +2.
# Else if answer is 3, Ravenclaw +2.
# Else if answer is 4, Gryffindor +2.
# Else, output the message "Wrong input."

# Q3) Which kind of instrument most pleases your ear?
#     1) The violin
#     2) The trumpet
#     3) The piano
#     4) The drum

# If the answer is 1, Slytherin +4.
# Else if the answer is 2, Hufflepuff +4.
# Else if the answer is 3, Ravenclaw +4.
# Else if the answer is 4, Gryffindor +4.
# Else, output "Wrong input."

# Lastly, print out the score for each house.

# Bonus: If you want to go further, see if you can figure out how to print out the house with the most points!

Hufflepuff = 0
Ravenclaw  = 0
Gryffindor = 0
Slytherin = 0

print("""Q1) Do you like Dawn or Dusk?
     1) Dawn
     2) Dusk""")

Q1 = int(input("Answer : "))
if Q1 == 1:
    Gryffindor += 1
    Ravenclaw += 1
if Q1 == 2: 
    Hufflepuff =+ 1 
    Slytherin += 1 
else:
    print("Wrong input !")


print("""Q2) When I’m dead, I want people to remember me as:
     1) The Good
     2) The Great
     3) The Wise
     4) The Bold""")

Q2 = int(input("Answer : "))
if Q2 == 1:
    Hufflepuff += 2
elif Q2 == 2:
    Slytherin += 2
elif Q2 == 3:
    Ravenclaw += 2
elif Q2 == 4:
    Gryffindor += 2
else:
    print("Wrong input")




print("""Q3) Which kind of instrument most pleases your ear?
     1) The violin
     2) The trumpet
     3) The piano
     4) The drum""")


Q3 = int(input("Answer : "))
if Q3 == 1:
    Slytherin += 4
elif Q3 == 2:
    Hufflepuff += 4
elif Q3 == 3:
    Ravenclaw += 4
elif Q3 == 4:
    Gryffindor += 4
else:
    print("Wrong input")


print("Hufflepuff : ",  Hufflepuff)
print("Slytherin : ", Slytherin)
print("Ravenclaw : ", Ravenclaw)
print("Gryffindor : ",Gryffindor)

if Hufflepuff > Slytherin and Hufflepuff > Ravenclaw and Hufflepuff > Gryffindor:
    print("You are an Hufflepuff")
elif Slytherin > Hufflepuff and Slytherin > Ravenclaw and Slytherin > Gryffindor:
    print("You are an Slytherin")
elif Ravenclaw > Slytherin and Ravenclaw > Hufflepuff and Ravenclaw > Gryffindor:
    print("You are an Ravenclaw")
elif Gryffindor > Slytherin and Gryffindor > Hufflepuff and Gryffindor > Ravenclaw:
    print("You are an Ravenclaw")

else:
    print("Internal error")

