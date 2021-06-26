// Classes and Objects
//  Write a class for your Grade card. The grade card is given to each student of a department per semester. The
// grade card typically contains the name of the department, name of the student, roll number, semester, a list of
// subjects with their marks and a calculated CGPA. Create 60 such grade cards in a 3
// rd semester with relevant data
// and find the name and roll number of student having highest CGPA.




#include <iostream>

using namespace std;

// return randim number from [lo, hi)
int getRandom(double lo, double hi) {
    double random = (double)rand() / RAND_MAX;
    random *= (hi - lo);
    random += lo;
    return (int)random;
}


class GradeCard {
    string deptName;
    string studentName;
    long rollNo;
    int semester;
    string subjects[5];
    int marks[5];
    float cgpa;

   public:
    GradeCard(){};
    GradeCard(string dName, string sName, long rNo, int sem , string sub[5], int m[5]) {
        deptName = dName;
        studentName = sName;
        rollNo = rNo;
        semester = sem;
        for (int i = 0; i < 5; i++) subjects[i] = sub[i];
        float tMarks = 0.0F;
        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
            tMarks += marks[i];
        }
        cgpa = tMarks / 50;  // 5*10
    }

    string getStudentName() {
        return studentName;
    }

    long getRollNo() {
        return rollNo;
    }

    float getCgpa() {
        return cgpa;
    }

    void display() {
        cout << "  Department : " << deptName << endl
             << "  Name       : " << studentName << endl    
             << "  Roll No.   : " << rollNo << endl
             << "  Semester   : " << semester << endl
             << "  CGPA       : " << cgpa << endl;
    }
};

int main() {
    GradeCard arr[60];
    // Creating 60 grade cards
    for (int i = 0; i < 60; i++) {
        string dept = "Information Technology";
        string name = "Student #" + to_string(i+1);
        int r = 1900 + i;
        int sem = 3;
        string sub[5] = {"COA", "DBMS", "DSA", "OOP", "Maths"};
        int marks[5] = {getRandom(50,100), getRandom(50,100), getRandom(50,100), 
                            getRandom(50,100), getRandom(50,100)};
        arr[i] = GradeCard(dept, name, r, sem, sub, marks);
        cout << "Created Grade Card : " << endl;
        arr[i].display();
        cout << endl;
    }
    cout << "------------------------------------" << endl;
    // Finding student with highest cgpa
    int maxIndex = 0;
    for (int i = 0; i < 60; i++) {
        if (arr[i].getCgpa() > arr[maxIndex].getCgpa())
            maxIndex = i;
    }
    cout << "Student with highest CGPA : " << endl;
    arr[maxIndex].display();
}
