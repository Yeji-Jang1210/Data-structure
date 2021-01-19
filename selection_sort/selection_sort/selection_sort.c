#include <stdio.h>
#include <stdbool.h>
void selection_sort(int array[], int size);

int main(void) 
{
    int arr[] = { 4,3,1,2,5,6 };
    printf("before:");
    for (int i = 0; i < 6; i++) {
        printf("%i", arr[i]);
    }
    printf("\n");
    printf("--- selection sort ---\n");
    selection_sort(arr, 6);
}

void selection_sort(int arr[], int size) 
{
    for (int n = 0; n < size; n++) 
    {
        bool swap = false;
        int tmp = 0;
        int* min;
        min = arr+n;
        for (int i = n; i < size-1; i++)
        {
            if (*min > arr[i + 1])
            {
                min = &arr[i + 1];
                swap = true;
            }
        }
        if (swap == false) 
        {
            break;
        }
        tmp = arr[n];
        *(arr + n) = *min;
        *min = tmp;
        printf("%i¹øÂ° : ", n + 1);
        for(int j = 0; j < size; j++) 
        {
            printf("%i", arr[j]);
        }
        printf("\n");
    }
}