#define _USE_MATH_DEFINES   //PI�� ���
#include <stdio.h>
#include <stdlib.h>
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <math.h>
#include <iostream>

using namespace cv;
int estimateValue(Mat img, double row, double col);
void rotationImg(Mat img,int degree);

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        printf("�߸��� �Է��Դϴ�");
        return 1;
    }
    char* imname = argv[1];
    int degree = atoi(argv[2]);
    String imgPath = samples::findFile(imname);  //�̹��� ��� ����
    Mat img = imread(imgPath, IMREAD_GRAYSCALE);        //imread(�����̸��� �ּ�,��������)
    if (img.empty()) 
    {
        printf("������ ���� �� ����");
        return 1;
    }

    rotationImg(img, degree);
}

void rotationImg(Mat img, int degree) 
{
    int row = img.rows;
    int col = img.cols;
    double radian = degree * M_PI / 180;
    double r = 0;  //double
    double c = 0;  //double
    int baseX = col / 2;
    int baseY = row / 2;
    Mat img3 = Mat(row, col, img.type());

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c = cos(radian) * (j - baseX) + -sin(radian) * (i - baseY) + baseX; //�� 
            r = sin(radian) * (j - baseX) + cos(radian) * (i - baseY) + baseY;  //��
            if ((c >= 0 && c < col) && (r >= 0 && r < row))
            {

                img3.at<uchar>(i, j) = estimateValue(img, r, c);
            }
            else
            {
                img3.at<uchar>(i, j) = 0;
            }
        }
    }

    printf("---img---\nrows : %dpx\ncols : %dpx\nsize : %dpx\n", img.rows, img.cols, img.rows * img.cols);  //��,��,������
    imshow("before rotation", img);//imshow(���÷��� �̸�,mat������ �̹��� ǥ��)
    printf("---rotation img---\nrows : %dpx\ncols : %dpx\nsize : %dpx\n", img3.rows, img3.cols, img3.rows * img3.cols);
    imshow("rotation img", img3);      
    waitKey();
}
int estimateValue(Mat img, double row, double col)
{
    int r = (int)row;
    int maxR, maxC;
    int c = (int)col;

    if (r + 1 > img.rows - 1)
    {
        maxR = r;
    }
    else
    {
        maxR = r + 1;
    }

    if (c + 1 > img.cols - 1)
    {
        maxC = c;
    }
    else
    {
        maxC = c + 1;
    }

    double colColor = img.at<uchar>(r, c) * (1.0 - (row - r)) + img.at<uchar>(maxR, c) * (row - r);  //���� �Ÿ��� �ݺ��
    double nextColColor = img.at<uchar>(r, maxC) * (1.0 - (row - r)) + img.at<uchar>(maxR, maxC) * (row - r);
    int estimateColor = colColor * (1.0 - (col - c)) + nextColColor * (col - c);
    return estimateColor;
}