//#include <iostream>
//#include <opencv2/opencv.hpp>
//
//using namespace std;
//
//double alpha;
//int beta;
//
//void display(cv::Mat& img)
//{
//	cv::imshow("img-show", img);
//	cv::waitKey(0);
//	cv::destroyAllWindows();
//}
//
//int main(int argc, char* argv[])
//{
//	cout << "plz input alpha in [0.1,1)" << endl;
//	cin >> alpha;
//	cout << "plz input beta in int class [1,100]" << endl;
//	cin >> beta;
//	cv::Mat image = cv::imread(argv[1]);
//	cv::Mat new_image = cv::Mat::zeros(image.size(), image.type());
//	cout << image.size() << endl;
//	cout << image.type() << endl;
//	for (int y = 0; y < image.rows; y++)
//	{
//		for (int x = 0; x < image.cols; x++)
//		{
//			for (int c = 0; c < 3; c++)
//			{
//				new_image.at<cv::Vec3b>(y, x)[c] = cv::saturate_cast<uchar>(alpha * (image.at<cv::Vec3b>(y, x)[c]) + beta);
//			}
//		}
//	}
//	image.convertTo(new_image, -1, alpha, beta); // ·½·¨¶þ
//	display(image);
//	display(new_image);
//
//
//	return 0;
//}