#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Person
{
    int id;
    char *name;
    int age;
    int height;
    int weight;
};

void swap(struct Person *a, struct Person *b)
{
    struct Person temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct person arr[], int n, int i, int (*cmp)(struct person, struct person))
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && cmp(*(arr[left]), arr[largest]))
        largest = left;

    if (right < n && cmp(arr[right], arr[largest]))
        largest = right;

    if (largest != i)
    {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest, cmp);
    }
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    struct Person *people = (struct Person *)malloc(n * sizeof(struct Person));
    printf("Enter data for %d people (Id Name Age Height Weight):\n", n);
    for (int i = 0; i < n; i++)
    {
        people[i].id = i;
        char tempName[100];
        scanf("%s %d %d %d", tempName, &people[i].age, &people[i].height, &people[i].weight);
        people[i].name = strdup(tempName);
    }

MENU:
    int option;
    printf("\nMAIN MENU (HEAP)\n");
    printf("1. Create a Min-heap based on age\n");
    printf("2. Create a Max-heap based on weight\n");
    printf("3. Display weight of the youngest person\n");
    printf("4. Insert a new person into the Min-heap\n");
    printf("5. Delete the oldest person\n");
    printf("6. Exit\n");
    printf("Enter option: ");
    scanf("%d", &option);
    return 0;
}
