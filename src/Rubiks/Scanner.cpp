#include <iostream>
#include <array>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// TODO: Modify HSV values to actually work
// TODO: Add color detection to each color
// TODO: Initialize the cube array with zeroes
// TODO: Less spaghetti?

int main()
{
    Mat img;
    Mat yellow, blue, orange, red, green, white;
    Mat yellowMask, blueMask, orangeMask, redMask, greenMask, whiteMask;
    
    array<array<array<int, 6>, 3>, 3> cube;
    
    bool tutorialToggle = false, yellowToggle = false, blueToggle = false, orangeToggle = false, redToggle = false, greenToggle = false, whiteToggle = false;
    
    VideoCapture cap(0);
    
    while (true) {
        cap.read(img);
        
        Rect ROI(Point(img.cols / 2 - 100, img.rows / 2 - 100) , Point(img.cols / 2 + 100, img.rows / 2 + 100));
        
        // User tutorial
        if (!tutorialToggle) {
            putText(img, "Rubik's Cube Solver!", Point(100, 100), FONT_HERSHEY_PLAIN, 5.0, Scalar(255, 128, 128), 5);
            putText(img, "Press Space to scan your cube", Point(100, 170), FONT_HERSHEY_PLAIN, 4.0, Scalar(255, 128, 128), 3.5);
            
            if (waitKey(1) == 32) {
                tutorialToggle = !tutorialToggle;
            }
        }
        
        // Scan yellow side
        if (tutorialToggle && !yellowToggle) {
            putText(img, "Scan Yellow Side", Point(100, 100), FONT_HERSHEY_PLAIN, 5.0, Scalar(0, 215, 255), 5);
            rectangle(img, Point(img.cols / 2 - 100, img.rows / 2 - 100), Point(img.cols / 2 + 100, img.rows / 2 + 100), Scalar(0, 215, 255), 5);
            
            if (waitKey(1) == 32) {
                yellowToggle = !yellowToggle;
                
                // Save it to the mat
                yellow = img(ROI);
                
                inRange(yellow, Scalar(19, 88, 149), Scalar(39, 155, 229), yellowMask);
                
                // Now check each point on the mask for white to know if that color is there
                Scalar colour1 = yellowMask.at<uchar>(Point(30, 30));
                Scalar colour2 = yellowMask.at<uchar>(Point(90, 30));
                Scalar colour3 = yellowMask.at<uchar>(Point(150, 30));
                Scalar colour4 = yellowMask.at<uchar>(Point(30, 90));
                Scalar colour5 = yellowMask.at<uchar>(Point(90, 90));
                Scalar colour6 = yellowMask.at<uchar>(Point(150, 90));
                Scalar colour7 = yellowMask.at<uchar>(Point(30, 150));
                Scalar colour8 = yellowMask.at<uchar>(Point(90, 150));
                Scalar colour9 = yellowMask.at<uchar>(Point(150, 150));
                
                if (colour1 == Scalar(255, 255, 255)) {
                    cube[0][0][0] = 0;
                }
                if (colour2 == Scalar(255, 255, 255)) {
                    cube[0][0][1] = 0;
                }
                if (colour3 == Scalar(255, 255, 255)) {
                    cube[0][0][2] = 0;
                }
                if (colour4 == Scalar(255, 255, 255)) {
                    cube[0][1][0] = 0;
                }
                if (colour5 == Scalar(255, 255, 255)) {
                    cube[0][1][1] = 0;
                }
                if (colour6 == Scalar(255, 255, 255)) {
                    cube[0][1][2] = 0;
                }
                if (colour7 == Scalar(255, 255, 255)) {
                    cube[0][2][0] = 0;
                }
                if (colour8 == Scalar(255, 255, 255)) {
                    cube[0][2][1] = 0;
                }
                if (colour9 == Scalar(255, 255, 255)) {
                    cube[0][2][2] = 0;
                }
                
                imshow("Yellow", yellowMask);
            }
        }
        
        // Scan blue side
        if (tutorialToggle && yellowToggle && !blueToggle) {
            putText(img, "Scan Blue Side", Point(100, 100), FONT_HERSHEY_PLAIN, 5.0, Scalar(255, 10, 10), 5);
            rectangle(img, Point(img.cols / 2 - 100, img.rows / 2 - 100), Point(img.cols / 2 + 100, img.rows / 2 + 100), Scalar(255, 10, 10), 5);
            
            if (waitKey(1) == 32) {
                blueToggle = !blueToggle;
                
                // Save it to the mat
                blue = img(ROI);
                
                inRange(blue, Scalar(102, 154, 58), Scalar(131, 255, 203), blueMask);
                
                imshow("Blue", blueMask);
            }
        }
        
        // Scan orange side
        if (tutorialToggle && yellowToggle && blueToggle && !orangeToggle) {
            putText(img, "Scan Orange Side", Point(100, 100), FONT_HERSHEY_PLAIN, 5.0, Scalar(0, 165, 255), 5);
            rectangle(img, Point(img.cols / 2 - 100, img.rows / 2 - 100), Point(img.cols / 2 + 100, img.rows / 2 + 100), Scalar(0, 165, 255), 5);
            
            if (waitKey(1) == 32) {
                orangeToggle = !orangeToggle;
                
                // Save it to the mat
                orange = img(ROI);
                
                inRange(orange, Scalar(0, 102, 113), Scalar(18, 187, 222), orangeMask);
                
                imshow("Orange", orangeMask);
            }
        }
        
        // Scan red side
        if (tutorialToggle && yellowToggle && blueToggle && orangeToggle && !redToggle) {
            putText(img, "Scan Red Side", Point(100, 100), FONT_HERSHEY_PLAIN, 5.0, Scalar(0, 5, 255), 5);
            rectangle(img, Point(img.cols / 2 - 100, img.rows / 2 - 100), Point(img.cols / 2 + 100, img.rows / 2 + 100), Scalar(0, 5, 255), 5);
            
            if (waitKey(1) == 32) {
                redToggle = !redToggle;
                
                // Save it to the mat
                red = img(ROI);
                
                inRange(red, Scalar(120, 123, 103), Scalar(179, 224, 211), redMask);
                
                imshow("Red", redMask);
            }
        }
        
        // Scan green side
        if (tutorialToggle && yellowToggle && blueToggle && orangeToggle && redToggle && !greenToggle) {
            putText(img, "Scan Green Side", Point(100, 100), FONT_HERSHEY_PLAIN, 5.0, Scalar(0, 255, 5), 5);
            rectangle(img, Point(img.cols / 2 - 100, img.rows / 2 - 100), Point(img.cols / 2 + 100, img.rows / 2 + 100), Scalar(0, 255, 5), 5);
            
            if (waitKey(1) == 32) {
                greenToggle = !greenToggle;
                
                // Save it to the mat
                green = img(ROI);
                
                inRange(green, Scalar(61, 94, 0), Scalar(99, 255, 255), greenMask);
                
                imshow("Green", greenMask);
            }
        }
        
        // Scan white side
        if (tutorialToggle && yellowToggle && blueToggle && orangeToggle && redToggle && greenToggle && !whiteToggle) {
            putText(img, "Scan White Side", Point(100, 100), FONT_HERSHEY_PLAIN, 5.0, Scalar(255, 255, 255), 5);
            rectangle(img, Point(img.cols / 2 - 100, img.rows / 2 - 100), Point(img.cols / 2 + 100, img.rows / 2 + 100), Scalar(255, 255, 255), 5);
            
            if (waitKey(1) == 32) {
                whiteToggle = !whiteToggle;
                
                // Save it to the mat
                white = img(ROI);
                
                inRange(white, Scalar(98, 0, 124), Scalar(123, 48, 205), whiteMask);
                
                imshow("White", whiteMask);
                
                // Now check each point on the mask for white to know if that color is there
                Scalar colour1 = whiteMask.at<uchar>(Point(30, 30));
                Scalar colour2 = whiteMask.at<uchar>(Point(90, 30));
                Scalar colour3 = whiteMask.at<uchar>(Point(150, 30));
                Scalar colour4 = whiteMask.at<uchar>(Point(30, 90));
                Scalar colour5 = whiteMask.at<uchar>(Point(90, 90));
                Scalar colour6 = whiteMask.at<uchar>(Point(150, 90));
                Scalar colour7 = whiteMask.at<uchar>(Point(30, 150));
                Scalar colour8 = whiteMask.at<uchar>(Point(90, 150));
                Scalar colour9 = whiteMask.at<uchar>(Point(150, 150));
                
                if (colour1 == Scalar(255, 255, 255)) {
                    cube[5][0][0] = 5;
                }
                if (colour2 == Scalar(255, 255, 255)) {
                    cube[5][0][1] = 5;
                }
                if (colour3 == Scalar(255, 255, 255)) {
                    cube[5][0][2] = 5;
                }
                if (colour4 == Scalar(255, 255, 255)) {
                    cube[5][1][0] = 5;
                }
                if (colour5 == Scalar(255, 255, 255)) {
                    cube[5][1][1] = 5;
                }
                if (colour6 == Scalar(255, 255, 255)) {
                    cube[5][1][2] = 5;
                }
                if (colour7 == Scalar(255, 255, 255)) {
                    cube[5][2][0] = 5;
                }
                if (colour8 == Scalar(255, 255, 255)) {
                    cube[5][2][1] = 5;
                }
                if (colour9 == Scalar(255, 255, 255)) {
                    cube[5][2][2] = 5;
                }
            }
        }
        
        // Now all the sides are scaned
        // Determine the colors of each cubie
        
        imshow("Frame", img);
        
        for (int i = 0; i < 6; ++i) {
            for (int j = 0; j < 3; ++j) {
                for (int k = 0; k < 3; ++k) {
                    cout << cube[i][j][k] << " ";
                }
            }
        }
        
        waitKey(1);
    }
    return 0;
}
