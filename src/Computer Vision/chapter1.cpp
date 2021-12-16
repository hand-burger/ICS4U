#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Importing Images

int main()
{
    string path = "/Users/jack/Documents/OpenCV/OpenCV/Resources/test.png";

    // Mat is matrix data type
    Mat img = imread(path);
    imshow("Image", img);

    waitKey(0);
    return 0;
}

// Importing Videos

int main()
{
    string path = "/Users/jack/Documents/OpenCV/OpenCV/Resources/test_video.mp4";
    VideoCapture cap(path);
    Mat img;

    while (true)
    {
        // Mat is matrix data type
        cap.read(img);
        imshow("Image", img);

        waitKey(1);
    }
    return 0;
}

// Webcam

int main()
{
    // 0 is the id number of the camera
    VideoCapture cap(0);
    Mat img;

    while (true)
    {
        // Mat is matrix data type
        cap.read(img);
        imshow("Image", img);

        waitKey(10);
    }
    return 0;
}
