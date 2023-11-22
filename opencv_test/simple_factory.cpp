#include <iostream>

using namespace std;

/*
造飞机造火箭
*/

/*----------------
1. 抽象产品类
----------------*/
class AbstractProduct
{
public:
	virtual ~AbstractProduct() {}
	virtual void MakeProduct() = 0;
};
/*----------------
2. 具体产品类
----------------*/

//2.1. 飞机产品类
class PlaneProduct :public AbstractProduct
{
public:
	~PlaneProduct() {}
	void MakeProduct()override
	{
		cout << "飞机产品" << endl;
	}
};
//2.2. 火箭产品类
class RocketProduct :public AbstractProduct
{
public:
	~RocketProduct() {}
	void MakeProduct()override
	{
		cout << "火箭产品" << endl;
	}
};
/*----------------
3. 具体工厂类：负责创建每一个实例产品对象
----------------*/
class Factory
{
public:
	//一个枚举，根据这个枚举的种类来决定你要创建哪个对象
	enum class ProductType { Plane, Rocket };
	static AbstractProduct* CreateProduct(ProductType type)
	{
		switch (type)
		{
			//创建飞机类
		case Factory::ProductType::Plane:
			return new PlaneProduct;
			//创建火箭类
		case Factory::ProductType::Rocket:
			return new RocketProduct;
		}
	}
};

//int main()
//{
//	//1. 工厂创建产品
//	AbstractProduct* Plane = Factory::CreateProduct(Factory::ProductType::Plane);
//	//2. 使用产品
//	Plane->MakeProduct();
//
//	AbstractProduct* Rocket = Factory::CreateProduct(Factory::ProductType::Rocket);
//	Rocket->MakeProduct();
//	delete Plane;
//	delete Rocket;
//	
//	return 0;
//}