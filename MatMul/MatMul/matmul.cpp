//#pragma warning(disable : 4996)
#include <stdio.h>

int main(void)
{

    /*FILE* a_fp = fopen("a.txt","r");
    FILE* b_fp = fopen("b.txt", "r");
    if (a_fp == NULL && b_fp == NULL)
    {
        printf("파일을 읽을 수 없음");
    }

    int row = 0;
    int col = 0;
    fscanf(a_fp, "%d ", &row);
    fscanf(a_fp, "%d ", &col);



    fclose(a_fp);
    fclose(b_fp);*/

    int a[2][3] = { {1,2,3} ,{4,5,6} };
    int b[3][2] = { {0,1} ,{0,1},{0,1} };

    int ab[2][2];   //ab의 크기는 a(row)xb(col)에 의해 결정
    int a_row = 2;
    int a_col = 3;
    int b_col = 2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < a_row; j++)
        {
            int sum = 0;
            for (int k = 0,mul = 0; k < a_col ; k++)
            {
                mul = a[i][k] * b[k][j];
                sum = sum + mul;
            }
            //ab[i][j] = mul;
            printf("%i ", sum);
        }
        printf("\n");
    }
}
