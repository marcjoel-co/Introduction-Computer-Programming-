/**
 * @file manageStudents.cpp
 * @author Marc Joel B. Deus
 * @brief  Write a C++ program that allows the user to manage a list of
 *         student names using string arrays. The program should provide the following 
 * @date 2025-02-23
 * 
 */
#include <iostream>
#include <string>
#include <limits> // for numeric_limits (used in Clearing the input)
#include <algorithm> // for transform and sort

using namespace std;

// Main function prototypes
void addStudent(string studentDB[], string studentName, int& studentID);
void removeStudent(string studentDB[], string studentName, int& studentID);
void searchStudent(const string studentDB[], const string& studentName, int studentID);
void displayStudent(const string studentDB[], int studentID);

// Helper function prototypes
string toLowercase(const string& str);
bool caseInsensitiveCompare(const string& a, const string& b);
void clearInputBuffer();
void optionMenu();


// Constant defined for the maximum number of students
const int MAX_STUDENTS = 10;
    
int main() {

    // initializing variables for use
    string students[MAX_STUDENTS] = {}; 
    int studentID = 0;
    bool running = true;
    
    // Main function loop
    while (running) {
        optionMenu();
        int choice;       
        // Makes sure to cin only accepts numbers 
        while (!(cin >> choice)) {
            clearInputBuffer();
            cout << "Invalid input. Please enter a number (1-5): ";
        }
        // Makes sure that the input buffer is cleared after each input
        if (choice != 5) {
            clearInputBuffer();
        }
        // Switch case for the choices  
        string studentName;
        switch (choice) {
            case 1:
                // Add student 
                if (studentID >= MAX_STUDENTS) {
                    cout << "Error: Student list is full (max " << MAX_STUDENTS << " students)" << endl;
                    break;
                }   
                cout << "Enter the student name: ";
                getline(cin, studentName);
                addStudent(students, studentName, studentID);
                break;
                
            case 2:
                // Remove student
                cout << "Enter the student name to remove: ";
                getline(cin, studentName);
                removeStudent(students, studentName, studentID);
                break;
                
            case 3:
                // Search for student name
                cout << "Enter the student name to search: ";
                getline(cin, studentName);
                searchStudent(students, studentName, studentID);
                break;
                
            case 4:
                // options student
                displayStudent(students, studentID);
                break;
                
            case 5:     
                // Exits program
                cout << "Exting program..." << endl;
                running = false;
                break;
                
            default:
                cout << "Invalid choice. Please enter a number between 1 and 5." << endl;
        }
    }
    return 0;
}

// helper function to convert string to lowercase
string toLowercase(const string& str) {
    string lower = str;
    transform(lower.begin(), lower.end(), lower.begin(), ::tolower);
    return lower;
}

// helper function to compare strings in a case-insensitive manner
// returns a or b if its value is less than the other
bool caseInsensitiveCompare(const string& a, const string& b) {
    return toLowercase(a) < toLowercase(b);
}

// helper function to clear the input buffer
void clearInputBuffer() {
    cin.clear();
    //.ignore() is used to clear the buffer
    cin.ignore(numeric_limits<streamsize>::max(), '\n');  // #include limits for numeric_limits
}

// simple text menu
void optionMenu() {
    cout << "\n--- Students Manager ---" << endl
         << "1. Add Student" << endl
         << "2. Remove Student" << endl
         << "3. Search Student" << endl
         << "4. Display Students" << endl
         << "5. Exit" << endl
         << "Enter your choice (1-5): ";
}

/**
 * @brief adds a student
 * 
 * @param studentDB  - Student Database
 * @param studentName  - The name of the student
 * @param studentID - Student ID (position in th earray)
 */
void addStudent(string studentDB[], string studentName, int& studentID) {
    if (studentName.empty()) {
        cout << "Error: Student name cannot be empty" << endl;
        return;
    }
    
    studentDB[studentID] = studentName;
    studentID++;
    //sorts the studentDB array using #include<algorithm>
    sort(studentDB, studentDB + studentID, caseInsensitiveCompare);
    cout << "Added student: " << studentName << " at seat " << studentID << endl;
}

//@brief Removes a students in the array
void removeStudent(string studentDB[], string studentName, int& studentID) {
    
    for (int i = 0; i < studentID; i++) {
        if (toLowercase(studentDB[i]) == toLowercase(studentName)) {
            // Shift remaining students to fill the gap
            for (int j = i; j < studentID - 1; j++) {
                studentDB[j] = studentDB[j + 1];
            }
            studentDB[studentID - 1] = "";
            studentID--;
            
            cout << "Removed student: " << studentName << endl;
            sort(studentDB, studentDB + studentID, caseInsensitiveCompare);
            cout << "Student list updated" << endl;
            displayStudent(studentDB, studentID);
            
            return;
        }
    }
    cout << "Student not found: " << studentName << endl;
}

// @brief Searches for a student in the array
void searchStudent(const string studentDB[], const string& studentName, int studentID) {
    //.empty() checks if the string is empty
    if (studentName.empty()) {
        cout << "Error: Search term cannot be empty" << endl;
        return;
    }

    // converts the search term to lowercase
    string searchTerm = toLowercase(studentName);
    bool found = false;

    // loops through the studentDB array and loops for the student
    for (int i = 0; i < studentID; i++) {
        //.find() is used to find the search term in the studentDB array
        if (toLowercase(studentDB[i]).find(searchTerm) != string::npos) {
            cout << "Student found: " << studentDB[i] << " at seat: " << (i + 1) << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Student not found: " << studentName << endl;
    }
}

// @brief Displays the list of students
void displayStudent(const string studentDB[], int studentID) {
    cout << "\n--- Student List ---" << endl;
    
    if (studentID == 0) {
        cout << "No students in the list" << endl;
    } else {
        for (int i = 0; i < studentID; i++) {
            cout << (i + 1) << "- " << studentDB[i] << endl;
        }
    }
    cout << "------------------" << endl;
}