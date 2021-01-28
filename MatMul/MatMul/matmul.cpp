#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

int* matMul(int* a, int* b,int a_row, int a_col, int b_row, int b_col, int *ab_row, int *ab_col);
int* insertArray(FILE* fname, int *row, int *col);
void printArray(int* array, int row, int col);

int main(int argc, char* argv[])
{
    
    if (argc > 3) 
    {
        printf("�ΰ��� �ؽ�Ʈ������ �Է��ϼ���");
        return -1;
    }

    FILE* a_fp = fopen(argv[1],"r");    //�б���� open
    FILE* b_fp = fopen(argv[2], "r");
    int a_row = 0;
    int a_col = 0;
    int b_row = 0;
    int b_col = 0;
    int ab_row = 0;
    int ab_col = 0;

    if (a_fp == NULL && b_fp == NULL)
    {
        printf("������ ���� �� ����");
        fclose(a_fp);
        fclose(b_fp);
        return -1;
    }

    int* a = insertArray(a_fp, &a_row, &a_col);
    int* b = insertArray(b_fp, &b_row, &b_col);

    if (a == NULL && b == NULL) 
    {
        printf("insertArray function error");
    }

    fclose(a_fp);   //close file
    fclose(b_fp);


    int* ab = matMul(a, b, a_row, a_col, b_row, b_col,&ab_row,&ab_col);
    if (ab == NULL) 
    {
        printf("matMul function error");
    }
    printArray(a,a_row,a_col);
    printArray(b,b_row,b_col);
    printArray(ab,ab_row,ab_col);


    free(a);    
    free(b);    
    free(ab);   
}
int* matMul(int* a,int* b,int a_row,int a_col, int b_row, int b_col,int *ab_row,int *ab_col)
{
    int size = a_row * b_col;
    *ab_row = a_row;
    *ab_col = b_col;
    
    int* matArr = (int*)malloc(sizeof(int) * size);  //�� ����� ���� ���� ������ �迭 ����
    if (matArr == NULL)
    {
        printf("�޸� �Ҵ� ����");
        return NULL;
    }

    if (a_col != b_row)
    {
        printf("��İ��� ���ǿ� �����ʴ� ����Դϴ�.");
        return NULL;
    }
    else 
    {
        int s = 0;
        for (int i = 0, r = 0; i < a_row; i++, r = r + a_col)
        {
            for (int j = 0; j < b_col; j++)
            {
                int sum = 0;
                for (int k = 0, mul = 0, l = 0; k < b_row; k++, l = l + b_col)
                {
                    mul = a[k + r] * b[j + l];
                    sum = sum + mul;
                }
                //�迭 �� ����
                matArr[s] = sum;
                s++;
            }
        }
    }
    return matArr;
}
int* insertArray(FILE* fname,int *row,int* col)
{
    fscanf(fname, "%d ", row);
    fscanf(fname, "%d ", col);
    int size = *row * *col;
    int *array = (int*)malloc(sizeof(int) * size);
    if (array == NULL)
    {
        printf("�޸� �Ҵ� ����");
        return NULL;
    }
    else
    {
        for (int i = 0; i < size; i++)      //�� ����
        {
                fscanf(fname, "%d", &array[i]);
        }
    }
    return array;
}
void printArray(int* array, int row, int col) 
{
    printf("-----Print Matrix-----\n");
    for (int i = 0,r = 0; i < row; i++,r=r+col) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("%i ", array[r+j]);
        }
        printf("\n");
    }
    printf("\n");
}