#include <bits/stdc++.h>
using namespace std;

void exchange(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}

void rotate_right(int arr[], int k)
{
    for (int i = k - 1; i > 0; i--)
    {
        exchange(arr + i, arr + (i - 1));
    }
}

int main()
{
    int n;
    cout << "Enter length of array" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter array" << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cout << "Enter No. of elements to rotate" << endl;
    cin >> k;
    if (k > n)
    {
        cout << "Invalid Input" << endl;
        return 0;
    }
    rotate_right(arr, k);
    for (int i = 0; i < n; i++)
        cout
            << arr[i] << endl;
    return 0;
}