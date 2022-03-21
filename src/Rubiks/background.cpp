#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

Mat sobel(Mat gray);
Mat canny(Mat src);

int main()
{
    Mat img, cube;
    
    cube = imread("/Users/jack/Pictures/images/Idk.png");
    
    imshow("Cube", cube);
    
    Mat hsvImg;
    cvtColor(cube, hsvImg, COLOR_BGR2HSV);
    
    Mat channel[3];
    split(hsvImg, channel);
    channel[2] = Mat(hsvImg.rows, hsvImg.cols, CV_8UC1, 200);//Set V
    //Merge channels
    merge(channel, 3, hsvImg);
    Mat rgbImg;
    cvtColor(hsvImg, rgbImg, COLOR_HSV2BGR);
//    imshow("Remove Shadows", rgbImg);
    
    Mat gray(rgbImg.rows, cube.cols, CV_8UC1);
    cvtColor(rgbImg, gray, COLOR_BGR2GRAY);
    normalize(gray, gray, 0, 255, NORM_MINMAX, CV_8UC1);
//    imshow("2. Grayscale", gray);
    
    //3. Edge detector
    GaussianBlur(gray, gray, Size(3,3), 0, 0, BORDER_DEFAULT);
    Mat edges;
    bool useCanny = false;
    if(useCanny){
        edges = canny(gray);
    } else {
        //Use Sobel filter and thresholding.
        edges = sobel(gray);
        //Automatic thresholding
        //threshold(edges, edges, 0, 255, cv::THRESH_OTSU);
        //Manual thresholding
        threshold(edges, edges, 25, 255, cv::THRESH_BINARY);
    }

//    imshow("3. Edge Detector", edges);
    
    Mat dilateGrad = edges;
    int dilateType = MORPH_ELLIPSE;
    int dilateSize = 8;
    Mat elementDilate = getStructuringElement(dilateType,
        Size(2*dilateSize + 1, 2*dilateSize+1),
        Point(dilateSize, dilateSize));
    dilate(edges, dilateGrad, elementDilate);
//    imshow("4. Dilate", dilateGrad);
    
    Mat floodFilled = cv::Mat::zeros(dilateGrad.rows+2, dilateGrad.cols+2, CV_8U);
    floodFill(dilateGrad, floodFilled, cv::Point(0, 0), 0, 0, cv::Scalar(), cv::Scalar(), 4 + (255 << 8) + cv::FLOODFILL_MASK_ONLY);
    floodFilled = cv::Scalar::all(255) - floodFilled;
    Mat temp;
    floodFilled(Rect(1, 1, dilateGrad.cols-2, dilateGrad.rows-2)).copyTo(temp);
    floodFilled = temp;
//    imshow("5. Floodfill", floodFilled);
    
    int erosionType = MORPH_ELLIPSE;
    int erosionSize = 4;
    Mat erosionElement = getStructuringElement(erosionType,
        Size(2*erosionSize+1, 2*erosionSize+1),
        Point(erosionSize, erosionSize));
    erode(floodFilled, floodFilled, erosionElement);
//    imshow("6. Erode", floodFilled);
    
    int largestArea = 0;
    int largestContourIndex = 0;
    Rect boundingRectangle;
    Mat largestContour(cube.rows, cube.cols, CV_8UC1, Scalar::all(0));
    vector<vector<Point>> contours;
    vector<Vec4i> hierarchy;
 
    findContours(floodFilled, contours, hierarchy, RETR_CCOMP, CHAIN_APPROX_SIMPLE);
   
    for(int i=0; i<contours.size(); i++)
    {
        double a = contourArea(contours[i], false);
        if(a > largestArea)
        {
            largestArea = a;
            largestContourIndex = i;
            boundingRectangle = boundingRect(contours[i]);
        }
    }
 
    Scalar color(255, 255, 255);
    drawContours(largestContour, contours, largestContourIndex, color, FILLED, 8, hierarchy); //Draw the largest contour using previously stored index.
//    imshow("7. Largest Contour", largestContour);
    
    Mat maskedSrc;
    cube.copyTo(maskedSrc, largestContour);
    imshow("Masked Source", maskedSrc);
    
//    imshow("src boxed", cube);
    
    waitKey(0);
    return 0;
}

Mat sobel(Mat gray){
    Mat edges;

    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;
    Mat edges_x, edges_y;
    Mat abs_edges_x, abs_edges_y;
    Sobel(gray, edges_x, ddepth, 1, 0, 3, scale, delta, BORDER_DEFAULT);
    convertScaleAbs( edges_x, abs_edges_x );
    Sobel(gray, edges_y, ddepth, 0, 1, 3, scale, delta, BORDER_DEFAULT);
    convertScaleAbs(edges_y, abs_edges_y);
    addWeighted(abs_edges_x, 0.5, abs_edges_y, 0.5, 0, edges);

    return edges;
}

Mat canny(Mat src)
{
    Mat detected_edges;

    int lowThreshold = 250;
    int highThreshold = 750;
    int kernel_size = 5;
    Canny(src, detected_edges, lowThreshold, highThreshold, kernel_size);

    return detected_edges;
 }
