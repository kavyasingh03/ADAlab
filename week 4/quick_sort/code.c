#include <time.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX 5000

void quicksort(int[], int, int);
int partition(int[], int, int);

int main() { 
    int i, n, a[MAX], ch = 1;
    clock_t start, end;

    while (ch == 1) { 
        printf("\nEnter the number of elements: ");
        scanf("%d", &n);

        if (n <= 0 || n > MAX) {  
            printf("Invalid input! Please enter a number between 1 and %d.\n", MAX);
            continue;
        }

        printf("Enter the array elements:\n");
        for (i = 0; i < n; i++)
            scanf("%d", &a[i]);

        printf("The entered array is:\n");
        for (i = 0; i < n; i++)
            printf("%d ", a[i]);

        start = clock();
        quicksort(a, 0, n - 1);
        end = clock();

        printf("\n\nThe sorted array elements are:\n");
        for (i = 0; i < n; i++)
            printf("%d\n", a[i]);

        printf("Time taken = %f seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

        printf("\n\nDo you wish to continue? (1 for Yes / 0 for No): ");
        if (scanf("%d", &ch) != 1) {  
            printf("Invalid input! Exiting program.\n");
            break;
        }

        if (ch != 1)  
            break;
    }

    return 0;
}

void quicksort(int a[], int low, int high) {
    int mid;
    if (low < high) {
        mid = partition(a, low, high);
        quicksort(a, low, mid - 1);
        quicksort(a, mid + 1, high);
    }
}

int partition(int a[], int low, int high) {
    int key, i, j, temp, k;
    key = a[low];
    i = low + 1;
    j = high;

    while (i <= j) {
        while (i <= high && key >= a[i])
            i = i + 1;
        while (key < a[j])
            j = j - 1;

        if (i < j) {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
        } else {
            k = a[j];
            a[j] = a[low];
            a[low] = k;
        }
    }
    return j;
}
