#include <iostream>
using namespace std;

//��ɻ�����

/*----------------
1. �����Ʒ��
----------------*/
class AbstractProduct
{
public:
	virtual void MakeProduct() = 0;
};

/*----------------
2. ���󹤳���
----------------*/
class AbstractFactory
{
public:
	virtual AbstractProduct* CreateProduct() = 0;
};

/*----------------
3. �����Ʒ�ࣺ �ɻ�
----------------*/
class PlaneProduct :public AbstractProduct
{
public:
	void MakeProduct()override
	{
		cout << "�ɻ���Ʒ" << endl;
	}
};
/*----------------
4. ���幤���ࣺ��ɻ�
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
3. �����Ʒ�ࣺ ���
----------------*/
class RocketProduct :public AbstractProduct
{
public:
	void MakeProduct()override
	{
		cout << "�����Ʒ" << endl;
	}
};
/*----------------
4. ���幤���ࣺ����
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
	//1. ���蹤�����ɻ��������
	AbstractFactory* factory = new PlaneFactory;
	//2. �����Ʒ
	AbstractProduct* product = factory->CreateProduct();
	//3. ʹ�ò�Ʒ
	product->MakeProduct();

	factory = new RocketFactory;
	product = factory->CreateProduct();
	product->MakeProduct();
	
	return 0;
}