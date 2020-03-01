#include "utils.h"

void planarToJpg(char *bgrPlanarImagePath, cv::Mat &image)
{
    int height = image.rows;
    int width = image.cols;

    // read planar image to mat
    FILE *fp = fopen(bgrPlanarImagePath, "rb");
    if (fp)
    {
        for (int k = 0; k < 3; ++k)
        {
            for (int i = 0; i < height; ++i)
            {
                for (int j = 0; j < width; ++j)
                {
                    if (!feof(fp))
                        fread(&image.ptr<UCHAR>(i)[3 * j + k], sizeof(UCHAR), 1, fp);
                }
            }
        }
    }
    else
    {
        printf("Fail to open image file for plot!");
        exit(1);
    }
    fclose(fp);
}

void readImage(char *imagePath, cv::Mat &img)
{
    img = cv::imread(imagePath, CV_LOAD_IMAGE_UNCHANGED);
    if (img.empty())
    {
        printf("Fail to read image!");
        exit(1);
    }
}

void saveImage(char *imagePath, cv::Mat &img)
{
    if (!cv::imwrite(imagePath, img))
    {
        printf("Fail to write image file!");
        exit(1);
    }
}
