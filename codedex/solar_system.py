from math import pi
from random import choice as ch 

planets = [
  'Mercury',
  'Venus',
  'Earth',
  'Mars',
  'Saturn'
]

planet_choose = ch(planets)

if planet_choose == "Mercury":
    r = 2440
elif planet_choose == "Venus":
    r = 6052
elif planet_choose == "Earth":
    r = 6371
elif planet_choose == "Mars":
    r = 3390
elif planet_choose =="Saturn":
    r = 58232 
else:
    print("Oops there is an error !")

area = 4 * pi * r ** 2

print(f"For the planets {planet_choose}, the area is {area}")