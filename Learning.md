positive examples



negative examples：arbitrary images of the same size



# 将图片切割到指定大小

```c++
// change_img_size.cpp : 定义控制台应用程序的入口点。
//
//#include "stdafx.h"//这句头文件一定要放在最上面，否则很容易报错

#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include <opencv2/objdetect.hpp>
#include <iostream>
#include <stdio.h>

using namespace cv;
using namespace std;

#define DST_IMG_WIDTH 24        //需要调整图片后的尺寸宽度
#define SRC_IMG_HEIGH 24        //需要调整图片后的尺寸高度

int main(int argc, char* argv[])
{
	Mat src_img;
	int i, j;
	string src_img_name = "C:\\Users\\林俊浩\\Desktop\\object-detection\\origin\\", dst_img_name = "C:\\Users\\林俊浩\\Desktop\\object-detection\\after\\";//源文件和目的文件的文件夹名字
	char chari[5], charj[5];//因为人脸数据不是很多，所以下标5足够用
	for (i = 1; i <= 8; i++)//15个人的人脸数据
	{
			src_img_name += to_string(i);//原图命名格式为，比如第5个人的第6张图，5_s6.bmp
			src_img_name += ".jpg";

			src_img = imread(src_img_name, 1);
			Mat dst_img_rsize(DST_IMG_WIDTH, SRC_IMG_HEIGH, src_img.type());
			resize(src_img, dst_img_rsize, dst_img_rsize.size(), 0, 0, INTER_LINEAR);
			dst_img_name += to_string(i);//转换后图的命名格式为：例上，5_s6n.bmp
			dst_img_name += ".jpg";
			imwrite(dst_img_name, dst_img_rsize);
			src_img_name = "C:\\Users\\林俊浩\\Desktop\\object-detection\\origin\\", dst_img_name = "C:\\Users\\林俊浩\\Desktop\\object-detection\\after\\";//每次循环后要重新清0字符数组内的内容，目的文件夹一定要事先建立，否则无效果
	}
	return 0;
}
```

