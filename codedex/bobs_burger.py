
class Restaurants:
    name = ""
    categorie = ""
    rating = 0.0
    delivery = False

bobs_burger = Restaurants()
bobs_burger.name = 'Bob\'s Burgers'
bobs_burger.categorie = 'American Diner'
bobs_burger.rating = 4.7
bobs_burger.delivery = False

print(vars(bobs_burger))

Sushimi = Restaurants()
Sushimi.name = 'Sushimi'
Sushimi.categorie = 'Japan restaurant'
Sushimi.rating = 4.5
Sushimi.delivery = True

print(vars(Sushimi))

Pizza_del_madre = Restaurants()
Pizza_del_madre.name = 'Pizza_del_madre'
Pizza_del_madre.categorie = 'Italian dinner'
Pizza_del_madre.rating = 4
Pizza_del_madre.delivery = True

print(vars(Pizza_del_madre))