#include <iostream>
using namespace std;

class Time {
    int h, m;

public:
    Time(int hh, int mm) : h(hh), m(mm) {}

    friend int minutesBetween(const Time&, const Time&);
    friend bool earlier(const Time&, const Time&);
};

inline int minutesBetween(const Time& a, const Time& b) {
    int x = a.h * 60 + a.m;
    int y = b.h * 60 + b.m;
    return (x > y) ? x - y : y - x;
}

inline bool earlier(const Time& a, const Time& b) {
    return a.h * 60 + a.m < b.h * 60 + b.m;
}

int main() {
    Time departure(9, 45), arrival(13, 10);

    cout << minutesBetween(departure, arrival) << '\n';
    cout << boolalpha << earlier(arrival, departure) << '\n';

    return 0;
}
