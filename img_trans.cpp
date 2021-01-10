#include "img_trans.h"

void smooth(const cv::String& path)
{
	cv::Mat in;
	in = cv::imread(path);
	//建立输入和输出窗口
	cv::namedWindow("smooth-in",cv::WINDOW_AUTOSIZE);
	cv::namedWindow("smooth-out", cv::WINDOW_AUTOSIZE);
	
	//显示输入图像
	cv::imshow("smooth-in", in);

	//用来存储输出图像
	cv::Mat out;

	//进行平滑处理
	//可以使用 GaussianBlur(), blur(), medianBlur(), bilateralFliter()
	cv::GaussianBlur(in, out, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

	//在输出窗口上展示平滑图像
	cv::imshow("smooth-out", out);

	//等待键盘事件，窗口将自动销毁
	cv::waitKey(0);
}

void halfsize(const cv::String& path)
{
	cv::Mat in;
	cv::Mat out;

	in = cv::imread(path);
	//使用cv::pyrDown来创建一个新图像，长宽为原来一半
	cv::pyrDown(in, out);

	cv::namedWindow("in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("out", cv::WINDOW_AUTOSIZE);
	cv::imshow("in", in);
	cv::imshow("out", out);
	cv::waitKey(0);
}

void canny(const cv::String& path)
{
	cv::Mat rgb_in, gray_out, cny_out;
	rgb_in = cv::imread(path);
	
	//转化为灰度图
	cv::cvtColor(rgb_in, gray_out, cv::COLOR_BGR2GRAY);
	//转化为边缘图
	cv::Canny(gray_out, cny_out, 10, 100, 3, true);

	cv::namedWindow("rgb_in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("gray_out", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("cny_out", cv::WINDOW_AUTOSIZE);

	cv::imshow("rgb_in", rgb_in);
	cv::imshow("gray_out", gray_out);
	cv::imshow("cny_out", cny_out);

	cv::waitKey(0);
}

void pixelvalue(const cv::String& path, int x, int y)
{
	cv::Mat in = cv::imread(path);

	//得到像素值
	cv::Vec3b indensity = in.at<cv::Vec3b>(y, x);

	uchar blue = indensity[0];
	uchar green = indensity[1];
	uchar red = indensity[2];

	std::cout << "At(x,y)=(" << x << "," << y << "):(blue, green, red)=(" << (unsigned int)blue << "," << (unsigned int)green << "," << (unsigned int)red << ")" << std::endl;
	std::cout << "Gray pixel there is:" << (unsigned int)in.at<uchar>(y, x) << std::endl;
}


