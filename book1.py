# Example 3: Library Book
class Book:
    def __init__(self, title, author, isbn):
        self._title = title
        self._author = author
        self._isbn = isbn
        self._is_checked_out = False

    def check_out(self):
        if self._is_checked_out:
            raise ValueError("Book is already checked out")
        self._is_checked_out = True

    def return_book(self):
        if not self._is_checked_out:
            raise ValueError("Book is not checked out")
        self._is_checked_out = False

    @property
    def title(self):
        return self._title

    @property
    def is_available(self):
        return not self._is_checked_out