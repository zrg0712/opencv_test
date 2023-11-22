//#include <iostream>
//#include <opencv2/opencv.hpp>
//
//using namespace std;
//
//void display(cv::Mat& img)
//{
//	cv::imshow("img-show", img);
//	cv::waitKey(0);
//	cv::destroyAllWindows();
//}
//
//void MyEllipse(cv::Mat img, double angle)
//{
//	int thickness = -1;
//	int lineType = 8;
//	cv::ellipse(img, cv::Point(100, 100), cv::Size(50, 25), angle, 0, 360, cv::Scalar(255, 0, 0), thickness, lineType);
//	display(img);
//}
//
//void MyLine(cv::Mat img, cv::Point start, cv::Point end)
//{
//	int thickness = 2;
//	int lineType = 8;
//	cv::line(img, start, end, cv::Scalar(0, 0, 255), thickness, lineType);
//	display(img);
//}
//
//void MyFilledCircle(cv::Mat img, cv::Point center)
//{
//	int thickness = -1;  // -1 表示被填充
//	int lineType = 8;
//
//	circle(img,
//		center,
//		200 / 32.0,
//		cv::Scalar(0, 0, 255),
//		thickness,
//		lineType);
//}
//
//int main(int argc, char* argv[])
//{
//	cv::Point pt(10, 20);  // 构造函数方法
//	pt.x = 15;  // 赋值法
//	pt.y = 25;
//	cout << pt << endl;
//
//	char atom_window[] = "Drawing 1:Atom";
//	char rook_window[] = "Drawing 2:Rook";
//
//	cv::Mat atom_image = cv::Mat::zeros(200, 200, CV_8UC3);
//	cv::Mat rook_image = cv::Mat::zeros(200, 200, CV_8UC3);
//	//MyLine(atom_image.clone(), cv::Point(10, 10), cv::Point(150, 180));
//	//MyEllipse(rook_image.clone(), 30);
//
//	cv::rectangle(rook_image,
//		cv::Point(0, 3 * 200 / 8.0),
//		cv::Point(200, 200),
//		cv::Scalar(0, 255, 255),
//		-1,
//		8);
//	display(rook_image);
//	return 0;
//}