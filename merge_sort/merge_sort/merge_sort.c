#include <stdio.h>
#define ARRAY_LENGTH 7
int sorted_arr[ARRAY_LENGTH];
void merge_sort(int array[], int start, int end);
void merge(int array[], int left, int mid, int right);

int main(void) 
{
    int arr[] = { 4,1,3,6,9,5,2 };

    printf("before: ");
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("%i ", arr[i]);
    }
    printf("\n");

    printf("Merge_Sort: ");
    printf("\n");
    merge_sort(arr, 0, ARRAY_LENGTH - 1);
}

void merge_sort(int array[], int start, int end)     //array[n]�϶� end = n-1
{
    int mid;
    if (start < end) //���۰� ���� ���� x
    {
        mid = (start + end) / 2;            //�߰��� ����
        merge_sort(array, start, mid);      //left divide
        merge_sort(array, mid + 1, end);    //right divide
        merge(array, start, mid, end);      //���� �ʿ�
    }
    for (int i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("%i ", array[i]);
    }
    printf("\n");

}
void merge(int array[], int left, int mid, int right) 
{   
    int l = left;
    int m = mid;
    int r = right;
    int r_mid = m + 1;
    int i = l;

    while (l <= m && r_mid <= r)
    {
        if (array[l] < array[r_mid])    //a<b�� ���� ���� �ڸ��� a���� �� a++
        {
            sorted_arr[i] = array[l];
            l++;
        }
        else
        {
            sorted_arr[i] = array[r_mid];  //a>b�� ���� ���� �ڸ��� b���� �� b++ 
            r_mid++;
        }
        i++;
    }
    //���� ���� �迭�� ����
    if (l > m)
    {
        while (r_mid <= r)
        {
            sorted_arr[i++] = array[r_mid++];
        }
    }
    else 
    {
        while (l <= m)
        {
            sorted_arr[i++] = array[l++];
        }
    }

    for (int i = left; i<=right ; i++) //l���� r���� ���� �迭�� ����
    {
        array[i] = sorted_arr[i];
    }

}
