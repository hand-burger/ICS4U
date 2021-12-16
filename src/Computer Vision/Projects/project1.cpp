// https://youtu.be/2FYm3GOonhk?t=8541

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Project 1
// Virtual Painter

Mat img;
vector<vector<int>> newPoints;

// hmin, hmax, smin, smax, vmin, vmax
// Color values for the objects to be detected
vector<vector<int>> myColors{{81, 158, 129, 255, 42, 255},  // Blue
                             {0, 179, 177, 211, 149, 255}}; // Red

// Colors for drawing on the canvas
vector<Scalar> myColorValues{{255, 0, 0}, {0, 0, 255}}; // Blue, Red

// Get contours from the pre-proccesed image
Point getContours(Mat imgDil)
{
    // Contour storage
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // Find contours
    findContours(imgDil, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    // Point of the object
    Point myPoint(0, 0);

    // Noise filter for objects with area less than 1000
    for (int i = 0; i < contours.size(); i++)
    {
        int area = contourArea(contours[i]);

        if (area > 1000)
        {
            // Get approximate polygon of the object
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

            // Bounding rectangle of shape
            boundRect[i] = boundingRect(conPoly[i]);
            // Get the point of the object
            myPoint.x = boundRect[i].x + boundRect[i].width / 2;
            myPoint.y = boundRect[i].y;

            // Draw the contours and rectangle on the object
            drawContours(img, conPoly, i, Scalar(255, 0, 255), 4);
            rectangle(img, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
        }
    }
    // Return the point of the object
    return myPoint;
}

// Get the color of the object
vector<vector<int>> findColor(Mat img)
{
    // Convert to HSV
    Mat imgHSV;
    cvtColor(img, imgHSV, COLOR_BGR2HSV);

    // Create a mask for the color
    for (int i = 0; i < myColors.size(); i++)
    {
        // Get the lower and upper bounds of the color from the pre-defined colors
        Scalar lower(myColors[i][0], myColors[i][2], myColors[i][4]);
        Scalar upper(myColors[i][1], myColors[i][3], myColors[i][5]);
        Mat mask;
        inRange(imgHSV, lower, upper, mask);
        //        imshow(to_string(i), mask);
        // Find the points of the object
        Point myPoint = getContours(mask);

        // Process the points
        if (myPoint.x != 0)
        {
            newPoints.push_back({myPoint.x, myPoint.y, i});
        }
    }
    // Return the points
    return newPoints;
}

void drawOnCanvas(vector<vector<int>> newPoints, vector<Scalar> myColorValues)
{
    // Draw the points on the canvas
    for (int i = 0; i < newPoints.size(); i++)
    {
        circle(img, Point(newPoints[i][0], newPoints[i][1]), 10, myColorValues[newPoints[i][2]], FILLED);
    }
}

int main()
{
    // 0 is the id number of the camera
    VideoCapture cap(0);

    while (true)
    {
        // Get the frame
        cap.read(img);
        // Get points
        newPoints = findColor(img);
        // Draw the color at the points on the canvas
        drawOnCanvas(newPoints, myColorValues);

        // Show the image
        imshow("Image", img);
        waitKey(1);
    }
    return 0;
}
