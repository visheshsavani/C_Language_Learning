#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int array[], int left, int middle, int right);
void mergeSort(int array[], int left, int right);
void quickSort(int array[], int low, int high);
int partition(int array[], int low, int high);
void swap(int *x, int *y);

int main()
{
    srand(time(NULL));
    FILE *input_file;
    FILE *output_file;
    int n = 100000;
    input_file = fopen("input.txt", "w");
    int arr[n];
    for (int j = 0; j < n; j++)
    {
        arr[j] = rand() % 100000 + 1;
        fprintf(input_file, "%d\n", arr[j]);
    }
    fclose(input_file);

    output_file = fopen("time_taken.csv", "w");
    printf("Block Size\tMerge Sort\tQuick Sort\n");
    input_file = fopen("input.txt", "r");
    for (int p = 99; p < n; p = p + 100)
    {
        int array[p + 1];
        int array1[p + 1];
        for (int j = 0; j < p; j++)
        {
            array[j] = arr[j];
            fscanf(input_file, "%1d", &array1[j]);
        }
        clock_t begin = clock();
        mergeSort(array, 0, p);
        clock_t mid = clock();
        quickSort(array1, 0, p);
        clock_t end = clock();
        double time_spent = (double)(mid - begin);
        double time_spent1 = (double)(end - mid);
        printf("%d\t%lf\t%lf\n", p + 1, time_spent, time_spent1);
        fprintf(output_file, "%d,%lf,%lf\n", p + 1, time_spent, time_spent1);
    }
    printf("\n");
    fclose(input_file);
    fclose(output_file);
}

void merge(int array[], int left, int middle, int right)
{
    int i, j, k;
    int n1 = middle - left + 1;
    int n2 = right - middle;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = array[left + i];
    for (j = 0; j < n2; j++)
        R[j] = array[middle + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            array[k] = L[i];
            i++;
        }
        else
        {
            array[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        array[k] = L[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        array[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int array[], int left, int right)
{
    if (left < right)
    {
        int middle = left + (right - left) / 2;

        mergeSort(array, left, middle);
        mergeSort(array, middle + 1, right);

        merge(array, left, middle, right);
    }
}

void quickSort(int array[], int low, int high)
{
    if (low < high)
    {
        int pivot_index = partition(array, low, high);

        quickSort(array, low, pivot_index - 1);
        quickSort(array, pivot_index + 1, high);
    }
}

int partition(int array[], int low, int high)
{
    int pivot = array[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            swap(&array[i], &array[j]);
        }
    }

    swap(&array[i + 1], &array[high]);
    return (i + 1);
}

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
