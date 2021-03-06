// https://youtu.be/2FYm3GOonhk?t=10972

#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/imgproc.hpp>
#include <iostream>

using namespace std;
using namespace cv;

// Project 2
// Document Scanner

Mat imgOriginal, imgBlur, imgGray, imgCanny, imgThre, imgDil, imgWarp, imgCrop;
// Store points of image
vector<Point> initialPoints, docPoints;

float w = 420, h = 596;

Mat preProcessing(Mat img)
{
    // Preprocessing of image
    cvtColor(img, imgGray, COLOR_BGR2GRAY);
    GaussianBlur(imgGray, imgBlur, Size(3, 3), 3.0);
    Canny(imgBlur, imgCanny, 25, 75);
    Mat kernel = getStructuringElement(MORPH_RECT, Size(3, 3));
    dilate(imgCanny, imgDil, kernel);

    // Return the preprocessed image
    return imgDil;
}

// Find the contours of the document
vector<Point> getContours(Mat image)
{
    // Contour storage
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    // Find contours
    findContours(image, contours, hierarchy, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE);

    // Contour poly and bounding rectangle
    vector<vector<Point>> conPoly(contours.size());
    vector<Rect> boundRect(contours.size());

    // Storage for the biggest shape (which will be the paper)
    vector<Point> biggest;
    int maxArea = 0;

    // Noise filter for objects with area less than 1000
    for (int i = 0; i < contours.size(); i++)
    {
        int area = contourArea(contours[i]);

        if (area > 1000)
        {
            float peri = arcLength(contours[i], true);
            approxPolyDP(contours[i], conPoly[i], 0.02 * peri, true);

            if (area > maxArea && conPoly[i].size() == 4)
            {
                // If this is the biggest area so far, store it as the biggest
                //                drawContours(imgOriginal, conPoly, i, Scalar(255, 0, 255), 5);
                biggest = {conPoly[i][0], conPoly[i][1], conPoly[i][2], conPoly[i][3]};
                maxArea = area;
            }
            //rectangle(imgOriginal, boundRect[i].tl(), boundRect[i].br(), Scalar(0, 255, 0), 5);
        }
    }
    // return the points of the biggest shape, which will be the paper.
    return biggest;
}

void drawPoints(vector<Point> points, Scalar color)
{
    // Draw the circles on the corners of the paper
    // & the number of the point
    for (int i = 0; i < points.size(); i++)
    {
        circle(imgOriginal, points[i], 10, color, FILLED);
        putText(imgOriginal, to_string(i), points[i], FONT_HERSHEY_SIMPLEX, 2, color, 2);
    }
}

vector<Point> reorder(vector<Point> points)
{
    // Reorder the points to be the correct order for the warp
    vector<Point> newPoints;
    vector<int> sumPoints, subPoints;

    for (int i = 0; i < 4; i++)
    {
        sumPoints.push_back(points[i].x + points[i].y);
        subPoints.push_back(points[i].x - points[i].y);
    }

    // Order the points
    newPoints.push_back(points[min_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);
    newPoints.push_back(points[max_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
    newPoints.push_back(points[min_element(subPoints.begin(), subPoints.end()) - subPoints.begin()]);
    newPoints.push_back(points[max_element(sumPoints.begin(), sumPoints.end()) - sumPoints.begin()]);

    // Return the new points to be drawn on the corners
    return newPoints;
}

Mat getWarp(Mat img, vector<Point> points, float w, float h)
{
    // Warp the document (img to imgWarp)
    Point2f src[4] = {points[0], points[1], points[2], points[3]};
    Point2f dst[4] = {{0.0f, 0.0f}, {w, 0.0f}, {0.0f, h}, {w, h}};

    Mat matrix = getPerspectiveTransform(src, dst);
    warpPerspective(img, imgWarp, matrix, Point(w, h));

    // Return the warped image
    return imgWarp;
}

int main()
{
    string path = "/Users/jack/Documents/OpenCV/OpenCV/Resources/paper.jpg";
    imgOriginal = imread(path);
    //    resize(imgOriginal, imgOriginal, Size(), 0.5, 0.5);

    // Pre-processing
    imgThre = preProcessing(imgOriginal);

    // Get biggest contour
    initialPoints = getContours(imgThre);
    docPoints = reorder(initialPoints);

    // Warp
    imgWarp = getWarp(imgOriginal, docPoints, w, h);

    // Crop
    int cropValue = 5;
    Rect roi(cropValue, cropValue, w - (2 * 5), h - (2 * 5));
    imgCrop = imgWarp(roi);

    // Show the images
    imshow("Image", imgOriginal);
    imshow("Image Dilation", imgThre);
    imshow("Image Warp", imgWarp);

    waitKey(0);
    return 0;
}
