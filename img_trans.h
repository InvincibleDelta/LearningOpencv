#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>

void smooth(const cv::String& path);//��˹ģ��

void halfsize(const cv::String& path);//�������Ϊԭ��1/2��ͼ��

void canny(const cv::String& path);//canny��Ե��������һ����ͨ�����Ҷȣ�ͼ��

void pixelvalue(const cv::String& path, int x, int y);//��ȡ����ֵ