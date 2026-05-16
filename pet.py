class Pet:
    def __init__(self, name, age):
        self.name = name
        self.age = age
        if age < 0:
            print("Age cannot be negative!")
            exit(1)

    def have_birthday(self):
        self.age += 1
        return f"{self.name} is now {self.age} years old!"

my_pet = Pet("Fluffy", 3)
print(my_pet.have_birthday())  # Fluffy is now 4 years old!