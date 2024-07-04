#include "../Headers/Menu.h"

Menu::Menu(LoadData &data) {this -> data = data;}

void Menu::clearScreen() {
    for (int i = 0; i < 40; i++) {
        cout << "\n";
    }
}

void Menu::printTitle() {
    cout << R"(
____  ____ _   _ ____ ___   _   _ _    ____     _  _ ____ _  _ ____ ____ ____ _  _ ____ _  _ ___
|___  |    |___| |__  |  \  |   | |    |__      |\/| |__| |\ | |__| | __ |___ |\/| |___ |\ |  |
 ___| |___ |   | |___ |___\ |___| |___ |___     |  | |  | | \| |  | |__] |___ |  | |___ | \|  |
    )" << "\n";
}

void Menu::Print(const string& s, int linelength) {
    int spaces;
    bool uneven = false;
    if ((linelength - int(s.size())) % 2 == 1) uneven = true;
    spaces = (linelength - int(s.size())) / 2;
    cout << "|";
    if (spaces > 0) cout << string(spaces, ' ');
    cout << s;
    if (spaces > 0) cout << string(spaces, ' ');
    if (uneven) cout << " ";
}

int Menu::getUserInput(vector<int> inputs) {
    int input;
    if(!cin){
        cin.ignore();
        cin.ignore(100,'\n');
        cin.clear();
    }
    cin >> input;
    while (cin.fail() || (find(inputs.begin(), inputs.end(), input) == inputs.end())) {
        if (cin.eof() || input == 0) {
            cout << "\nExiting\n\n";
            exit(0);
        }
        cin.clear();
        cin.ignore();
        cerr << "Not a valid input, please input one of the shown options: ";
        cin >> input;
    }
    cin.ignore(100, '\n');
    return input;
}

string Menu::getUserTextInput() {
    string input;
    getline(cin, input);
    if (cin.fail()) cout << "deez";
    while (cin.fail() || input.length() == 0) {
        if (cin.eof()) {
            cout << "\nExiting\n\n";
            exit(0);
        }
        cin.clear();
        cin.ignore(100, '\n');
        cerr << "Not a valid input, please try again: ";
        getline(cin, input);
    }
    return input;
}

