#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//ʳƷ�࣬����һ������
class Food
{
protected:
	//ʳ������
	string name;
	//ʳ��۸�
	double price;
	//����
	int num;
public:
	//�麯��
	virtual double get_summ(double summ)
	{
		double sum = summ * 0.75;
		cout << "���ø��෽��" << endl;
		return sum;
	}
	//�麯��
	virtual double get_sum()
	{
		double sum = price * num;
		return sum;
	}
	//name����������
	virtual void set_name(string name)
	{
		this->name = name;
	}
	//name���Ի����
	virtual string get_name()
	{
		return name;
	}
	//price����������
	virtual void set_price(double price)
	{
		this->price = price;
	}
	//price���Ի����
	virtual double get_price()
	{
		return price;
	}
	//�������Ի����
	virtual void set_num(int num)
	{
		this->num = num;
	}
	//�������Եõ���
	virtual int get_num()
	{
		return num;
	}
};
//��Ʒ�ۿ�
class DiscountFood :public Food
{
public:
	double get_sum(double summ) {
		double sum = summ * 0.75;
		cout << "DiscountFood�ۿۺ�ļ۸���:\t\t" << sum << endl;
		return sum;
	}


};

void main() {
	Food * food = new DiscountFood();
	food->get_summ(10);
}