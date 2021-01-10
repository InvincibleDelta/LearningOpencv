#include "img_trans.h"

void smooth(const cv::String& path)
{
	cv::Mat in;
	in = cv::imread(path);
	//����������������
	cv::namedWindow("smooth-in",cv::WINDOW_AUTOSIZE);
	cv::namedWindow("smooth-out", cv::WINDOW_AUTOSIZE);
	
	//��ʾ����ͼ��
	cv::imshow("smooth-in", in);

	//�����洢���ͼ��
	cv::Mat out;

	//����ƽ������
	//����ʹ�� GaussianBlur(), blur(), medianBlur(), bilateralFliter()
	cv::GaussianBlur(in, out, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

	//�����������չʾƽ��ͼ��
	cv::imshow("smooth-out", out);

	//�ȴ������¼������ڽ��Զ�����
	cv::waitKey(0);
}

void halfsize(const cv::String& path)
{
	cv::Mat in;
	cv::Mat out;

	in = cv::imread(path);
	//ʹ��cv::pyrDown������һ����ͼ�񣬳���Ϊԭ��һ��
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
	
	//ת��Ϊ�Ҷ�ͼ
	cv::cvtColor(rgb_in, gray_out, cv::COLOR_BGR2GRAY);
	//ת��Ϊ��Եͼ
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

	//�õ�����ֵ
	cv::Vec3b indensity = in.at<cv::Vec3b>(y, x);

	uchar blue = indensity[0];
	uchar green = indensity[1];
	uchar red = indensity[2];

	std::cout << "At(x,y)=(" << x << "," << y << "):(blue, green, red)=(" << (unsigned int)blue << "," << (unsigned int)green << "," << (unsigned int)red << ")" << std::endl;
	std::cout << "Gray pixel there is:" << (unsigned int)in.at<uchar>(y, x) << std::endl;
}


