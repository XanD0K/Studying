# Example 3: Library Book
class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author
        self._is_checked_out = False

    @property
    def title(self):
        return self._title
    
    @title.setter
    def title(self, title):
        if not title.strip():
            raise ValueError("Title can't be empty")
        self._title = title.strip()

    @property
    def author(self):
        return self._author
    
    @author.setter
    def author(self, author):
        if not author.strip():
            raise ValueError("Author can't be empty")
        self._author = author.strip()

    @property
    def is_available(self):
        return not self._is_checked_out
    
    def checked_out(self):
        if self._is_checked_out:
            raise ValueError(f"{self.title.title()} is already checked out")
        self._is_checked_out = True

    def return_book(self):
        if not self._is_checked_out:
            raise ValueError(f"{self.title.title()} is not checked out")
        self._is_checked_out = False

    def __str__(self) -> str:
        status = "Available" if self.is_available else "Checked out"
        return f"Book('{self.title}' by {self.author}) - {status}"


book = Book("Clean Code", "Robert C. Martin")

print(book)                    # Book('Clean Code' by Robert C. Martin) - Available
print(book.is_available)       # True

book.check_out()
print(book)                    # Book('Clean Code' by Robert C. Martin) - Checked out
print(book.is_available)       # False

book.return_book()
print(book.is_available)       # True