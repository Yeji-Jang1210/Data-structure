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
        printf("두개의 텍스트파일을 입력하세요");
        return -1;
    }

    FILE* a_fp = fopen(argv[1],"r");    //읽기모드로 open
    FILE* b_fp = fopen(argv[2], "r");
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
    int** matArr = (int**)malloc(sizeof(int*) * a_row);  //두 행렬의 곱을 담을 이차원 배열 만듬
    if (matArr == NULL)
    {
        printf("메모리 할당 실패");
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
        printf("행렬곱의 조건에 맞지않는 행렬입니다.");
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
                //배열 값 저장
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
        printf("메모리 할당 실패");
        return NULL;
    }
    else
    {
        for (int i = 0; i < *row; i++)     //2차원 배열로 할당
        {
            array[i] = (int*)malloc(sizeof(int) * (*col));
            if (array[i] == NULL)
            {
                return NULL;
            }
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