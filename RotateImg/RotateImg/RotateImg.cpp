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
        printf("잘못된 입력입니다");
        return 1;
    }
    char* imname = argv[1];
    int degree = atoi(argv[2]);
    double radian = degree * M_PI/180;
    int row = 0;
    int col = 0;
    String imgPath = samples::findFile(imname);  //이미지 경로 저장
    Mat img = imread(imgPath, IMREAD_GRAYSCALE);        //imread(파일이름의 주소,색상형식)
    if (img.empty()) 
    {
        printf("파일을 읽을 수 없음");
        return 1;
    }
    imshow("img",img);      //imshow(디스플레이 이름,mat형식의 이미지 표시)
   
    row = img.rows;
    col = img.cols;

    printf("---img---\nrows : %dpx\ncols : %dpx\nsize : %dpx\n", img.rows, img.cols,img.rows * img.cols);  //행,열,사이즈
    Mat img3 = Mat(row,col,img.type());
    int r = 0;
    int c = 0;
    int baseX = col / 2;
    int baseY = row / 2;

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            c = cos(radian) * (j - baseX) + -sin(radian) * (i - baseY) + baseY; //열 
            r = sin(radian) * (j - baseX) + cos(radian) * (i - baseY) + baseY;  //행
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
    printf("---img3---\nrows : %dpx\ncols : %dpx\nsize : %dpx\n", img3.rows, img3.cols, img3.rows * img3.cols);  //행,열,사이즈
    imshow("rotate img", img3);
    waitKey();
}
