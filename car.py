class Car:
    def __init__(self, brand, mileage):
        self.brand = brand  # Store brand
        self.mileage = mileage  # Store mileage
    
    @property
    def brand(self):
        return self._brand
    
    @brand.setter
    def brand(self, brand):
        if not brand or not isinstance(brand, str):
            raise ValueError("Brand cannot be empty!")
        self._brand = brand

    @property
    def mileage(self):
        return self._mileage
    
    @mileage.setter
    def mileage(self, mileage):
        if not isinstance(mileage, int):
            raise ValueError("Mileage cannot be empty!")
        if mileage < 0:
            raise ValueError("Mileage cannot be negative!")
        self._mileage = mileage

    def drive(self, distance):
        if distance < 0:
            raise ValueError("Distance cannot be negative!")
        self.mileage += distance  # Update mileage
        return f"{self.brand} drove {distance} miles. New mileage: {self.mileage}"

    def get_mileage(self):
        return f"{self.brand} has {self.mileage} miles."
    
    def __str__(self):
        return f"That's a {self.brand} thar drove {self.mileage} miles."


my_car = Car("Toyota", 10000)
print(my_car.get_mileage())  # Toyota has 10000 miles.
print(my_car.drive(50))      # Toyota drove 50 miles. New mileage: 10050
print(my_car)