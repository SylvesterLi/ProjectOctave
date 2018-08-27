#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
#include "opencv2/core.hpp"
#include "opencv2/features2d.hpp"
#include "opencv2/xfeatures2d.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;
using namespace cv::xfeatures2d;
using namespace std;

//��ǰimg_1Ϊԭͼ��
//srcδʹ�ã�dstΪĿ��ͼ��graySrcΪ�Ҷ�ͼ��normDstΪ��һ��ͼ��
Mat src, dst, img_1,graySrc,normDst;

//��������
int harrisThresh = 127;
int threshMax = 255;



//��������
void HarrisTrack(int, void *);



int main(int argc, char** argv) {
	img_1 = imread("C:/Users/SANG-ASUS/Desktop/ppp.png");
	if (img_1.empty()) {
		printf("could not load image...\n");
		return -1;
	}
	imshow("input image", img_1);

	
	//Harris�ǵ��� �ο�
	//https://blog.csdn.net/woxincd/article/details/60754658 

	//������д��
	//cvCornerHarris(src, dst, 3);

	cvtColor(img_1, graySrc, CV_BGR2GRAY);
	imshow("gray", graySrc);

	//cornerHarris(src, dst, 3, 3, 1.0);
	
	namedWindow("harris", WINDOW_AUTOSIZE);
	createTrackbar("harrisTitle", "harris", &harrisThresh, threshMax, HarrisTrack);
	HarrisTrack(0,0);


	waitKey(0);
	return 0;
}

void HarrisTrack(int, void *)
{
	dst = Mat::zeros(graySrc.size(), CV_32FC1);
	//����
	cornerHarris(graySrc, dst, 2, 3, 0.04);
	normalize(dst, normDst, 0,255, NORM_MINMAX);	
	//����dstΪScaleAbs�Ľ��
	convertScaleAbs(normDst, dst);

	Mat resultImg = img_1.clone();
	for (int row = 0; row  < resultImg.rows; row ++)
	{
		//��ȡ����ǰRow
		uchar* currentRow = dst.ptr(row);
		for (int col = 0; col < resultImg.cols; col++)
		{
			//������currentRow[0] ������ĵ�һ����
			int value = (int)* currentRow;
			//������ֵ�Ĳŷų���
			if (value > harrisThresh)
			{
				//row col��Ҫ�㷴��
				circle(resultImg, Point(col, row), 2, Scalar(0, 255, 0));
			}
			currentRow++;
		}
	}
	//չʾresultImg�������
	imshow("harris", resultImg);

}