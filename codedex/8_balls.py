import random
question = input("Question : ")
rndm = random.randint(1,9)
print(rndm)
answer = ""

if rndm == 1:
    answer = "Yes - definitely."
if rndm == 2:
    answer = "It is decidedly so."
if rndm == 3:
    answer = "Without a doubt."
if rndm == 4:
    answer = "Reply hazy, try again."
if rndm == 5:
    answer = "Ask again later."
if rndm == 6:
    answer = "Better not tell you now."
if rndm == 7:
    answer = "My sources say no."
if rndm == 8:
    answer = "Outlook not so good."
if rndm == 9:
    answer = "Very doubtful."

print("Magic balls says : ", answer)
