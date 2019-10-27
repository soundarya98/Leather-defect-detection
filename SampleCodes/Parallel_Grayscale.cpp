#include "stdafx.h"
#include <opencv2/highgui.hpp>
#include <opencv2/core.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;


void RGB2Gray(const cv::Mat& src, cv::Mat& dst)
{
	CV_Assert(src.type() == CV_8UC3);
	int rows = src.rows, cols = src.cols;

	dst.create(src.size(), CV_8UC1);

	if (src.isContinuous() && dst.isContinuous())
	{
		cols = rows * cols;
		rows = 1;
	}

	for (int row = 0; row < rows; row++)
	{
		const uchar* src_ptr = src.ptr<uchar>(row);
		uchar* dst_ptr = dst.ptr<uchar>(row);

		for (int col = 0; col < cols; col++)
		{
			dst_ptr[col] = (uchar)(src_ptr[0] * 0.114f + src_ptr[1] * 0.587f + src_ptr[2] * 0.299f);
			src_ptr += 3;
		}
	}
}

int main()
{
	Mat SrcImg = cv::imread("mic_HD.jpg");
	Mat DstImg;
	RGB2Gray(SrcImg, DstImg);
	imshow("gray", DstImg);
	waitKey();
	return 0;
}
