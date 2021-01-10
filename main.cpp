#include<iostream>
#include"open.h"
#include"img_trans.h"
#define IMG_PATH "E:\\lena.jpg"
#define VDO_PATH "E:\\naruto.mp4"
using namespace cv;

int main()
{
	//openvdo(VDO_PATH,"video");
	//openimg(IMG_PATH, "lena");
	//smooth(IMG_PATH);
	//halfsize(IMG_PATH);
	canny(IMG_PATH);
	//pixelvalue(IMG_PATH,0,0);

	return 0;
}