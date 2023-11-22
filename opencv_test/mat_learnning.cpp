//#include <opencv2/opencv.hpp>
//#include <iostream>
//
//using namespace std;
//
//void image_show(cv::Mat& img)
//{
//	cv::namedWindow("image show", cv::WINDOW_AUTOSIZE);
//	cv::imshow("image show", img);
//	cv::waitKey(0);
//	cv::destroyAllWindows();
//}
//
//cv::Mat& ScanImageAndReduceIterator(cv::Mat& I, const uchar* const table)
//{
//	// accept only char type matrices
//	CV_Assert(I.depth() != sizeof(uchar));
//
//	const int channels = I.channels();
//	switch (channels)
//	{
//	case 1:
//	{
//		cv::MatIterator_<uchar> it, end;
//		for (it = I.begin<uchar>(), end = I.end<uchar>(); it != end; ++it)
//			*it = table[*it];
//		break;
//	}
//	case 3:
//	{
//		cv::MatIterator_<cv::Vec3b> it, end;
//		for (it = I.begin<cv::Vec3b>(), end = I.end<cv::Vec3b>(); it != end; ++it)
//		{
//			(*it)[0] = table[(*it)[0]];
//			(*it)[1] = table[(*it)[1]];
//			(*it)[2] = table[(*it)[2]];
//		}
//	}
//	}
//
//	return I;
//}
//
//cv::Mat& ScanImageAndReduceC(cv::Mat& I, const uchar* const table)
//{
//	// accept only char type matrices
//	CV_Assert(I.depth() != sizeof(uchar));
//
//	int channels = I.channels();
//	int nRows = I.rows * channels;
//	int nCols = I.cols;
//	if (I.isContinuous())
//	{
//		nCols = nCols * nRows;
//		nRows = 1;
//	}
//
//	int i, j;
//	uchar* p;
//	for (i = 0; i < nRows; ++i)
//	{
//		p = I.ptr<uchar>(i);
//		for (j = 0; j < nCols; ++j)
//		{
//			p[j] = table[p[j]];
//		}
//	}
//	return I;
//
//}
//
//int main(int argc, char* argv[])
//{
//
//	int divideWith = 10; // convert our input string to number - C++ style
//	//  ��ɫ�ռ�����
//	uchar table[256];
//	for (int i = 0; i < 256; ++i)
//		table[i] = divideWith * (i / divideWith);
//	/*
//	Mat������
//	OpenCV���������ͼ����ڴ�������Զ���ɵģ�������ر�ָ���Ļ�����
//	ʹ��OpenCV��C++�ӿ�ʱ����Ҫ�����ڴ��ͷ����⡣
//	��ֵ������Ϳ������캯���� ctor ��ֻ������Ϣͷ��
//	ʹ�ú��� clone() ���� copyTo() ������һ��ͼ��ľ���
//	*/
//	// ABCָ��ͬһ������
//	// ���һ��ʹ�����Ķ���������ͨ�����ü���������ʵ�֣�ʹ��clone()��copyTo()��������
//	cv::Mat A, C;  // ������Ϣͷ����
//	A = cv::imread(argv[1], 1);
//	cv::Mat B(A); // ʹ�ÿ������캯��
//	C = A; // ��ֵ����
//
//	// ��Ҫ����һ������Ȥ���� ROI ����ֻ��Ҫ���������߽���Ϣ����Ϣͷ
//	cv::Mat D(A, cv::Rect(10, 10, 100, 100));  // ����ROI
//
//	// clone()��copyTo()�����ڸı�F����G����Ӱ��A��Ϣͷ��ָ��ľ���
//	cv::Mat F = A.clone();
//	cv::Mat G;
//	A.copyTo(G);
//
//	// ---------------------------------------------------- //
//	// �洢������ָ����ɫ�ռ����������
//	//cv::imwrite("./images/Gray_Image.jpg", A); // ����ͼ��
//
//	// display image
//	//cv::namedWindow("image show", cv::WINDOW_AUTOSIZE);
//	//cv::imshow("image show", A);
//	//cv::waitKey(0);
//	//cv::destroyAllWindows();
//
//	//// <<: only is useful to two-dimensional matrix
//	////cout << "A= " << A << endl;
//	//cv::Mat M(2, 2, CV_8UC3, cv::Scalar(0, 0, 255)); // customize the image
//	//// CV_[The number of bits per item][Signed or Unsigned][Type Prefix]C[The channel number]
//	////image_show(M);
//	//cout << "M= " << M << endl;
//
//
//	// print iamge message
//	//cv::Mat R = cv::Mat(3, 2, CV_8UC3); 
//	//cv::randu(R, cv::Scalar::all(0), cv::Scalar::all(255));  // random initialization
//	//// print method
//	//cout << "R(default) = " << endl << R << endl;
//	//cout << "R(python) = " << endl << cv::format(R, cv::Formatter::FMT_PYTHON) << endl;
//	//cout << "R(numpy) = " << endl << cv::format(R, cv::Formatter::FMT_NUMPY) << endl;
//
//
//	// OpenCV֧��ʹ�������<<����ӡ��������OpenCV���ݽṹ��
//	// 2ά��
//	//cv::Point2f P(5, 1);
//	//cout << "Point(2D) = " << P << endl;
//
//	//cv::Point3f P3f(2, 6, 7);
//	//cout << "Point (3D) = " << P3f << endl << endl;
//
//	//vector<float> v;
//	//v.push_back((float)CV_PI);   v.push_back(2);    v.push_back(3.01f);
//	//cout << "Vector of floats via Mat = " << cv::Mat(v) << endl << endl;
//
//	//vector<cv::Point2f> vPoints(20);
//	//for (size_t E = 0; E < vPoints.size(); ++E)
//	//	vPoints[E] = cv::Point2f((float)(E * 5), (float)(E % 7));
//	//cout << "A vector of 2D Points = " << vPoints << endl << endl;
//
//	/*
//	��ʱ
//	OpenCV�ṩ���������Ŀ����ڼ�ʱ�ĺ��� getTickCount() �� getTickFrequency() ��
//	��һ�������������CPU��ĳ���¼������������ԣ������߹���ʱ�����������ڶ��������������CPUһ�������ߵ�ʱ����������
//	*/
//	//double t = (double)cv::getTickCount();
//	//// do something ...
//	//t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
//	//cout << "Times passed in seconds: " << t << endl;
//
//	/*
//	�����洢����������ͼ��ɨ���ٶȣ����ǿ���ʹ�� isContinuous() ��ȥ�жϾ����Ƿ��������洢��.
//
//	*/
//	image_show(A);
//	cv::Mat test = ScanImageAndReduceC(A, table);
//	image_show(test);
//}