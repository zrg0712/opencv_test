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
//	//  颜色空间缩减
//	uchar table[256];
//	for (int i = 0; i < 256; ++i)
//		table[i] = divideWith * (i / divideWith);
//	/*
//	Mat方法：
//	OpenCV函数中输出图像的内存分配是自动完成的（如果不特别指定的话）。
//	使用OpenCV的C++接口时不需要考虑内存释放问题。
//	赋值运算符和拷贝构造函数（ ctor ）只拷贝信息头。
//	使用函数 clone() 或者 copyTo() 来拷贝一副图像的矩阵。
//	*/
//	// ABC指向同一个对象
//	// 最后一个使用它的对象负责清理，通过引用计数机制来实现，使用clone()、copyTo()拷贝本身
//	cv::Mat A, C;  // 创建信息头部分
//	A = cv::imread(argv[1], 1);
//	cv::Mat B(A); // 使用拷贝构造函数
//	C = A; // 赋值运算
//
//	// 想要创建一个感兴趣区域（ ROI ），只需要创建包含边界信息的信息头
//	cv::Mat D(A, cv::Rect(10, 10, 100, 100));  // 创建ROI
//
//	// clone()、copyTo()，现在改变F或者G不会影响A信息头所指向的矩阵
//	cv::Mat F = A.clone();
//	cv::Mat G;
//	A.copyTo(G);
//
//	// ---------------------------------------------------- //
//	// 存储方法：指定颜色空间和数据类型
//	//cv::imwrite("./images/Gray_Image.jpg", A); // 保存图像
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
//	// OpenCV支持使用运算符<<来打印其它常用OpenCV数据结构。
//	// 2维点
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
//	计时
//	OpenCV提供了两个简便的可用于计时的函数 getTickCount() 和 getTickFrequency() 。
//	第一个函数返回你的CPU自某个事件（如启动电脑）以来走过的时钟周期数，第二个函数返回你的CPU一秒钟所走的时钟周期数。
//	*/
//	//double t = (double)cv::getTickCount();
//	//// do something ...
//	//t = ((double)cv::getTickCount() - t) / cv::getTickFrequency();
//	//cout << "Times passed in seconds: " << t << endl;
//
//	/*
//	连续存储有助于提升图像扫描速度，我们可以使用 isContinuous() 来去判断矩阵是否是连续存储的.
//
//	*/
//	image_show(A);
//	cv::Mat test = ScanImageAndReduceC(A, table);
//	image_show(test);
//}