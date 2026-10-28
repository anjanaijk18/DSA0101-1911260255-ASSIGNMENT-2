#include <iostream>
using namespace std;

int& highestMark(int marks[], int n)
{
    int maxIndex = 0;
    for (int i = 1; i < n; i++)
        if (marks[i] > marks[maxIndex])
            maxIndex = i;
    return marks[maxIndex];
}

int& dangerousFunction()
{
    int x = 100;
    return x;
}

int main()
{
    int marks[] = {75, 88, 92, 81, 67};
    int n = 5;

    cout << "Highest mark: " << highestMark(marks, n) << '\n';
    highestMark(marks, n) += 2;
    cout << "After moderation: " << highestMark(marks, n) << '\n';

    return 0;
}
