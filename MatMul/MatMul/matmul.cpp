#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool matMul(int** a, int** b,int a_row, int a_col, int b_row, int b_col);
int** insertArray(FILE* fname, int *row, int *col);

int main(void)
{

    FILE* a_fp = fopen("a.txt","r");    //읽기모드로 open
    FILE* b_fp = fopen("b.txt", "r");
    int a_row = 0;
    int a_col = 0;
    int b_row = 0;
    int b_col = 0;

    if (a_fp == NULL && b_fp == NULL)
    {
        printf("파일을 읽을 수 없음");
        fclose(a_fp);
        fclose(b_fp);
        return -1;
    }

    int** a = insertArray(a_fp, &a_row, &a_col);
    int** b = insertArray(b_fp, &b_row, &b_col);

    if (a == NULL && b == NULL) 
    {
        printf("is error");
    }

    fclose(a_fp);   //close file
    fclose(b_fp);

    if (matMul(a, b, a_row, a_col, b_row, b_col) == false)
    {
        printf("is error");
    }
    for (int i = 0; i < a_row; i++)
    {
        free(a[i]);
    }
    free(a);    //error
    for (int i = 0; i < b_row; i++)
    {
        free(b[i]);
    }
    free(b);    //error
}
bool matMul(int** a,int** b,int a_row,int a_col, int b_row, int b_col)
{
    if (a_col != b_row)
    {
        printf("행렬곱의 조건에 맞지않는 행렬입니다.");
        return false;
    }
    else 
    {
        printf("-----Matrix Multiplication-----\n");
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
                printf("%i ", sum);
            }
            printf("\n");
        }
    }
    return true;
}
int** insertArray(FILE* fname,int *row,int* col)
{

    int **array = (int**)malloc(sizeof(int*) * (*row));
    if (array == NULL)
    {
        printf("메모리 할당 실패");
        return NULL;
    }
    else
    {
        fscanf(fname, "%d ", row);
        fscanf(fname, "%d ", col);
        for (int i = 0; i < *row; i++)     //2차원 배열로 할당
        {
            array[i] = (int*)malloc(sizeof(int) * (*col));
        }

        for (int i = 0; i < *row; i++)      //값 대입
        {
            for (int j = 0; j < *col; j++)
            {
                fscanf(fname, "%d", &array[i][j]);
            }
        }
    }
    return array;
}
