//#include <iostream>
//
//using namespace std;
//
//class Singleton
//{
//private:
//	static Singleton* m_pInstance;  // ��̬��Ա�������������������ʼ��
//	Singleton() {  // ����private�У���ֹ�û��Լ�����������ʵ��
//		cout << "constructor called!" << endl;
//	}
//	// ʹ��=delete��ֹ���ƹ��캯���͸��Ƹ�ֵ�����
//	Singleton(Singleton&) = delete;
//	Singleton& operator=(const Singleton&) = delete;
//public:
//	~Singleton()
//	{
//		cout << "destructor called!" << endl;
//	}
//	static Singleton* getInstace()  // ��̬��Ա�������޷��������������ķǾ�̬���ݳ�Ա��ֻ�ܵ��úͷ�������ľ�̬��Ա����������
//	{
//		if (m_pInstance == nullptr)
//		{
//			m_pInstance = new Singleton;
//		}
//		return m_pInstance;
//	}
//};
//
//Singleton* Singleton::m_pInstance = nullptr;  // ʹ�þ�̬�������Ƹö���ʵ��ֻ��һ��
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
//	/*����ʽ(Lazy-Initialization)�ķ�����ֱ��ʹ��ʱ��ʵ��������
//	Ҳ��˵ֱ������geInstance() ������ʱ��� new һ�������Ķ���
//	�ô�����������þͲ���ռ���ڴ档*/
//	//Singleton* instance1 = Singleton::getInstace();
//	//Singleton* instance2 = Singleton::getInstace();
//	return 0;
//}