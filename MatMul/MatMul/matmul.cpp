#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

void mat_Mul(int** a, int** b,int a_row, int a_col);

int main(void)
{

    FILE* a_fp = fopen("a.txt","r");    //읽기모드로 open
    FILE* b_fp = fopen("b.txt", "r");

    if (a_fp == NULL && b_fp == NULL)
    {
        printf("파일을 읽을 수 없음");
        fclose(a_fp);
        fclose(b_fp);
        return -1;
    }
    else 
    {

        //행렬곱이 가능한지 검사
        int a_row, a_col, b_row, b_col;
        fscanf(a_fp, "%d ", &a_row);
        fscanf(a_fp, "%d ", &a_col);
        fscanf(b_fp, "%d ", &b_row);
        fscanf(b_fp, "%d ", &b_col);
        if ((a_col != b_row) && (a_row != b_row))
        {
            printf("행렬곱이 불가능합니다");
            fclose(a_fp);
            fclose(b_fp);
            return -1;
        }
        else
        {
            //a 배열에 대입 시작
            int** a = (int**)malloc(sizeof(int*) * a_row);
            if (a == NULL)
            {
                printf("메모리 할당 실패");
                fclose(a_fp);
                fclose(b_fp);
                return -1;
            }
            else
            {
                for (int i = 0; i < a_row; i++)     //2차원 배열로 할당
                {
                    a[i] = (int*)malloc(sizeof(int) * a_col);
                }

                for (int i = 0; i < a_row; i++)
                {
                    for (int j = 0; j < a_col; j++)
                    {
                        fscanf(a_fp, "%d", &a[i][j]);
                    }
                }
                //값 대입 끝
            }

            //b 배열에 대입 시작

            int** b = (int**)malloc(sizeof(int*) * b_row);
            if (b == NULL)
            {
                printf("메모리 할당 실패");
                fclose(a_fp);
                fclose(b_fp);
                return -1;
            }
            else
            {
                for (int i = 0; i < b_row; i++)
                {
                    b[i] = (int*)malloc(sizeof(int) * b_col);
                }

                for (int i = 0; i < b_row; i++)
                {
                    for (int j = 0; j < b_col; j++)
                    {
                        fscanf(b_fp, "%d", &b[i][j]);
                    }
                }
            }
            //값 대입 끝

            fclose(a_fp);   //close file
            fclose(b_fp);

            mat_Mul(a, b, a_row, b_row);    //행렬 곱 함수 실행

            //메모리 해제
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
        }
    }
}
void mat_Mul(int** a,int** b,int a_row,int a_col) 
{
    printf("-----Matrix Multiplication-----\n");
    for (int i = 0; i < a_row; i++)
    {
        for (int j = 0; j < a_row; j++)
        {
            int sum = 0;
            for (int k = 0,mul = 0; k < a_col ; k++)
            {
                mul = a[i][k] * b[k][j];
                sum = sum + mul;
            }
            printf("%i ", sum);
        }
        printf("\n");
    }
}
