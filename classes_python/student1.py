class Student:
    def __init__(self, name: str):
        self.name = name
        self._grades: list[float] = []

    @property
    def name(self) -> str:
        return self._name

    @name.setter
    def name(self, value: str):
        if not value or not isinstance(value, str):
            raise ValueError("Name cannot be empty!")
        self._name = value

    @property
    def grades(self) -> list[float]:
        return self._grades.copy()

    def add_grade(self, grade: float) -> str:
        if not 0 <= grade <= 100:
            raise ValueError("Grade must be between 0 and 100!")
        self._grades.append(grade)
        return f"Added grade {grade} for {self.name}"

    @property
    def average(self) -> float:
        """Computed property (muito poderoso!)"""
        if not self._grades:
            raise ValueError(f"{self.name} has no grades yet!")
        return sum(self._grades) / len(self._grades)

    def __str__(self):
        return f"Student({self.name}, average={self.average:.1f})"


# Uso bem mais limpo
s = Student("Bob")
s.add_grade(85)
s.add_grade(90)
print(s.average)           # 87.5
print(s)                   # Student(Bob, average=87.5)