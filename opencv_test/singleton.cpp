//#include <iostream>
//
//using namespace std;
//
//class Singleton
//{
//private:
//	static Singleton* m_pInstance;  // 静态成员变量，类内声明类外初始化
//	Singleton() {  // 放在private中，禁止用户自己声明并定义实例
//		cout << "constructor called!" << endl;
//	}
//	// 使用=delete禁止复制构造函数和复制赋值运算符
//	Singleton(Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//public:
//	~Singleton()
//	{
//		cout << "destructor called!" << endl;
//	}
//	static Singleton* getInstace()  // 静态成员函数，无法访问属于类对象的非静态数据成员，只能调用和访问其余的静态成员函数和属性
//	{
//		if (m_pInstance == nullptr)
//		{
//			m_pInstance = new Singleton;
//		}
//		return m_pInstance;
//	}
//};
//
//Singleton* Singleton::m_pInstance = nullptr;  // 使用静态变量控制该对象实例只有一个
//
//void test()
//{
//
//	Singleton* instance1 = Singleton::getInstace();
//	Singleton* instance2 = Singleton::getInstace();
//}
//
//
//int main()
//{
//	/*懒汉式(Lazy-Initialization)的方法是直到使用时才实例化对象，
//	也就说直到调用geInstance() 方法的时候才 new 一个单例的对象。
//	好处是如果被调用就不会占用内存。*/
//	//Singleton* instance1 = Singleton::getInstace();
//	//Singleton* instance2 = Singleton::getInstace();
//	return 0;
//}