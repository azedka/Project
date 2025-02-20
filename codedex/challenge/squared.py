number = int(input("Enter a number : "))
total = 0
for i in range(1, number+1):
    print(i*i)
    total += i*i

print(total)
