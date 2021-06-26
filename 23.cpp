#include <iostream>
#include <vector>

using namespace std;

// return randim number from [lo, hi)
double getRandom(double lo, double hi) {
    double random = (double)rand() / RAND_MAX;
    random *= (hi - lo);
    random += lo;
    return random;
}

class BalanceBelowLimit {};
class NegativeAmount {};
class NegativeRate {};

class SavingsAccount {
    string name;
    const long accNo;
    double balance;

    static double interestRate;
    static long nextAccNo;

   public:
    SavingsAccount(string name, double balance) : accNo(nextAccNo++) {
        if (balance < 1000) throw BalanceBelowLimit();
        this->name = name;
        this->balance = balance;
    }

    static void setInterestRate(double interestRate) {
        SavingsAccount::interestRate = interestRate;
    }

    static double getInterestRate() { return interestRate; }

    string getName() { return name; }

    long getAccNo() { return accNo; }

    void deposit(double amount) {
        if (amount < 0) throw NegativeAmount();
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount < 0) throw NegativeAmount();
        if (balance - amount < 1000) throw BalanceBelowLimit();
        balance -= amount;
    }

    double getBalence() { return balance; }

    double getYearlyInterest() { return balance * (interestRate / 100); }

    void show() {
        cout << "Name     :" << name << endl;
        cout << "Acc. No. :" << accNo << endl;
        cout << "Balance  :" << balance << endl;
    }
};

long SavingsAccount::nextAccNo = 1;
double SavingsAccount::interestRate = 4.0;

int main() {
    vector<SavingsAccount> arr;
    for (int i = 0; i < 100; i++) {
        string name = "person " + to_string(i);
        double amount = getRandom(1000, 100000);
        SavingsAccount sa(name, amount);
        arr.push_back(sa);
        cout << "Created account : " << endl;
        sa.show();
    }

    double totalInterest = 0;
    for (int i = 0; i < 100; i++) {
        double curInterest = arr[i].getYearlyInterest();
        totalInterest += curInterest;
        arr[i].deposit(arr[i].getYearlyInterest());
        cout << "Interest paid to " << arr[i].getName() << " : Rs. "
             << curInterest << endl;
    }
    cout << endl << "Total interest paid : Rs. " << totalInterest << endl;
}
