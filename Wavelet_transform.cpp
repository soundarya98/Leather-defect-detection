#include <opencv2\highgui\highgui.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2\core\mat.hpp>
#include <opencv2\imgproc\imgproc.hpp>
#include<iostream>
#include<math.h>
#include<conio.h>
using namespace std;
using namespace cv;

class image
{
public:
    Mat im,im1,im2,im3,im4,im5,im6,temp,im11,im12,im13,im14,imi,imd,imr;
    float a,b,c,d;
    int getim();
};

int image::getim()
{
    im=imread("lena.jpg",0); //Load image in Gray Scale
    imi=Mat::zeros(im.rows,im.cols,CV_8U);
    im.copyTo(imi);

    im.convertTo(im,CV_32F,1.0,0.0);
    im1=Mat::zeros(im.rows/2,im.cols,CV_32F);
    im2=Mat::zeros(im.rows/2,im.cols,CV_32F);
    im3=Mat::zeros(im.rows/2,im.cols/2,CV_32F);
    im4=Mat::zeros(im.rows/2,im.cols/2,CV_32F);
    im5=Mat::zeros(im.rows/2,im.cols/2,CV_32F);
    im6=Mat::zeros(im.rows/2,im.cols/2,CV_32F);

    //--------------Decomposition-------------------

    for(int rcnt=0;rcnt<im.rows;rcnt+=2)
    {
        for(int ccnt=0;ccnt<im.cols;ccnt++)
        {

            a=im.at<float>(rcnt,ccnt);
            b=im.at<float>(rcnt+1,ccnt);
            c=(a+b)*0.707;
            d=(a-b)*0.707;
            int _rcnt=rcnt/2;
            im1.at<float>(_rcnt,ccnt)=c;
            im2.at<float>(_rcnt,ccnt)=d;
        }
    }

    for(int rcnt=0;rcnt<im.rows/2;rcnt++)
    {
        for(int ccnt=0;ccnt<im.cols;ccnt+=2)
        {

            a=im1.at<float>(rcnt,ccnt);
            b=im1.at<float>(rcnt,ccnt+1);
            c=(a+b)*0.707;
            d=(a-b)*0.707;
            int _ccnt=ccnt/2;
            im3.at<float>(rcnt,_ccnt)=c;
            im4.at<float>(rcnt,_ccnt)=d;
        }
    }

    for(int rcnt=0;rcnt<im.rows/2;rcnt++)
    {
        for(int ccnt=0;ccnt<im.cols;ccnt+=2)
        {

            a=im2.at<float>(rcnt,ccnt);
            b=im2.at<float>(rcnt,ccnt+1);
            c=(a+b)*0.707;
            d=(a-b)*0.707;
            int _ccnt=ccnt/2;
            im5.at<float>(rcnt,_ccnt)=c;
            im6.at<float>(rcnt,_ccnt)=d;
        }
    }

    imr=Mat::zeros(256,256,CV_32F);
    imd=Mat::zeros(256,256,CV_32F);
    im3.copyTo(imd(Rect(0,0,128,128)));
    im4.copyTo(imd(Rect(0,127,128,128)));
    im5.copyTo(imd(Rect(127,0,128,128)));
    im6.copyTo(imd(Rect(127,127,128,128)));


    //---------------------------------Reconstruction-------------------------------------

    im11=Mat::zeros(im.rows/2,im.cols,CV_32F);
    im12=Mat::zeros(im.rows/2,im.cols,CV_32F);
    im13=Mat::zeros(im.rows/2,im.cols,CV_32F);
    im14=Mat::zeros(im.rows/2,im.cols,CV_32F);

    for(int rcnt=0;rcnt<im.rows/2;rcnt++)
    {
        for(int ccnt=0;ccnt<im.cols/2;ccnt++)
        {
            int _ccnt=ccnt*2;
            im11.at<float>(rcnt,_ccnt)=im3.at<float>(rcnt,ccnt);     //Upsampling of stage I
            im12.at<float>(rcnt,_ccnt)=im4.at<float>(rcnt,ccnt);
            im13.at<float>(rcnt,_ccnt)=im5.at<float>(rcnt,ccnt);
            im14.at<float>(rcnt,_ccnt)=im6.at<float>(rcnt,ccnt);
        }
    }


    for(int rcnt=0;rcnt<im.rows/2;rcnt++)
    {
        for(int ccnt=0;ccnt<im.cols;ccnt+=2)
        {

            a=im11.at<float>(rcnt,ccnt);
            b=im12.at<float>(rcnt,ccnt);
            c=(a+b)*0.707;
            im11.at<float>(rcnt,ccnt)=c;
            d=(a-b)*0.707;                           //Filtering at Stage I
            im11.at<float>(rcnt,ccnt+1)=d;
            a=im13.at<float>(rcnt,ccnt);
            b=im14.at<float>(rcnt,ccnt);
            c=(a+b)*0.707;
            im13.at<float>(rcnt,ccnt)=c;
            d=(a-b)*0.707;
            im13.at<float>(rcnt,ccnt+1)=d;
        }
    }

    temp=Mat::zeros(im.rows,im.cols,CV_32F);

    for(int rcnt=0;rcnt<im.rows/2;rcnt++)
    {
        for(int ccnt=0;ccnt<im.cols;ccnt++)
        {

            int _rcnt=rcnt*2;
            imr.at<float>(_rcnt,ccnt)=im11.at<float>(rcnt,ccnt);     //Upsampling at stage II
            temp.at<float>(_rcnt,ccnt)=im13.at<float>(rcnt,ccnt); 
        }
    }

    for(int rcnt=0;rcnt<im.rows;rcnt+=2)
    {
        for(int ccnt=0;ccnt<im.cols;ccnt++)
        {

            a=imr.at<float>(rcnt,ccnt);
            b=temp.at<float>(rcnt,ccnt);
            c=(a+b)*0.707;
            imr.at<float>(rcnt,ccnt)=c;                                      //Filtering at Stage II
            d=(a-b)*0.707;
            imr.at<float>(rcnt+1,ccnt)=d;
        }
    }

    imd.convertTo(imd,CV_8U);
    namedWindow("Input Image",1);
    imshow("Input Image",imi);
    namedWindow("Wavelet Decomposition",1);
    imshow("Wavelet Decomposition",imd);
    imr.convertTo(imr,CV_8U);
    namedWindow("Wavelet Reconstruction",1);
    imshow("Wavelet Reconstruction",imr);
    waitKey(0);
    return 0;
}

int main()
{
    image my;
    my.getim();
    return 0;
}