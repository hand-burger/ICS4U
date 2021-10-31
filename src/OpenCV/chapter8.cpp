#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Face Detection \\

int main()
{
    string path = "/Users/jack/Documents/OpenCV/OpenCV/Resources/test.png";

    // Mat is matrix data type
    Mat img = imread(path);

    CascadeClassifier faceCasacde;
    faceCasacde.load("/Users/jack/Documents/OpenCV/OpenCV/Resources/haarcascade_frontalface_default.xml");

    vector<Rect> faces;
    faceCasacde.detectMultiScale(img, faces, 1.1, 10);

    // Draw rectangle around face
    for (int i = 0; i < faces.size(); i++)
    {
        rectangle(img, faces[i].tl(), faces[i].br(), Scalar(255, 0, 255), 3);
    }

    imshow("Image", img);

    waitKey(0);
    return 0;
}
