#include <iostream>
using namespace std;

//造飞机造火箭

/*----------------
1. 抽象产品类
----------------*/
class AbstractProduct
{
public:
	virtual void MakeProduct() = 0;
};

/*----------------
2. 抽象工厂类
----------------*/
class AbstractFactory
{
public:
	virtual AbstractProduct* CreateProduct() = 0;
};

/*----------------
3. 具体产品类： 飞机
----------------*/
class PlaneProduct :public AbstractProduct
{
public:
	void MakeProduct()override
	{
		cout << "飞机产品" << endl;
	}
};
/*----------------
4. 具体工厂类：造飞机
----------------*/
class PlaneFactory :public AbstractFactory
{
public:
	AbstractProduct* CreateProduct()override
	{
		return new PlaneProduct;
	}
};

/*----------------
3. 具体产品类： 火箭
----------------*/
class RocketProduct :public AbstractProduct
{
public:
	void MakeProduct()override
	{
		cout << "火箭产品" << endl;
	}
};
/*----------------
4. 具体工厂类：造火箭
----------------*/
class RocketFactory :public AbstractFactory
{
public:
	AbstractProduct* CreateProduct()override
	{
		return new RocketProduct;
	}
};
int main()
{
	//1. 开设工厂（飞机，火箭）
	AbstractFactory* factory = new PlaneFactory;
	//2. 制造产品
	AbstractProduct* product = factory->CreateProduct();
	//3. 使用产品
	product->MakeProduct();

	factory = new RocketFactory;
	product = factory->CreateProduct();
	product->MakeProduct();
	
	return 0;
}