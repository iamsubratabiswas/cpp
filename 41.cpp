#include <iostream>

using namespace std;

class Person {
    string name;
    int age;        // in years
    double height;  // in cm

   public:
    Person() {
        name = "";
        age = 0;
        height = 0;
    }

    Person(string name, int age, double height) {
        this->name = name;
        this->age = age;
        this->height = height;
    }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    int getAge() { return age; }
    void setAge(int age) { this->age = age; }

    double getHeight() { return height; }
    void setHeight() { this->height = height; }
    
    // void printDetails() {
    //     cout << "Name   : " << name << endl
    //     << "Age    : " << age << "years" << endl
    //     << "Height : " << height << "cm" << endl;
    // }

    virtual void printDetails() {
        cout << "Name   : " << name << endl
        << "Age    : " << age << "years" << endl
        << "Height : " << height << "cm" << endl;
    }
};

class Student : public Person {
    long roll;
    int yearOfAdmission;

   public:
    Student() {
        roll = 0;
        yearOfAdmission = 0;
    }

    Student(string name, int age, double height, long roll, int yearOfAdmission)
        : Person(name, age, height) {
        this->roll = roll;
        this->yearOfAdmission = yearOfAdmission;
    }

    int getYearOfAdmission() { return yearOfAdmission; }
    void setYearOfAdmission(int yearOfAdmission) {
        this->yearOfAdmission = yearOfAdmission;
    }

    long getRoll() { return roll; }
    void setRoll(long roll) { this->roll = roll; }

    void printDetails() {
        Person::printDetails();
        cout << "Roll   : " << roll << endl
        << "Year of Admission : " << yearOfAdmission << endl;
    }
};

int main() {
    string name = "1 - Person's name";
    Person p1(name, 20, 175);
    p1.printDetails();
    name = "1 - Student's name";
    Student s1(name, 20, 165, 40, 2019);
    s1.printDetails();
    name = "2 - Person's name";
    Person p2(name, 19, 180);
    name = "2 - Student's name";
    Student s2(name, 20, 170, 1111, 2019);

    Person* parr[4];
    parr[0] = &p1;
    parr[1] = &p2;
    parr[2] = &s1;
    parr[3] = &s2;

    parr[0]->printDetails();
    parr[1]->printDetails();
    parr[2]->printDetails();
    parr[3]->printDetails();
}
