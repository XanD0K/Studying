class BankAccount:
    def __init__(self, owner, initial_balance):
        self.owner = owner
        self.balance = initial_balance
        if initial_balance < 0:
            sys.exit("Initial balance cannot be negative!")

    def deposit(self, amount):
        if amount <= 0:
            return "Deposit must be positive!"
        self.balance += amount
        return f"{self.owner} deposited ${amount}. New balance: ${self.balance}"

    def withdraw(self, amount):
        if amount <= 0:
            return "Withdrawal must be positive!"
        if amount > self.balance:
            return "Insufficient funds!"
        self.balance -= amount
        return f"{self.owner} withdrew ${amount}. New balance: ${self.balance}"

# Usage
account = BankAccount("Alice", 1000)
print(account.deposit(500))   # Alice deposited $500. New balance: $1500
print(account.withdraw(200))  # Alice withdrew $200. New balance: $1300
print(account.withdraw(2000)) # Insufficient funds!