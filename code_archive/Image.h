#ifndef IMAGE_H
#define IMAGE_H

class Image
{
public:
    Image(); //无参数的构造函数，创建行列都为零的Image对象
    Image(int h, int w); //构造函数重载，创建h行，w列的Image对象
    Image(int h, int w, unsigned char val); //构造函数重载，创建的图像像素值都为val;
    Image(char* ImageName); //构造函数重载，利用文件名从硬盘加载图像文件成为Image对象;
    Image(unsigned char *m, int rows, int cols);
    Image(unsigned char m[][100], int rows);
    Image(unsigned char **m, int h, int w);
    Image(const Image *im);
    Image(const Image &im);

    ~Image(); //析构函数;

    void Read(char* ImageName);
    void Write(char* filename);
    void Show(char* winname); //显示图像;
    unsigned char& At(int row, int col);
	void Set(int row, int col, unsigned char value); //设置像素(row,col)为某值;
	void SetAll(unsigned char value);
	void Flip(int code);
	void Resize(int code);
	void Cut(int x1,int y1,int x2,int y2);
	void Rotate(int degree);
	void Mean_Variance(float &m, float &var);
	
	int GetHeight() {return height;}
	void SetHeight(int h) {height = h;}
	

	//void Swap(Image &other);
	//static void Swap(Image &a, Image &b);

	Image& operator=(const Image& other);
	bool operator==(const Image& other);

	class iterator
	{
	public:
		unsigned char* p;
		iterator(unsigned char *q) : p(q) {}
		iterator(unsigned char **q, int n) {}

	};

private:
    void Alloc(int h, int w);
	void Release();

private:    
    unsigned char **data;
    int height;
    int width;

};



#endif