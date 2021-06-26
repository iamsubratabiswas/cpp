// Inheritance
// Write a class Employee having data member name, salary etc. Write proper constructors, methods to get/set
// them and a virtual method printDetails() that prints all information of a person. Now write two classes Manager
// and Clerk from Employee. Add ‘type’ and ‘allowance’ in the manager and Clerk respectively. Write
// constructors, methods to get/set them and a override printDetails(). Now create a Manager and a Clerk object and
// call printDetails() function on them to display their information.
// Now Create an array of pointers to Employee and store addresses of two Employee, two Managers and two
// Clerks. Call printDetails() on all elements (a loop may be used). Also find the total salary drawn by all
// employees.



#include <iostream>

using namespace std;

class Employee {
    string name;
    double salary;  // in cm

   public:
    Employee() {
        name = "";
        salary = 0;
    }

    Employee(string name, double salary) {
        this->name = name;
        this->salary = salary;
    }

    string getName() { return name; }
    void setName(string name) { this->name = name; }

    double getSalary() { return salary; }
    void setSalary() { this->salary = salary; }

    virtual void printDetails() {
        cout << "Name   : " << name << endl
             << "Salary : " << salary << " Rs." << endl;
    }
};

class Manager : public Employee {
    string type;

   public:
    Manager() { type = ""; }

    Manager(string name, double salary, string type) : Employee(name, salary) {
        this->type = type;
    }

    string getType() { return type; }
    void setType(string type) { this->type = type; }

    void printDetails() {
        Employee::printDetails();
        cout << "Type   : " << type << endl;
    }
};

class Clerk : public Employee {
    double allowance;

   public:
    Clerk() { allowance = 0; }

    Clerk(string name, double salary, double allowance)
        : Employee(name, salary) {
        this->allowance = allowance;
    }
    double getAllowance() { return allowance; }
    void setAllowance() { this->allowance = allowance; }

    void printDetails() {
        Employee::printDetails();
        cout << "Allowance : " << allowance << " Rs." << endl;
    }
};

int main() {
    Manager m("Manager 1", 216000, "Technical");
    m.printDetails();
    cout << endl;
    Clerk c("Clerk 1", 37500, 1200);
    c.printDetails();
    cout << endl;
    double totalSal = 0;
    Employee *earr[6];
    earr[0] = new Employee("Employee 1", 89000);
    earr[1] = new Employee("Employee 2", 91000);
    earr[2] = new Manager("Manager 1", 209000, "Technical");
    earr[3] = new Manager("Manager 2", 190600, "Technical");
    earr[4] = new Clerk("Clerk 1", 35000, 5000);
    earr[5] = new Clerk("Clerk 2", 38000, 5000);
    for (int i = 0; i < 6; i++) {
        earr[i]->printDetails();
        totalSal += earr[i]->getSalary();
        cout << endl;
    }
    cout << "Total salary drawn by all employees: " << totalSal << endl;
}
