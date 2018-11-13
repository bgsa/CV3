#include <iostream> 
#include <fstream> 

#include "opencv2/imgcodecs.hpp" 
#include "opencv2/highgui.hpp" 
#include "opencv2/stitching.hpp" 

using namespace std;
using namespace cv;

int main(int argc, char* argv[])
{
	Mat result;
	vector<Mat> imgs;

	Mat img1 = imread("./resources/images/img1.jpg");
	imgs.push_back(img1);
	imshow("Image 1", img1);

	Mat img2 = imread("./resources/images/img2.jpg");
	imgs.push_back(img2);
	imshow("Image 2", img2);
	
	Ptr<Stitcher> stitcher = Stitcher::create(Stitcher::PANORAMA, false);
		
	Stitcher::Status status = stitcher->stitch(imgs, result);

	if (status != Stitcher::OK)
	{
		cout << "Não foi possível criar panorâmica. \n";
		waitKey(0);
		return -1;
	}

	imwrite("./resources/images/result.jpg", result);
	imshow("Result", result);

	waitKey(0);
	return 0;
}