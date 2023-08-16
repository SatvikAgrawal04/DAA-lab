#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// void bubbleSort(int arr[], int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//                 swap(&arr[j], &(arr[j + 1]));
//         }
//     }
// }

// void selectionSort(int arr[], int n)
// {
//     for (int i = 0; i < n - 1; i++)
//     {
//         int k = i;
//         for (int j = i + 1; j < n; j++)
//         {
//             if (arr[j] < arr[k])
//                 k = j;
//         }
//         swap(&arr[k], &arr[i]);
//     }
// }

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
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

    clock_t start1, end1, start2, end2;

    insertionSort(arr, size);

    start1 = clock();
    insertionSort(arr, size);
    end1 = clock();

    reverse(arr, arr + size);

    start2 = clock();
    insertionSort(arr, size);
    end2 = clock();

    double time_taken1 = double(end1 - start1) / CLOCKS_PER_SEC;
    double time_taken2 = double(end2 - start2) / CLOCKS_PER_SEC;
    cout << "Time taken by program is : " << endl
         << "Best Case: " << time_taken1 << setprecision(5);
    cout << " sec " << endl;
    cout << "Worst Case: " << time_taken2 << setprecision(5);
    cout << " sec " << endl;
    return 0;
}