void Menu::MainMenu(int List_Size) {
    List_Size = 15;
    printTitle();

    cout << "\n";
    cout << "\tMain Menu\n";
    cout << "(1) UCS\n";
    cout << "(2) Students\n";
    cout << "(3) Schedules\n";
    cout << "(4) Requests\n";
    cout << "(0) Exit\n";
    cout << " > ";

    vector<int> inputs = {0, 1, 2, 3, 4};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            clearScreen();
            UCsMenu(List_Size);
            break;
        case 2:
            clearScreen();
            StudentsMenu(List_Size);
            break;
        case 3:
            clearScreen();
            SchedulesMenu(List_Size);
            break;
        case 4:
            clearScreen();
            RequestMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::wait(int List_Size) {

    cout << "\n";
    cout << "\tWhere do you want to go next\n";
    cout << "(1) UCS\n";
    cout << "(2) Students\n";
    cout << "(3) Schedules\n";
    cout << "(4) Requests\n";
    cout << "(0) Exit\n";
    cout << " > ";

    vector<int> inputs = {0, 1, 2, 3, 4};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            clearScreen();
            UCsMenu(List_Size);
            break;
        case 2:
            clearScreen();
            StudentsMenu(List_Size);
            break;
        case 3:
            clearScreen();
            SchedulesMenu(List_Size);
            break;
        case 4:
            clearScreen();
            RequestMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::UCsMenu(int List_Size) {
    printTitle();
    if (List_Size > data.getUCs().size() - 1) List_Size = 15;

    cout << "\n";
    cout << "\tUC Menu\n";
    cout << "(1) List by UC code\n";
    cout << "(2) List by Class code\n";
    cout << "(3) List by Number of Students\n";
    cout << "(4) Students in an UC\n";
    cout << "(5) Students in a Class\n";
    cout << "(6) Students in a year\n";
    cout << "(7) Change the size of the lists (Currently " << List_Size << ")\n";
    cout << "(8) Go back\n";
    cout << "(0) Exit\n";
    cout << " > ";

    vector<int> inputs = {0, 1, 2, 3, 4, 5, 6, 7, 8};
    int input = getUserInput(inputs);

    switch (input) {
        case 1:
            clearScreen();
            ListUCcodeMenu(List_Size);
            break;
        case 2:
            clearScreen();
            ListClasscodeMenu(List_Size);
            break;
        case 3:
            clearScreen();
            ListNumberStudentsMenu(List_Size);
            break;
        case 4:
            if (!data.getUCs().empty()) {
                cout << "\nWhich UC do you want? Here's an example: L.EIC001";
                string UCcode = getUserTextInput();
                int n = 0;
                for (UC *i: data.getUCs()) {
                    if (i -> getcodeUC() == UCcode) n += i -> getNumStudents();
                }
                if (n == 0) {
                    cout << "\nWell, the UC code you wanted doesn't exist. Did you write it correctly? Try again\n";
                    this -> UCsMenu(List_Size);
                }
                cout << "\nThere are " << n << " students total in this UC";
            }
            wait(List_Size);
            break;
        case 5:
            if (!data.getUCs().empty()) {
                cout << "\nWhich Class do you want?  Here's an example: 1LEIC01 ";
                string ClassCode = getUserTextInput();
                cout << "\nAnd from which UC? Here's an example: L.EIC001 ";
                string UCcode = getUserTextInput();
                int n = 0;
                for (UC *i: data.getUCs()) {
                    if (i -> getClass() == ClassCode && i -> getcodeUC() == UCcode) n += i -> getNumStudents();
                }
                if (n == 0) {
                    cout << "\nWell, the Class code and UC code combination you wanted doesn't exist. Did you write both correctly? Try again\n";
                    this -> UCsMenu(List_Size);
                }
                cout << "\nThere are " << n << " students total in this Class";
            }
            wait(List_Size);
            break;
        case 6:
            if (!data.getUCs().empty()) {
                cout << "\nWhich year do you want? 1, 2, or 3?";
                char NumStudents;
                cin >> NumStudents;
                int n = 0;
                for (UC *i: data.getUCs()) {
                    if (i -> getClass().front() == NumStudents) n += i -> getNumStudents();
                }
                if (n == 0) {
                    cout << "\nWell, the year you wanted doesn't exist. Did you write it correctly? Try again\n";
                    this -> UCsMenu(List_Size);
                }
                cout << "\nThere are " << n << " students total in year " << NumStudents;
            }
            wait(List_Size);
            break;
        case 7:
            if (!data.getUCs().empty()) {
                cout << "What is the new size of the lists?\n";
                cout << "    (0 to " << data.getUCs().size() - 1 << ") > ";
                vector<int> inputs1;
                inputs1.reserve(data.getUCs().size());
                for (int i = 0; i < data.getUCs().size(); ++i) inputs1.push_back(i);
                int size = getUserInput(inputs1);
                this -> UCsMenu(size);
            }
        case 8:
            clearScreen();
            MainMenu(List_Size);
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::StudentsMenu(int List_Size) {
    printTitle();
    if (List_Size > data.getStudents().size() - 1) List_Size = 15;

    cout << "\n";
    cout << "\tStudent Menu\n";
    cout << "(1) List by Student code\n";
    cout << "(2) List by Student name\n";
    cout << "(3) List by number of UCs the Student is enrolled in\n";
    cout << "(4) Change the size of the lists (Currently " << List_Size << ")\n";
    cout << "(5) Go back\n";
    cout << "(0) Exit\n";
    cout << " > ";

    //Receive input
    vector<int> inputs = {0, 1, 2, 3, 4, 5};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            clearScreen();
            ListStudentCodeMenu(List_Size);
            break;
        case 2:
            clearScreen();
            ListStudentNameMenu(List_Size);
            break;
        case 3:
            clearScreen();
            ListNumUCsMenu(List_Size);
            break;
        case 4:
            if (!data.getStudents().empty()) {
                cout << "What is the new size of the lists?\n";
                cout << "    (0 to " << data.getStudents().size() - 1 << ") > ";
                vector<int> inputs1;
                inputs1.reserve(data.getStudents().size());
                for (int i = 0; i < data.getStudents().size(); ++i) inputs1.push_back(i);
                int size = getUserInput(inputs1);
                this -> StudentsMenu(size);
            }
        case 5:
            clearScreen();
            MainMenu(List_Size);
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::SchedulesMenu(int List_Size) {
    printTitle();
    if (List_Size > data.getSchedules().size() - 1) List_Size = 15;


    cout << "\n";
    cout << "\tSchedule Menu\n";
    cout << "(1) List by UC code\n";
    cout << "(2) List by Class code\n";
    cout << "(3) List all Schedules of a specific UC/Class/Student\n";
    cout << "(4) Change the size of the lists (Currently " << List_Size << ")\n";
    cout << "(5) Go back\n";
    cout << "(0) Exit\n";
    cout << " > ";

    vector<int> inputs = {0, 1, 2, 3, 4, 5};
    int input = getUserInput(inputs);

    switch (input) {
        case 1:
            clearScreen();
            ListScheduleUCcodeMenu(List_Size);
            break;
        case 2:
            clearScreen();
            ListScheduleClasscodeMenu(List_Size);
            break;
        case 3:
            clearScreen();
            ListScheduleMenu(List_Size);
            break;
        case 4:
            if (!data.getSchedules().empty()) {
                cout << "What is the new size of the lists?\n";
                cout << "    (0 to " << data.getSchedules().size() - 1 << ") > ";
                vector<int> inputs1;
                inputs1.reserve(data.getSchedules().size());
                for (int i = 0; i < data.getSchedules().size(); ++i) inputs1.push_back(i);
                int size = getUserInput(inputs1);
                this -> SchedulesMenu(size);
            }
        case 5:
            clearScreen();
            MainMenu(List_Size);
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::RequestMenu(int List_Size) {
    printTitle();

    cout << "\n";
    cout << "\tRequests Menu\n";
    cout << "(1) Add Request\n";
    cout << "(2) Erase queue\n";
    cout << "(3) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3, 4, 5, 6};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            clearScreen();
            AddRequestMenu(List_Size);
            break;
        case 2:
            if (!data.getRequests().empty()) {
                while (!data.getRequests().empty()) {
                    data.getRequests().pop();
                }
            }
            else {
                cout << "The requests queue is already empty\n";
            }
            wait(List_Size);
            break;
        case 3:
            clearScreen();
            StudentsMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::ListUCcodeMenu(int List_Size) {
    printTitle();
    data.sortUCs_CodeUC();

    cout << "Choose how you want the list:\n";
    cout << "(1) Crescent\n";
    cout << "(2) Decrescent\n";
    cout << "(3) A specific UC\n";
    cout << "(4) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3, 4};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            Print("UC", 10);
            Print("Class", 10);
            Print("Occupation", 10);
            cout << "|\n";
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            for (int i = 0; i < List_Size; i++) {
                Print(data.getUCs().at(i) -> getcodeUC(), 10);
                Print(data.getUCs().at(i) -> getClass(), 10);
                Print(to_string(data.getUCs().at(i) -> getNumStudents()), 10);
                cout << "|\n";
            }
            for (int i = 0; i < 30; ++i) cout << "-";
            wait(List_Size);
            break;
        case 2:
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            Print("UC", 10);
            Print("Class", 10);
            Print("Occupation", 10);
            cout << "|\n";
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            for (int i = List_Size; i > 0; i--) {
                Print(data.getUCs().at(i) -> getcodeUC(), 10);
                Print(data.getUCs().at(i) -> getClass(), 10);
                Print(to_string(data.getUCs().at(i) -> getNumStudents()), 10);
                cout << "|\n";
            }
            for (int i = 0; i < 30; ++i) cout << "-";
            wait(List_Size);
            break;
        case 3:
            if (!data.getUCs().empty()) {
                cout << "Which UC do you want? Here's an example: L.EIC001";
                string UCcode = getUserTextInput();
                vector<UC*> temp;
                for (UC *i: data.getUCs()) {
                    if (i -> getcodeUC() == UCcode) temp.push_back(i);
                }
                if (temp.empty()) {
                    cout << "\nWell, the UC code you wanted doesn't exist. Did you write it correctly? Try again\n";
                    this -> ListUCcodeMenu(List_Size);
                } else {
                    for (int i = 0; i < 30; ++i) cout << "-";
                    cout << "\n";
                    Print("UC", 10);
                    Print("Class", 10);
                    Print("Occupation", 10);
                    cout << "|\n";
                    for (int i = 0; i < 30; ++i) cout << "-";
                    cout << "\n";
                    if (temp.size() < List_Size) List_Size = (int) temp.size();
                    for (int i = 0; i < List_Size; i++) {
                        Print(temp[i]->getcodeUC(), 10);
                        Print(temp[i]->getClass(), 10);
                        Print(to_string(temp[i]->getNumStudents()), 10);
                        cout << "|\n";
                    }
                    for (int i = 0; i < 30; ++i) cout << "-";
                }
            }
            wait(List_Size);
            break;
        case 4:
            clearScreen();
            UCsMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::ListClasscodeMenu(int List_Size) {
    printTitle();
    data.sortUCs_ClassCode();

    cout << "Choose how you want the list:\n";
    cout << "(1) Crescent\n";
    cout << "(2) Decrescent\n";
    cout << "(3) A specific Class\n";
    cout << "(4) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3, 4};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            Print("Class", 10);
            Print("UC", 10);
            Print("Occupation", 10);
            cout << "|\n";
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            for (int i = 0; i < List_Size; i++) {
                Print(data.getUCs().at(i) -> getClass(), 10);
                Print(data.getUCs().at(i) -> getcodeUC(), 10);
                Print(to_string(data.getUCs().at(i) -> getNumStudents()), 10);
                cout << "|\n";
            }
            for (int i = 0; i < 30; ++i) cout << "-";
            wait(List_Size);
            break;
        case 2:
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            Print("Class", 10);
            Print("UC", 10);
            Print("Occupation", 10);
            cout << "|\n";
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            for (int i = List_Size; i > 0; i--) {
                Print(data.getUCs().at(i) -> getClass(), 10);
                Print(data.getUCs().at(i) -> getcodeUC(), 10);
                Print(to_string(data.getUCs().at(i) -> getNumStudents()), 10);
                cout << "|\n";
            }
            for (int i = 0; i < 30; ++i) cout << "-";
            wait(List_Size);
            break;
        case 3:
            if (!data.getUCs().empty()) {
                cout << "Which Class do you want? Here's an example: 1LEIC01";
                string ClassCode = getUserTextInput();
                vector<UC*> temp;
                for (UC *i: data.getUCs()) {
                    if (i -> getClass() == ClassCode) temp.push_back(i);
                }
                if (temp.empty()) {
                    cout << "\nWell, the Class code you wanted doesn't exist. Did you write it correctly? Try again\n";
                    this -> ListClasscodeMenu(List_Size);
                } else {
                    for (int i = 0; i < 30; ++i) cout << "-";
                    cout << "\n";
                    Print("Class", 10);
                    Print("UC", 10);
                    Print("Occupation", 10);
                    cout << "|\n";
                    for (int i = 0; i < 30; ++i) cout << "-";
                    cout << "\n";
                    if (temp.size() < List_Size) List_Size = (int) temp.size();
                    for (int i = 0; i < List_Size; i++) {
                        Print(temp[i]->getClass(), 10);
                        Print(temp[i]->getcodeUC(), 10);
                        Print(to_string(temp[i]->getNumStudents()), 10);
                        cout << "|\n";
                    }
                    for (int i = 0; i < 30; ++i) cout << "-";
                }
            }
            wait(List_Size);
            break;
        case 4:
            clearScreen();
            UCsMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::ListNumberStudentsMenu(int List_Size) {
    printTitle();
    data.sortUCs_NumStudents();

    cout << "Choose how you want the list:\n";
    cout << "(1) Crescent\n";
    cout << "(2) Decrescent\n";
    cout << "(3) Only higher than\n";
    cout << "(4) Only lower than\n";
    cout << "(5) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3, 4, 5};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            Print("Occupation", 10);
            Print("UC", 10);
            Print("Class", 10);
            cout << "|\n";
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            for (int i = 0; i < List_Size; i++) {
                Print(to_string(data.getUCs().at(i) -> getNumStudents()), 10);
                Print(data.getUCs().at(i) -> getcodeUC(), 10);
                Print(data.getUCs().at(i) -> getClass(), 10);
                cout << "|\n";
            }
            for (int i = 0; i < 30; ++i) cout << "-";
            wait(List_Size);
            break;
        case 2:
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            Print("Occupation", 10);
            Print("UC", 10);
            Print("Class", 10);
            cout << "|\n";
            for (int i = 0; i < 30; ++i) cout << "-";
            cout << "\n";
            for (int i = List_Size; i > 0; i--) {
                Print(to_string(data.getUCs().at(i) -> getNumStudents()), 10);
                Print(data.getUCs().at(i) -> getcodeUC(), 10);
                Print(data.getUCs().at(i) -> getClass(), 10);
                cout << "|\n";
            }
            for (int i = 0; i < 30; ++i) cout << "-";
            wait(List_Size);
            break;
        case 3:
            if (!data.getUCs().empty()) {
                cout << "What's the mininum number of students you're thinking of? Shoot a number";
                int NumStudents;
                cin >> NumStudents;
                vector<UC*> temp;
                for (UC *i: data.getUCs()) {
                    if (i -> getNumStudents() >= NumStudents) temp.push_back(i);
                }
                if (temp.empty()) {
                    cout << "\nWell, there are no classes in any UC with that many students. Try again\n";
                    this -> ListClasscodeMenu(List_Size);
                } else {
                    for (int i = 0; i < 30; ++i) cout << "-";
                    cout << "\n";
                    Print("Occupation", 10);
                    Print("UC", 10);
                    Print("Class", 10);
                    cout << "|\n";
                    for (int i = 0; i < 30; ++i) cout << "-";
                    cout << "\n";
                    if (temp.size() < List_Size) List_Size = (int) temp.size();
                    for (int i = 0; i < List_Size; i++) {
                        Print(to_string(temp[i]->getNumStudents()), 10);
                        Print(temp[i]->getcodeUC(), 10);
                        Print(temp[i]->getClass(), 10);
                        cout << "|\n";
                    }
                    for (int i = 0; i < 30; ++i) cout << "-";
                }
            }
            wait(List_Size);
            break;
        case 4:
            if (!data.getUCs().empty()) {
                cout << "What's the maximum number of students you're thinking of? Shoot a number";
                int NumStudents;
                cin >> NumStudents;
                vector<UC*> temp;
                for (UC *i: data.getUCs()) {
                    if (i -> getNumStudents() <= NumStudents) temp.push_back(i);
                }
                if (temp.empty()) {
                    cout << "\nWell, there are no classes in any UC with that few students. Try again\n";
                    this -> ListClasscodeMenu(List_Size);
                } else {
                    for (int i = 0; i < 30; ++i) cout << "-";
                    cout << "\n";
                    Print("Occupation", 10);
                    Print("UC", 10);
                    Print("Class", 10);
                    cout << "|\n";
                    for (int i = 0; i < 30; ++i) cout << "-";
                    cout << "\n";
                    if (temp.size() < List_Size) List_Size = (int) temp.size();
                    for (int i = 0; i < List_Size; i++) {
                        Print(to_string(temp[i]->getNumStudents()), 10);
                        Print(temp[i]->getcodeUC(), 10);
                        Print(temp[i]->getClass(), 10);
                        cout << "|\n";
                    }
                    for (int i = 0; i < 30; ++i) cout << "-";
                }
            }
            wait(List_Size);
            break;
        case 5:
            clearScreen();
            UCsMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::ListStudentCodeMenu(int List_Size) {
    printTitle();
    data.sortStudents_StudentCode();

    cout << "Choose how you want the list:\n";
    cout << "(1) Crescent\n";
    cout << "(2) Decrescent\n";
    cout << "(3) A specific Student code\n";
    cout << "(4) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3, 4};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            for (int i = 0; i < 65; ++i) cout << "-";
            cout << "\n";
            Print("StudentCode", 15);
            Print("StudentName", 20);
            Print("UcCode", 10);
            Print("ClassCode", 15);
            cout << "|\n";
            for (int i = 0; i < 65; ++i) cout << "-";
            cout << "\n";
            for (int i = 0; i < List_Size; i++) {
                Print(to_string(data.getStudents().at(i).getId()), 15);
                Print(data.getStudents().at(i).getName(), 20);
                Print(data.getStudents().at(i).getClasses()[0].getcodeUC(), 10);
                Print(data.getStudents().at(i).getClasses()[0].getClass(), 15);
                cout << "|\n";
            }
            for (int i = 0; i < 65; ++i) cout << "-";
            wait(List_Size);
            break;
        case 2:
            for (int i = 0; i < 65; ++i) cout << "-";
            cout << "\n";
            Print("StudentCode", 15);
            Print("StudentName", 20);
            Print("UcCode", 10);
            Print("ClassCode", 15);
            cout << "|\n";
            for (int i = 0; i < 65; ++i) cout << "-";
            cout << "\n";
            for (int i = List_Size; i > 0; i--) {
                Print(to_string(data.getStudents().at(i).getId()), 15);
                Print(data.getStudents().at(i).getName(), 20);
                Print(data.getStudents().at(i).getClasses()[0].getcodeUC(), 10);
                Print(data.getStudents().at(i).getClasses()[0].getClass(), 15);
                cout << "|\n";
            }
            for (int i = 0; i < 65; ++i) cout << "-";
            wait(List_Size);
            break;
        case 3:
            if (!data.getStudents().empty()) {
                cout << "What's the student code you're looking for? Here's an example: 201920727";
                int StudentCode;
                cin >> StudentCode;
                vector<Student> temp;
                for (const Student& i: data.getStudents()) {
                    if (i.getId() == StudentCode) temp.push_back(i);
                }
                if (temp.empty()) {
                    cout << "\nWell, the Student code you wanted doesn't exist. Did you write it correctly? Try again\n";
                    this -> ListStudentCodeMenu(List_Size);
                } else {
                    int size = (int) temp.front().getClasses().size();
                    for (int i = 0; i < 38; ++i) cout << "-";
                    cout << "\n";
                    Print("StudentCode", 15);
                    Print("StudentName", 20);
                    cout << "|\n";
                    for (int i = 0; i < 38; ++i) cout << "-";
                    cout << "\n";
                    Print(to_string(temp.front().getId()), 15);
                    Print(temp.front().getName(), 20);
                    cout << "|\n";
                    for (int i = 0; i < 38; ++i) cout << "-";
                    cout << "\n\n";
                    for (int j = 0; j < size; j++) {
                        for (int i = 0; i < 28; ++i) cout << "-";
                        cout << "\n";
                        Print("UcCode", 10);
                        Print("ClassCode", 15);
                        cout << "|\n";
                        for (int i = 0; i < 28; ++i) cout << "-";
                        cout << "\n";
                        Print(temp.front().getClasses()[j].getcodeUC(), 10);
                        Print(temp.front().getClasses()[j].getClass(), 15);
                        cout << "|\n";
                        for (int i = 0; i < 28; ++i) cout << "-";
                        cout << "\n\n";
                    }
                }
            }
            wait(List_Size);
            break;
        case 4:
            clearScreen();
            StudentsMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::ListStudentNameMenu(int List_Size) {
    printTitle();
    data.sortStudents_StudentName();

    cout << "Choose how you want the list:\n";
    cout << "(1) Crescent\n";
    cout << "(2) Decrescent\n";
    cout << "(3) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            for (int i = 0; i < 65; ++i) cout << "-";
            cout << "\n";
            Print("StudentName", 20);
            Print("StudentCode", 15);
            Print("UcCode", 10);
            Print("ClassCode", 15);
            cout << "|\n";
            for (int i = 0; i < 65; ++i) cout << "-";
            cout << "\n";
            for (int i = 0; i < List_Size; i++) {
                Print(data.getStudents().at(i).getName(), 15);
                Print(to_string(data.getStudents().at(i).getId()), 20);
                Print(data.getStudents().at(i).getClasses()[0].getcodeUC(), 10);
                Print(data.getStudents().at(i).getClasses()[0].getClass(), 15);
                cout << "|\n";
            }
            for (int i = 0; i < 65; ++i) cout << "-";
            wait(List_Size);
            break;
        case 2:
            for (int i = 0; i < 65; ++i) cout << "-";
            cout << "\n";
            Print("StudentName", 20);
            Print("StudentCode", 15);
            Print("UcCode", 10);
            Print("ClassCode", 15);
            cout << "|\n";
            for (int i = 0; i < 65; ++i) cout << "-";
            cout << "\n";
            for (int i = List_Size; i > 0; i--) {
                Print(data.getStudents().at(i).getName(), 15);
                Print(to_string(data.getStudents().at(i).getId()), 20);
                Print(data.getStudents().at(i).getClasses()[0].getcodeUC(), 10);
                Print(data.getStudents().at(i).getClasses()[0].getClass(), 15);
                cout << "|\n";
            }
            for (int i = 0; i < 65; ++i) cout << "-";
            wait(List_Size);
            break;
        case 3:
            clearScreen();
            StudentsMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::ListNumUCsMenu(int List_Size) {
    printTitle();
    data.sortStudents_StudentCode();

    cout << "\n";
    cout << "Choose how you want the list:\n";
    cout << "(1) Crescent\n";
    cout << "(2) Decrescent\n";
    cout << "(3) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            if (!data.getStudents().empty()) {
                cout << "Choose the number of UCs you want to check for  >  ";
                int NumUCs;
                cin >> NumUCs;
                vector<Student> temp;
                for (Student i: data.getStudents()) {
                    if (i.getClasses().size() >= NumUCs) temp.push_back(i);
                }
                if (temp.empty()) {
                    cout << "\nWell, there are no students enrolled in that many UCs. Try again\n";
                    this -> ListNumUCsMenu(List_Size);
                } else {
                    for (int i = 0; i < 65; ++i) cout << "-";
                    cout << "\n";
                    Print("StudentCode", 15);
                    Print("StudentName", 20);
                    Print("UcCode", 10);
                    Print("ClassCode", 15);
                    cout << "|\n";
                    for (int i = 0; i < 65; ++i) cout << "-";
                    cout << "\n";
                    for (int i = 0; i < List_Size; i++) {
                        Print(to_string(temp.at(i).getId()), 15);
                        Print(temp.at(i).getName(), 20);
                        Print(temp.at(i).getClasses()[0].getcodeUC(), 10);
                        Print(temp.at(i).getClasses()[0].getClass(), 15);
                        cout << "|\n";
                    }
                    for (int i = 0; i < 65; ++i) cout << "-";
                }
            }
            wait(List_Size);
            break;
        case 2:
            if (!data.getStudents().empty()) {
                cout << "Choose the number of UCs you want to check for  >  ";
                int NumUCs;
                cin >> NumUCs;
                vector<Student> temp;
                for (Student i: data.getStudents()) {
                    if (i.getClasses().size() >= NumUCs) temp.push_back(i);
                }
                if (temp.empty()) {
                    cout << "\nWell, there are no students enrolled in that many UCs. Try again\n";
                    this -> ListNumUCsMenu(List_Size);
                } else {
                    for (int i = 0; i < 65; ++i) cout << "-";
                    cout << "\n";
                    Print("StudentCode", 15);
                    Print("StudentName", 20);
                    Print("UcCode", 10);
                    Print("ClassCode", 15);
                    cout << "|\n";
                    for (int i = 0; i < 65; ++i) cout << "-";
                    cout << "\n";
                    for (int i = List_Size; i > 0; i--) {
                        Print(to_string(temp.at(i).getId()), 15);
                        Print(temp.at(i).getName(), 20);
                        Print(temp.at(i).getClasses()[0].getcodeUC(), 10);
                        Print(temp.at(i).getClasses()[0].getClass(), 15);
                        cout << "|\n";
                    }
                    for (int i = 0; i < 65; ++i) cout << "-";
                }
            }
            wait(List_Size);
            break;
        case 3:
            clearScreen();
            StudentsMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::ListScheduleUCcodeMenu(int List_Size) {
    printTitle();
    data.sortSchedules_CodeUC();

    cout << "Choose how you want the list:\n";
    cout << "(1) Crescent\n";
    cout << "(2) Decrescent\n";
    cout << "(3) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            for (int i = 0; i < 70; ++i) cout << "-";
            cout << "\n";
            Print("UC", 10);
            Print("ClassCode", 10);
            Print("Weekday", 15);
            Print("Start", 10);
            Print("End", 10);
            Print("Type", 5);
            cout << "|\n";
            for (int i = 0; i < 70; ++i) cout << "-";
            cout << "\n";
            for (int i = 0; i < List_Size; i++) {
                Print(data.getSchedules().at(i).getCodeUC(), 10);
                Print(data.getSchedules().at(i).getClass(), 10);
                string wday;
                if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 1) {wday = "Monday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 2) {wday = "Tuesday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 3) {wday = "Wednesday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 4) {wday = "Thursday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 5) {wday = "Friday";}
                Print(wday, 15);
                Print(to_string(int(data.getSchedules().at(i).getIntervals().front().getStart())) + "h:" + to_string(int((data.getSchedules().at(i).getIntervals().front().getStart() - (data.getSchedules().at(i).getIntervals().front().getStart())) * 60)) + "m", 10);
                Print(to_string(int(data.getSchedules().at(i).getIntervals().front().getEnd())) + "h:" + to_string(int((data.getSchedules().at(i).getIntervals().front().getEnd() - (data.getSchedules().at(i).getIntervals().front().getEnd())) * 60)) + "m", 10);
                Print(data.getSchedules().at(i).getIntervals().front().getType(), 5);
                cout << "|\n";
            }
            for (int i = 0; i < 70; ++i) cout << "-";
            wait(List_Size);
            break;
        case 2:
            for (int i = 0; i < 70; ++i) cout << "-";
            cout << "\n";
            Print("UC", 10);
            Print("ClassCode", 10);
            Print("Weekday", 15);
            Print("Start", 10);
            Print("End", 10);
            Print("Type", 5);
            cout << "|\n";
            for (int i = 0; i < 70; ++i) cout << "-";
            cout << "\n";
            for (int i = List_Size; i > 0; i--) {
                Print(data.getSchedules().at(i).getCodeUC(), 10);
                Print(data.getSchedules().at(i).getClass(), 10);
                string wday;
                if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 1) {wday = "Monday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 2) {wday = "Tuesday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 3) {wday = "Wednesday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 4) {wday = "Thursday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 5) {wday = "Friday";}
                Print(wday, 15);
                Print(to_string(int(data.getSchedules().at(i).getIntervals().front().getStart())) + "h:" + to_string(int((data.getSchedules().at(i).getIntervals().front().getStart() - (data.getSchedules().at(i).getIntervals().front().getStart())) * 60)) + "m", 10);
                Print(to_string(int(data.getSchedules().at(i).getIntervals().front().getEnd())) + "h:" + to_string(int((data.getSchedules().at(i).getIntervals().front().getEnd() - (data.getSchedules().at(i).getIntervals().front().getEnd())) * 60)) + "m", 10);
                Print(data.getSchedules().at(i).getIntervals().front().getType(), 5);
                cout << "|\n";
            }
            for (int i = 0; i < 70; ++i) cout << "-";
            wait(List_Size);
            break;
        case 3:
            clearScreen();
            SchedulesMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::ListScheduleClasscodeMenu(int List_Size) {
    printTitle();
    data.sortSchedules_ClassCode();

    cout << "Choose how you want the list:\n";
    cout << "(1) Crescent\n";
    cout << "(2) Decrescent\n";
    cout << "(3) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            for (int i = 0; i < 70; ++i) cout << "-";
            cout << "\n";
            Print("ClassCode", 10);
            Print("UC", 10);
            Print("Weekday", 15);
            Print("Start", 10);
            Print("End", 10);
            Print("Type", 5);
            cout << "|\n";
            for (int i = 0; i < 70; ++i) cout << "-";
            cout << "\n";
            for (int i = 0; i < List_Size; i++) {
                Print(data.getSchedules().at(i).getClass(), 10);
                Print(data.getSchedules().at(i).getCodeUC(), 10);
                string wday;
                if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 1) {wday = "Monday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 2) {wday = "Tuesday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 3) {wday = "Wednesday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 4) {wday = "Thursday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 5) {wday = "Friday";}
                Print(wday, 15);
                Print(to_string(int(data.getSchedules().at(i).getIntervals().front().getStart())) + "h:" + to_string(int((data.getSchedules().at(i).getIntervals().front().getStart() - (data.getSchedules().at(i).getIntervals().front().getStart())) * 60)) + "m", 10);
                Print(to_string(int(data.getSchedules().at(i).getIntervals().front().getEnd())) + "h:" + to_string(int((data.getSchedules().at(i).getIntervals().front().getEnd() - (data.getSchedules().at(i).getIntervals().front().getEnd())) * 60)) + "m", 10);
                Print(data.getSchedules().at(i).getIntervals().front().getType(), 5);
                cout << "|\n";
            }
            for (int i = 0; i < 70; ++i) cout << "-";
            wait(List_Size);
            break;
        case 2:
            for (int i = 0; i < 70; ++i) cout << "-";
            cout << "\n";
            Print("ClassCode", 10);
            Print("UC", 10);
            Print("Weekday", 15);
            Print("Start", 10);
            Print("End", 10);
            Print("Type", 5);
            cout << "|\n";
            for (int i = 0; i < 70; ++i) cout << "-";
            cout << "\n";
            for (int i = List_Size; i > 0; i--) {
                Print(data.getSchedules().at(i).getClass(), 10);
                Print(data.getSchedules().at(i).getCodeUC(), 10);
                string wday;
                if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 1) {wday = "Monday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 2) {wday = "Tuesday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 3) {wday = "Wednesday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 4) {wday = "Thursday";}
                else if (data.getSchedules().at(i).getIntervals().front().getWeekDay() == 5) {wday = "Friday";}
                Print(wday, 15);
                Print(to_string(int(data.getSchedules().at(i).getIntervals().front().getStart())) + "h:" + to_string(int((data.getSchedules().at(i).getIntervals().front().getStart() - (data.getSchedules().at(i).getIntervals().front().getStart())) * 60)) + "m", 10);
                Print(to_string(int(data.getSchedules().at(i).getIntervals().front().getEnd())) + "h:" + to_string(int((data.getSchedules().at(i).getIntervals().front().getEnd() - (data.getSchedules().at(i).getIntervals().front().getEnd())) * 60)) + "m", 10);
                Print(data.getSchedules().at(i).getIntervals().front().getType(), 5);
                cout << "|\n";
            }
            for (int i = 0; i < 70; ++i) cout << "-";
            wait(List_Size);
            break;
        case 3:
            clearScreen();
            SchedulesMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::ListScheduleMenu(int List_Size) {
    printTitle();
    data.sortSchedules_CodeUC();

    cout << "Choose what you want in the list:\n";
    cout << "(1) A specific UC\n";
    cout << "(2) A specific Class\n";
    cout << "(3) A specific Student\n";
    cout << "(4) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3, 4};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            if (!data.getSchedules().empty()) {
                cout << "Which UC do you want? Here's an example: L.EIC001";
                string UCcode = getUserTextInput();
                vector<Schedule> temp;
                for (Schedule& S : data.getSchedules()) {
                    if (S.getCodeUC() == UCcode)
                        temp.push_back(S);
                }
                if (temp.empty()) {
                    cout << "\nWell, the UC code you wanted doesn't exist. Did you write it correctly? Try again\n";
                    this -> ListScheduleMenu(List_Size);
                } else {
                    int size = (int) temp.size();
                    for (int j = 0; j < size; j++) {
                        cout << "\n";
                        for (int i = 0; i < 67; ++i) cout << "-";
                        cout << "\n";
                        Print("UcCode", 10);
                        Print("ClassCode", 10);
                        Print("Weekday", 15);
                        Print("Start", 10);
                        Print("End", 10);
                        Print("Type", 5);
                        cout << "|\n";
                        for (int i = 0; i < 67; ++i) cout << "-";
                        cout << "\n";
                        Print(temp.at(j).getCodeUC(), 10);
                        Print(temp.at(j).getClass(), 10);
                        string wday;
                        int day = temp.at(j).getIntervals().front().getWeekDay();
                        if (day == 1) {wday = "Monday";}
                        else if (day == 2) {wday = "Tuesday";}
                        else if (day == 3) {wday = "Wednesday";}
                        else if (day == 4) {wday = "Thursday";}
                        else if (day == 5) {wday = "Friday";}
                        Print(wday, 15);
                        Print(to_string(int(temp.at(j).getIntervals().front().getStart())) + "h:" + to_string(int((temp.at(j).getIntervals().front().getStart() - (temp.at(j).getIntervals().front().getStart())) * 60)) + "m", 10);
                        Print(to_string(int(temp.at(j).getIntervals().front().getEnd())) + "h:" + to_string(int((temp.at(j).getIntervals().front().getEnd() - (temp.at(j).getIntervals().front().getEnd())) * 60)) + "m", 10);
                        Print(temp.at(j).getIntervals().front().getType(), 5);
                        cout << "|\n";
                        for (int i = 0; i < 67; ++i) cout << "-";
                        cout << "\n\n";
                    }
                }
            }
            wait(List_Size);
            break;
        case 2:
            data.sortSchedules_ClassCode();
            if (!data.getSchedules().empty()) {
                cout << "Which Class do you want? Here's an example: 1LEIC01";
                string Classcode = getUserTextInput();
                vector<Schedule> temp;
                for (Schedule& S : data.getSchedules()) {
                    if (S.getClass() == Classcode)
                        temp.push_back(S);
                }
                if (temp.empty()) {
                    cout << "\nWell, the Class code you wanted doesn't exist. Did you write it correctly? Try again\n";
                    this -> ListScheduleMenu(List_Size);
                } else {
                    int size = (int) temp.size();
                    for (int j = 0; j < size; j++) {
                        cout << "\n";
                        for (int i = 0; i < 67; ++i) cout << "-";
                        cout << "\n";
                        Print("ClassCode", 10);
                        Print("UcCode", 10);
                        Print("Weekday", 15);
                        Print("Start", 10);
                        Print("End", 10);
                        Print("Type", 5);
                        cout << "|\n";
                        for (int i = 0; i < 67; ++i) cout << "-";
                        cout << "\n";
                        Print(temp.at(j).getClass(), 10);
                        Print(temp.at(j).getCodeUC(), 10);
                        string wday;
                        int day = temp.at(j).getIntervals().front().getWeekDay();
                        if (day == 1) {wday = "Monday";}
                        else if (day == 2) {wday = "Tuesday";}
                        else if (day == 3) {wday = "Wednesday";}
                        else if (day == 4) {wday = "Thursday";}
                        else if (day == 5) {wday = "Friday";}
                        Print(wday, 15);
                        Print(to_string(int(temp.at(j).getIntervals().front().getStart())) + "h:" + to_string(int((temp.at(j).getIntervals().front().getStart() - (temp.at(j).getIntervals().front().getStart())) * 60)) + "m", 10);
                        Print(to_string(int(temp.at(j).getIntervals().front().getEnd())) + "h:" + to_string(int((temp.at(j).getIntervals().front().getEnd() - (temp.at(j).getIntervals().front().getEnd())) * 60)) + "m", 10);
                        Print(temp.at(j).getIntervals().front().getType(), 5);
                        cout << "|\n";
                        for (int i = 0; i < 67; ++i) cout << "-";
                        cout << "\n\n";
                    }
                }
            }
            wait(List_Size);
            break;
        case 3:
            if (!data.getSchedules().empty()) {
                cout << "What student code are you looking for? Here's an example: 201920727";
                int StudentCode;
                cin >> StudentCode;
                string StudentName;
                vector<Schedule> temp;
                for (Student& i: data.getStudents()) {
                    if (i.getId() == StudentCode)  {
                        StudentName = i.getName();
                        for (const UC& j : i.getClasses()){
                            for (Schedule& S : data.getSchedules()) {
                                if (S.getCodeUC() == j.getcodeUC() && S.getClass() == j.getClass()) temp.push_back(S);
                            }
                        }
                    }
                }
                if (temp.empty()) {
                    cout << "\nWell, the Student code you wanted doesn't exist. Did you write it correctly? Try again\n";
                    this -> ListStudentCodeMenu(List_Size);
                } else {
                    int size = (int) temp.size();
                    for (int j = 0; j < size; j++) {
                        cout << "\n";
                        for (int i = 0; i < 104; ++i) cout << "-";
                        cout << "\n";
                        Print("StudentCode", 15);
                        Print("StudentName", 20);
                        Print("UcCode", 10);
                        Print("ClassCode", 10);
                        Print("Weekday", 15);
                        Print("Start", 10);
                        Print("End", 10);
                        Print("Type", 5);
                        cout << "|\n";
                        for (int i = 0; i < 104; ++i) cout << "-";
                        cout << "\n";
                        Print(to_string(StudentCode), 15);
                        Print(StudentName, 20);
                        Print(temp.at(j).getCodeUC(), 10);
                        Print(temp.at(j).getClass(), 10);
                        string wday;
                        int day = temp.at(j).getIntervals().front().getWeekDay();
                        if (day == 1) {wday = "Monday";}
                        else if (day == 2) {wday = "Tuesday";}
                        else if (day == 3) {wday = "Wednesday";}
                        else if (day == 4) {wday = "Thursday";}
                        else if (day == 5) {wday = "Friday";}
                        Print(wday, 15);
                        Print(to_string(int(temp.at(j).getIntervals().front().getStart())) + "h:" + to_string(int((temp.at(j).getIntervals().front().getStart() - (temp.at(j).getIntervals().front().getStart())) * 60)) + "m", 10);
                        Print(to_string(int(temp.at(j).getIntervals().front().getEnd())) + "h:" + to_string(int((temp.at(j).getIntervals().front().getEnd() - (temp.at(j).getIntervals().front().getEnd())) * 60)) + "m", 10);
                        Print(temp.at(j).getIntervals().front().getType(), 5);
                        cout << "|\n";
                        for (int i = 0; i < 104; ++i) cout << "-";
                        cout << "\n\n";
                    }
                }
            }
            wait(List_Size);
            break;
        case 4:
            clearScreen();
            UCsMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}

void Menu::AddRequestMenu(int List_Size) {
    printTitle();

    cout << "Add requests Menu\n";
    cout << "(1) Add Student to a Class\n";
    cout << "(2) Remove Student from a Class\n";
    cout << "(3) Swap the classes of 2 Students \n";
    cout << "(4) Go back\n";
    cout << "(0) Exit\n";

    vector<int> inputs = {0, 1, 2, 3, 4};
    int input;
    input = getUserInput(inputs);

    switch (input) {
        case 1:
            if (!data.getRequests().empty() || data.getRequests().empty()) {
                cout << "Which student do you want to add? Write their Student code. Here's an example: 201920727\n";
                int StudentCode;
                cin >> StudentCode;
                cout << "To which UC do you want to add said student? Here's an example: L.EIC001\n";
                string codeUC = getUserTextInput();
                cout << "And to which class? Here's an example: 1LEIC01\n ";
                string Classcode = getUserTextInput();
                for (Student& S: data.getStudents()) {
                    if (S.getId() == StudentCode) {
                        bool InClass = false;
                        bool inUC = false;
                        bool compatibleSchedule = false;
                        for (const UC& i : S.getClasses()) {
                            if (i.getClass() == Classcode) {
                                InClass = true;
                            }
                            if (i.getcodeUC() == codeUC) {
                                inUC = true;
                            }
                            for (Schedule& s1 : data.getSchedules()) {
                                if (s1.getCodeUC() == i.getcodeUC() && s1.getClass() == i.getClass()) {
                                    for (Schedule& s2 : data.getSchedules()) {
                                        if (s2.getCodeUC() == codeUC && s2.getClass() == Classcode) {
                                            for (Interval& I1 : s1.getIntervals()) {
                                                for (Interval& I2 : s2.getIntervals()) {
                                                    if (I1 == I2) {
                                                        compatibleSchedule = true;
                                                    }
                                                }
                                            }
                                        }
                                    }

                                }
                            }
                        }
                        if (compatibleSchedule) {
                            if (!InClass && !inUC || InClass && !inUC) {
                                data.addStudent(StudentCode, codeUC, Classcode);
                            }
                            else if (inUC && InClass) {
                                cout << "That student is already in that class in that UC";
                            }
                            else if (inUC && !InClass) {
                                cout << "That student is already in that UC but in a different class";
                            }
                        }
                        else {
                            cout << "That student has an incompatible schedule with the class and UC you want to add him to";
                        }
                    }
                }
            }
            wait(List_Size);
            break;
        case 2:
            if (!data.getRequests().empty() || data.getRequests().empty()) {
                cout << "Which student do you want to remove? Write their Student code. Here's an example: 201920727\n";
                int StudentCode;
                cin >> StudentCode;
                cout << "From which UC do you want to remove said student? Here's an example: L.EIC001\n";
                string to_be_removed_UCCode = getUserTextInput();
                cout << "And from which class? Here's an example: 1LEIC01\n ";
                string to_be_removed_Classcode = getUserTextInput();
                for (Student &S: data.getStudents()) {
                    if (S.getId() == StudentCode) {
                        for (const UC &i: S.getClasses()) {
                            if (i.getcodeUC() == to_be_removed_UCCode && i.getClass() == to_be_removed_Classcode) {
                                data.removeStudent(StudentCode, to_be_removed_UCCode, to_be_removed_Classcode);
                            }
                        }
                    }
                }
            }
            wait(List_Size);
            break;
        case 3:
            if (!data.getRequests().empty() || data.getRequests().empty()) {
                cout << "Which students do you want to swap? Write their Student codes. Here's an example: 201920727\n";
                cout << "First student code: \n";
                int StudentCode1;
                cin >> StudentCode1;
                cout << "Second student code: \n";
                int StudentCode2;
                cin >> StudentCode2;
                for (Student& S1: data.getStudents()) {
                    if (S1.getId() == StudentCode1) {
                        for (Student& S2: data.getStudents()) {
                            if (S2.getId() == StudentCode2) {
                                for (const UC& i1 : S1.getClasses()) {
                                    for (const UC& i2 : S2.getClasses()) {
                                        if (i1.getcodeUC() == i2.getcodeUC()) {
                                            data.removeStudent(S1.getId(), i1.getcodeUC(), i1.getClass());
                                            data.removeStudent(S2.getId(), i2.getcodeUC(), i2.getClass());
                                            data.addStudent(S1.getId(), i1.getcodeUC(), i2.getClass());
                                            data.addStudent(S2.getId(), i2.getcodeUC(), i1.getClass());
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            wait(List_Size);
            break;
        case 4:
            clearScreen();
            RequestMenu(List_Size);
            break;
        case 0:
            LoadData::processAllRequests(data.getStudents(), data.getUCs(), data.getSchedules(), data.getRequests());
            LoadData::archiveStudents(data.getStudents());
            exit(0);
        default:
            break;
    }
}
