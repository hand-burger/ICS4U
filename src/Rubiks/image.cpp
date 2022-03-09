#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <vector>
#include <string>

using namespace std;
using namespace cv;


int main()
{
	vector<vector<int>> colorValues
	{
	{ 91, 117, 0, 156, 69, 237 }, // White HSV
	{ 23, 44, 31, 255, 92, 138 }, // Yellow HSV
	{ 0, 13, 168, 255, 45, 146 }, // Red HSV, may need to be tuned more
	{ 10, 24, 203, 255, 62, 144 }, // Orange HSV
	{ 69, 121, 203, 255, 66, 123 }, // Blue HSV
	{ 57, 84, 83, 232, 49, 206 } // Green HSV
	};
	
	string path = "cube.jpg";
	Mat img = imread(path);
	resize(img, img, Size(3024/6, 2764/6), INTER_LINEAR);

	Mat imgGray;
	cvtColor(img, imgGray, COLOR_BGR2GRAY);

	Mat imgBlur;
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 50, 50);

	Mat imgEdges;
	
	float lowThresh = 20;
	float highThresh = 3 * lowThresh;

	Canny(imgGray, imgEdges, lowThresh, highThresh);

	Mat SE = getStructuringElement(MORPH_RECT, Size(3, 3));

	int dilateIterations = 5;

	Mat dilation;

	morphologyEx(imgEdges, dilation, MORPH_DILATE, SE, Point(-1, -1), dilateIterations);

	vector<vector<Point>> imageCorners;
	imageCorners.push_back({ Point(0,0), Point(dilation.cols,0) });
	imageCorners.push_back({ Point(dilation.cols,0), Point(dilation.cols, dilation.rows) });
	imageCorners.push_back({ Point(dilation.cols, dilation.rows), Point(0,dilation.rows) });
	imageCorners.push_back({ Point(0,dilation.rows), Point(0, 0) });

	int lineThickness = 150;

	for (int c = 0; c < 4; c++)
	{
		vector<Point> currentVect = imageCorners[c];

		Point startPoint = currentVect[0];
		Point endPoint = currentVect[1];

		line(dilation, startPoint, endPoint, Scalar(255, 255, 255), lineThickness);
	}

	// Now invert the image

	Mat cubeMask = 255 - dilation;

	int closeIterations = 50;

	morphologyEx(cubeMask, cubeMask, MORPH_DILATE, SE, Point(-1, -1), closeIterations);
	morphologyEx(cubeMask, cubeMask, MORPH_ERODE, SE, Point(-1, -1), closeIterations);

	vector<vector<Point>> contours;
	vector<Vec4i> hierarchy;

	findContours(cubeMask, contours, hierarchy, RETR_TREE, CHAIN_APPROX_SIMPLE, Point(0, 0));

	Rect boundRect = boundingRect( contours[0] );

	boundRect.height += 35;

	Mat cropImage = img(Range(boundRect.y - 10, boundRect.height + 90), Range(boundRect.x - 10, boundRect.width + 90));

	Mat imgHSV;
	cvtColor(img, imgHSV, COLOR_BGR2HSV);

	int verticalGrids = 3;
	int horizontalGrids = 3;

	float gridWidth = (float)boundRect.width / 3.0;
	float gridHeight = (float)boundRect.height / 3.0;

	int gridCounter = 1;

	for (int j = 0; j < verticalGrids; j++)
	{
		int yo = j * gridHeight;

		for (int i = 0; i < horizontalGrids; i++)
		{
			int xo = i * gridWidth;

			Rect gridBox;
			gridBox.x = boundRect.x + xo;
			gridBox.y = boundRect.y + yo;
			gridBox.width = gridWidth;
			gridBox.height = gridHeight;

			// Get the point of the current cube
			Point currentCube;
			currentCube.x = gridBox.x + 0.5 * gridBox.width;
			currentCube.y = gridBox.y + 0.5 * gridBox.height;

			// Now check the color at that point
			Vec3b colour = imgHSV.at<Vec3b>(currentCube);
			string R = to_string(colour.val[0]);
			putText(img, R, currentCube, FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 255, 255));

			rectangle(img, gridBox, Scalar(128, 256, 255/(i+1)), 5);

			/*string gridCounterString = to_string(gridCounter);

			Point textPosition;
			textPosition.x = gridBox.x + 0.5 * gridBox.width;
			textPosition.y = gridBox.y + 0.5 * gridBox.height;

			putText(img, gridCounterString, textPosition, FONT_HERSHEY_SIMPLEX, 1, Scalar(255, 0, 0), 3, LINE_8, false);*/



			gridCounter++;

			//imshow("img", img);
		}
	}

	imshow("img", cropImage);

	waitKey(0);

	return 0;
}