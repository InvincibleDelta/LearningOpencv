#pragma once
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

extern int g_slider_position;//��ʾ��������λ��
extern int g_run;//������ʾֹͣ����֮ǰҪ���ŵ�ͼƬ������������ʾ������Ƶ����ģʽ
extern int g_dontset;//������λ��ʱ������ֹ���뵥��ģʽ
static cv::Mat g_src;//�洢ͼ��ṹ
static cv::VideoCapture g_cap;//�洢֡�ṹ

//�򿪲���ʾͼƬ
int openimg(const cv::String& path, const cv::String& windowname);
//����Ƶ����֡��ʾ
int openvdo(const cv::String& path, const cv::String& windowname);
//�ص�����
void onTrackbarSlide(int pos, void*);
