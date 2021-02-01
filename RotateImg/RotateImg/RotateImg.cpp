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

    int pixelColor = img.at<uchar>(0, 0);   //uchar : grayscale이라 0-255까지 필요하기 때문
    printf("rows : %dpx\ncols : %dpx\nsize : %dpx\n", img.rows, img.cols,img.rows * img.cols);  //행,열,사이즈
    
    Mat img2 = Mat(row,col,img.type());
    int r = 0;
    int c = 0;
    for (int i = 0; i < row; i++)
    {

        for (int j = 0; j < col; j++)
        {
            c = cos(radian) * j + -sin(radian) * i; //열 
            r = sin(radian) * j + cos(radian) * i;  //행
            img2.at<uchar>(r,c) = img.at<uchar>(i, j);  //error
            //printf("r : %i c : %i\n", r, c);
        }
       
    }

    imshow("img copy", img2);
    waitKey();
    waitKey();

}