#include <stdio.h>
#include <stdlib.h>
void bubble_sort(int array[], int size);

int main(void)
{
	int arr[] = { 5,1,3,4,6,2 };
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
		for (int i = 0; i + 1 < size; i++)
		{
			if (array[i] > array[i + 1])	//a가 b보다 클경우
			{
				int tmp = 0;
				tmp = array[i];		//a값을 tmp로
				array[i] = array[i + 1];	//b값을 a로
				array[i + 1] = tmp;	//tmp값을 b로
			}
		}
		printf("%i번째 : ", n + 1);
		for (int j = 0; j < size; j++)
		{
			printf("%i", array[j]);
		}
		printf("\n");
}
