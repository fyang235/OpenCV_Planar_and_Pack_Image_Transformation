#include "utils.h"

int main(int argc, char const *argv[])
{
    char *bgrPlanarImagePath = "./images/two_people_384x384.bgr";
    char *outPutImagePath = "./images/two_people_384x384_out.jpg";

    int height = 384, width = 384;
    cv::Mat img(height, width, CV_8UC3);

    // convert image
    planarToJpg(bgrPlanarImagePath, img);

    // save image
    saveImage(outPutImagePath, img);

    // show image
    namedWindow("Image", CV_WINDOW_AUTOSIZE);
    imshow("Image", img);
    waitKey(0);
    destroyWindow("Image");

    return 0;
}
