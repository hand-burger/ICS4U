#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <opencv2/objdetect.hpp>
#include <iostream>

using namespace cv;
using namespace std;

void getContours(Mat imgDil, Mat img)
{
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());
    string objType;

    // Noise filter for objects with area less than 1000
    for (int i = 0; i < contours.size(); i++)
    {
        int area = contourArea(contours[i]);

        int tmin = 1500, tmax = 3500;

        if (area > tmin && area < tmax)
        {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            drawContours(img, conPoly, i, Scalar(255, 0, 255), 4);

            // Bounding rectangle of shape
            boundRect[i] = boundingRect(conPoly[i]);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

            int objCor = (int)conPoly[i].size();

            if (objCor == 4)
            {
                objType = "Rectangle";
            }

            // Draw text to img
            putText(img, objType, {boundRect[i].x, boundRect[i].y - 5}, FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 126));
        }
    }
}

int main()
{
    // Rubiks cube detection
    // 1.
    VideoCapture cap(0);
    Mat img, imgCrop;
    Mat imgGray, imgBlur, imgCanny, imgDil;

    while (true)
    {
        cap.read(img);
        // Crop webcam frame to avoid noise and concentrate on cube
        Rect roi(390, 370, 250, 250);
        img = img(roi);

        // Image Pre-processing
        cvtColor(img, imgGray, COLOR_BGR2GRAY);
        GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
        Canny(imgBlur, imgCanny, 25, 75);
        Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
        dilate(imgCanny, imgDil, kernel);

        // Now find contours
        getContours(imgDil, img);

        imshow("Image Dilate", imgDil);
        imshow("Image", img);
        waitKey(1);
    }
    return 0;
}
