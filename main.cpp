#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Student
{
    string name;
    int rollNo;
    bool present;
};
Student student;
vector<Student> st;

save(const vector<Student>& st, const string & sFile){
    ofstream out("C:/Users/bhask/Desktop/C++/student_attendance_management/stInfo.txt");
    if(!out){
        cerr<<"File Not Found"<<sFile;
    }
    for(int i = 0; i<)
}
int main()
{
    int value;
    while (true)
    {
        cout << "1. To add Student Info" << endl;
        cout << "2. To Mark Attendance" << endl;
        cout << "3. To Show Details" << endl;
        cout << "4. To Save In File" << endl;
        cout << "0. To Exit" << endl;
        cout << "Enter Your Choice";
        cin >> value;
        if (value == 1)
        {
            system("cls");
            char choice;
            do
            {
                cout << "Enter Name:-";
                cin >> student.name;
                cout << "Enter Roll No:-";
                cin >> student.rollNo;
                st.push_back(student);
                cout << "Student Details Saved Successfully";
                cout << "Enter x for Exit or To continue Enter c";
                cin >> choice;

            } while (choice != 'x' && choice == 'c');
        }
        else if (value == 2)
        {
            system("cls");
            char attendance;
            for (int i = 0; i < st.size(); i++)
            {
                cout << "Name:-" << st[i].name << endl;
                cout << "Roll No:-" << st[i].rollNo << endl;
                cout << "Enter P to Mark Present And A to Mark Absent";
                cin >> attendance;
                if (attendance == 'P')
                {
                    st[i].present = true;
                }
                else if (attendance == 'A')
                {
                    st[i].present = false;
                }
            }
        }
        else if (value == 3)
        {
            system("cls");
            for (int i = 0; i < st.size(); i++)
            {
                if (st[i].present == true)
                {
                    cout << "Name:-" << st[i].name << endl;
                    cout << "Roll No:-" << st[i].rollNo << endl;
                    cout << "Status: Present" << endl;
                }
                else if (st[i].present == false)
                {
                    cout << "Name:-" << st[i].name << endl;
                    cout << "Roll No:-" << st[i].rollNo << endl;
                    cout << "Status: Absent" << endl;
                }
            }
        }
        else if (value == 4)
        {
            save(st, "C:/Users/bhask/Desktop/C++/student_attendance_management/stInfo.txt");
        }
        else if (value == 0)
        {
        }
        else
        {
            cout << "Invalid Choice";
        }
    }
}
