#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int start, int end)
{

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] <= pivot)
            count++;
    }

    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);

    // Sorting left and right parts of the pivot element
    int i = start, j = end;

    while (i < pivotIndex && j > pivotIndex)
    {

        while (arr[i] <= pivot)
        {
            i++;
        }

        while (arr[j] > pivot)
        {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end)
{

    // base case
    if (start >= end)
        return;

    // partitioning the array
    int p = partition(arr, start, end);

    // Sorting the left part
    quickSort(arr, start, p - 1);

    // Sorting the right part
}

int main(int argc, char const *argv[])
{
    string filename, opfile;
    int number;
    int size;
    cin >> size;
    cin >> filename;
    double time_taken1, time_taken2, time_taken3;
MENU:
    int arr[size];
    int ct = 0;
    ifstream input_file(filename);
    while (input_file >> number && ct < size)
    {
        arr[ct++] = number;
    }

    // clock_t start1, end1, start2, end2;
    // double time_taken1 = double(end1 - start1) / CLOCKS_PER_SEC;
    // double time_taken2 = double(end2 - start2) / CLOCKS_PER_SEC;

    printf("\nMAIN MENU (QUICK SORT)\n1. Ascending Data\n2. Descending Data\n3. Random Data\n4. EXIT\n");
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        quickSort(arr, 0, size - 1);

        clock_t start1, end1;
        start1 = clock();
        quickSort(arr, 0, size - 1);
        end1 = clock();

        time_taken1 = double(end1 - start1) / CLOCKS_PER_SEC;
        cout << "Time taken: " << fixed << setprecision(5) << time_taken1 << " seconds" << endl;
        goto MENU;

    case 2:
        quickSort(arr, 0, size - 1);
        reverse(arr, arr + size);

        clock_t start2, end2;
        start2 = clock();
        quickSort(arr, 0, size - 1);
        end2 = clock();

        time_taken2 = double(end2 - start2) / CLOCKS_PER_SEC;
        cout << "Time taken: " << fixed << setprecision(5) << time_taken2 << " seconds" << endl;
        goto MENU;

    case 3:
        clock_t start3, end3;
        start3 = clock();
        quickSort(arr, 0, size - 1);
        end3 = clock();

        time_taken3 = double(end3 - start3) / CLOCKS_PER_SEC;
        cout << "Time taken: " << fixed << setprecision(5) << time_taken3 << " seconds" << endl;
        goto MENU;
    case 4:
        exit(0);
    }

    return 0;
}