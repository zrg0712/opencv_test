//#include <opencv2/opencv.hpp>
//#include <string>
//#include <iostream>
//
//using namespace std;
//
//
//int main(int argc, char* argv[])
//{
//	double alpha = 0.2;
//	double beta;
//
//	cv::Mat src1, src2, dst;
//	src1 = cv::imread(argv[1]);
//	src2 = cv::imread(argv[2]);
//	cv::resize(src2, src2, cv::Size(1440, 900));
//	if (!src1.data) { cout << "Error loading src1" << endl; }
//	if (!src2.data) { cout << "Error loading src2" << endl; }
//	cout << src1.rows << " " << src1.cols << endl;
//	cout << src2.rows << " " << src2.cols << endl;
//	cv::namedWindow("Linear Blend", 1);
//	beta = (1.0 - alpha);
//	cv::addWeighted(src1, alpha, src2, beta, 0.0, dst);
//	cv::imshow("Linear Blend", dst);
//	cv::waitKey(0);
//	cv::destroyAllWindows();
//
//	return 0;
//}