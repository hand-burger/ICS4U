#include <opencv/4.5.3_2/include/opencv4/opencv.hpp>

using namespace cv;

using namespace std;

int main()
{

    Mat image;

    namedWindow("Display window");

    VideoCapture cap(0);

    if (!cap.isOpened())
    {

        cout << "cannot open camera";
    }

    while (true)
    {

        cap >> image;

        imshow("Display window", image);

        waitKey(25);
    }

    return 0;
}