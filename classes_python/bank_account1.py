# Example 1: Bank Account
class BankAccount:
    def __init__(self, owner, balance=0):
        self.owner = owner
        self.balance = balance

    @property
    def balance(self):
        return self._balance

    @property
    def owner(self):
        return self._owner
    
    @owner.setter
    def owner(self, owner):
        if not owner.strip():
            raise ValueError("Account must have an owner!")
        self._owner = owner.strip()

    def deposit(self, amount):
        if amount <= 0:
            raise ValueError("Deposit amount must be positive")
        self._balance += amount

    def withdraw(self, amount):
        if amount <= 0:
            raise ValueError("Withdrawal amount must be positive")
        if amount > self._balance:
            raise ValueError("Insufficient funds")
        self._balance -= amount

    def __str__(self) -> str:
        return f"BankAccount(owner={self.owner}, balance=R${self.balance:.2f})"



account = BankAccount("Maria Silva", 1000)
print(account)

account.deposit(500)
print(account.balance)        # 1500

account.withdraw(200)
print(account)                # BankAccount(owner=Maria Silva, balance=R$1300.00)