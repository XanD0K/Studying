class Student:
    def __init__(self, name):
        self.name = name
        self.grades = []
        if not name:
            sys.exit("Name cannot be empty!")

    def add_grade(self, grade):
        if not 0 <= grade <= 100:
            return "Grade must be between 0 and 100!"
        self.grades.append(grade)
        return f"Added grade {grade} for {self.name}"

    def get_average(self):
        if not self.grades:
            return f"{self.name} has no grades yet!"
        average = sum(self.grades) / len(self.grades)
        return f"{self.name}'s average is {average:.1f}"

# Usage
student = Student("Bob")
print(student.add_grade(85))    # Added grade 85 for Bob
print(student.add_grade(90))    # Added grade 90 for Bob
print(student.get_average())    # Bob's average is 87.5
print(student.add_grade(101))   # Grade must be between 0 and 100!