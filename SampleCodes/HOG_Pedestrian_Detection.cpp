#include "stdafx.h"
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include "opencv2/objdetect.hpp"
#include <opencv2/ml.hpp>

using namespace cv::ml;
using namespace cv;
using namespace std;


int main() {

	// OpenCV's HOG based Pedestrian Detector
	HOGDescriptor hogDefault(
		Size(64, 128), //winSize
		Size(16, 16),  //blocksize
		Size(8, 8),    //blockStride,
		Size(8, 8),    //cellSize,
		9,     //nbins,
		0,     //derivAperture,
		-1,    //winSigma,
		0,     //histogramNormType,
		0.2,   //L2HysThresh,
		1,     //gammal correction,
		64,    //nlevels=64
		0);    //signedGradient

			   // Set the people detector.
	vector< float > svmDetectorDefault = hogDefault.getDefaultPeopleDetector();
	hogDefault.setSVMDetector(svmDetectorDefault);


	float finalHeight = 400.0;

	String imagePath = "race2.jpg";
	Mat im = imread(imagePath, IMREAD_COLOR);

	float finalWidth = (finalHeight * im.cols) / im.rows;
	resize(im, im, Size(finalWidth, finalHeight));

	vector<Rect> bboxes;
	vector<double> weights;

	float hitThreshold = 1.0;
	Size winStride = Size(4, 4);
	Size padding = Size(0, 0);
	float scale = 1.05;
	float finalThreshold = 2;
	bool useMeanshiftGrouping = 0;

	hogDefault.detectMultiScale(im, bboxes, weights, 0, winStride, padding,
		scale, finalThreshold, useMeanshiftGrouping);

	if (!bboxes.empty()) {
		cout << "Default Detector :: pedestrians detected: " << bboxes.size() << endl;
		vector< Rect >::const_iterator loc = bboxes.begin();
		vector< Rect >::const_iterator end = bboxes.end();
		for (; loc != end; ++loc) {
			rectangle(im, *loc, Scalar(0, 255, 0), 2);
		}
	}

	imshow("pedestrians", im);
	//imwrite("result_pedestrian.jpg", im);
	waitKey(0);

	return 0;
}

