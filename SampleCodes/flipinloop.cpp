#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <iostream>
#include <vector>
#include <sstream>

using namespace cv;
using namespace std;
int main()
{

	String folderpath = "MasterDataset//MasterDatasetOrigJPG//batch_7//*.jpg";
	vector <String> filenames;
	vector<int> filenamesCount;
	cv::glob(folderpath, filenames);

	filenamesCount.push_back(1);

	for (size_t i = 0; i < 12; i++)
	{
		filenamesCount.push_back(1);
		Mat src, dst;//dst image
		src = imread(filenames[i]);
		if (src.empty())
		{
			cout << "not found";
		}
		flip(src, dst, 1);
		std::ostringstream name;
		name << "jpgflip//img_flip_batch_7_" << i+1 << ".jpg";
		cv::imwrite(name.str(), dst);
	}
}