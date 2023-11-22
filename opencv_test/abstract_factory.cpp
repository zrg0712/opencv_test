#include <iostream>
using namespace std;
/*
抽象工厂模式
1. 抽象产品类
2. 抽象产品族
3. 具体产品类
4. 抽象工厂类
5. 具体工厂类
*/

//----生产键盘和鼠标----

//抽象产品类： 声明了产品具有的业务方法
class AbstractProduct
{
public:
	virtual ~AbstractProduct() {}
	virtual void MakeProduct() = 0;
};

//1. 键盘
//抽象产品族
class KeyBoard :public AbstractProduct {};

//具体产品类：实现产品的具体方法
class LogiKeyBoard :public KeyBoard
{
public:
	~LogiKeyBoard() {}
	void MakeProduct()override
	{
		cout << "罗技键盘" << endl;
	}
};
class RazerKeyBoard :public KeyBoard
{
public:
	~RazerKeyBoard() {}
	void MakeProduct()override
	{
		cout << "雷蛇键盘" << endl;
	}
};

//2. 鼠标
//抽象产品族
class Mouse :public AbstractProduct {};

//具体产品类
class LogiMouse :public Mouse
{
public:
	~LogiMouse() {}
	void MakeProduct()override
	{
		cout << "罗技鼠标" << endl;
	}
};
class RazerMouse :public Mouse
{
public:
	~RazerMouse() {}
	void MakeProduct()override
	{
		cout << "雷蛇鼠标" << endl;
	}
};

/*
//TODO：在此增加新的产品族与具体产品类...
//
//*/

//抽象工厂类: 声明提供创建每一族产品的方法
class AbstractFactory
{
public:
	virtual ~AbstractFactory() {}
	virtual KeyBoard* CreateKeyBoard() = 0;
	virtual Mouse* CreateMouse() = 0;
	//TODO: 提供每一个产品族的创建方法...
};

//具体工厂类：实现创建产品的方法
//1. 罗技工厂
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
//2. 雷蛇工厂
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