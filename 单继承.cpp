#include<iostream>
using namespace std;

//这里是对单继承进行测试

class AbsTractCalculator
{
public:
	double a;
	double b;
	AbsTractCalculator();
	~AbsTractCalculator();
	virtual double getResult() {
		return 0;
	}

private:

};

AbsTractCalculator::AbsTractCalculator()
{
}

AbsTractCalculator::~AbsTractCalculator()
{
}

class Calculator :public AbsTractCalculator
{
public:
	Calculator();
	~Calculator();
	double getResult() {
		return a + b;
	}

private:

};

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

int main() {
	//父类方法指向子类对象，调用子类方法
	AbsTractCalculator* abs = new Calculator();
	abs->a = 1.5;
	abs->b = 1.5;
	//子类结果
	cout << "a+b=" << abs->getResult() << endl;
	//父类结果
	cout << "a+b=" << abs->AbsTractCalculator::getResult() << endl;

	return 0;
}