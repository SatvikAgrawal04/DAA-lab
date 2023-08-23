#include <bits/stdc++.h>
using namespace std;

void increment(int *a)
{
    a = a + 1;
    cout << *a << endl;
}

int main(int argc, char const *argv[])
{
    int a = 0;
    increment(&a);
    cout << a << endl;
    return 0;
}
