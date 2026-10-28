#include <iostream>
using namespace std;

class SavingsAccount {
    int accNo, count = 0;
    double balance, trans[10];

public:
    SavingsAccount(int a, double b) : accNo(a), balance(b) {}

    void deposit(double);
    void withdraw(double);

    void add(double x) {
        if (count == 10) {
            for (int i = 0; i < 9; i++)
                trans[i] = trans[i + 1];
            count--;
        }
        trans[count++] = x;
    }

    void miniStatement() {
        cout << "Account: " << accNo << "\nBalance: " << balance << '\n';
        for (int i = 0; i < count; i++)
            cout << trans[i] << '\n';
    }
};

void SavingsAccount::deposit(double x) {
    if (x > 0) {
        balance += x;
        add(x);
    }
}

void SavingsAccount::withdraw(double x) {
    if (x > 0 && x <= balance) {
        balance -= x;
        add(-x);
    }
}

int main() {
    SavingsAccount s(1001, 5000);
    s.deposit(1000);
    s.withdraw(500);
    s.deposit(2000);
    s.withdraw(300);
    s.miniStatement();
    return 0;
}
