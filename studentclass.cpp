#include <iostream>
#include<map>
using namespace std;

class student
{
private:
    string name;
    double cgpa;
    string id;

public:
    student()
    {
        name = "";
        cgpa = 0.0;
        id = "";
    }
    student(string name, double cgpa, string id)
    {
        this->name = name;
        this->cgpa = cgpa;
        this->id = id;
    }
    void display()
    {
        cout << "Name: " << name << endl;
        cout << "CGPA: " << cgpa << endl;
        cout << "ID: " << id << endl;
    }
};
int main(){
    map<string, student> students;
    string name, id;
    double cgpa;
    while(true){
        cout << "Enter student name (or 'exit' to quit): ";
        cin >> name;
        if(name == "exit"){
            break;
        }
        cout << "Enter student CGPA: ";
        cin >> cgpa;
        cout << "Enter student ID: ";
        cin >> id;

        student s(name, cgpa, id);
        students[id] = s; 
    }
    while(true){
        cout << "Enter student ID to display (or 'exit' to quit): ";
        cin >> id;
        if(id == "exit"){
            break;
        }
        if(students.find(id) != students.end()){
            students[id].display();
        } else {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    return 0;
}
