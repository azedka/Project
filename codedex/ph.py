ph = int(input("Enter the ph of your liquid (0-14) : "))

if ph > 7:
    print("Basic")
elif ph < 7:
    print("Acid")
else:
    print("Neutral")