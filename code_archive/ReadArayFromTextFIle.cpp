#include <cstdio>

int main()
{
    FILE* fp = NULL;
    fopen_s(&fp, "array.txt", "r");
    if (fp == NULL)
    {
        printf("Fail to open file.\n");
        return -1;
    }

    int n = 0;
    fscanf_s(fp, "%d", &n);
    int a[10];
    for (int i = 0; i < n; i++)
    {
        fscanf_s(fp, "%d", a + i);
    }

    fclose(fp);

    return 0;
}