#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

struct Student {
    string name;
    int rollNo;
    bool present = false; // Initialize as false
};

vector<Student> st;

void save(const vector<Student>& st, const string &sFile) {
    ofstream out(sFile);
    if (!out) {
        cerr << "File Not Found: " << sFile << endl;
        return;
    }
    for (int i = 0; i < st.size(); i++) {
        out << "Name: " << st[i].name << endl;
        out << "Roll No: " << st[i].rollNo << endl;
        out << "Status: " << (st[i].present ? "Present" : "Absent") << endl;
    }
    out.close();
    cout << "File Saved: " << sFile << endl;
}

int main() {
    int value;
    while (true) {
        cout << "1. To add Student Info" << endl;
        cout << "2. To Mark Attendance" << endl;
        cout << "3. To Show Details" << endl;
        cout << "4. To Save In File" << endl;
        cout << "0. To Exit" << endl;
        cout << "Enter Your Choice: ";
        cin >> value;
        cin.ignore();  // Flush the newline character

        if (value == 1) {
            system("cls");
            char choice;
            do {
                Student student;
                cout << "Enter Name: ";
                getline(cin, student.name);
                cout << "Enter Roll No: ";
                cin >> student.rollNo;
                cin.ignore();  // Flush buffer
                st.push_back(student);
                cout << "Student Details Saved Successfully" << endl;
                cout << "Enter 'x' to Exit or 'c' to continue: ";
                cin >> choice;
                cin.ignore();
            } while (choice != 'x' && choice == 'c');
        } 
        else if (value == 2) {
            system("cls");
            char attendance;
            for (int i = 0; i < st.size(); i++) {
                cout << "Name: " << st[i].name << endl;
                cout << "Roll No: " << st[i].rollNo << endl;
                cout << "Enter 'P' to Mark Present and 'A' to Mark Absent: ";
                cin >> attendance;
                attendance = toupper(attendance);
                st[i].present = (attendance == 'P');
            }
        } 
        else if (value == 3) {
            system("cls");
            for (int i = 0; i < st.size(); i++) {
                cout << "Name: " << st[i].name << endl;
                cout << "Roll No: " << st[i].rollNo << endl;
                cout << "Status: " << (st[i].present ? "Present" : "Absent") << endl;
            }
        } 
        else if (value == 4) {
            save(st, "C:/Users/bhask/Desktop/C++/student_attendance_management/stInfo.txt");
        } 
        else if (value == 0) {
            exit(0);
        } 
        else {
            system("cls");
            cout << "Invalid Choice" << endl;
        }
    }
}
