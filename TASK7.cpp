#include <iostream>
using namespace std;

class SavingsAccount {
    int accNo, count = 0, next = 0;
    double balance, trans[10];

public:
    SavingsAccount(int a, double b) : accNo(a), balance(b) {}

    void add(double x) {
        balance += x;
        trans[next] = x;
        next = (next + 1) % 10;
        if (count < 10) count++;
    }

    void miniStatement() {
        cout << "Account: " << accNo
             << "\nBalance: " << balance << '\n';

        int start = (next - count + 10) % 10;
        for (int i = 0; i < count; i++)
            cout << trans[(start + i) % 10] << '\n';
    }
};

int main() {
    SavingsAccount s(1001, 5000);
    s.add(1000);
    s.add(-500);
    s.add(2000);
    s.add(-300);
    s.miniStatement();
    return 0;
}
