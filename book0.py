class Book:
    def __init__(self, title, author, total_pages):
        self.title = title
        self.author = author
        self.total_pages = total_pages
        self.pages_read = 0
        if total_pages <= 0:
            sys.exit("Total pages must be positive!")

    def read_pages(self, pages):
        self.pages_read += pages
        if self.pages_read > self.total_pages:
            self.pages_read = self.total_pages
        return f"Read {pages} pages of {self.title}. Now at {self.pages_read}/{self.total_pages} pages."

    def is_finished(self):
        return self.pages_read >= self.total_pages

# Usage
book = Book("Python 101", "Jane Doe", 300)
print(book.read_pages(50))  # Read 50 pages of Python 101. Now at 50/300 pages.
print(book.is_finished())   # False
print(book.read_pages(250)) # Read 250 pages of Python 101. Now at 300/300 pages.
print(book.is_finished())   # True