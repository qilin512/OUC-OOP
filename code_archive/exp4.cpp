#include "highgui.h"
 
void ReadImageData(unsigned char **dst, unsigned char *src, int rows, int cols, int width_step)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			dst[i][j] = src[width_step * i + j];
		}
	}
}

void WriteImageData(unsigned char *dst, unsigned char **src, int rows, int cols, int width_step)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			dst[width_step * i + j] = src[i][j];
		}
	}
}

void FlipImageUpDown(unsigned char **d, int rows, int cols)
{
	for (int i = 0; i < rows / 2; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			unsigned char t = d[i][j];
			d[i][j] = d[rows - i - 1][j];
			d[rows - i - 1][j] = t;
		}
	}
}

void FlipImageLeftRight(unsigned char **d, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols / 2; j++)
		{
			unsigned char t = d[i][j];
			d[i][j] = d[i][cols - j - 1];
			d[i][cols - j - 1] = t;
		}
	}
}


int main(int argc, char* argv[])
{
	IplImage* img = cvLoadImage("Fruits.jpg", CV_LOAD_IMAGE_GRAYSCALE);
    cvNamedWindow("Image", CV_WINDOW_AUTOSIZE);//Create the window.
    cvShowImage("Image", img);//Display the image.
    cvWaitKey(0); //Wait for keys.
    
    unsigned char *img_data = (unsigned char *)(img->imageData); //Read the image.
    int height = img->height;    //Get the height(row) of the image.
	int width = img->width;      //Get the width(column) of the image.
    int width_step = img->widthStep;    //Get the bytes which are occupied by each line of the image.

// Check if width_step is equal to image width * the number of bytes per element.
// Write your code here
// Change to the image file "Fruits_480x511.jpg". The number of columns of the image is less one column than the previous image, and then check if the above result still stands.

// Dynamically allocate the 2D array "a". The size is height*width and the data type is "unsigned char".
// Write your code here
	int i;
	unsigned char **a = new unsigned char* [height];
	for (i = 0; i < height; i++)
	{
		a[i] = new unsigned char [width];
	}

// Implement the function "ReadImageData" and read image data to 2D array "a".
    // Such as calling ReadImageData£¨a, img_data, height, width, width_step£©£»
// write your code here
	ReadImageData(a, img_data, height,  width, width_step);

// Turn the image upside down.
// Write your code here
// Call FlipImageUpDown
	FlipImageUpDown(a, height, width);
// Write your code here
// Call the function "WriteImageData", which writes the data of 2D array "a" back to the memory area of the source image (the memory area referred to by the pointer "img_data").
// Write your code here
	WriteImageData(img_data, a, height, width, width_step);
	cvShowImage("Image", img);
    cvWaitKey(0); //Wait for keys.
// Turn the image left right flipped.
// Call FlipImageLeftRight
	FlipImageLeftRight(a, height, width);
// Write your code here
// Call WriteImageData to write the results from "a" back to "img_data".
	WriteImageData(img_data, a, height, width, width_step);
    cvShowImage("Image", img);
    cvWaitKey(0); //Wait for keys.
/// Dynamically allocate a 2D array b which is used to store the resized image.
    // Write your code here
/// Reduce the size of the original image to half of the original size, and the result is stored in b. Write a function to do this.
    // Write your code here
	unsigned char **b = new unsigned char* [height/2];
	for (i = 0; i < height/2; i++)
	{
		b[i] = new unsigned char [width/2];
	}

	for (i = 0; i < height / 2; i++)
	{
		for (int j = 0; j < width / 2; j++)
		{
			b[i][j] = a[2*i][2*j];
		}
	}

    
    IplImage *img2 = cvCreateImage(cvSize(width/2, height/2), IPL_DEPTH_8U, 1);
    WriteImageData((unsigned char*)(img2->imageData), b, img2->height, img2->width, img2->widthStep);
    cvShowImage("Image", img2);
    cvWaitKey(0); //Wait for keys.

    cvDestroyWindow("Image");//Destroy the window.
    cvReleaseImage(&img); //Release the image.
	cvReleaseImage(&img2); //Release the image.

// Release the space of the two-dimensional arrays a and b.
// Write your code here
	for (i = 0; i < height; i++)
	{
		delete [] a[i];
	}
	delete [] a;

	for (i = 0; i < height / 2; i++)
	{
		delete [] b[i];
	}
	delete [] b;

    return 0;
}
