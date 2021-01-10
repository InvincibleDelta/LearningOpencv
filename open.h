#pragma once
#include<opencv2/opencv.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

extern int g_slider_position;//表示滑动条的位置
extern int g_run;//正数表示停止程序之前要播放的图片数量，负数表示连续视频播放模式
extern int g_dontset;//单击新位置时用来防止进入单步模式
static cv::Mat g_src;//存储图像结构
static cv::VideoCapture g_cap;//存储帧结构

//打开并显示图片
int openimg(const cv::String& path, const cv::String& windowname);
//打开视频并逐帧显示
int openvdo(const cv::String& path, const cv::String& windowname);
//回调函数
void onTrackbarSlide(int pos, void*);
