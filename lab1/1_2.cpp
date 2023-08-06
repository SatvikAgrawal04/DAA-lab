#include <bits/stdc++.h>
using namespace std;

void prefix_array(int arr[], int prefix_arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        prefix_arr[i] = sum;
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

    int prefix_arr[n];
    prefix_array(arr, prefix_arr, n);
    for (int i = 0; i < n; i++)
        cout << prefix_arr[i] << endl;
    return 0;
}