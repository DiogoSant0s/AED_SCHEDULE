#include "../Headers/LoadData.h"

//Compare bools for the sorters
bool compareCodeUCpointer(UC* U1, UC* U2) {
    if (U1 -> getcodeUC() == U2 -> getcodeUC()) {
        if (U1 -> getClass().front() == U2 -> getClass().front()) {
            if (U1 -> getClass()[5] == U2 -> getClass()[5]) {
                return U1 -> getClass()[6] < U2 -> getClass()[6];
            }
            else {
                return U1 -> getClass()[5] < U2 -> getClass()[5];
            }
        }
        else {
            return U1 -> getClass().front() < U2 -> getClass().front();
        }
    }
    else if (U1 -> getcodeUC()[6] == U2 -> getcodeUC()[6]) {
        return U1 -> getcodeUC()[7] < U2 -> getcodeUC()[7];
    }
    else {
        return U1 -> getcodeUC()[6] < U2 -> getcodeUC()[6];
    }
}

bool compareClassCodepointer(UC* U1, UC* U2) {
    if (U1 -> getClass() == U2 -> getClass()) {
        if (U1 -> getcodeUC()[6] == U2 -> getcodeUC()[6]) {
            return U1 -> getcodeUC()[7] < U2 -> getcodeUC()[7];
        }
        else {
            return U1 -> getcodeUC()[6] < U2 -> getcodeUC()[6];
        }
    }
    else if (U1 -> getClass().front() == U2 -> getClass().front()) {
        if (U1 -> getClass()[5] == U2 -> getClass()[5]) {
            return U1 -> getClass()[6] < U2 -> getClass()[6];
        }
        else {
            return U1 -> getClass()[5] < U2 -> getClass()[5];
        }
    }
    else {
        return U1 -> getClass().front() < U2 -> getClass().front();
    }
}

bool compareNumStudentspointer(UC* U1, UC* U2) {
    if (U1 -> getNumStudents() == U2 -> getNumStudents()) {
        if (U1 -> getcodeUC() == U2 -> getcodeUC()) {
            if (U1 -> getClass().front() == U2 -> getClass().front()) {
                if (U1 -> getClass()[5] == U2 -> getClass()[5]) {
                    return U1 -> getClass()[6] < U2 -> getClass()[6];
                }
                else {
                    return U1 -> getClass()[5] < U2 -> getClass()[5];
                }
            }
            else {
                return U1 -> getClass().front() < U2 -> getClass().front();
            }
        }
        else if (U1 -> getcodeUC()[6] == U2 -> getcodeUC()[6]) {
            return U1 -> getcodeUC()[7] < U2 -> getcodeUC()[7];
        }
        else {
            return U1 -> getcodeUC()[6] < U2 -> getcodeUC()[6];
        }
    }
    else {
        return U1 -> getNumStudents() < U2 -> getNumStudents();
    }
}

bool compareStudentId(Student& S1, Student& S2) {
    return S1.getId() < S2.getId();
}

bool compareStudentName(Student& S1, Student& S2) {
    string a = S1.getName();
    string b = S2.getName();
    for (char& i : a) {i = (char) tolower(i);}
    for (char& i : b) {i = (char) tolower(i);}
    return a.compare(b) < 0;
}

bool compareSceduleCodeUC(Schedule& S1, Schedule& S2) {
    if (S1.getCodeUC().size() == S2.getCodeUC().size()) {
        if (S1.getCodeUC() == S2.getCodeUC()) {
            if (S1.getClass().front() == S2.getClass().front()) {
                if (S1.getClass()[5] == S2.getClass()[5]) {
                    return S1.getClass()[6] < S2.getClass()[6];
                }
                else {
                    return S1.getClass()[5] < S2.getClass()[5];
                }
            }
            else {
                return S1.getClass().front() < S2.getClass().front();
            }
        }
        else if (S1.getCodeUC()[6] == S2.getCodeUC()[6]) {
            return S1.getCodeUC()[7] < S2.getCodeUC()[7];
        }
        else {
            return S1.getCodeUC()[6] < S2.getCodeUC()[6];
        }
    }
    else {
        return S1.getCodeUC().size() < S2.getCodeUC().size();
    }
}

bool compareSceduleClassCode(Schedule& S1, Schedule& S2) {
    if (S1.getClass() == S2.getClass()) {
        if (S1.getCodeUC().size() == S2.getCodeUC().size()) {
            if (S1.getCodeUC()[6] == S2.getCodeUC()[6]) {
                return S1.getCodeUC()[7] < S2.getCodeUC()[7];
            }
            else {
                return S1.getCodeUC()[6] < S2.getCodeUC()[6];
            }
        }
        else {
            return S1.getCodeUC().size() < S2.getCodeUC().size();
        }
    }
    else if (S1.getClass().front() == S2.getClass().front()) {
        if (S1.getClass()[5] == S2.getClass()[5]) {
            return S1.getClass()[6] < S2.getClass()[6];
        }
        else {
            return S1.getClass()[5] < S2.getClass()[5];
        }
    }
    else {
        return S1.getClass().front() < S2.getClass().front();
    }
}

