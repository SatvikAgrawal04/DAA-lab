#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
                swap(&arr[j], &(arr[j + 1]));
        }
    }
}

int main(int argc, char const *argv[])
{
    string filename, opfile;
    int number;
    int size;
    cin >> size;
    cin >> filename;
    int arr[size];
    int ct = 0;
    ifstream input_file(filename);
    while (input_file >> number && ct < size)
    {
        arr[ct++] = number;
    }

    clock_t start, end;

    start = clock();

    bubbleSort(arr, size);

    end = clock();

    double time_taken = double(end - start) / CLOCKS_PER_SEC;
    cout << "Time taken by program is : " << fixed
         << time_taken << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
