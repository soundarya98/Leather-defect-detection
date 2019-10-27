#include "stdafx.h"
#include<opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <sstream>

using namespace cv;
using namespace std;

int main()
{

	String folderpath = "Fruits_Negative//*.jpg";
	vector <String> filenames;
	vector<int> filenamesCount;
	cv::glob(folderpath, filenames);

	filenamesCount.push_back(1);

	for (size_t i = 0; i<18; i++)
	{
		filenamesCount.push_back(1);
		Size size(100, 100);//the dst image size,e.g.100x100
		Mat dst, img13new;//dst image
		Mat src = imread(filenames[i]);
		//Mat src = imread("Fruits_Positive\\img13.jpg");//src image
		if (src.empty())
		{
			cout << "not found";
		}
		resize(src, dst, size);//resize image
		
		std::ostringstream name;
		name << "Fruits_Positive//img_new_neg" << i << ".jpg";
		cv::imwrite(name.str(), dst);
	}


}



