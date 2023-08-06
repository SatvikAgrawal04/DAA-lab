#include <bits/stdc++.h>
using namespace std;

int second_largest(int arr[], int n)
{
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    int sec_max = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > sec_max && arr[i] < max)
        {
            sec_max = arr[i];
        }
    }
    return sec_max;
}
int second_smallest(int arr[], int n)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < min)
            min = arr[i];
    }
    int sec_min = second_largest(arr, n);
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < sec_min && arr[i] > min)
        {
            sec_min = arr[i];
        }
    }
    return sec_min;
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

    cout << second_largest(arr, n) << endl;
    cout << second_smallest(arr, n) << endl;
    return 0;
}