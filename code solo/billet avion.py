istanbul = 200
dubai = 500
jakarta = 800

destination = input("Where do you want to go? (Istanbul(1), Dubai(2), Jakarta(3)): ")
destination = int(destination)

total_price = 0

if destination == 1:
    total_price += istanbul
elif destination == 2:
    total_price += dubai
elif destination == 3:
    total_price += jakarta
else:
    print("Invalid destination")

print("The initial total price is", total_price, "euros")

travel_class = input("Do you want to be in economy or first class? (1/2): ")
travel_class = int(travel_class)

if travel_class == 2:
    total_price *= 3
elif travel_class != 1:
    print("Invalid response")

print("The total price after class selection is", total_price, "euros")

number_of_people = int(input("How many people will be traveling? "))

people_info = {}
for i in range(1, number_of_people + 1):
    person_name = input(f"Enter the name of person {i}: ")
    person_age = int(input(f"Enter the age of person {i}: "))

    if person_age < 18 or person_age > 60:
        person_fare = 0.8 * total_price
    else:
        person_fare = total_price

    people_info[person_name] = {'age': person_age, 'fare': person_fare}

print("Information about people and total price per person:")
for person, info in people_info.items():
    print(f"{person}, {info['age']} years old, Fare: {info['fare']} euros")

total_final_price = sum(info['fare'] for info in people_info.values())
print("The final total price for all people is", total_final_price, "euros")
