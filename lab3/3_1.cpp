#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int k, int &comp)
{
    int l = 0, r = n - 1;
    int result = -1;
    while (l < r)
    {
        int m = l + (r - l) / 2;
        comp++;
        if (arr[m] == k)
        {
            result = m;
            r = m - 1;
        }
        else if (arr[m] > k)
            r = m - 1;

        else
            l = m + 1;
    }
    return result;
}

int main(int argc, char const *argv[])
{
    int n;
    cout << "Enter size: ";
    cin >> n;
    int arr[n];
    cout << "Enter elements: ";
    int comp = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Enter key: ";
    int k;
    cin >> k;
    sort(arr, arr + n);
    int f = binarySearch(arr, n, k, comp);

    if (f != -1)
    {
        cout << k << " found at index " << f << endl;
        cout << "No. of comparisions: " << comp << endl;
    }
    else
    {
        cout << "not Found";
    }
    return 0;
}