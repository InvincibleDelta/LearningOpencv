#include "open.h"

int g_slider_position = 0;//��ʾ��������λ��
int g_run = 1;//������ʾֹͣ����֮ǰҪ���ŵ�ͼƬ������������ʾ������Ƶ����ģʽ
int g_dontset = 0;//������λ��ʱ������ֹ���뵥��ģʽ


void onTrackbarSlide(int pos, void*)//�������Ļ�����λ�õĻص�����
{
	g_cap.set(cv::CAP_PROP_POS_FRAMES, pos);//����λ��
	if (!g_dontset)
	{
		g_run = 1;
	}
	g_dontset = 0;
}


int openimg(const cv::String& path, const cv::String& windowname)
{
	g_src = cv::imread(path);//����ͼ��
	if (g_src.empty())//�п�
	{
		printf("can't load the image...\n");
		return 0;
	}
	cv::namedWindow(windowname, cv::WINDOW_AUTOSIZE);//�򿪴���
	cv::imshow(windowname, g_src);//����ͼ��
	cv::waitKey(0);//��ͣ���򲢵ȴ������¼����ȴ�������������������<=0�������޵ȴ�ֱ���м�������
	cv::destroyWindow(windowname);
	return 1;
}

int openvdo(const cv::String& path, const cv::String& windowname)
{
	g_cap.open(path);//����Ƶ�ļ�
	cv::namedWindow(windowname, cv::WINDOW_AUTOSIZE);//�򿪴���
	int frames = (int)g_cap.get(cv::CAP_PROP_FRAME_COUNT);
	int tmpw = (int)g_cap.get(cv::CAP_PROP_FRAME_WIDTH);
	int tmph = (int)g_cap.get(cv::CAP_PROP_FRAME_HEIGHT);
	std::cout << "Vedio has " << frames << " frames of dimensions(" << tmpw << "," << tmph << ")." << std::endl;
	cv::createTrackbar("Position", windowname, &g_slider_position, frames, onTrackbarSlide);//����������
	cv::Mat frame;//����������Ƶ֡
	while (1)
	{
		if (g_run)
		{
			g_cap >> frame;
			if (frame.empty())break;
			int current_pos = (int)g_cap.get(cv::CAP_PROP_POS_FRAMES);
			g_dontset = 1;
			cv::setTrackbarPos("Position", windowname, current_pos);//�������µ�λ��
			cv::imshow(windowname, frame);
			if (cv::waitKey(33) >= 0)break;
			--g_run;//ʣ�µ�֡��
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

