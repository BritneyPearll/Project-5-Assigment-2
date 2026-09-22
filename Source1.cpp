
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct STUDENT_DATA
{
    string firstName;
    string lastName;

#ifdef PRE_RELEASE
    string email;
#endif
};

int main()
{
    vector<STUDENT_DATA> students;

#ifdef PRE_RELEASE
    cout << "Running Pre-Release Version" << endl;
    ifstream file("StudentData_Emails.txt");
#else
    cout << "Running Standard Version" << endl;
    ifstream file("StudentData.txt");
#endif

    if (!file.is_open())
    {
        cout << "Error opening student data file!" << endl;
        return 1;
    }

    string line;

    while (getline(file, line))
    {
        size_t firstComma = line.find(',');

        if (firstComma == string::npos)
            continue;

        STUDENT_DATA student;

        student.firstName = line.substr(0, firstComma);

#ifdef PRE_RELEASE
        size_t secondComma = line.find(',', firstComma + 1);

        if (secondComma == string::npos)
            continue;

        student.lastName = line.substr(
            firstComma + 1,
            secondComma - firstComma - 1
        );

        student.email = line.substr(secondComma + 1);
#else
        student.lastName = line.substr(firstComma + 1);
#endif

        students.push_back(student);
    }

    file.close();

#ifdef _DEBUG
    cout << "\nSTUDENT LIST" << endl;
    cout << "------------------------" << endl;

    for (const auto& student : students)
    {
        cout << "First Name: " << student.firstName << endl;
        cout << "Last Name: " << student.lastName << endl;

#ifdef PRE_RELEASE
        cout << "Email: " << student.email << endl;
#endif

        cout << "------------------------" << endl;
    }

    cout << "Total students: " << students.size() << endl;
#endif

    return 0;
}