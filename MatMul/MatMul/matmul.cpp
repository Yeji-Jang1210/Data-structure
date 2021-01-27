#pragma warning(disable : 4996)
#include <stdio.h>
#include <stdlib.h>

void mat_Mul(int** a, int** b,int a_row, int a_col);

int main(void)
{

    FILE* a_fp = fopen("a.txt","r");    //�б���� open
    FILE* b_fp = fopen("b.txt", "r");

    if (a_fp == NULL && b_fp == NULL)
    {
        printf("������ ���� �� ����");
        fclose(a_fp);
        fclose(b_fp);
        return -1;
    }
    else 
    {

        //��İ��� �������� �˻�
        int a_row, a_col, b_row, b_col;
        fscanf(a_fp, "%d ", &a_row);
        fscanf(a_fp, "%d ", &a_col);
        fscanf(b_fp, "%d ", &b_row);
        fscanf(b_fp, "%d ", &b_col);
        if ((a_col != b_row) && (a_row != b_row))
        {
            printf("��İ��� �Ұ����մϴ�");
            fclose(a_fp);
            fclose(b_fp);
            return -1;
        }
        else
        {
            //a �迭�� ���� ����
            int** a = (int**)malloc(sizeof(int*) * a_row);
            if (a == NULL)
            {
                printf("�޸� �Ҵ� ����");
                fclose(a_fp);
                fclose(b_fp);
                return -1;
            }
            else
            {
                for (int i = 0; i < a_row; i++)     //2���� �迭�� �Ҵ�
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
                //�� ���� ��
            }

            //b �迭�� ���� ����

            int** b = (int**)malloc(sizeof(int*) * b_row);
            if (b == NULL)
            {
                printf("�޸� �Ҵ� ����");
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
            //�� ���� ��

            fclose(a_fp);   //close file
            fclose(b_fp);

            mat_Mul(a, b, a_row, b_row);    //��� �� �Լ� ����

            //�޸� ����
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
