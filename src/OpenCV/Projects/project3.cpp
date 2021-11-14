// https://youtu.be/2FYm3GOonhk?t=13574

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Project 3
// Number Plate Detection

int main()
{
    VideoCapture cap(0);
    Mat img;

    // Load the haar cascade file for russian number plates
    CascadeClassifier plateCascade;
    plateCascade.load("/Users/jack/Documents/OpenCV/OpenCV/Resources/haarcascade_russian_plate_number.xml");

    // Storage for plates
    vector<Rect> plates;

    while (true)
    {
        cap.read(img);

        // Detect plates
        plateCascade.detectMultiScale(img, plates, 1.1, 10);

        // Draw rectangle around plates
        for (int i = 0; i < plates.size(); i++)
        {
            Mat imgCrop = img(plates[i]);
            //            imshow(to_string(i), imgCrop);
            // Store image of detected plate
            imwrite("/Users/jack/Documents/OpenCV/OpenCV/Resources/Plates/" + to_string(i) + ".png", imgCrop);
            // Draw rectangle around plate
            rectangle(img, plates[i].tl(), plates[i].br(), Scalar(255, 0, 255), 3);
        }

        // Show image
        imshow("Image", img);

        waitKey(1);
    }
    return 0;
}
