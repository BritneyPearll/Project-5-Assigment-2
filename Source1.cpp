
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// Store each student's information
struct STUDENT_DATA
{
    string firstName;
    string lastName;
};

int main()
{
    vector<STUDENT_DATA> students;

    // Open the student data file
    ifstream file("StudentData.txt");

    if (!file.is_open())
    {
        cout << "Error opening StudentData.txt" << endl;
        return 1;
    }

    string line;

    // Read each student from the file
    while (getline(file, line))
    {
        size_t comma = line.find(',');

        if (comma != string::npos)
        {
            STUDENT_DATA student;

            student.firstName = line.substr(0, comma);
            student.lastName = line.substr(comma + 1);

            students.push_back(student);
        }
    }

    file.close();

    // Display all students
    cout << "STUDENT LIST" << endl;
    cout << "------------------------" << endl;

    for (const auto& student : students)
    {
        cout << "First Name: " << student.firstName << endl;
        cout << "Last Name: " << student.lastName << endl;
        cout << "------------------------" << endl;
    }

    // Display total number of students
    cout << "Total students: " << students.size() << endl;

    return 0;
}