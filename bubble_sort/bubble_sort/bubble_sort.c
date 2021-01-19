#include <stdio.h>
#include <stdbool.h>	//bool type
#include <time.h>	//�ð��Լ� �߰�
void bubble_sort(int array[], int size);

int main(void)
{
	clock_t start = clock();	//����
	int arr[] = {1,2,3,4,5,6 };
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
	printf("\n");
	clock_t end = clock();	//����
	printf("Time: %lf\n", (double)(end - start) / CLOCKS_PER_SEC);	//�ɸ��� �ð�

}

void bubble_sort(int array[], int size) 
{	
	for (int n = 0; n < size ; n++)
	{	
		int s_size = size;	//�񱳰� ���������� �������� ���� �ʿ䰡 x ���� �پ��
		bool swap = false;
		for (int i = 0; i < s_size - 1 ; i++)
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
		s_size--;
	}
}
