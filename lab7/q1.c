#include <stdio.h>
struct Item
{
    int item_no;
    float item_profit, item_wieght, profit_weight_ratio;
};

void swap(struct Item *a, struct Item *b)
{
    struct Item temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct Item arr[], int N, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < N && arr[left].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = left;
    if (right < N && arr[right].profit_weight_ratio > arr[largest].profit_weight_ratio)
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, N, largest);
    }
}

void heapSort(struct Item arr[], int N)
{
    for (int i = N / 2 - 1; i >= 0; i--)
        heapify(arr, N, i);

    for (int i = N - 1; i >= 0; i--)
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    printf("Enter no. of items: ");
    scanf("%d", &n);
    struct Item items[n];
    int cap;
    for (int i = 0; i < n; i++)
    {
        printf("Enter item_no, profit and weight: ");
        scanf("%d %f %f", &items[i].item_no, &items[i].item_profit, &items[i].item_wieght);
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &cap);

    heapSort(items, n);
    for (int i = 0; i < n; i++)
    {
        items[i].profit_weight_ratio = items[i].item_profit / items[i].item_wieght;
    }

    for (int i = 0; i < n; i++)
    {
        printf("item_no\tprofit\tweight\tratio\n");
        printf("%d\t%f\t%f\t%f\n", items[i].item_no, items[i].item_profit, items[i].item_wieght, items[i].profit_weight_ratio);
    }

    float final_value = 0;
    for (int i = 0; i < n; i++)
    {
        if (items[i].item_wieght < cap)
        {
            cap -= items[i].item_wieght;
            final_value += items[i].item_profit;
        }
        else
        {
            final_value += items[i].item_profit * ((float)cap / items[i].item_wieght)
        }
    }
    printf("%f\n", final_value);
    return 0;
}
