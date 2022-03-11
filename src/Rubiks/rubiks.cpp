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
	// Ideally, take two images which each have three faces completely visible to scan the entire cube in two images
	VideoCapture cap(0);
	Mat img, cubeTop, cubeBottom, imgGray, imgBlur, imgEdges, imgDilation;
	Mat SE = getStructuringElement(MORPH_RECT, Size(3, 3));
	// Track the number of images captured of the cube
	int imagesCaptured = 0;

	// Read one frame to get some info on the one time
	cap.read(img);

	Size imgSize = img.size();
	int imgY = imgSize.height / 2;
	int imgX = imgSize.width / 2;

	Rect frame(imgX - 100, imgY - 100, 200, 200);

	while (imagesCaptured <= 1)
	{
		cap.read(img);
		flip(img, img, 1);

		// Draw square in the middle of frame to show the centre
		rectangle(img, frame, Scalar(255, 255, 255), 5);

		imshow("Img", img);
		if (waitKey(1) == 32)
		{
			if (imagesCaptured == 0)
			{
				// Get first three faces from top of cube
				imwrite("Images/cube1.png", img);
				imagesCaptured++;
			}
			else if (imagesCaptured == 1)
			{
				// Get second three faces from bottom of cube
				imwrite("Images/cube2.png", img);
				imagesCaptured++;
			}
		}
		//cout << imagesCaptured << endl;
	}
	
	// Get rid of the webcam
	destroyWindow("Img");
	cap.release();

	// Open top and bottom of cube
	cubeTop = imread("Images/cube1.png");
	cubeBottom = imread("Images/cube2.png");

	cubeTop = cubeTop(frame);
	cubeBottom = cubeBottom(frame);

	imshow("Cube Top", cubeTop);
	imshow("Cube Bottom", cubeBottom);

	// Now the magic happens

	// Conver to gray
	cvtColor(cubeTop, imgGray, COLOR_BGR2GRAY);
	// Blur
	GaussianBlur(imgGray, imgBlur, Size(3, 3), 50, 50);
	// Canny
	Canny(imgBlur, imgEdges, 20, 60);
	// Dilate
	morphologyEx(imgEdges, imgDilation, MORPH_DILATE, SE, Point(-1, -1), 5);

	imshow("Dilation", imgDilation);

	waitKey(0);

	return 0;
}