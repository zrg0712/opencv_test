#include <iostream>
using namespace std;
/*
���󹤳�ģʽ
1. �����Ʒ��
2. �����Ʒ��
3. �����Ʒ��
4. ���󹤳���
5. ���幤����
*/

//----�������̺����----

//�����Ʒ�ࣺ �����˲�Ʒ���е�ҵ�񷽷�
class AbstractProduct
{
public:
	virtual ~AbstractProduct() {}
	virtual void MakeProduct() = 0;
};

//1. ����
//�����Ʒ��
class KeyBoard :public AbstractProduct {};

//�����Ʒ�ࣺʵ�ֲ�Ʒ�ľ��巽��
class LogiKeyBoard :public KeyBoard
{
public:
	~LogiKeyBoard() {}
	void MakeProduct()override
	{
		cout << "�޼�����" << endl;
	}
};
class RazerKeyBoard :public KeyBoard
{
public:
	~RazerKeyBoard() {}
	void MakeProduct()override
	{
		cout << "���߼���" << endl;
	}
};

//2. ���
//�����Ʒ��
class Mouse :public AbstractProduct {};

//�����Ʒ��
class LogiMouse :public Mouse
{
public:
	~LogiMouse() {}
	void MakeProduct()override
	{
		cout << "�޼����" << endl;
	}
};
class RazerMouse :public Mouse
{
public:
	~RazerMouse() {}
	void MakeProduct()override
	{
		cout << "�������" << endl;
	}
};

/*
//TODO���ڴ������µĲ�Ʒ��������Ʒ��...
//
//*/

//���󹤳���: �����ṩ����ÿһ���Ʒ�ķ���
class AbstractFactory
{
public:
	virtual ~AbstractFactory() {}
	virtual KeyBoard* CreateKeyBoard() = 0;
	virtual Mouse* CreateMouse() = 0;
	//TODO: �ṩÿһ����Ʒ��Ĵ�������...
};

//���幤���ࣺʵ�ִ�����Ʒ�ķ���
//1. �޼�����
class LogiFactory :public AbstractFactory
{
public:
	~LogiFactory() {}
	KeyBoard* CreateKeyBoard()override
	{
		return new LogiKeyBoard;
	}
	Mouse* CreateMouse()override
	{
		return new LogiMouse;
	}
};
//2. ���߹���
class RazerFactory :public AbstractFactory
{
public:
	~RazerFactory() {}
	KeyBoard* CreateKeyBoard()override
	{
		return new RazerKeyBoard;
	}
	Mouse* CreateMouse()override
	{
		return new RazerMouse;
	}
};

//int main()
//{
//	AbstractFactory* Factory = new RazerFactory;
//	KeyBoard* keyBoard = Factory->CreateKeyBoard();
//	Mouse* mouse = Factory->CreateMouse();
//	keyBoard->MakeProduct();
//	mouse->MakeProduct();
//
//	delete Factory;
//	delete keyBoard;
//	delete mouse;
//
//	Factory = new LogiFactory;
//	keyBoard = Factory->CreateKeyBoard();
//	mouse = Factory->CreateMouse();
//	keyBoard->MakeProduct();
//	mouse->MakeProduct();
//
//	delete Factory;
//	delete keyBoard;
//	delete mouse;
//	Factory = nullptr;
//	keyBoard = nullptr;
//	mouse = nullptr;
//	return 0;
//}