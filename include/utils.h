#ifndef _UTILS_H
#define _UTILS_h

#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
typedef unsigned char UCHAR;

void planarToJpg(const char *bgrPlanarImagePath, cv::Mat &img);
void readImage(const char *imagePath, cv::Mat &img);
void saveImage(const char *imagePath, const cv::Mat &img);
void serializeMat(const char *binaryPath, const cv::Mat &img);
void deSerializeMat(const char *binaryPath, cv::Mat &img);

#endif