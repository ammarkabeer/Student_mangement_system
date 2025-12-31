#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Student {
public:
    int id;
    string name;
    int age;

    Student(int id, string name, int age) : id(id), name(name), age(age) {}
};

class StudentManager {
private:
    vector<Student> students;

public:
    void addStudent(int id, string name, int age) {
        students.push_back(Student(id, name, age));
        cout << "Student added successfully.\n";
    }

    void displayStudents() {
        if (students.empty()) {
            cout << "No students to display.\n";
            return;
        }
        cout << "ID\tName\tAge\n";
        for (const auto& s : students) {
            cout << s.id << "\t" << s.name << "\t" << s.age << "\n";
        }
    }

    void searchStudent(int id) {
        for (const auto& s : students) {
            if (s.id == id) {
                cout << "Student found: " << s.name << ", Age: " << s.age << "\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }

    void deleteStudent(int id) {
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->id == id) {
                students.erase(it);
                cout << "Student deleted successfully.\n";
                return;
            }
        }
        cout << "Student not found.\n";
    }
};

int main() {
    StudentManager manager;
    int choice, id, age;
    string name;

    while (true) {
        cout << "\nStudent Management System\n";
        cout << "1. Add Student\n";
        cout << "2. Display Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter ID: ";
                cin >> id;
                cout << "Enter Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter Age: ";
                cin >> age;
                manager.addStudent(id, name, age);
                break;
            case 2:
                manager.displayStudents();
                break;
            case 3:
                cout << "Enter ID to search: ";
                cin >> id;
                manager.searchStudent(id);
                break;
            case 4:
                cout << "Enter ID to delete: ";
                cin >> id;
                manager.deleteStudent(id);
                break;
            case 5:
                cout << "Exiting...\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}
