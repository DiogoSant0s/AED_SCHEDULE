#include "../Headers/Student.h"

//Student constructors
Student::Student(string name, int StudentId, vector<UC> classes) : name(std::move(name)), StudentId(StudentId), classes(std::move(classes)) {}
Student::Student(const Student &S) {
    this -> name = S.name;
    this -> StudentId = S.StudentId;
    this -> classes = S.classes;
}

//Student getters
string Student::getName() {return name;}
int Student::getId() const {return StudentId;}
vector<UC> Student::getClasses() {return classes;}

//Student setters
void Student::setName(string newName) {name = std::move(newName);}
void Student::setId(int newStudentId) {StudentId = newStudentId;}
void Student::setClasses(vector<UC> newClasses) {classes = std::move(newClasses);}

void Student::addUC(const UC& UC) {classes.push_back(UC);}

bool Student::operator==(Student& S) const {
    return S.getName() == name && S.getId() == StudentId;
}
