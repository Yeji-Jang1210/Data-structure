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
void freeTxtFile(FILE** txt, int size);

int main(int argc, char* argv[])
{

    if (argc < 3)
    {
        printf("��İ��� �ּ� �ΰ��� ������ �־�� �մϴ�.");
        return -1;
    }

    int size = argc - 1;
    FILE** tfile = (FILE**)malloc(sizeof(FILE*) * size);
    if (tfile == NULL)
    {
        printf("is error");
        return -1;
    }
    for (int i = 0; i < size; i++)  //������ ���������� �о� tfile[]�� ����
    {
        tfile[i] = fopen(argv[i + 1], "r");
        if (tfile[i] == NULL)
        {
            printf("������ ���� �� ����");
            freeTxtFile(tfile,size);
            return -1;
        }
    }

    printf("---Before Matrix Multiplication---\n");
    matrix* matArr = insertArray(tfile[0]);
    printArray(matArr);
    for (int i = 1; i < size; i++)
    {
        matrix* arr = insertArray(tfile[i]);
        printArray(arr);
        matArr = matMul(matArr, arr);
        freeMatrix(arr);
    }
    printf("---After Matrix Multiplication---\n");
    printArray(matArr);
    freeMatrix(matArr);
}

matrix* matMul(matrix* a, matrix* b)
{
    int row = a->row;
    int col = b->col;
    int size = a->row * b->col;

    matrix* matArr = (matrix*)malloc(sizeof(matrix) * size);  //�� ����� ���� ���� ������ �迭 ����
    if (matArr == NULL)
    {
        printf("�޸� �Ҵ� ����");
        return NULL;
    }
    matArr->row = row;
    matArr->col = col;
    if (a->col != b->row)
    {
        printf("��İ��� ���ǿ� �����ʴ� ����Դϴ�.");
        free(matArr);
        return NULL;
    }
    else
    {
        int* arr = (int*)malloc(sizeof(int) * size);
        if (arr == NULL)
        {
            printf("�޸� �Ҵ� ����");
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
                //�迭 �� ����
                *(arr + s) = sum;
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

    matrix* mat = (matrix*)malloc(sizeof(matrix));
    if (mat == NULL)
    {
        printf("�޸� �Ҵ� ����");
        return NULL;
    }
    else
    {
        int* arr = (int*)malloc(sizeof(int) * size);
        if (arr == NULL)
        {
            printf("�޸� �Ҵ� ����");
            return NULL;
        }
        else
        {
            for (int i = 0; i < size; i++)      //�� ����
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
    printf("Print Matrix\n");

    for (int i = 0, r = 0; i < mat->row; i++, r = r + mat->col)
    {
        for (int j = 0; j < mat->col; j++)
        {
            printf("%i ", mat->arr[r + j]);
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

void freeTxtFile(FILE** txt, int size)
{
    for (int i = 0; i < size; i++)
    {
        fclose(txt[i]);
        free(txt[i]);
    }
    free(txt);
}