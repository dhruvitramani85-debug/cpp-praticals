#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Structure to store student details
struct Student {
    string enrollmentNo;
    string name;
    string branch;
    int semester;
    float percentage;
    char grade;
};

// Function prototypes using address-based access (pointers)
void displayAllRecords(const Student* students, int count);
void calculateStatistics(const Student* students, int count);

int main() {
    cout << "********************************************" << endl;
    cout << "STUDENT RECORD MANAGEMENT SYSTEM" << endl;
    cout << "********************************************" << endl;

    int n;
    cout << "Enter Number of Students: ";
    cin >> n;

    // Part A - Dynamic Memory Allocation
    Student* students = new Student[n];
    cout << "Dynamic Memory Allocated Successfully" << endl << endl;

    cout << "Enter Student Details" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Student " << (i + 1) << endl;
        cout << "Enrollment Number: ";
        cin >> (students + i)->enrollmentNo;
        cin.ignore(); // Clear newline buffer

        cout << "Student Name : ";
        getline(cin, (students + i)->name);

        cout << "Branch : ";
        cin >> (students + i)->branch;

        cout << "Semester : ";
        cin >> (students + i)->semester;

        cout << "Percentage : ";
        cin >> (students + i)->percentage;

        cout << "Grade : ";
        cin >> (students + i)->grade;
        cout << endl;
    }

    // Part B & C - Address-based Traversal and Function Access
    displayAllRecords(students, n);
    calculateStatistics(students, n);

    // Part D - Dynamic Memory Deallocation
    delete[] students;
    students = nullptr; // Reset the pointer for safety

    cout << "Dynamic Memory Released Successfully" << endl;
    cout << "Address Variable Reset Successfully" << endl;
    cout << "Program Executed Successfully" << endl;

    return 0;
}

// Function to display records using address arithmetic (offset-based traversal)
void displayAllRecords(const Student* students, int count) {
    cout << "Student Records using Address-based Access" << endl;
    for (int i = 0; i < count; ++i) {
        const Student* ptr = students + i; // Offset arithmetic
        cout << "Address: " << static_cast<const void*>(ptr) << endl;
        cout << ptr->enrollmentNo << " "
             << ptr->name << " "
             << ptr->branch << " "
             << ptr->semester << " "
             << fixed << setprecision(2) << ptr->percentage << " "
             << ptr->grade << endl;
    }
    cout << endl;
}

// Function to calculate and display class academic statistics
void calculateStatistics(const Student* students, int count) {
    if (count == 0) return;

    float totalPercentage = 0.0;
    float highest = (students)->percentage;
    float lowest = (students)->percentage;

    for (int i = 0; i < count; ++i) {
        float currentPercentage = (students + i)->percentage;
        totalPercentage += currentPercentage;

        if (currentPercentage > highest) {
            highest = currentPercentage;
        }
        if (currentPercentage < lowest) {
            lowest = currentPercentage;
        }
    }

    float average = totalPercentage / count;

    cout << "Academic Summary" << endl;
    cout << "Class Average Percentage: " << fixed << setprecision(2) << average << "%" << endl;
    cout << "Highest Percentage : " << highest << "%" << endl;
    cout << "Lowest Percentage : " << lowest << "%" << endl;
    cout << endl;
}
