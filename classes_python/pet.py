class Pet:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    @property
    def name(self) -> str:
        return self._name

    @name.setter
    def name(self, name: str):
        if not name or not isinstance(name, str):
            raise ValueError("Name cannot be empty!")
        self._name = name

    @property
    def age(self):
        return self._age
    
    @age.setter
    def age(self, age):
        if age < 0:
            raise ValueError("Age must be a positive integer!")
        self._age = age
        
    def have_birthday(self):
        self.age += 1
        return f"{self.name} is now {self.age} years old!"

    def __str__(self) -> str:
        return f"Pet(name={self.name}, age={self.age})"

my_pet = Pet("Fluffy", 3)
print(my_pet)
print(my_pet.have_birthday())  # Fluffy is now 4 years old!
print(my_pet)