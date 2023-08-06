#include <bits/stdc++.h>
using namespace std;

void exchange(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6};
    int i = 3;
    exchange(arr + i, arr + (i - 1));
    for (int i = 0; i < 6; i++)
        cout << arr[i] << endl;
}