bill = [13.99, 28.75, 9.99, 9.99, 6.95, 7.45, 16.45, 16.45]
my_share = 0
for shop in bill:
    my_share += shop
    print(my_share)

my_share /= 4
print(my_share)