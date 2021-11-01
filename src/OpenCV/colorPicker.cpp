#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Webcam Color Detection for Project 1 \\

int main()
{
    VideoCapture cap(0);

    Mat img;
    Mat imgHSV, mask;

    int hmin = 0, smin = 0, vmin = 0;
    int hmax = 179, smax = 255, vmax = 255;

    namedWindow("Trackbars", (640, 200));
    createTrackbar("Hue Min", "Trackbars", &hmin, 179);
    createTrackbar("Hue Max", "Trackbars", &hmax, 179);
    createTrackbar("Sat Min", "Trackbars", &smin, 255);
    createTrackbar("Sat Max", "Trackbars", &smax, 255);
    createTrackbar("Val Min", "Trackbars", &vmin, 255);
    createTrackbar("Val Max", "Trackbars", &vmax, 255);

    while (true)
    {
        cap.read(img);
        cvtColor(img, imgHSV, COLOR_BGR2HSV);
        Scalar lower(hmin, smin, vmin);
        Scalar upper(hmax, smax, vmax);

        // Create mask
        inRange(imgHSV, lower, upper, mask);

        // Put to the text to the mask since it doesn't work properly on mac :(
        putText(mask, "hmin: " + to_string(hmin), Point(25, 125), FONT_ITALIC, 0.75, Scalar(255, 0, 0), 0.75);
        putText(mask, "hmax: " + to_string(hmax), Point(25, 225), FONT_ITALIC, 0.75, Scalar(255, 0, 0), 0.75);
        putText(mask, "smin: " + to_string(smin), Point(25, 325), FONT_ITALIC, 0.75, Scalar(255, 0, 0), 0.75);
        putText(mask, "smax: " + to_string(smax), Point(25, 425), FONT_ITALIC, 0.75, Scalar(255, 0, 0), 0.75);
        putText(mask, "vmin: " + to_string(vmin), Point(25, 525), FONT_ITALIC, 0.75, Scalar(255, 0, 0), 0.75);
        putText(mask, "vmax: " + to_string(vmax), Point(25, 625), FONT_ITALIC, 0.75, Scalar(255, 0, 0), 0.75);

        imshow("Image", img);
        imshow("Image HSV", imgHSV);
        imshow("Image Mask", mask);

        waitKey(1);
    }

    return 0;
}
