class Car:
    def __init__(self, brand, mileage):
        self.brand = brand  # Store brand
        self.mileage = mileage  # Store mileage
        if mileage < 0:
            raise ValueError("Mileage cannot be negative!")

    def drive(self, distance):
        self.mileage += distance  # Update mileage
        return f"{self.brand} drove {distance} miles. New mileage: {self.mileage}"

    def get_mileage(self):
        return f"{self.brand} has {self.mileage} miles."

def main():
    my_car = Car("Toyota", 10000)
    print(my_car.get_mileage())  # Toyota has 10000 miles.
    print(my_car.drive(50))      # Toyota drove 50 miles. New mileage: 10050