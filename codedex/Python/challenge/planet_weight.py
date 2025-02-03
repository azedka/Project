weight = float(input("Input your weight : "))
planet = int(input("enter the planet where you are going on (1-7): "))
name = ""

if planet == 1:
    weight = weight*0.38
    name = "Mercury"

elif planet == 2:
    weight = weight*0.91
    name = "Venus"

elif planet == 3:
    weight = weight*0.38
    name = "Mars"

elif planet == 4:
    weight = weight*2.53
    name = "Jupiter"

elif planet == 5:
    weight = weight*1.07
    name = "Saturn"

elif planet == 6:
    weight = weight*0.89
    name = "Uranus"

elif planet == 7:
    weight = weight*1.14
    name = "Neptune"

print(f"You weight {weight} on {name}")
