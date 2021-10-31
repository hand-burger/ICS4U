#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Warp Perspective \\

int main()
{
    string path = "/Users/jack/Documents/OpenCV/OpenCV/Resources/cards.jpg";

    // Mat is matrix data type
    Mat img = imread(path);

    Mat matrix, imgWarp;
    float w = 250, h = 350;

    Point2f src[4] = {{529, 142}, {771, 190}, {405, 395}, {674, 457}};
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    for (int i = 0; i < 4; i++)
    {
        circle(img, src[i], 10, Scalar(255, 204, 204), FILLED);
    }

    imshow("Image", img);
    imshow("Image Warp", imgWarp);

    waitKey(0);
    return 0;
}
