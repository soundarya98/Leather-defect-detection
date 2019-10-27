#include "stdafx.h"
#include "opencv2/objdetect.hpp"
#include "opencv2/videoio.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"

#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

/** Global variables */
String faceCascadePath, smileCascadePath;
CascadeClassifier faceCascade, smileCascade;

int main(int argc, const char** argv)
{
	int smileNeighborsMax = 100;
	int neighborStep = 2;

	faceCascadePath = "C:\\Users\\SOUJANARI\\Downloads\\opencv\\sources\\data\\haarcascades\\haarcascade_frontalface_default.xml";
	smileCascadePath = "C:\\Users\\SOUJANARI\\Downloads\\opencv\\sources\\data\\haarcascades\\haarcascade_smile.xml";

	//-- 1. Load the cascades
	if (!faceCascade.load(faceCascadePath)) 
	{
		printf("--(!)Error loading face cascade\n"); 
		return -1; 
	}
			if (!smileCascade.load(smileCascadePath))
			{
				printf("--(!)Error loading smile cascade\n"); 
				return -1; 
			}

					std::vector<Rect> faces;
					std::vector<Rect> smile;

				// Detect the face using the cascade
				Mat frame = imread("me.jpg");
				Mat frameGray, frameClone;
				frameClone = frame.clone();
				cvtColor(frame, frameGray, COLOR_BGR2GRAY);

				faceCascade.detectMultiScale(frameGray, faces, 1.4, 5);

				// Get the face area from the detected face rectangle
				for (size_t i = 0; i < faces.size(); i++)
				{
					int x = faces[i].x;
					int y = faces[i].y;
					int w = faces[i].width;
					int h = faces[i].height;

					rectangle(frameClone, Point(x, y), Point(x + w, y + h), Scalar(255, 0, 0), 2, 3);

					Mat faceROI = frameGray(faces[i]);
					Mat faceROIClone = faceROI.clone();
					
					// Detect the smile from the detected face area and display the image
					int neigh = 28;
					smileCascade.detectMultiScale(faceROI, smile, 1.4, neigh);
					{
						for (size_t j = 0; j < smile.size(); j++)
						{
							int smileX = smile[j].x;
							int smileY = smile[j].y;
							int smileW = smile[j].width;
							int smileH = smile[j].height;

							rectangle(frameClone, Point(smileX+x, smileY+y),Point(smileX + smileW+x, smileY + smileH+y), Scalar(0, 255, 0), 2, 4);
						}
						putText(frameClone, format("# Neighbors = %d", neigh), Point(10, 50),FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255), 4);
						namedWindow("Face and Smile Demo", WINDOW_NORMAL);
						imshow("Face and Smile Demo", frameClone);
						waitKey();
					}
				}
			}