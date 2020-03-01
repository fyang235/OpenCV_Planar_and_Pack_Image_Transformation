#ifndef _UTILS_H
#define _UTILS_h

#include <stdio.h>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/imgcodecs.hpp>

using namespace cv;
typedef unsigned char UCHAR;

void planarToJpg(char *bgrPlanarImagePath, cv::Mat &image);
void readImage(char *imagePath, cv::Mat &img);
void saveImage(char *imagePath, cv::Mat &img);

#endif