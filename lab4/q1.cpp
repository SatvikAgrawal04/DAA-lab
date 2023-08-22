#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int array[], int const left, int const mid,
           int const right)
{
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    auto *leftArray = new int[subArrayOne],
         *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    auto indexOfSubArrayOne = 0, indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo)
    {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo])
        {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else
        {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne)
    {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo)
    {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is right index
// of the sub-array of arr to be sorted
void mergeSort(int array[], int const begin, int const end)
{
    if (begin >= end)
        return;

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}

// Driver code
// This code is contributed by Mayank Tyagi
// This code was revised by Joshua Estes

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

    printf("\nMAIN MENU (MERGE SORT)\n1. Ascending Data\n2. Descending Data\n3. Random Data\n4. EXIT\n");
    int ch;
    cin >> ch;
    switch (ch)
    {
    case 1:
        mergeSort(arr, 0, size - 1);

        clock_t start1, end1;
        start1 = clock();
        mergeSort(arr, 0, size - 1);
        end1 = clock();

        time_taken1 = double(end1 - start1) / CLOCKS_PER_SEC;
        cout << "Time taken: " << fixed << setprecision(5) << time_taken1 << " seconds" << endl;
        goto MENU;

    case 2:
        mergeSort(arr, 0, size - 1);
        reverse(arr, arr + size);

        clock_t start2, end2;
        start2 = clock();
        mergeSort(arr, 0, size - 1);
        end2 = clock();

        time_taken2 = double(end2 - start2) / CLOCKS_PER_SEC;
        cout << "Time taken: " << fixed << setprecision(5) << time_taken2 << " seconds" << endl;
        goto MENU;

    case 3:
        clock_t start3, end3;
        start3 = clock();
        mergeSort(arr, 0, size - 1);
        end3 = clock();

        time_taken3 = double(end3 - start3) / CLOCKS_PER_SEC;
        cout << "Time taken: " << fixed << setprecision(5) << time_taken3 << " seconds" << endl;
        goto MENU;
    case 4:
        exit(0);
    }

    return 0;
}