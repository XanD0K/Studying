import sys

class Student:
    def __init__(self, name):
        self.name = name
        self._grades = []
    
    # Getter
    @property
    def name(self):
        return self._name

    # Setter
    @name.setter
    def name(self, name):
        if not name:
            sys.exit("Name cannot be empty!")
        self._name = name

    @property
    def grades(self):
        return self._grades.copy()
    
    def add_grade(self, grade):
        if not 0 <= grade <= 100:
            return "Grade must be between 0 and 100!"
        self._grades.append(grade)
        return f"Added grade {grade} for {self.name}"

    def get_average(self):
        if not self._grades:
            return f"{self.name} has no grades yet!"
        average = sum(self._grades) / len(self._grades)
        return f"{self.name}'s average is {average:.1f}"


# Usage
student = Student("Bob")
print(student.add_grade(85))    # Added grade 85 for Bob
print(student.add_grade(90))    # Added grade 90 for Bob
print(student.get_average())    # Bob's average is 87.5
print(student.add_grade(101))   # Grade must be between 0 and 100!