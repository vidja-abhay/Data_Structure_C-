//IN A DATABASE THERE ARE N STUDENTS.THE FIELS OF THE TBALE ARE NAME, AGE, GRADE, GENDER. YOUR TASK IS TO RETURN THE STUDENTS NAMES WHO ARE GREATER THAN 20 YEAR OL AND CALCULATE THE AVERAGE OF GRADES USING ASCII VALUE OF FEMALE CANDIDATES.


#include <iostream>
#include <vector>
#include <string>
#include <iomanip> // for setting precision

using namespace std;

class Student {
private:
    string name;
    int age;
    double grade;
    char gender;

public:
    // Constructor to initialize a student
    Student(string name, int age, double grade, char gender) 
        : name(name), age(age), grade(grade), gender(gender) {}

    // Getter functions
    string getName() const { return name; }
    int getAge() const { return age; }
    double getGrade() const { return grade; }
    char getGender() const { return gender; }
    
    // Static method to get names of students older than 20
    static vector<string> getNamesAbove20(const vector<Student>& students) {
        vector<string> names;
        for (const auto& student : students) {
            if (student.getAge() > 20) {
                names.push_back(student.getName());
            }
        }
        return names;
    }

    // Static method to calculate the average grade using ASCII values for female students
    static double calculateFemaleGradeAverage(const vector<Student>& students) {
        double total = 0.0;
        int femaleCount = 0;

        for (const auto& student : students) {
            if (student.getGender() == 'F' || student.getGender() == 'f') {
                // ASCII value of the first character of the name multiplied by the grade
                total += static_cast<int>(student.getName()[0]) * student.getGrade();
                femaleCount++;
            }
        }

        // Avoid division by zero
        return (femaleCount > 0) ? total / femaleCount : 0.0;
    }
};

int main() {
    // Example list of students
    vector<Student> students = {
        Student("Alice", 21, 85.5, 'F'),
        Student("Bob", 19, 78.0, 'M'),
        Student("Charlie", 22, 92.0, 'M'),
        Student("Diana", 23, 88.5, 'F'),
        Student("Eve", 20, 75.0, 'F')
    };

    // Step 1: Get names of students older than 20
    vector<string> namesAbove20 = Student::getNamesAbove20(students);
    cout << "Students older than 20:" << endl;
    for (const auto& name : namesAbove20) {
        cout << name << endl;
    }

    // Step 2: Calculate the average grade using ASCII values for female students
    double avgFemaleGrade = Student::calculateFemaleGradeAverage(students);
    cout << fixed << setprecision(2);
    cout << "Average grade (using ASCII values of names) for female students: " << avgFemaleGrade << endl;

    return 0;
}
