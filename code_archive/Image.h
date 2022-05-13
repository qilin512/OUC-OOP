#ifndef IMAGE_H
#define IMAGE_H

class Image
{
public:
    Image(); //�޲����Ĺ��캯�����������ж�Ϊ���Image����
    Image(int h, int w); //���캯�����أ�����h�У�w�е�Image����
    Image(int h, int w, unsigned char val); //���캯�����أ�������ͼ������ֵ��Ϊval;
    Image(char* ImageName); //���캯�����أ������ļ�����Ӳ�̼���ͼ���ļ���ΪImage����;
    Image(unsigned char *m, int rows, int cols);
    Image(unsigned char m[][100], int rows);
    Image(unsigned char **m, int h, int w);
    Image(const Image *im);
    Image(const Image &im);

    ~Image(); //��������;

    void Read(char* ImageName);
    void Write(char* filename);
    void Show(char* winname); //��ʾͼ��;
    unsigned char& At(int row, int col);
	void Set(int row, int col, unsigned char value); //��������(row,col)Ϊĳֵ;
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