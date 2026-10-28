#include <iostream>
using namespace std;

struct Parcel {
    double weight;
    bool express, insured;
};

double charge(double weight, bool express = false,
              bool insured = false) {
    return weight * 50 + (express ? 100 : 0)
                     + (insured ? 50 : 0);
}

double charge(int grams) {
    return grams * 0.05;
}

double charge(Parcel p) {
    return charge(p.weight, p.express, p.insured);
}

int main() {
    Parcel p = {2.0, true, true};

    cout << "charge(2): " << charge(2) << '\n';
    cout << "charge(2.0): " << charge(2.0) << '\n';
    cout << "charge(2.0, true): " << charge(2.0, true) << '\n';
    cout << "charge(2.0, true, true): " << charge(2.0, true, true) << '\n';
    cout << "charge(2000): " << charge(2000) << '\n';
    cout << "charge(Parcel): " << charge(p) << '\n';

    return 0;
}
