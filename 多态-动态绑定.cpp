#include <iostream>
using namespace std;

//这里做的是动态绑定

//父类
class Base
{
public:
    virtual void f1()
    {
        cout << "base" << endl;
    }
};
//子类1
class Drived1 :public Base
{
public:
    void f1()
    {
        cout << "Drived1" << endl;
    }
};
//子类2
class Drived2 :public Base
{
public:
    void f1()
    {
        cout << "Drived2" << endl;
    }
};
void Test(Base* pB)
{
    pB->f1();
}
int main()
{
    Base b;
    Drived1 d1;
    Drived2 d2;
    //指向父类
    Test(&b);
    //指向子类1
    Test(&d1);
    //指向子类1
    Test(&d2);
    return 0;
}


/*
运行结果如下:

    base
    Drived1
    Drived2

    D:\C++Project\多态-动态绑定\Debug\多态-动态绑定.exe (进程 10200)已退出，代码为 0。
    按任意键关闭此窗口. . .
*/