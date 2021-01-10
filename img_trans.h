#pragma once
#include<opencv2/opencv.hpp>
#include<iostream>

void smooth(const cv::String& path);//高斯模糊

void halfsize(const cv::String& path);//输出长宽为原来1/2新图像

void canny(const cv::String& path);//canny边缘检测器输出一个单通道（灰度）图像

void pixelvalue(const cv::String& path, int x, int y);//获取像素值