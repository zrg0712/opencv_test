////ʾ��1
//#include <iostream>
//#include <string>
//#include <memory>
//
//using namespace std;
//
////�߲���Խӿ�
//class Strategy
//{
//public:
//    virtual double CalcPrice(double  goodsPrice) { return 0; }
//};
//
////�������
////��ͨ�ͻ�����
//class NormalCustomerStrategy : public Strategy
//{
//public:
//    double CalcPrice(double  goodsPrice) override
//    {
//        //��ͨ�ͻ�û���ۿ�
//        std::cout << "��ͨ�ͻ�û���ۿ�" << std::endl;
//        return goodsPrice;
//    }
//};
//
////�Ͽͻ�����
//class OldCustomerStrategy : public Strategy
//{
//public:
//    double CalcPrice(double  goodsPrice) override
//    {
//        //�Ͽͻ� ͳһ�ۿ�5%
//        std::cout << "�Ͽͻ��ۿ�5%" << std::endl;
//        return goodsPrice * (1 - 0.05);
//    }
//};
//
////��ͻ�����
//class LargeCustomerStrategy : public Strategy
//{
//    double CalcPrice(double  goodsPrice) override
//    {
//        //��ͻ� ͳһ�ۿ�10%
//        std::cout << "��ͻ��ۿ�10%" << std::endl;
//        return goodsPrice * (1 - 0.1);
//    }
//};
//
//
////����������
//class Price
//{
//public:
//    Price(Strategy* strategy) : pStrategy(strategy) {}
//    double Quote(double goodsPrice)
//    {
//        if (pStrategy != nullptr)
//        {
//            return pStrategy->CalcPrice(goodsPrice);
//        }
//        return 0;
//    }
//private:
//    std::unique_ptr<Strategy> pStrategy{ nullptr };
//};
//
//int main()
//{
//    {
//        Price price(new NormalCustomerStrategy);
//        double goodsPrice = price.Quote(100);
//        std::cout << "��ͨ�ͻ����ռ�:" << goodsPrice << std::endl;
//    }
//
//    {
//        Price price(new OldCustomerStrategy);
//        double goodsPrice = price.Quote(100);
//        std::cout << "�Ͽͻ����ռ�:" << goodsPrice << std::endl;
//    }
//
//    {
//        Price price(new LargeCustomerStrategy);
//        double goodsPrice = price.Quote(100);
//        std::cout << "��ͻ����ռ�:" << goodsPrice << std::endl;
//    }
//
//    return 0;
//}
