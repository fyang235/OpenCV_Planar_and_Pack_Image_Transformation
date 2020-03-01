#include "utils.h"

void planarToJpg(const char *bgrPlanarImagePath, cv::Mat &img)
{
    int height = img.rows;
    int width = img.cols;

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
                        fread(&img.ptr<UCHAR>(i)[3 * j + k], sizeof(UCHAR), 1, fp);
                }
            }
        }
    }
    else
    {
        printf("Fail to open image file for transformation! \n");
        exit(1);
    }
    printf("Image transformed to JPG! \n");
    fclose(fp);
}

void readImage(const char *imagePath, cv::Mat &img)
{
    img = cv::imread(imagePath, CV_LOAD_IMAGE_UNCHANGED);
    if (img.empty())
    {
        printf("Fail to read image!");
        exit(1);
    }
    else
    {
        printf("Reading image from %s \n", imagePath);
    }
}

void saveImage(const char *imagePath, const cv::Mat &img)
{
    if (!cv::imwrite(imagePath, img))
    {
        printf("Fail to write image file!");
        exit(1);
    }
    else
    {
        printf("Image has been saved to %s \n", imagePath);
    }
}

void serializeMat(const char *binaryPath, const cv::Mat &img)
{
    int height = img.rows;
    int width = img.cols;
    int channel = 3;

    FILE *fp = fopen(binaryPath, "wb");
    if (fp)
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                for (int k = 0; k < channel; ++k)
                {
                    if (!feof(fp))
                        fwrite(&img.ptr<UCHAR>(i)[channel * j + k], sizeof(UCHAR), 1, fp);
                }
            }
        }
    }
    else
    {
        printf("Fail to serialize Mat to %s! \n", binaryPath);
        exit(1);
    }
    fclose(fp);
    printf("Mat has been serialized to %s! \n", binaryPath);
}

void deSerializeMat(const char *binaryPath, cv::Mat &img)
{
    int height = img.rows;
    int width = img.cols;
    int channel = 3;

    FILE *fp = fopen(binaryPath, "rb");
    if (fp)
    {
        for (int i = 0; i < height; ++i)
        {
            for (int j = 0; j < width; ++j)
            {
                for (int k = 0; k < channel; ++k)
                {
                    if (!feof(fp))
                        fread(&img.ptr<UCHAR>(i)[channel * j + k], sizeof(UCHAR), 1, fp);
                }
            }
        }
    }
    else
    {
        printf("Fail to deserialize Mat to %s! \n", binaryPath);
        exit(1);
    }
    fclose(fp);
    printf("Mat has been deserialized from %s! \n", binaryPath);
}