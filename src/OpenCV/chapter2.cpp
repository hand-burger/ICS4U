#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Basic Functions \\

int main()
{
    string path = "/Users/jack/Documents/OpenCV/OpenCV/Resources/test.png";

    // Mat is matrix data type
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDia, imgErode;

    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(img, imgBlur, Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);

    // Creates kernel for dilation or erosion
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    // Dilate to fill in lines and then erode them to make the lines smaller again
    dilate(imgCanny, imgDia, kernel);
    erode(imgDia, imgErode, kernel);

    imshow("Image", img);
    imshow("Image Gray", imgGray);
    imshow("Image Blur", imgBlur);
    imshow("Image Canny", imgCanny);
    imshow("Image Dilation", imgDia);
    imshow("Image Erode", imgErode);

    waitKey(0);
    return 0;
}
