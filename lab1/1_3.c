#include <stdio.h>
struct map
{
    int key;
    int value;
};
void print(int arr[], int n)
{
    printf("\n\nThe elements of the array are :\n\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
}

int countDuplicates(int arr[], int n)
{
    int count = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
                break; // We break the inner loop as soon as we find a duplicate to avoid counting it multiple times.
            }
        }
    }

    return count;
}

#include <stdio.h>

int findMostFrequentElement(int arr[], int n)
{
    int maxCount = 0;
    int mostFrequentElement = arr[0];

    for (int i = 0; i < n; i++)
    {
        int count = 1;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                count++;
            }
        }

        if (count > maxCount)
        {
            maxCount = count;
            mostFrequentElement = arr[i];
        }
    }

    return mostFrequentElement;
}

int main()
{
    FILE *myFile;
    myFile = fopen("hello.txt", "r");
    printf("Enter the size: ");
    int n;
    scanf("%d", &n);
    int arr[n];
    int i;
    for (i = 0; i < n; i++)
    {
        fscanf(myFile, "%d", &arr[i]);
    }
    print(arr, n);
    printf("\nNo. of duplicates are: %d", countDuplicates(arr, n));
    printf("\nMost frequent element is: %d", findMostFrequentElement(arr, n));
    return 0;
}