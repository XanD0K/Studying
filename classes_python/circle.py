import math

class Circle:
    def __init__(self, radius: float):
        self.radius = radius

    @property
    def radius(self) -> float:
        return self._radius

    @radius.setter
    def radius(self, radius: float):
        if not isinstance(radius, (int, float)):
            raise ValueError("Radius must be a number")
        if radius <= 0:
            raise ValueError("Radius must be a positive number")
        self._radius = radius

    @property
    def area(self) -> float:
        return math.pi * self._radius ** 2

    @property
    def circumference(self) -> float:
        return 2 * math.pi * self._radius

    def scale(self, factor: float):
        if not isinstance(factor, (int, float)) or factor <= 0:
            raise ValueError("Factor must be a positive number")
        self.radius = self.radius * factor


# Testes
c = Circle(5)
print(c.area)           # 78.53981633974483
print(c.circumference)  # 31.41592653589793

c.scale(2)
print(c.radius)         # 10.0
print(c.area)           # 314.1592653589793