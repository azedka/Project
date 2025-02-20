# If they are tall enough and have enough credits, print "Enjoy the ride!"
# Else if they have enough credits, but they aren't tall enough, print "You are not tall enough to ride."
# Else if they are tall enough, but they don't have enough credits, print "You don't have enough credits."
# Else, print a message saying they have not met either requirement.

height = 180
credits = 9 

if height >= 137 and credits >= 10:
    print("Good ride")

elif credits <= 10:
    print("You don't have enought money")

elif height <= 137:
    print("You are not tall enought to ride")

else:
     print("You have not met either requirement")