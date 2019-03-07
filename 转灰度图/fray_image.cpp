#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#define ImagePath "C:\\Users\\�ֿ���\\Desktop\\object-detection\\origin\\"
#define ImageType ".jpg"
#define ImageDst "C:\\Users\\�ֿ���\\Desktop\\object-detection\\after\\"
#define Imagenum 10
using namespace cv;
using namespace std;
 
//����ͼƬ����ʾ�Ҷ�ͼ
void loadGrayImg()
{
	for (int i = 1; i < Imagenum; i++)
	{
		String img = ImagePath + to_string(i) + ImageType;
		cout << img << endl;
		Mat src = imread(img);
		/*int t;
		std::cin >> t;*/
		if (src.empty())
		{
			cout << "could load image..." << endl;
			return;
		}
		//�Ҷ�ͼ
		Mat grayImg;
		cvtColor(src, grayImg, COLOR_BGR2GRAY);
		imshow("cc", grayImg);
		////����ɫ�ʿռ�
		Mat otherImg;
		cvtColor(src, otherImg, COLOR_BGR2GRAY);
		namedWindow("window3", CV_WINDOW_AUTOSIZE);
		imshow("window3", otherImg);
		//����ͼƬ
		imwrite(ImageDst + to_string(i) + ImageType, grayImg);
	}

	
}

int main()
{
	loadGrayImg();

	waitKey(0);
	return 0;
}
