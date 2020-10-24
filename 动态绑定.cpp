//#include <iostream>
//using namespace std;
//
////这里做的是动态绑定
//
////父类
//class Base
//{
//public:
//    virtual void f1()
//    {
//        cout << "base" << endl;
//    }
//};
////子类1
//class Drived1 :public Base
//{
//public:
//    void f1()
//    {
//        cout << "Drived1" << endl;
//    }
//};
////子类2
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
//    //指向父类
//    Test(&b);
//    //指向子类1
//    Test(&d1);
//    //指向子类1
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
    //D* pd = new D();           //指针存在注意静态类型和动态类型
    B * pb = new D();            //指正注意静态类型和动态类型
    //pd->DoSomething();         //普通成员函数，静态绑定静态类型中的方法
    pb->DoSomething();        //普通成员函数，静态绑定静态类型中的方法

    //pd->vfun();            //虚成员函数，动态绑定到动态类型中的方法   virtual为动态
    pb->vfun();              //虚成员函数，动态绑定到动态类型中的方法
    return 0;
}

/*
        B::DoSomething()
        D::vfun()

        D:\C++Project\动态绑定\Debug\MyPolymorphism.exe (进程 21296)已退出，代码为 0。
        按任意键关闭此窗口. . .

*/