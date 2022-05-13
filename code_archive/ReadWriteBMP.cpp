#include <cstdio>
#include <cstdlib>
#include <iostream>

#pragma pack(push,1)
struct BMPFILEHEADER
{
    unsigned short bfType;
    unsigned int   bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int   bfOffBits;
};
#pragma pack(pop)

struct BITMAPINFOHEADER
{
    unsigned long    biSize;
    long             biWidth;
    long             biHeight;
    unsigned short   biPlanes;
    unsigned short   biBitCount;

    unsigned long    biCompression;

    unsigned long    biSizeImage;
    long             biXPelsPerMeter;
    long             biYPelsPerMeter;
    unsigned long    biClrUsed;
    unsigned long    biClrImportant;
};

void malloc_int(int **p, int n)
{
    *p = (int *)malloc(n * sizeof(int));
}

void use_malloc_int()
{
    int m = 6;
    int *q = nullptr;
    malloc_int(&q, m);

    free(q);
}

unsigned char** ReadBMP(const char* filename, BMPFILEHEADER& fh, BITMAPINFOHEADER& ih)
{
    FILE* fp = NULL;
    fopen_s(&fp, filename, "rb");



    fread(&fh, sizeof(fh), 1, fp);

    fread(&ih, sizeof(ih), 1, fp);

    int h = ih.biHeight;
    int w = ih.biWidth;
    int padding = h * w % 4 == 0 ? 0 : 4 - (h * w % 4);

    unsigned char** d;
    d = new unsigned char* [h];
    for (int i = 0; i < h; i++)
    {
        d[i] = new unsigned char[w];
        for (int j = 0; j < w; j++)
        {
            unsigned char v[3];
            fread(v, 3, 1, fp);
            d[i][j] = v[0] / 3 + v[1] / 3 + v[2] / 3;
            
        }
        if (padding != 0)
        {
            unsigned char dump;
            for (int p = 0; p < padding; p++)
            {
                fread(&dump, 1, 1, fp);
            }
        }
    }
    fclose(fp);
    return d;
}

void WriteBMP(const char* filename, unsigned char **d, int h, int w)
{
    FILE* fp = NULL;
    fopen_s(&fp, filename, "wb");
    BMPFILEHEADER fh;
    BITMAPINFOHEADER ih;
    fh.bfType = 0x4d42;
    fh.bfOffBits = 54;
    int padding = h * w % 4 == 0 ? 0 : 4 - (h * w % 4);
    fh.bfSize = 54 + (w * 3 + padding) * h;
    fh.bfReserved1 = 0;
    fh.bfReserved2 = 0;

    fwrite(&fh, sizeof(fh), 1, fp);

    ih.biHeight = h;
    ih.biWidth = w;
    ih.biBitCount = 24;
    ih.biSize = 40;
    ih.biSizeImage = (w * 3 + padding) * h;
    ih.biPlanes = 1;
    ih.biCompression = 0;
    ih.biXPelsPerMeter = 0;
    ih.biYPelsPerMeter = 0;
    ih.biClrUsed = 0;
    ih.biClrImportant = 0;

    fwrite(&ih, sizeof(ih), 1, fp);

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            for (int c = 0; c < 3; c++)
            {              
                fwrite(&(d[i][j]), 1, 1, fp);
            }
        }
        if (padding != 0)
        {
            unsigned char dump = 0;
            for (int p = 0; p < padding; p++)
            {
                fwrite(&dump, 1, 1, fp);
            }
        }
    }
    fclose(fp);
 }

int main()
{
    FILE* fp = nullptr;
    fopen_s(&fp, "../Fruits.bmp", "rb");

    unsigned short bfType;
    fread(&bfType, sizeof(unsigned short), 1, fp);
    unsigned int bfSize;
    fread(&bfSize, sizeof(unsigned int), 1, fp);

    int w, h;
    fseek(fp, 18, 0);
    fread(&w, sizeof(int), 1, fp);
    fread(&h, sizeof(int), 1, fp);

    unsigned char **d = new unsigned char * [h];
    for (int i = 0; i < h; i++)
    {
        d[i] = new unsigned char [w];
    }

    fseek(fp, 54, 0);
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            unsigned char pix[3];
            for (int c = 0; c < 3; c++)
            {
                fread(&pix[c], sizeof(char), 1, fp);
            }
            d[i][j] = pix[0] / 3 + pix[1] / 3 + pix[2] / 3;
        }
    }

    fclose(fp);

//    BMPFILEHEADER bmpfileheader;
//    BITMAPINFOHEADER bitmapinfoheader;

//    std::cout << "Read BMP file" << std::endl;
//    unsigned char** d = ReadBMP("Fruits.bmp", bmpfileheader, bitmapinfoheader);
//
//    std::cout << "Write BMP file" << std::endl;
//    WriteBMP("fruits_gray.bmp", d, bitmapinfoheader.biHeight, bitmapinfoheader.biWidth);
    
    //FILE* fp2 = NULL;
    //fopen_s(&fp, "Fruits.txt", "w");
    //if (fp == NULL)
    //{
    //    printf("Fail to open file.\n");
    //    return -1;
    //}
    //fprintf_s(fp2, "%d", bitmapinfoheader.biHeight);
    //fprintf_s(fp2, "%d", bitmapinfoheader.biWidth);
    //for (int i = 0; i < bitmapinfoheader.biHeight; i++)
    //{
    //    for (int j = 0; j < bitmapinfoheader.biWidth, j++)
    //    {
    //        fprintf_s(fp2, "%d", data[bitmapinfoheader.]);
    //    }
    //}
    //fclose(fp2);


    for (int i = 0; i < h; i++)
    {
        delete[] d[i];
    }
    delete[] d;


    return 0;
}
