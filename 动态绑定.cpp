//#include <iostream>
//using namespace std;
//
////���������Ƕ�̬��
//
////����
//class Base
//{
//public:
//    virtual void f1()
//    {
//        cout << "base" << endl;
//    }
//};
////����1
//class Drived1 :public Base
//{
//public:
//    void f1()
//    {
//        cout << "Drived1" << endl;
//    }
//};
////����2
//class Drived2 :public Base
//{
//public:
//    void f1()
//    {
//        cout << "Drived2" << endl;
//    }
//};
//void Test(Base* pB)
//{
//    pB->f1();
//}
//int main()
//{
//    Base b;
//    Drived1 d1;
//    Drived2 d2;
//    //ָ����
//    Test(&b);
//    //ָ������1
//    Test(&d1);
//    //ָ������1
//    Test(&d2);
//    return 0;
//}




/////////////////////////////////////////////////////////
#include <iostream>
using namespace std;

class B
{
public:
    void DoSomething() {
        std::cout << "B::DoSomething()" << endl;
    }
    virtual void vfun() {
        std::cout << "B::vfun()" << endl;
    }
};

class D : public B
{
public:
    void DoSomething() {
        std::cout << "D::DoSomething()" << endl;
    }
    virtual void vfun() {
        std::cout << "D::vfun()" << endl;

    }
};

int main()
{
    //D* pd = new D();           //ָ�����ע�⾲̬���ͺͶ�̬����
    B * pb = new D();            //ָ��ע�⾲̬���ͺͶ�̬����
    //pd->DoSomething();         //��ͨ��Ա��������̬�󶨾�̬�����еķ���
    pb->DoSomething();        //��ͨ��Ա��������̬�󶨾�̬�����еķ���

    //pd->vfun();            //���Ա��������̬�󶨵���̬�����еķ���   virtualΪ��̬
    pb->vfun();              //���Ա��������̬�󶨵���̬�����еķ���
    return 0;
}

/*
        B::DoSomething()
        D::vfun()

        D:\C++Project\��̬��\Debug\MyPolymorphism.exe (���� 21296)���˳�������Ϊ 0��
        ��������رմ˴���. . .

*/