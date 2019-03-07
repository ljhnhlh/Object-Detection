#include "opencv2/objdetect.hpp"
#include "opencv2/highgui.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
using namespace std;
using namespace cv;

CascadeClassifier stone;
void detectAndDisplay(Mat frame);
int main() {
	//string xmlpath = "F:\\opencv\\opencv\\sources\\data\\haarcascades\\haarcascade_eye.xml";
	string xmlpath = "C:\\Users\\林俊浩\\Desktop\\object-detection\\xml\\cascade.xml";
	string videoPath = "C:\\Users\\林俊浩\\Desktop\\object-detection\\video\\V90306-200326.mp4";
//	string videoPath = "F:\\迅雷下载\\[生活大爆炸][第一季]第5集_hd.mp4";
	cout << "begin" << endl;
	if (!stone.load(xmlpath))
	{
		cout << "load failed" << endl;
		return -1;
	}
	VideoCapture capture;
	capture.open(videoPath);
	if (!capture.isOpened())
	{
		cout << "video load failed" << endl;
		return -1;
	}
	cout << "begin" << endl;
	Mat frame;
	while (capture.read(frame))
	{
		if (frame.empty())
		{
			cout << "--(!) No captured frame -- Break!\n";
			break;
		}
		//-- 3. Apply the classifier to the frame
		detectAndDisplay(frame);
		if (waitKey(10) == 27)
		{
			break; // escape
		}
	}
	return 0;
}
void detectAndDisplay(Mat frame) {
	Mat frame_gray;
	cvtColor(frame, frame_gray, COLOR_BGR2GRAY);
	//equalizeHist(frame_gray, frame_gray);
	std::vector<Rect> sto;
	cv::Size minSize = cv::Size(3, 3);
	cv::Size maxSize = cv::Size(3, 3);
	//imshow("Capture - Face detection", frame);
	/stone.detectMultiScale(frame, sto, 1.15, 3, 0, minSize, maxSize);
	Scalar colors[] =
	{
		// 红橙黄绿青蓝紫
		CV_RGB(255, 0, 0),
		CV_RGB(255, 97, 0),
		CV_RGB(255, 255, 0),
		CV_RGB(0, 255, 0),
		CV_RGB(0, 255, 255),
		CV_RGB(0, 0, 255),
		CV_RGB(160, 32, 240)
	};
	int radius;
	for (size_t i = 0; i < sto.size(); i++)
	{
		Point center(sto[i].x + sto[i].width / 2, sto[i].y + sto[i].height / 2);
		ellipse(frame, center, Size(sto[i].width / 2, sto[i].height / 2), 0, 0, 360, Scalar(255, 0, 255), 4);
		Mat faceROI = frame(sto[i]);
		//-- In each face, detect eyes
		radius = cvRound((sto[i].width + sto[i].height) * 0.25);
		circle(frame, center, radius, colors[i % 7], 2);
	}
	
	//-- Show what you got
	imshow("Capture - Face detection", frame);
}

