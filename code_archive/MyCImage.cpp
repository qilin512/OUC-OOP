#include <stdlib.h>
#include "CImage.h"
#include "highgui.h"


void CreatCImage(MyCImage *im)
{
	im->height = 0;
	im->width = 0;
	im->data = NULL;
}

void CreatCImageHW(MyCImage *im, int h, int w)
{
	int i;
	im->height = h;
	im->width = w;
	im->data = (unsigned char**)malloc(h * sizeof(unsigned char*));
    for (i = 0; i < h; i++)
    {
        im->data[i] = (unsigned char*)malloc(w * sizeof(unsigned char));
    }
}

void CreatCImageFromFile(MyCImage *im, char* ImageName)
{
	int i, j;

	IplImage* img = cvLoadImage(ImageName, CV_LOAD_IMAGE_GRAYSCALE);
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int widthstep = img->widthStep;
    
    //将一维指针img_data指向的内存中的值写入成员变量二维指针data所指的内存中
    //write your code here
    im->height = img->height;
    im->width = img->width;

    im->data = (unsigned char**)malloc(im->height * sizeof(unsigned char*));
    for (i = 0; i < im->height; i++)
    {
        im->data[i] = (unsigned char*)malloc(im->width * sizeof(unsigned char));
    }

    for (i = 0; i < im->height; i++)
    {
        for (j = 0; j < im->width; j++)
        {
            im->data[i][j] = img_data[i*widthstep + j];
        }
    }

    cvReleaseImage(&img);	
}

void CreatCImageFromAnother(MyCImage *im, MyCImage *other)
{

}

void ShowCImage(MyCImage *im, char* winname)
{
	int i, j;
	IplImage *img = cvCreateImage(cvSize(im->width, im->height), IPL_DEPTH_8U, 1);
    unsigned char *img_data = (unsigned char *)(img->imageData);
    int widthstep = img->widthStep;
    
    //将data所指内存中的值写入img_data所指的内存
    //write your code here
    for (i = 0; i < im->height; i++)
    {
        for (j = 0; j < im->width; j++)
        {
            img_data[i*widthstep + j] = im->data[i][j];
        }
    }


    cvNamedWindow(winname, CV_WINDOW_AUTOSIZE);//创建窗口
    cvShowImage(winname, img);
    cvWaitKey(0);
    cvReleaseImage(&img); //释放图像;
}

void ReleaseCImage(MyCImage *im)
{
	int i;
	for (i = 0; i < im->height; i++)
	{
		free(im->data[i]);
	}
	free(im->data);
}

