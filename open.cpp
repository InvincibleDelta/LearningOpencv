#include "open.h"

int g_slider_position = 0;//表示滑动条的位置
int g_run = 1;//正数表示停止程序之前要播放的图片数量，负数表示连续视频播放模式
int g_dontset = 0;//单击新位置时用来防止进入单步模式


void onTrackbarSlide(int pos, void*)//用来更改滑动条位置的回调函数
{
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);//调整位置
	if (!g_dontset)
	{
		g_run = 1;
	}
	g_dontset = 0;
}


int openimg(const cv::String& path, const cv::String& windowname)
{
	g_src = cv::imread(path);//载入图像
	if (g_src.empty())//判空
	{
		printf("can't load the image...\n");
		return 0;
	}
	cv::namedWindow(windowname, cv::WINDOW_AUTOSIZE);//打开窗口
	cv::imshow(windowname, g_src);//绘制图像
	cv::waitKey(0);//暂停程序并等待键盘事件，等待正数毫秒数，若参数<=0，则无限等待直到有键被按下
	cv::destroyWindow(windowname);
	return 1;
}

int openvdo(const cv::String& path, const cv::String& windowname)
{
	g_cap.open(path);//打开视频文件
	cv::namedWindow(windowname, cv::WINDOW_AUTOSIZE);//打开窗口
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
	std::cout << "Vedio has " << frames << " frames of dimensions(" << tmpw << "," << tmph << ")." << std::endl;
	cv::createTrackbar("Position", windowname, &g_slider_position, frames, onTrackbarSlide);//创建滑动条
	cv::Mat frame;//用来保存视频帧
	while (1)
	{
		if (g_run)
		{
			g_cap >> frame;
			if (frame.empty())break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
			g_dontset = 1;
			cv::setTrackbarPos("Position", windowname, current_pos);//滑动条新的位置
			cv::imshow(windowname, frame);
			if (cv::waitKey(33) >= 0)break;
			--g_run;//剩下的帧数
		}
		char c = (char)cv::waitKey(10);
		if (c == 's')
		{
			g_run = 1;
			std::cout << "Simple step, run = " << g_run << std::endl;
		}
		if (c == 'r')
		{
			g_run = -1;
			std::cout << "Run mode, run = " << g_run << std::endl;
		}
		if (c == 27)break;
	}
	return 0;
}

