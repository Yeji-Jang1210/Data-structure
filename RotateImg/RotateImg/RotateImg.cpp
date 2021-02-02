#define _USE_MATH_DEFINES
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>
#include <iostream>

using namespace cv;

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        printf("�߸��� �Է��Դϴ�");
        return 1;
    }
    char* imname = argv[1];
    int degree = atoi(argv[2]);
    double radian = degree * M_PI/180;
    int row = 0;
    int col = 0;
    String imgPath = samples::findFile(imname);  //�̹��� ��� ����
    Mat img = imread(imgPath, IMREAD_GRAYSCALE);        //imread(�����̸��� �ּ�,��������)
    if (img.empty()) 
    {
        printf("������ ���� �� ����");
        return 1;
    }
    imshow("img",img);      //imshow(���÷��� �̸�,mat������ �̹��� ǥ��)
   
    row = img.rows;
    col = img.cols;

    printf("---img---\nrows : %dpx\ncols : %dpx\nsize : %dpx\n", img.rows, img.cols,img.rows * img.cols);  //��,��,������
    Mat img3 = Mat(row,col,img.type());
    int r = 0;
    int c = 0;
    int baseX = col / 2;
    int baseY = row / 2;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c = cos(radian) * (j - baseX) + -sin(radian) * (i - baseY) + baseY; //�� 
            r = sin(radian) * (j - baseX) + cos(radian) * (i - baseY) + baseY;  //��
            if ((c >= 0 && c < col) && (r >= 0 && r < row))
            {

                img3.at<uchar>(i, j) = img.at<uchar>(r, c);
            }
            else
            {
                img3.at<uchar>(i, j) = 0;
            }
        }
    }
    printf("---img3---\nrows : %dpx\ncols : %dpx\nsize : %dpx\n", img3.rows, img3.cols, img3.rows * img3.cols);  //��,��,������
    imshow("rotate img", img3);
    waitKey();
}
