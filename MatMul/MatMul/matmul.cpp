#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdbool.h>
#include <malloc.h>

struct matrix 
{
    int* arr;
    int row;
    int col;
};

matrix* matMul(matrix* a, matrix* b);
matrix* insertArray(FILE* fname);
void printArray(matrix* mat);
void freeMatrix(matrix* mat);

int main(int argc, char* argv[])
{
    
    if (argc > 3) 
    {
        printf("두개의 텍스트파일을 입력하세요");
        return -1;
    }

    FILE* a_fp = fopen(argv[1],"r");    //읽기모드로 open
    FILE* b_fp = fopen(argv[2], "r");

    if (a_fp == NULL && b_fp == NULL)
    {
        printf("파일을 읽을 수 없음");
        fclose(a_fp);
        fclose(b_fp);
        return -1;
    }

    matrix* a = insertArray(a_fp);
    matrix* b = insertArray(b_fp);

    fclose(a_fp);
    fclose(b_fp);

    if (a == NULL && b == NULL) 
    {
        printf("insertArray function error");
    }

    matrix* ab = matMul(a, b);
    if (ab == NULL) 
    {
        printf("matMul function error");
    }
    printArray(a);
    printArray(b);
    printArray(ab);

    freeMatrix(a);
    freeMatrix(b);
    freeMatrix(ab);
}
matrix* matMul(matrix* a,matrix* b)
{
    int row = a->row;
    int col = b->col;
    int size = a->row * b->col;
    
    matrix* matArr = (matrix*)malloc(sizeof(matrix) * size);  //두 행렬의 곱을 담을 이차원 배열 만듬
    if (matArr == NULL)
    {
        printf("메모리 할당 실패");
        return NULL;
    }
    matArr->row = row;
    matArr->col = col;
    if (a->col != b->row)
    {
        printf("행렬곱의 조건에 맞지않는 행렬입니다.");
        free(matArr);
        return NULL;
    }
    else 
    {
        int* arr = (int*)malloc(sizeof(int)*size);
        if (arr == NULL) 
        {
            printf("메모리 할당 실패");
            return NULL;
        }

        int s = 0;
        for (int i = 0, r = 0; i < row; i++, r = r + a->col)
        {
            for (int j = 0; j < col; j++)
            {
                int sum = 0;
                for (int k = 0, mul = 0, l = 0; k < b->row; k++, l = l + col)
                {
                    mul = a->arr[k + r] * b->arr[j + l];
                    sum = sum + mul;
                }
                //배열 값 저장
                *(arr+s) = sum;
                s++;
            }
        }
        matArr->arr = arr;
    }
    return matArr;
}
matrix* insertArray(FILE* fname)
{
    int row = 0;
    int col = 0;
    fscanf(fname, "%d ", &row);
    fscanf(fname, "%d ", &col);
    int size = row * col;

    matrix *mat = (matrix*)malloc(sizeof(matrix));
    if (mat == NULL)
    {
        printf("메모리 할당 실패");
        return NULL;
    }
    else
    {
        int* arr = (int*)malloc(sizeof(int)*size);
        if (arr == NULL)
        {
            printf("메모리 할당 실패");
            return NULL;
        }
        else
        {
            for (int i = 0; i < size; i++)      //값 대입
            {
                fscanf(fname, "%d", &arr[i]);
            }
            mat->arr = arr;
        }
    }
    mat->row = row;
    mat->col = col;
    return mat;
}
void printArray(matrix* mat) 
{
    printf("-----Print Matrix-----\n");
    for (int i = 0,r = 0; i < mat->row; i++,r=r+mat->col) 
    {
        for (int j = 0; j < mat->col; j++) 
        {
            printf("%i ", mat->arr[r+j]);
        }
        printf("\n");
    }
    printf("\n");
}
void freeMatrix(matrix* mat) 
{
    free(mat->arr);
    free(mat);
}