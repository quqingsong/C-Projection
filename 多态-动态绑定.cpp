#include <iostream>
using namespace std;

//���������Ƕ�̬��

//����
class Base
{
public:
    virtual void f1()
    {
        cout << "base" << endl;
    }
};
//����1
class Drived1 :public Base
{
public:
    void f1()
    {
        cout << "Drived1" << endl;
    }
};
//����2
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
    //ָ����
    Test(&b);
    //ָ������1
    Test(&d1);
    //ָ������1
    Test(&d2);
    return 0;
}


/*
���н������:

    base
    Drived1
    Drived2

    D:\C++Project\��̬-��̬��\Debug\��̬-��̬��.exe (���� 10200)���˳�������Ϊ 0��
    ��������رմ˴���. . .
*/