void LoadData::loadData_Classes() {
    string textLine;
    ifstream File("../Schedule_Files/classes.csv");
    getline(File, textLine);

    while (getline(File, textLine)) {
        string codeUC, Class, Weekday, StartHour, Duration, Type;
        stringstream input(textLine);
        int weekday = 0;

        getline(input, Class, ',');
        getline(input, codeUC, ',');
        getline(input, Weekday, ',');
        getline(input, StartHour, ',');
        getline(input, Duration, ',');
        getline(input, Type, '\r');

        if (Weekday == "Monday") {weekday = 1;}
        else if (Weekday == "Tuesday") {weekday = 2;}
        else if (Weekday == "Wednesday") {weekday = 3;}
        else if (Weekday == "Thursday") {weekday = 4;}
        else if (Weekday == "Friday") {weekday = 5;}
        float start = stof(StartHour);
        float end = stof(Duration) + start;

        Interval currentInterval = Interval(weekday, start, end, Type);
        UC currentUC = UC(codeUC, Class);
        Schedule currentSchedule = Schedule(currentUC, {currentInterval});

        if (Schedules.empty()) Schedules.push_back(currentSchedule);
        else {
            bool unique = true;
            for (Schedule& i : Schedules) {
                if (currentSchedule == i) {
                    i.addInterval(currentInterval);
                    unique = false;
                }
            }
            if (unique) Schedules.push_back(currentSchedule);
        }
    }
}

void LoadData::loadData_Classes_per_UC() {
    string textLine;
    ifstream File("../Schedule_Files/classes_per_uc.csv");
    getline(File, textLine);
    while (getline(File, textLine)) {
        string UcCode,ClassCode;
        stringstream input(textLine);

        getline(input, UcCode, ',');
        getline(input, ClassCode, '\r');

        UCs.push_back((new UC(UcCode, ClassCode, 0)));
    }
}

void LoadData::loadData_Students_Classes() {
    string textLine;
    ifstream File("../Schedule_Files/students_classes.csv");
    getline(File, textLine);

    while (getline(File, textLine)) {
        string StudentCode, StudentName, UcCode, Class;
        stringstream input(textLine);
        int StudentId;

        getline(input, StudentCode, ',');
        getline(input, StudentName, ',');
        getline(input, UcCode, ',');
        getline(input, Class, '\r');

        StudentId = stoi(StudentCode);
        UC currentUC = UC(UcCode, Class);
        Student currentStudent = Student(StudentName, StudentId, {currentUC});
        for (UC *i : UCs) {
            if (currentUC == *i) {
                i -> addStudent();
            }
        }

        if (Students.empty()) Students.push_back(currentStudent);
        else {
            bool unique = true;
            for (Student& i : Students) {
                if (currentStudent == i) {
                    i.addUC(currentUC);
                    unique = false;
                }
            }
            if (unique) Students.push_back(currentStudent);
        }
    }
    sortStudents_StudentCode();
}

//LoadData getters
vector<UC*> LoadData::getUCs() {return UCs;}
vector<Schedule> LoadData::getSchedules() {return Schedules;}
vector<Student> LoadData::getStudents() {return Students;}
queue<Request>& LoadData::getRequests() {return Requests;}

//LoadData sorters
vector<UC*> LoadData::sortUCs_CodeUC() {
    sort(UCs.begin(), UCs.end(), compareCodeUCpointer);
    return UCs;
}
vector<UC*> LoadData::sortUCs_ClassCode() {
    sort(UCs.begin(), UCs.end(), compareClassCodepointer);
    return UCs;
}
vector<UC*> LoadData::sortUCs_NumStudents() {
    sort(UCs.begin(), UCs.end(), compareNumStudentspointer);
    return UCs;
}
vector<Student> LoadData::sortStudents_StudentCode() {
    sort(Students.begin(), Students.end(), compareStudentId);
    return Students;
}
vector<Student> LoadData::sortStudents_StudentName() {
    sort(Students.begin(), Students.end(), compareStudentName);
    return Students;
}
vector<Schedule> LoadData::sortSchedules_CodeUC() {
    sort(Schedules.begin(), Schedules.end(), compareSceduleCodeUC);
    return Schedules;
}
vector<Schedule> LoadData::sortSchedules_ClassCode() {
    sort(Schedules.begin(), Schedules.end(), compareSceduleClassCode);
    return Schedules;
}

void LoadData::archiveRequest(queue<Request>& r) {
    ofstream File("../Schedule_Files/Failed_Requests.csv");
    File << "StudentId,UcCode,ClassCode,RequestType,RequestStatus" << endl;
    while (!r.empty()) {
        Request R = r.front();
        r.pop();
        File << R.getStudentId() << ","  << R.getcodeUC() << "," << R.getClass() << "," << R.getRequestType() << "," << R.getRequestStatus() << "," << endl;
    }
}

void LoadData::archiveStudents(const vector<Student>& S) {
    ofstream File("../Schedule_Files/students_classesOut.csv");
    File << "StudentCode,StudentName,UcCode,ClassCode" << endl;
    for (Student s : S) {
        for (const UC& i : s.getClasses()) {
            File << s.getId() << ","  << s.getName() << "," << i.getcodeUC() << "," << i.getClass() << endl;
        }
    }
}

void LoadData::removeStudent(int StudentId, const string& codeUC, const string& Class) {
    Request r = Request(StudentId, codeUC, Class, "remove");
    Requests.push(r);
}

void LoadData::addStudent(int StudentId, const string& codeUC, const string& Class) {
    Request r = Request(StudentId, codeUC, Class, "add");
    Requests.push(r);
}

void LoadData::processAllRequests(const vector<Student>& students, const vector<UC*>& ucs, const vector<Schedule>& schedules, queue<Request>& requests) {
    queue<Request> Temp;
    while (!requests.empty()) {
        Request r = requests.front();
        requests.pop();
        if (r.handleRequest(students, ucs, schedules)) {
            cout << "Request processed successfully!" << endl;
        } else {
            cout << "Request failed!" << endl;
            Temp.push(r);
        }
    }
    archiveRequest(Temp);
}