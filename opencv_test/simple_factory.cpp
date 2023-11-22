#include <iostream>

using namespace std;

/*
��ɻ�����
*/

/*----------------
1. �����Ʒ��
----------------*/
class AbstractProduct
{
public:
	virtual ~AbstractProduct() {}
	virtual void MakeProduct() = 0;
};
/*----------------
2. �����Ʒ��
----------------*/

//2.1. �ɻ���Ʒ��
class PlaneProduct :public AbstractProduct
{
public:
	~PlaneProduct() {}
	void MakeProduct()override
	{
		cout << "�ɻ���Ʒ" << endl;
	}
};
//2.2. �����Ʒ��
class RocketProduct :public AbstractProduct
{
public:
	~RocketProduct() {}
	void MakeProduct()override
	{
		cout << "�����Ʒ" << endl;
	}
};
/*----------------
3. ���幤���ࣺ���𴴽�ÿһ��ʵ����Ʒ����
----------------*/
class Factory
{
public:
	//һ��ö�٣��������ö�ٵ�������������Ҫ�����ĸ�����
	enum class ProductType { Plane, Rocket };
	static AbstractProduct* CreateProduct(ProductType type)
	{
		switch (type)
		{
			//�����ɻ���
		case Factory::ProductType::Plane:
			return new PlaneProduct;
			//���������
		case Factory::ProductType::Rocket:
			return new RocketProduct;
		}
	}
};

//int main()
//{
//	//1. ����������Ʒ
//	AbstractProduct* Plane = Factory::CreateProduct(Factory::ProductType::Plane);
//	//2. ʹ�ò�Ʒ
//	Plane->MakeProduct();
//
//	AbstractProduct* Rocket = Factory::CreateProduct(Factory::ProductType::Rocket);
//	Rocket->MakeProduct();
//	delete Plane;
//	delete Rocket;
//	
//	return 0;
//}