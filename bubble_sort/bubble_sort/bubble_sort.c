#include <stdio.h>
#include <stdbool.h>
void bubble_sort(int array[], int size);

int main(void)
{
	int arr[] = { 4,3,6,2,1,5 };
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
		bool swap = false;
		for (int i = 0; i + 1 < size; i++)
		{	
			if (array[i] > array[i + 1])	//a>b
			{
				int tmp = 0;
				tmp = array[i];		//a = tmp
				array[i] = array[i + 1];	//b = a
				array[i + 1] = tmp;	//tmp = b
				swap = true;
			}
		}
		if (swap == false) // ��ȯ�� �Ҿ�� �ʾ��� ���
		{
			break;	//for�� ��������
		}
		printf("%i��° : ", n + 1);
		for (int j = 0; j < size; j++)
		{
			printf("%i", array[j]);
		}
		printf("\n");
	}
}
