#ifndef CIMAGE_H
#define CIMAGE_H

typedef struct CImagetag
{
	unsigned char **data;
    int height;
    int width;
}MyCImage;

void CreatCImage(MyCImage *im);
void CreatCImageHW(MyCImage *im, int h, int w);
void CreatCImageFromFile(MyCImage *im, char* ImageName);
void CreatCImageFromAnother(MyCImage *im, MyCImage *other);

void ShowCImage(MyCImage *im, char* winname);

void ReleaseCImage(MyCImage *im);



#endif