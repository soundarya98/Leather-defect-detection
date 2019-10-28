// ConsoleApplication4.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>

using namespace cv;
using namespace std;

int main()
{
	
	Size size = Size(64, 64);
	Size block_size = Size(size.width / 4, size.height / 4);
	Size block_stride = Size(size.width / 8, size.height / 8);
	Size cell_size = block_stride;
	int num_bins = 9;
	HOGDescriptor hog(size, block_size, block_stride, cell_size, num_bins);

	String folderpath = "Dataset//*.jpg";
	vector <String> filenames;
	vector<int> filenamesCount;
	cv::glob(folderpath, filenames);

	filenamesCount.push_back(1);
	Mat features;
	vector<int>labels; 
	
	for (size_t i = 1; i<=36; i++)
	{
			Mat drawing = imread(filenames[i]);
		//Mat drawing = imread("img_new_pos1.jpg", 0);
			if (drawing.empty())
			{
				cout << "not found!";
				waitKey();
			}
	
			//waitKey();
			int label;
			
			if (i <= 19)
				label = 1;
			else
				label = -1; 
			//label = 1;
		
			vector<Point> location;
			vector<float> descriptors;
			
		hog.compute(drawing, descriptors, Size(0, 0), Size(0, 0), location);
		Mat descr = Mat(descriptors, true).reshape(1, 1);
		features.push_back(descr);
		labels.push_back(label); 
	}
	
	// now you can train the svm:
	Ptr<ml::SVM> svm = ml::SVM::create();
	svm->setType(ml::SVM::C_SVC);
	svm->setKernel(ml::SVM::LINEAR);
	svm->setGamma(3);
	svm->setTermCriteria(TermCriteria(TermCriteria::MAX_ITER, 100, 1e-6));

	Ptr<ml::TrainData> tData = ml::TrainData::create(features, ml::ROW_SAMPLE, labels);
	svm->train(tData);
	svm->save("testing.yml"); 
	//cout << "yes done";
	//cin.get();

    return 0;
}

