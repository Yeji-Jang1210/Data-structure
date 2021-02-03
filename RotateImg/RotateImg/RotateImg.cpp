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
            c = cos(radian) * (j - baseX) + -sin(radian) * (i - baseY) + baseX; //열 
            r = sin(radian) * (j - baseX) + cos(radian) * (i - baseY) + baseY;  //행
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