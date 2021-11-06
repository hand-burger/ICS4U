// https://youtu.be/2FYm3GOonhk?t=13574

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

    CascadeClassifier plateCascade;
    plateCascade.load("/Users/jack/Documents/OpenCV/OpenCV/Resources/haarcascade_russian_plate_number.xml");

    vector<Rect> plates;

    while (true)
    {
        cap.read(img);

        plateCascade.detectMultiScale(img, plates, 1.1, 10);

        // Draw rectangle around face
        for (int i = 0; i < plates.size(); i++)
        {
            Mat imgCrop = img(plates[i]);
            //            imshow(to_string(i), imgCrop);
            imwrite("/Users/jack/Documents/OpenCV/OpenCV/Resources/Plates/" + to_string(i) + ".png", imgCrop);
            rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
        }

        imshow("Image", img);

        waitKey(1);
    }
    return 0;
}
