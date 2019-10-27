#include "stdafx.h"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <vector>
#include <opencv2/objdetect/objdetect.hpp>
#include <stdexcept>
#include <fstream>

using namespace cv;
using namespace std;

int main(void) {

	Mat draw2 = imread("p4.jpeg");
	Size imgsize(2874, 3264);//the dst image size,e.g.100x100
	Mat draw;//dst image
	resize(draw2, draw, imgsize);//resize image
	ifstream fid("rectangletest.txt");
	if (!fid.good())
	{
		cout << "cannot find";
		cin.get();
	}


	vector<int>tlx;
	vector<int>tly;
	vector<int>brx;
	vector<int>bry;
	vector<int> height, width;
	vector<Rect> rectarray;

	float size;
	fid >> size;
	float vals;

	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fid >> vals;
			if (j == 0)
			{
				tlx.push_back(vals);
			}
			if (j == 1)
			{
				tly.push_back(vals);
			}
			if (j == 2)
			{
				brx.push_back(vals);
			}
			if(j==3)
			{
				bry.push_back(vals);
			}
		}

		width.push_back(abs(brx[i] - tlx[i]));
		height.push_back(abs(bry[i] - tly[i]));
		rectarray.push_back(Rect(tlx[i], tly[i], width[i], height[i]));
	}
	/*for (int i = 0; i < size; i++)
	{
		rectangle(draw, rectarray[i], Scalar(0, 200, 0), 8);
	}*/
	int thresh = 0;
	for (int i = 0; i < size-1; i++)
	{
		for (int j = i+1; j>i && j<size; j++)
		{
			Rect rector = rectarray[i] | rectarray[j];
			Rect rectand = rectarray[i] & rectarray[j];
			float perc =(float(rectand.area())/float(rector.area()));

			if (perc > thresh)
			{
				rectarray[i] = rector;
				for (int k = j+1; k < size; k++)
				{
					rectarray[k - 1] = rectarray[k];

				}
				size--;

			}
		}
	}

	/*for (int i = 0; i < size; i++)
		{
			rectarray.push_back(Rect(rectarray[i]));
		}
		groupRectangles(rectarray, 1, 0.5);*/

	float rectarea=0;
	for (int i = 0; i < size-1; i++)
	{
		rectangle(draw, rectarray[i], Scalar(200, 200, 0), 10);
		rectarea = rectarray[i].area() + rectarea;
	}

	float wholearea = draw.size[0] * draw.size[1];
	cout << "The percentage is " << (rectarea / wholearea) * 100 << "%";
	cin.get();

	namedWindow("rectangles", WINDOW_NORMAL);
	imshow("rectangles", draw);

	waitKey(0);
	return 0;
}