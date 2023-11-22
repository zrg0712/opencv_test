//#include <iostream>
//#include <memory>
//#include <mutex>
//
//using namespace std;
//
//class Singleton
//{
//public:
//	//using Ptr = std::shared_ptr<Singleton>;
//	~Singleton()
//	{
//		cout << "destructor called!" << endl;
//	}
//	Singleton(Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//
//	static shared_ptr<Singleton> getInstance()
//	{
//		if (m_pInstance == nullptr) {
//			std::lock_guard<std::mutex> lk(m_mutex);
//
//			if (m_pInstance == nullptr) {
//				m_pInstance = std::shared_ptr<Singleton>(new Singleton);
//			}
//		}
//
//		return m_pInstance;
//
//	}
//private:
//	Singleton()
//	{
//		cout << "constructor called!" << endl;
//	}
//	static shared_ptr<Singleton> m_pInstance;
//	static mutex m_mutex;
//};
//
//shared_ptr<Singleton> Singleton::m_pInstance = nullptr;
//mutex Singleton::m_mutex;
//
//int main() {
//	shared_ptr<Singleton> instance1 = Singleton::getInstance();
//	shared_ptr<Singleton> instance2 = Singleton::getInstance();
//
//	return 0;
//}
//
