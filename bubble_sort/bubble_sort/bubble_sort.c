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
			if (array[i] > array[i + 1])	//a�� b���� Ŭ���
			{
				int tmp = 0;
				tmp = array[i];		//a���� tmp��
				array[i] = array[i + 1];	//b���� a��
				array[i + 1] = tmp;	//tmp���� b��
			}
		}
		printf("%i��° : ", n + 1);
		for (int j = 0; j < size; j++)
		{
			printf("%i", array[j]);
		}
		printf("\n");
}
