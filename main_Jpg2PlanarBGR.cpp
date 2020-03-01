#include <stdio.h>
#include <math.h>

#include "opencv2/imgcodecs/imgcodecs_c.h"
#include <opencv2/opencv.hpp>
typedef unsigned char U_CHAR;

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        fprintf(stderr, "Usage:%s [src_file] [out_file]\n", argv[0]);
        exit(-1);
    }

    IplImage *img = 0;
    const char *filename = argv[1];
    const char *outname = argv[2];
    int flag = 1;
    img = cvLoadImage(filename, flag);
    if (img == 0)
    {
        printf("Load image error\n");
        return -1;
    }

    CvSize size;

    size.width = 384;
    size.height = 384;

    IplImage *dst;
    dst = cvCreateImage(size, img->depth, img->nChannels);

    cvResize(img, dst, CV_INTER_CUBIC);

    U_CHAR *data = (U_CHAR *)dst->imageData;

    int step = dst->widthStep;
    printf("widthStep: %d, height: %d, width: %d\n", step, dst->height, dst->width);

    FILE *fp = fopen(outname, "wb");

    int h = dst->height;
    int w = dst->width;
    int c = dst->nChannels;

    //注意遍历顺序
    for (int k = 0; k < c; k++)
    {
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                fwrite(&data[i * step + j * c + k], sizeof(U_CHAR), 1, fp);
            }
        }
    }
    fclose(fp);

    return 0;
}
