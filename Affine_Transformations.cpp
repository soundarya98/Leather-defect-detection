#include "stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <iostream>
#include <cmath>
#include <vector>

using namespace cv;
using namespace std;

//In this program, we will use OpenCV warpaffine function to transform 
//a triangle from source image to another triangle as shown in the 
//above figure.

int main(void)
{
	// Read image
	Mat source = imread("mic_HD.jpg", 1);

	// Create 2 warp matrices for different transformations
	Mat warpMat = (Mat_<double>(2, 3) << 1.2, 0.2, 2, -0.3, 1.3, 1);

	// Another mask
	Mat warpMat2 = (Mat_<double>(2, 3) << 1.2, 0.3, 2, 0.2, 1.3, 1);

	Mat result, result2;

	// Use warp affine
	cv::warpAffine(source, result, warpMat,
		Size(1.5*source.rows, 1.4*source.cols), INTER_LINEAR, BORDER_REFLECT_101);
	cv::warpAffine(source, result2, warpMat2,
		Size(1.5*source.rows, 1.4*source.cols), INTER_LINEAR, BORDER_REFLECT_101);

	// Display images
	imshow("Original", source);
	imshow("Result", result);
	imshow("Result2", result2);
	waitKey(0);
	destroyAllWindows();
}