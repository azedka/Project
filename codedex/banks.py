
class BankAccount:
    def __init__(self, first_name, last_name, account_id, account_type, pin, balance):
        self.first_name = first_name
        self.last_name = last_name
        self.account_id = account_id
        self.account_type = account_type
        self.pin = pin
        self.balance = balance

    def deposit(self, ammount):
        pin_input = int(input("Put your pin : "))
        if pin_input == self.pin:
            self.balance += ammount
            print("You had add", ammount, "$, you had now", self.balance, "$")
        else:
            print("Wrong password")

    def withdraw(self, ammount):
        pin_input = int(input("Put your pin : "))
        if pin_input == self.pin:
            
            self.balance -= ammount
            print("You had substract", ammount, "$, you had now", self.balance, "$")
        else:
            print("Wrong password")


    def display_balance(self):
        print("You have", self.balance, "$")

Azedka = BankAccount("Azedka", "Bagnette", 1, "Casual", 1234, 0.0)

Azedka.deposit(10)
Azedka.withdraw(20)
Azedka.display_balance()