//#include <opencv2/opencv.hpp>
//#include <iostream>
//#include <vector>
//#include <assert.h>
//#include <onnxruntime_cxx_api.h>
//
//using namespace std;
//using namespace cv;
//
////void img_show(Mat& src);
////
////void colorSpace(Mat& image)
////{
////	Mat gray, hsv;
////	cvtColor(image, hsv, COLOR_BGR2HSV);
////	cvtColor(image, gray, COLOR_BGR2GRAY);
////	imwrite("hsv.jpg", hsv);
////	imwrite("gray.jpg", gray);
////}
////
////void mat_operat(Mat& image)
////{
////	Mat m1, m2;
////	m1 = image.clone();
////	image.copyTo(m2);
////
////	Mat m3 = Mat::ones(Size(400, 400), CV_8UC3);
////	m3 = Scalar(255, 0, 0);
////	//img_show(m3);
////	std::cout << "width: " << m3.cols << " height: " << m3.rows << " channels: " << m3.channels() << std::endl;
////	Mat m4;
////	m3.copyTo(m4);
////	m4 = Scalar(0, 255, 255);
////	img_show(m3);
////	img_show(m4);
////}
////
////void pixel_visit(Mat& image)
////{
////	int dims = image.channels();
////	int h = image.rows;
////	int w = image.cols;
////	for (int row = 0; row < h; row++)
////	{
////		for (int col = 0; col < w; col++)
////		{
////			if (dims == 1)
////			{
////				int pv = image.at<uchar>(row, col);
////				image.at<uchar>(row, col) = 255 - pv;
////			}
////			else
////			{
////				cv::Vec3b bgr = image.at<Vec3b>(row, col);
////				image.at<Vec3b>(row, col)[0] = 255 - bgr[0];
////				image.at<Vec3b>(row, col)[1] = 255 - bgr[1];
////				image.at<Vec3b>(row, col)[2] = 255 - bgr[2];
////			}
////		}
////	}
////	img_show(image);
////}
////
////void pixel_visit_point(Mat& image)
////{
////	int dim = image.channels();
////	int h = image.rows;
////	int w = image.cols;
////	for (int row = 0; row < h; row++)
////	{
////		uchar* cur = image.ptr<uchar>(row);
////
////		for (int col = 0; col < w; col++)
////		{
////			if (dim == 1)
////			{
////				int pv = *cur;
////				*cur = 255 - pv;
////				cur++;
////			}
////			else
////			{
////				*cur = 255 - *cur; //指针每做一次运算，就向后移动一位
////				cur++;
////				*cur = 255 - *cur;
////				cur++;
////				*cur = 255 - *cur;
////				cur++;
////				
////			}
////		}
////	}
////	img_show(image);
////}
////
////void pixel_operator(Mat& image)
////{
////	Mat dst = Mat::zeros(image.size(), image.type());
////	Mat m = Mat::zeros(image.size(), image.type());
////	dst = image - Scalar(50, 50, 50);
////	m = Scalar(50, 50, 50);
////	img_show(dst);
////	multiply(image, m, dst);
////	img_show(dst);
////}
////
////void img_show(Mat& src)
////{
////	imshow("img", src);
////	waitKey(0);
////	destroyAllWindows();
////}
//
//int main(int argc, char* argv[])
//{
//	Ort::Env env(ORT_LOGGING_LEVEL_WARNING, "test");
//	Ort::SessionOptions session_options;
//	session_options.SetIntraOpNumThreads(1);
//	session_options.SetGraphOptimizationLevel(GraphOptimizationLevel::ORT_ENABLE_EXTENDED);
//
//
//	//#ifdef _WIN32
//	const wchar_t* model_path = L"mobileNet.onnx";  
//	//#else
//	//	const char* model_path = "model.onnx";
//	//#endif
//	Ort::Session session(env, model_path, session_options);
//	Ort::AllocatorWithDefaultOptions allocator;
//
//	// print number of model input nodes
//	size_t num_input_nodels = session.GetInputCount();  
//
//	std::vector<const char*> input_node_names = { "input","input_mask" };
//	std::vector<const char*> output_node_names = { "output","output_mask" };
//
//	std::vector<int64_t> input_node_dims = { 10, 20 };
//	size_t input_tensor_size = 10 * 20;
//	std::vector<float> input_tensor_values(input_tensor_size);
//	for (unsigned int i = 0; i < input_tensor_size; i++)
//		input_tensor_values[i] = (float)i / (input_tensor_size + 1);
//	// create input tensor object from data values
//	auto memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
//	Ort::Value input_tensor = Ort::Value::CreateTensor<float>(memory_info, input_tensor_values.data(), input_tensor_size, input_node_dims.data(), 2);
//	assert(input_tensor.IsTensor());
//
//	std::vector<int64_t> input_mask_node_dims = { 1, 20, 4 };
//	size_t input_mask_tensor_size = 1 * 20 * 4;
//	std::vector<float> input_mask_tensor_values(input_mask_tensor_size);
//	for (unsigned int i = 0; i < input_mask_tensor_size; i++)
//		input_mask_tensor_values[i] = (float)i / (input_mask_tensor_size + 1);
//	// create input tensor object from data values
//	auto mask_memory_info = Ort::MemoryInfo::CreateCpu(OrtArenaAllocator, OrtMemTypeDefault);
//	Ort::Value input_mask_tensor = Ort::Value::CreateTensor<float>(mask_memory_info, input_mask_tensor_values.data(), input_mask_tensor_size, input_mask_node_dims.data(), 3);
//	assert(input_mask_tensor.IsTensor());
//
//	std::vector<Ort::Value> ort_inputs;
//	ort_inputs.push_back(std::move(input_tensor));
//	ort_inputs.push_back(std::move(input_mask_tensor));
//	// score model & input tensor, get back output tensor
//	auto output_tensors = session.Run(Ort::RunOptions{ nullptr }, input_node_names.data(), ort_inputs.data(), ort_inputs.size(), output_node_names.data(), 2);
//
//	// Get pointer to output tensor float values
//	float* floatarr = output_tensors[0].GetTensorMutableData<float>();
//	float* floatarr_mask = output_tensors[1].GetTensorMutableData<float>();
//
//	printf("Done!\n");
//
//
//
//
//
//	//Mat src = imread(argv[1], IMREAD_COLOR);
//	////Mat src = imread("test.jpg");
//	//if (src.empty())
//	//{
//	//	cout << "could not load image" << endl;
//	//}
//
//	return 0;
//}