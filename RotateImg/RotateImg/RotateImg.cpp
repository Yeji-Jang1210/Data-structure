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

    int pixelColor = img.at<uchar>(0, 0);   //uchar : grayscale�̶� 0-255���� �ʿ��ϱ� ����
    printf("rows : %dpx\ncols : %dpx\nsize : %dpx\n", img.rows, img.cols,img.rows * img.cols);  //��,��,������
    
    Mat img2 = Mat(row,col,img.type());
    int r = 0;
    int c = 0;
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            c = cos(radian) * j + -sin(radian) * i; //�� 
            r = sin(radian) * j + cos(radian) * i;  //��
            img2.at<uchar>(r,c) = img.at<uchar>(i, j);  //error
            //printf("r : %i c : %i\n", r, c);
        }
       
    }

    imshow("img copy", img2);
    waitKey();
    waitKey();

}