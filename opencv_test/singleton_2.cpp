//#include <iostream>
//
//using namespace std;
//
//class Singleton
//{
//public:
//	~Singleton()
//	{
//		cout << "destructor called!" << endl;
//	}
//	Singleton(const Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static Singleton& getInstance()
//	{
//		static Singleton instance;
//		return instance;
//	}
//
//private:
//	Singleton()
//	{
//		cout << "constructor called!" << endl;
//	}
//};
//
//int main()
//{
//	Singleton& instance_1 = Singleton::getInstance();
//	Singleton& instance_2 = Singleton::getInstance();
//	return 0;
//}