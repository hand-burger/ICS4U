#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/bgsegm.hpp>

using namespace std;
using namespace cv;
using namespace cv::bgsegm;

void track(int, void *);
Mat imgOriginal, fgMask;
Mat imgGray, imgCrop, imgContours, imgMirror;

int thresh = 140, maxVal = 255;
int type = 2, value = 8;

int main()
{
    // Background subtractor
    Ptr<BackgroundSubtractor> pMOG2 = createBackgroundSubtractorMOG2();

    Rect myRoi(288, 12, 288, 288);
    Mat element = getStructuringElement(MORPH_RECT, Size(3, 3), Point(1, 1));
    Mat frame;
    Mat resizeF;
    VideoCapture cap(0);

    while (true)
    {
        cap.read(imgOriginal);
        flip(imgOriginal, imgMirror, 1);
        rectangle(imgMirror, myRoi, Scalar(0, 0, 255));
        imgCrop = imgMirror(myRoi);
        cvtColor(imgCrop, imgGray, COLOR_RGB2GRAY);
        GaussianBlur(imgGray, imgGray, Size(23, 23), 0);

        namedWindow("Set");
        createTrackbar("Thresh", "Set", &thresh, 250, track);
        createTrackbar("Maximum", "Set", &maxVal, 255, track);
        createTrackbar("Thresh Type", "Set", &type, 4, track);
        createTrackbar("Kernel", "Set", &value, 100, track);

        // Subtract the background
        pMOG2->apply(imgCrop, fgMask);
        rectangle(fgMask, myRoi, Scalar(0, 0, 255));

        track(0, 0);
        imshow("Original img", imgMirror);
        imshow("Foreground mask", fgMask);
        imshow("Gray img", imgGray);

        waitKey(1);
    }

    return 0;
}

void track(int, void *)
{
    int count = 0;
    char a[40];

    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;

    GaussianBlur(fgMask, fgMask, Size(27, 27), 3.5, 3.5);
    threshold(fgMask, fgMask, thresh, maxVal, type);
    Canny(fgMask, imgContours, value, value * 2, 3);
    findContours(fgMask, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

    Mat drawing = Mat::zeros(imgContours.size(), CV_8UC3);

    if (contours.size() > 0)
    {
        int indexOfBiggestContour = -1;
        long sizeOfBiggestContour = 0;
        for (int i = 0; i < contours.size(); i++)
        {
            if (contours[i].size() > sizeOfBiggestContour)
            {
                sizeOfBiggestContour = contours[i].size();
                indexOfBiggestContour = i;
            }
        }

        vector<vector<int>> hull(contours.size());
        vector<vector<Point>> hullPoint(contours.size());
        vector<vector<Vec4i>> defects(contours.size());
        vector<vector<Point>> defectPoint(contours.size());
        vector<vector<Point>> conPoly(contours.size());
        Point2f rect_point[4];
        vector<RotatedRect> minRect(contours.size());
        vector<Rect> boundRect(contours.size());

        for (int i = 0; i < contours.size(); i++)
        {
            int area = contourArea(contours[i]);
            if (area > 5000)
            {
                // Get convex hulls and convexity defects of hand (fingers)
                convexHull(contours[i], hull[i], true);
                convexityDefects(contours[i], hull[i], defects[i]);
                if (indexOfBiggestContour == i)
                {
                    minRect[i] = minAreaRect(contours[i]);
                    for (int j = 0; j < hull[i].size(); j++)
                    {
                        int ind = hull[i][j];
                        hullPoint[i].push_back(contours[i][ind]);
                    }
                    count = 0;

                    for (int j = 0; j < defects[i].size(); j++)
                    {
                        if (defects[i][j][3] > 13 * 256)
                        {
                            int p_end = defects[i][j][1];
                            int p_far = defects[i][j][2];
                            defectPoint[i].push_back(contours[i][p_far]);
                            circle(imgGray, contours[i][p_end], 3, Scalar(0, 255, 0), 2);
                            count++;
                        }
                    }
                    if (count == 1)
                    {
                        strcpy(a, "0");
                    }
                    else if (count == 2)
                    {
                        strcpy(a, "1");
                    }
                    else if (count == 3)
                    {
                        strcpy(a, "2");
                    }
                    else if (count == 4)
                    {
                        strcpy(a, "3");
                    }
                    else if (count == 5)
                    {
                        strcpy(a, "4");
                    }
                    else if (count > 5 && count < 8)
                    {
                        strcpy(a, "5");
                    }
                    else
                    {
                        strcpy(a, "Show hand");
                    }

                    putText(imgMirror, a, Point(75, 420), FONT_HERSHEY_PLAIN, 3, Scalar(0, 255, 0), 3, 8, false);

                    drawContours(drawing, contours, i, Scalar(255, 255, 0), 2, 8, vector<Vec4i>(), 0, Point());
                    drawContours(drawing, hullPoint, i, Scalar(255, 255, 0), 1, 8, vector<Vec4i>(), 0, Point());
                    drawContours(imgGray, hullPoint, i, Scalar(0, 0, 255), 2, 8, vector<Vec4i>(), 0, Point());
                    approxPolyDP(contours[i], conPoly[i], 3, false);
                    boundRect[i] = boundingRect(conPoly[i]);
                    rectangle(imgGray, boundRect[i].tl(), boundRect[i].br(), Scalar(255, 0, 0), 2, 8, 0);
                    minRect[i].points(rect_point);
                    for (int j = 0; j < 4; j++)
                    {
                        line(imgGray, rect_point[j], rect_point[(j + 1) % 4], Scalar(0, 255, 0), 2, 8);
                    }
                }
            }
        }
    }
    imshow("Drawing", drawing);
}
