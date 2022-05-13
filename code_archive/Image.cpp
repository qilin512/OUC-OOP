#include "Image.h"
#include "highgui.h"

Image::Image() : height(0), width(0), data(NULL)
{
}

void Image::Alloc(int h, int w)
{
    data = new unsigned char* [h];
    for (int i = 0; i < h; i++)
    {
        data[i] = new unsigned char [w];
    }
}

void Image::Release()
{
	for (int i = 0; i < height; i++)
	{
		delete [] data[i];
	}
	delete [] data;
}

Image::Image(int h, int w) : height(h), width(w)
{
    Alloc(h, w);
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = 0;
        }
    }
}

Image::Image(int h, int w, unsigned char val) : height(h), width(w)
{
    Alloc(h, w);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = val;
        }
    }
}

Image::Image(char* ImageName)
{
    IplImage* img = cvLoadImage(ImageName, CV_LOAD_IMAGE_GRAYSCALE);
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int widthstep = img->widthStep;
    
    //将一维指针img_data指向的内存中的值写入成员变量二维指针data所指的内存中
    //write your code here
    height = img->height;
    width = img->width;

    Alloc(height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = img_data[i*widthstep + j];
        }
    }

    cvReleaseImage(&img);
}

Image::Image(unsigned char *m, int rows, int cols)
{
    height = rows;
    width = cols;

    Alloc(height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = m[i*cols + j];
        }
    }
}

Image::Image(unsigned char m[][100], int rows)
{
    height = rows;
    width = 100;

    Alloc(height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = m[i][j];
        }
    }
}

Image::Image(unsigned char **m, int h, int w)
{
    height = h;
    width = w;
    
    Alloc(height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = m[i][j];
        }
    }
}

Image::Image(const Image *im)
{
    height = im->height;
    width = im->width;

    Alloc(height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = im->data[i][j];
        }
    }
}


Image::Image(const Image &im)
{
    height = im.height;
    width = im.width;

    Alloc(height, width);

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = im.data[i][j];
        }
    }
}

Image::~Image()
{
	Release();
}

void Image::Read(char* ImageName)
{
    IplImage* img = cvLoadImage(ImageName, CV_LOAD_IMAGE_GRAYSCALE);
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int widthstep = img->widthStep;
    
    //将一维指针img_data指向的内存中的值写入成员变量二维指针data所指的内存中
    //write your code here
    if (height != img->height || width != img->width)
    {
		Release();
		height = img->height;
		width = img->width;
		Alloc(height, width);
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = img_data[i*widthstep + j];
        }
    }

    cvReleaseImage(&img);
}

void Image::Write(char* filename)
{
    IplImage* img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
	unsigned char *img_data = (unsigned char *)(img->imageData);
	int widthstep = img->widthStep;

    //将成员变量二维指针data所指内存中的值写入一维指针img_data所指的内存
    //write your code here
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img_data[i*widthstep + j] = data[i][j];
        }
    }

	cvSaveImage(filename, img);
	cvReleaseImage(&img);

}

void Image::Show(char* winname)
{
    IplImage *img = cvCreateImage(cvSize(width, height), IPL_DEPTH_8U, 1);
    unsigned char *img_data = (unsigned char *)(img->imageData);
    int widthstep = img->widthStep;
    
    //将data所指内存中的值写入img_data所指的内存
    //write your code here
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            img_data[i*widthstep + j] = this->data[i][j];
        }
    }


    cvNamedWindow(winname, CV_WINDOW_AUTOSIZE);//创建窗口
    cvShowImage(winname, img);
    cvWaitKey(0);
    cvReleaseImage(&img); //释放图像;

}

unsigned char& Image::At(int row, int col)
{
    return data[row][col];
}

void Image::Set(int row, int col, unsigned char value)
{
	assert(row >= 0 && row < height && col >=0 && col < width);
	data[row][col] = value;
}

void Image::SetAll(unsigned char value)
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = value;
        }
    }
}

void Image::Flip(int code)
{
	if (code == 0)
	{
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width/2; j++)
			{
				unsigned char t = data[i][j];
				data[i][j] = data[i][width-j-1];
				data[i][width-j-1] = t;
			}
		}
	}
	else if (code == 1)
	{
		for (int i = 0; i < height/2; i++)
		{
			unsigned char *t = data[i];
			data[i] = data[height-i-1];
			data[height-i-1] = t;
		}
	}
}

void Image::Resize(int code)
{
	if (code == 0)
	{
		height /= 2;
		width /= 2;
		unsigned char **d = data;
		Alloc(height, width);
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				data[i][j] = d[i*2][j*2];
				
			}
		}
		for (i = 0; i < height*2; i++)
		{
			delete [] d[i];
		}
		delete [] d;
	}
	else if (code == 1)
	{
		height *= 2;
		width *= 2;
		unsigned char **d = data;
		Alloc(height, width);
		for (int i = 0; i < height; i++)
		{
			for (int j = 0; j < width; j++)
			{
				data[i][j] = d[i/2][j/2];
				
			}
		}
		for (i = 0; i < height/2; i++)
		{
			delete [] d[i];
		}
		delete [] d;
	}
}

void Image::Cut(int x1,int y1,int x2,int y2)
{
	int h = height;
	height = y2 - y1;
	width = x2 - x1;
	unsigned char **d = data;
	Alloc(height, width);
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			data[i][j] = d[i+y1][j+x1];
			
		}
	}
	for (i = 0; i < h; i++)
	{
		delete [] d[i];
	}
	delete [] d;
}

void Image::Rotate(int degree)
{
	if (degree % 90 != 0)
		return;

	int t = height;
	height = width;
	width = t;
	unsigned char **d = data;

	if (height != width)
	{
		Alloc(height, width);
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			data[i][j] = d[width-j-1][i];
			
		}
	}
	for (i = 0; i < width; i++)
	{
		delete [] d[i];
	}
	delete [] d;
}

void Image::Mean_Variance(float &m, float &var)
{
	float sum = 0;
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			sum += data[i][j];
			
		}
	}
	m = sum / (height * width);
	
	var = 0;
	for (i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			var += (data[i][j] - m) * (data[i][j] - m);			
		}
	}
	var /= height * width;
}

/*
void Swap(Image &a, Image &b)
{
	int t = a.height;
	a.height = b.height;
	b.height = t;

	t = a.width;
	a.width = b.width;
	b.width = t;

	unsigned char **d = a.data;
	a.data = b.data;
	b.data = d;
}
*/

/*
void Image::Swap(Image &other)
{
	int t = other.height;
	other.height = height;
	this->height = t;

	t = other.width;
	other.width = width;
	width = t;

	unsigned char **d = other.data;
	other.data = data;
	data = d;
}



void Image::Swap(Image &a, Image &b)
{
	int t = a.height;
	a.height = b.height;
	b.height = t;

	t = a.width;
	a.width = b.width;
	b.width = t;

	unsigned char **d = a.data;
	a.data = b.data;
	b.data = d;
}
*/

Image& Image::operator=(const Image& other)
{
	if (this == &other)
		return *this;  //  检查自赋值

    if (height != other.height || width != other.width)
    {
		Release();
		height = other.height;
		width = other.width;
		Alloc(height, width);
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            data[i][j] = other.data[i][j];
        }
    }

	return *this;
}

bool Image::operator==(const Image& other)
{
	if (height != other.height || width != other.width)
		return false;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (data[i][j] != other.data[i][j])
				return false;
        }
    }

	return true;
}