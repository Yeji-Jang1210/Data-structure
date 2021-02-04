#define _USE_MATH_DEFINES   //PI를 사용
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
void returnSize(double radian, int x, int y, int* sizeX, int* sizeY, int baseX, int baseY);
int addRotationImgSize(int dot1, int dot2, int dot3, int dot4);

int main(int argc, char* argv[]) 
{
    if (argc != 3) 
    {
        printf("잘못된 입력입니다");
        return 1;
    }
    char* imname = argv[1];
    int degree = atoi(argv[2]);
    String imgPath = samples::findFile(imname);  //이미지 경로 저장
    Mat img = imread(imgPath, IMREAD_GRAYSCALE);        //imread(파일이름의 주소,색상형식)
    if (img.empty()) 
    {
        printf("파일을 읽을 수 없음");
        return 1;
    }
    rotationImg(img, degree);
}

void rotationImg(Mat img, int degree) 
{
    double radian = degree * M_PI / 180;
    int y = img.rows;
    int x = img.cols;
    int baseX = x / 2;
    int baseY = y / 2;
    int sizeX = 0;
    int sizeY = 0;

    returnSize(radian, x,  y, &sizeX, &sizeY, baseX, baseY);
    Mat img3 = Mat(sizeY, sizeX,img.type());

    int reBaseX = sizeX / 2;
    int reBaseY = sizeY / 2;
    double r = 0;  //double
    double c = 0;  //double

    for (int i = 0; i < sizeY; i++)
    {
        for (int j = 0; j < sizeX; j++)
        {
            c = cos(radian) * (j - reBaseX) + -sin(radian) * (i - reBaseY) + baseX; //열 
            r = sin(radian) * (j - reBaseX) + cos(radian) * (i - reBaseY) + baseY;  //행
            if ((c >= 0 && c < x) && (r >= 0 && r < y))
            {
                img3.at<uchar>(i, j) = estimateValue(img, r, c);
            }
            else
            {
                img3.at<uchar>(i, j) = 0;
            }
        }
    }

    printf("---img---\nrows : %dpx\ncols : %dpx\nsize : %dpx\n", img.rows, img.cols, img.rows * img.cols);  //행,열,사이즈
    imshow("before rotation", img);//imshow(디스플레이 이름,mat형식의 이미지 표시)
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

    double colColor = img.at<uchar>(r, c) * (1.0 - (row - r)) + img.at<uchar>(maxR, c) * (row - r);  //색과 거리는 반비례
    double nextColColor = img.at<uchar>(r, maxC) * (1.0 - (row - r)) + img.at<uchar>(maxR, maxC) * (row - r);
    int estimateColor = colColor * (1.0 - (col - c)) + nextColColor * (col - c);
    return estimateColor;
}
int addRotationImgSize(int dot1, int dot2, int dot3, int dot4) 
{
    int dotArr[4] = { dot1, dot2, dot3, dot4 };
    int min = dotArr[0];
    int max = dotArr[0];
    int tmp = 0;
    for (int i = 1; i < 4; i++) 
    {
        if (dotArr[i] > max)
        {
            max = dotArr[i]; 
        }
        if (dotArr[i] < min) 
        {
            min = dotArr[i];
        }
    }
    int size = max-min;
    return size;
}
void returnSize(double radian, int x,int y, int *sizeX, int *sizeY,int baseX,int baseY) 
{

    //0,0
    int c_dot1 = cos(radian) * (0 - baseX) + sin(radian) * (0 - baseY) + baseX;
    int r_dot1 = -sin(radian) * (0 - baseX) + cos(radian) * (0 - baseY) + baseY;

    //0,x-1
    int c_dot2 = cos(radian) * ((x - 1) - baseX) + sin(radian) * (0 - baseY) + baseX;
    int r_dot2 = -sin(radian) * ((x - 1) - baseX) + cos(radian) * (0 - baseY) + baseY;

    //y-1,0
    int c_dot3 = cos(radian) * (0 - baseX) + sin(radian) * ((y - 1) - baseY) + baseX;
    int r_dot3 = -sin(radian) * (0 - baseX) + cos(radian) * ((y - 1) - baseY) + baseY;

    //y-1,x-1
    int c_dot4 = cos(radian) * ((x - 1) - baseX) + sin(radian) * ((y - 1) - baseY) + baseX;
    int r_dot4 = -sin(radian) * ((x - 1) - baseX) + cos(radian) * ((y - 1) - baseY) + baseY;

    *sizeX = addRotationImgSize(c_dot1, c_dot2, c_dot3, c_dot4);
    *sizeY = addRotationImgSize(r_dot1, r_dot2, r_dot3, r_dot4);
}