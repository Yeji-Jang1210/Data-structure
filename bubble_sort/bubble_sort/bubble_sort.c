#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int array[], int size);

int main(void)
{
	int arr[] = { 1,2,3,4,5,6 };
	printf("before : ");
	for (int i = 0; i < 6; i++)
	{
		printf("%i", arr[i]);
	}
	printf("\n");
	bubble_sort(arr, 6);
	printf("\nbubble sort:");
	for (int i = 0; i < 6; i++) 
	{
		printf("%i", arr[i]);
	}

}

void bubble_sort(int array[], int size) 
{	
	for (int n = 0; n < size ; n++)
	{	
		int swap = 0;
		for (int i = 0; i + 1 < size; i++)
		{	
			if (array[i] > array[i + 1])	//a>b
			{
				int tmp = 0;
				tmp = array[i];		//a = tmp
				array[i] = array[i + 1];	//b = a
				array[i + 1] = tmp;	//tmp = b
				swap++;
			}
		}
		if (swap == 0) // 교환이 잃어나지 않았을 경우
		{
			break;	//for문 빠져나옴
		}
		printf("%i번째 : ", n + 1);
		for (int j = 0; j < size; j++)
		{
			printf("%i", array[j]);
		}
		printf("\n");
	}
}
