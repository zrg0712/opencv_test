//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace std;
//
//static cv::Scalar randomColor(cv::RNG& rng)  // 产生一个颜色
//{
//	int icolor = (unsigned)rng; // 产生一个随机数
//	cout << icolor << endl;
//	cout << (icolor & 255) << endl;
//	cout << ((icolor >> 8) & 255) << endl;
//	cout << ((icolor >> 16) & 255) << endl;
//	return cv::Scalar(icolor & 255, (icolor >> 8) & 255, (icolor >> 16) & 255);
//}
//
//int main()
//{
//	cv::RNG rng(0x00000101);
//	//cv::RNG rng(0xFFFFFFFF);
//
//	auto x = randomColor(rng);
//}