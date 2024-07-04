#include "../Headers/Request.h"

//Request constructor
Request::Request(int StudentId, string codeUC, string Class, string requestType) : StudentId(StudentId), codeUC(std::move(codeUC)), Class(std::move(Class)), requestType(std::move(requestType)) {}

//Request getters
int Request::getStudentId() const {return StudentId;}
string Request::getcodeUC() const {return codeUC;}
string Request::getClass() const {return Class;}
string Request::getRequestType() const {return requestType;}
string Request::getRequestStatus() const {return requestStatus;}

//Request setter
void Request::setRequestStatus(string newrequestStatus) {this -> requestStatus = std::move(newrequestStatus);}

bool Request::handleRequest(vector<Student> Students, const vector<UC*>& UCs, const vector<Schedule>& Schedules) {
    if (requestType == "remove") {
        for (Student &S: Students) {
            if (S.getId() == StudentId) {
                vector<UC> temp;
                for (UC &i: S.getClasses()) {
                    if (i.getcodeUC() != codeUC && i.getClass() != Class) {
                        temp.emplace_back(i.getcodeUC(), i.getClass());
                    }
                    if (i.getcodeUC() == codeUC && i.getClass() == Class) {
                        i.removeStudent();
                    }
                }
                S.setClasses(temp);
            }
        }
        setRequestStatus("accepted");
        return true;
    }
    else if (requestType == "add") {
        for (Student &S: Students) {
            if (S.getId() == StudentId) {
                for (UC *i : UCs) {
                    if (i -> getcodeUC() == codeUC && i -> getClass() == Class && i -> getNumStudents() < UC::getcap()) {
                        i->addStudent();
                        S.addUC(UC(codeUC, Class));
                    }
                    else {
                        setRequestStatus("rejected");
                        return false;
                    }
                }
            }
        }
        setRequestStatus("accepted");
        return true;
    }
    return false;
}
