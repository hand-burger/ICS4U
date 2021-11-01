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
    VideoCapture cap(0);
    Mat img;

    while (true)
    {
        cap.read(img);
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

        waitKey(1);
    }
    return 0;
}
