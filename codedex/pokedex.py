class Pokedex:
    def __init__(self, entry, name, types, description, is_caught):
        self.entry = entry
        self.name = name
        self.types = types
        self.description = description
        self.is_caught = is_caught

    def speak(self):
        print(self.name)
    
    def display_detail(self):
        print("Entry : ", self.entry)
        print("Name : ", self.name)
        print("Types : ", self.types)
        print("Description : ", self.description)
        if self.is_caught == True:
            print(self.name, "has already been captured")
        else:
            print(self.name, "never been captured")

bulbasaur = Pokedex(1, "Bulbasaur", ["Grass", "Poison", ], "For some time after its birth, it uses the nutrients that are packed into the seed on its back in order to grow.", True )
charmander = Pokedex(4, "Charmander", "Fire", "The flame on its tail shows the strength of its life-force. If Charmander is weak, the flame also burns weakly.", False)
squirtle = Pokedex(7, "Squirtle", "Water", "After birth, its back swells and hardens into a shell. It sprays a potent foam from its mouth.", True)


bulbasaur.speak()
bulbasaur.display_detail()

charmander.speak()
charmander.display_detail()

squirtle.speak()
squirtle.display_detail()


        
        