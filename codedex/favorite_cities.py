class Cities:
    def __init__(self, name, country, populations, landmarks):
        self.name = name
        self.country = country
        self.populations = populations
        self.landmarks = landmarks

london = Cities("London", "England", 80000000, ["London bridges", "Homed"])
paris = Cities("Paris", "France", 6000000, ["Effeil Tower", "Versaille"])

print(vars(london))
print(vars(paris))