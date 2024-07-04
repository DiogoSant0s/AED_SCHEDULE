#include "../Headers/UC.h"

//UC constructors
UC::UC(string codeUC, string Class, int NumStudents) : codeUC(std::move(codeUC)), Class(std::move(Class)), NumStudents(NumStudents) {}
UC::UC(string codeUC, string Class) : codeUC(std::move(codeUC)), Class(std::move(Class)) {}
UC::UC(const UC& C) {
    this -> codeUC = C.codeUC;
    this -> Class = C.Class;
}

//UC getters
string UC::getcodeUC() const {return codeUC;}
string UC::getClass() const {return Class;}
int UC::getcap() {return cap;}
int UC::getNumStudents() const {return NumStudents;}

//UC setters
void UC::setcodeUC(string newcodeUC) {this -> codeUC = std::move(newcodeUC);}
void UC::setClass(string newClass) {this -> Class = std::move(newClass);}

void UC::addStudent() {
    NumStudents++;
}

void UC::removeStudent() {
    NumStudents--;
}

bool UC::operator==(UC& UC) const {
    return UC.getcodeUC() == codeUC && UC.getClass() == Class;
}
