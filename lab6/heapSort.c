#include <stdio.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left] > arr[largest])
        largest = left;
    if (right < N && arr[right] > arr[largest])
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(int arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main()
{
    // int n;
    // scanf("%d", &n);
    // int numbers[n];
    // char arr[100];
    // scanf("%s", arr);

    // FILE *fp = fopen(arr, "r");
    // int i = 0;
    // int num;
    // while (fscanf(fp, "%d", &num) > 0)
    // {
    //     numbers[i] = num;
    //     i++;
    // }
    // fclose(fp);

    int numbers[] = {5, 1, 2, 8, 9};
    int n = 5;

    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    heapSort(numbers, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", numbers[i]);
    }
    return 0;
}