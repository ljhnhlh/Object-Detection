// change_img_size.cpp : �������̨Ӧ�ó������ڵ㡣
//
//#include "stdafx.h"//���ͷ�ļ�һ��Ҫ���������棬��������ױ���

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

#define DST_IMG_WIDTH 24        //��Ҫ����ͼƬ��ĳߴ���
#define SRC_IMG_HEIGH 24        //��Ҫ����ͼƬ��ĳߴ�߶�

int main(int argc, char* argv[])
{
	Mat src_img;
	int i, j;
	string src_img_name = "C:\\Users\\�ֿ���\\Desktop\\object-detection\\origin\\", dst_img_name = "C:\\Users\\�ֿ���\\Desktop\\object-detection\\after\\";//Դ�ļ���Ŀ���ļ����ļ�������
	char chari[5], charj[5];//��Ϊ�������ݲ��Ǻܶ࣬�����±�5�㹻��
	for (i = 1; i <= 8; i++)//15���˵���������
	{
			src_img_name += to_string(i);//ԭͼ������ʽΪ�������5���˵ĵ�6��ͼ��5_s6.bmp
			src_img_name += ".jpg";

			src_img = imread(src_img_name, 1);
			Mat dst_img_rsize(DST_IMG_WIDTH, SRC_IMG_HEIGH, src_img.type());
			resize(src_img, dst_img_rsize, dst_img_rsize.size(), 0, 0, INTER_LINEAR);
			dst_img_name += to_string(i);//ת����ͼ��������ʽΪ�����ϣ�5_s6n.bmp
			dst_img_name += ".jpg";
			imwrite(dst_img_name, dst_img_rsize);
			src_img_name = "C:\\Users\\�ֿ���\\Desktop\\object-detection\\origin\\", dst_img_name = "C:\\Users\\�ֿ���\\Desktop\\object-detection\\after\\";//ÿ��ѭ����Ҫ������0�ַ������ڵ����ݣ�Ŀ���ļ���һ��Ҫ���Ƚ�����������Ч��
	}
	return 0;
}
