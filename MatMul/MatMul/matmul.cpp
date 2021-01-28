#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

int** matMul(int** a, int** b,int a_row, int a_col, int b_row, int b_col);
int** insertArray(FILE* fname, int *row, int *col);
void printArray(int** array);

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

    if (a_fp == NULL && b_fp == NULL)
    {
        printf("������ ���� �� ����");
        fclose(a_fp);
        fclose(b_fp);
        return -1;
    }

    int** a = insertArray(a_fp, &a_row, &a_col);
    int** b = insertArray(b_fp, &b_row, &b_col);

    if (a == NULL && b == NULL) 
    {
        printf("insertArray function error");
    }

    fclose(a_fp);   //close file
    fclose(b_fp);

    int** ab = matMul(a, b, a_row, a_col, b_row, b_col);
    if (ab == NULL) 
    {
        printf("matMul function error");
    }
    printArray(a);
    printArray(b);
    printArray(ab);

    for (int i = 0; i < a_row; i++)
    {
        free(a[i]);
    }
    free(a);    
    for (int i = 0; i < b_row; i++)
    {
        free(b[i]);
    }
    free(b);    
    for (int i = 0; i < a_row; i++)
    {
        free(ab[i]);
    }
    free(ab);   
}
int** matMul(int** a,int** b,int a_row,int a_col, int b_row, int b_col)
{
    int** matArr = (int**)malloc(sizeof(int*) * a_row);  //�� ����� ���� ���� ������ �迭 ����
    if (matArr == NULL)
    {
        printf("�޸� �Ҵ� ����");
        return NULL;
    }

    for (int i = 0; i < b_col; i++) 
    {
        matArr[i] = (int*)malloc(sizeof(int) * b_col);
        if (matArr[i] == NULL) 
        {
            return NULL;
        }
    }

    if (a_col != b_row)
    {
        printf("��İ��� ���ǿ� �����ʴ� ����Դϴ�.");
        return NULL;
    }
    else 
    {
        for (int i = 0; i < a_row; i++)
        {
            for (int j = 0; j < b_col; j++)
            {
                int sum = 0;
                for (int k = 0, mul = 0; k < a_col; k++)
                {
                    mul = a[i][k] * b[k][j];
                    sum = sum + mul;
                }
                //�迭 �� ����
                matArr[i][j] = sum;
            }
        }
    }
    return matArr;
}
int** insertArray(FILE* fname,int *row,int* col)
{
    fscanf(fname, "%d ", row);
    fscanf(fname, "%d ", col);

    int **array = (int**)malloc(sizeof(int*) * (*row));
    if (array == NULL)
    {
        printf("�޸� �Ҵ� ����");
        return NULL;
    }
    else
    {
        for (int i = 0; i < *row; i++)     //2���� �迭�� �Ҵ�
        {
            array[i] = (int*)malloc(sizeof(int) * (*col));
            if (array[i] == NULL)
            {
                return NULL;
            }
        }
        for (int i = 0; i < *row; i++)      //�� ����
        {
            for (int j = 0; j < *col; j++)
            {
                fscanf(fname, "%d", &array[i][j]);
            }
        }
    }
    return array;
}
void printArray(int** array) 
{
    int row = _msize(array)/sizeof(int*);
    int col = _msize(array[0])/sizeof(int);
    printf("-----Print Matrix-----\n");
    for (int i = 0; i < row; i++) 
    {
        for (int j = 0; j < col; j++) 
        {
            printf("%i ", array[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}