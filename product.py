class Product:
    def __init__(self, name: str, price: float, stock: int = 0):
        self.name = name
        self.price = price
        self.stock = stock

    @property
    def name(self) -> str:
        return self._name

    @name.setter
    def name(self, name: str):
        if not isinstance(name, str) or not name.strip():
            raise ValueError("Name cannot be empty")
        self._name = name.strip()

    @property
    def price(self) -> float:
        return self._price

    @price.setter
    def price(self, price: float):
        if not isinstance(price, (int, float)) or price <= 0:
            raise ValueError("Price must be a positive number")
        self._price = float(price)

    @property
    def stock(self) -> int:
        return self._stock

    @stock.setter
    def stock(self, stock: int):
        if not isinstance(stock, int) or stock < 0:
            raise ValueError("Stock must be a non-negative integer")
        self._stock = stock

    @property
    def is_in_stock(self) -> bool:
        return self.stock > 0

    def sell(self, quantity: int):
        if not isinstance(quantity, int) or quantity < 0:
            raise ValueError("Quantity must be a non-negative integer")
        if quantity > self.stock:
            raise ValueError(f"Not enough stock of '{self.name}'")
        self.stock -= quantity

    def restock(self, quantity: int):
        if not isinstance(quantity, int) or quantity < 0:
            raise ValueError("Quantity must be a non-negative integer")
        self.stock += quantity

    def apply_discount(self, percent: float):
        if not isinstance(percent, (int, float)) or not (0 < percent <= 100):
            raise ValueError("Discount must be between 0 and 100")
        self.price *= (100 - percent) / 100

    def __str__(self):
        return f"{self.stock} × {self.name} @ R${self.price:.2f} each"


p = Product("banana", 5, 5000)
print(p)

if p.is_in_stock:
    p.sell(1000)
    print(p)

p.restock(500)
print(p)

p.apply_discount(20)
print(p)

print(p.is_in_stock)

if p.is_in_stock:
    p.sell(4500)
    print(p)

print(p.is_in_stock)
