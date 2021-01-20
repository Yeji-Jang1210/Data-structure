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

void merge_sort(int array[], int start, int end)     //array[n]일때 end = n-1
{
    int mid;
    if (start < end) //시작과 끝이 같지 x
    {
        mid = (start + end) / 2;            //중간값 재계산
        merge_sort(array, start, mid);      //left divide
        merge_sort(array, mid + 1, end);    //right divide
        merge(array, start, mid, end);      //병합 필요
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
        if (array[l] < array[r_mid])    //a<b면 제일 왼쪽 자리에 a대입 후 a++
        {
            sorted_arr[i] = array[l];
            l++;
        }
        else
        {
            sorted_arr[i] = array[r_mid];  //a>b면 제일 왼쪽 자리에 b대입 후 b++ 
            r_mid++;
        }
        i++;
    }
    //남은 숫자 배열에 대입
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

    for (int i = left; i<=right ; i++) //l부터 r까지 원래 배열로 복사
    {
        array[i] = sorted_arr[i];
    }

}
