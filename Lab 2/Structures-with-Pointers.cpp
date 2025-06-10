#include <iostream>
using namespace std;
struct Student {
string name;
int age;
float marks;
};
int main() {
Student *ptr = new Student;
ptr->name = "John";
ptr->age = 20;
ptr->marks = 85.5;
cout << "Name: " << ptr->name << "\nAge: " << ptr->age << "\nMarks: " << ptr->marks << endl;
delete ptr;
return 0;
}