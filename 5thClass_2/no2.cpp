#include<iostream>
#include<opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main() {
	Mat srcMat, thresold_img;	srcMat = imread("C:/Users/Desktop/4.jpg",0);
	threshold(srcMat, thresold_img, 100, 255, THRESH_BINARY);

    imshow("erzhi", thresold_img);

    Mat stats;
    Mat centroids;
	Mat labels;
    int num_labels = connectedComponentsWithStats(thresold_img, labels, stats, centroids, 8, CV_32S);
	cout << num_labels-1 << endl; 



     for (int i = 1; i < num_labels; i++) 
	 {
	    Vec2d pt = centroids.at<Vec2d>(i, 0);
		int x = stats.at<int>(i, CC_STAT_LEFT);
		int y = stats.at<int>(i, CC_STAT_TOP);
		int width = stats.at<int>(i, CC_STAT_WIDTH);
		int height = stats.at<int>(i, CC_STAT_HEIGHT);
		int area = stats.at<int>(i, CC_STAT_AREA);
		printf("area : %d, center point(%.2f, %.2f)\n", area, pt[0], pt[1]);
		circle(thresold_img, Point(pt[0], pt[1]), 2, Scalar(0, 0, 255), -1, 8, 0);
		rectangle(thresold_img, Rect(x, y, width, height), Scalar(255, 0, 255), 1, 8, 0);
	}

	imshow("jijian", thresold_img);
	waitKey(0);
	return 0;
}