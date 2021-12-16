#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace cv;
using namespace std;

// Shape Detection

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

        if (area > 1000)
        {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);
            drawContours(img, conPoly, i, Scalar(255, 0, 255), 4);

            // Bounding rectangle of shape
            boundRect[i] = boundingRect(conPoly[i]);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);

            int objCor = (int)conPoly[i].size();

            if (objCor == 3)
            {
                objType = "Triangle";
            }
            else if (objCor == 4)
            {
                float aspRatio = (float)boundRect[i].width / (float)boundRect[i].height;
                if (aspRatio > 0.95 && aspRatio < 1.05)
                {
                    objType = "Square";
                }
                else
                {
                    objType = "Rectangle";
                }
            }
            else if (objCor > 4)
            {
                objType = "Prob circle?";
            }

            // Draw text to img
            putText(img, objType, {boundRect[i].x, boundRect[i].y - 5}, FONT_HERSHEY_SCRIPT_COMPLEX, 0.75, Scalar(255, 0, 126));
        }
    }
}

int main()
{
    string path = "/Users/jack/Documents/OpenCV/OpenCV/Resources/shapes.png";

    // Mat is matrix data type
    Mat img = imread(path);
    Mat imgGray, imgBlur, imgCanny, imgDil;

    // Image Pre-processing
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3, 0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);

    // Now find contours
    getContours(imgDil, img);

    imshow("Image", img);
    //    imshow("Image Dilate", imgDil);

    waitKey(0);
    return 0;
}
