#include<iostream>
using namespace std;

//�����ǶԵ��̳н��в���

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
	//���෽��ָ��������󣬵������෽��
	AbsTractCalculator* abs = new Calculator();
	abs->a = 1.5;
	abs->b = 1.5;
	//������
	cout << "a+b=" << abs->getResult() << endl;
	//������
	cout << "a+b=" << abs->AbsTractCalculator::getResult() << endl;

	return 0;
}