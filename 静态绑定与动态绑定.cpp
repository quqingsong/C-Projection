#include<iostream>
#include<string>
#include<fstream>
using namespace std;

//食品类，这是一个父类
class Food
{
protected:
	//食物名字
	string name;
	//食物价格
	double price;
	//数量
	int num;
public:
	//虚函数
	virtual double get_summ(double summ)
	{
		double sum = summ * 0.75;
		cout << "调用父类方法" << endl;
		return sum;
	}
	//虚函数
	virtual double get_sum()
	{
		double sum = price * num;
		return sum;
	}
	//name属性设置器
	virtual void set_name(string name)
	{
		this->name = name;
	}
	//name属性获得器
	virtual string get_name()
	{
		return name;
	}
	//price属性设置器
	virtual void set_price(double price)
	{
		this->price = price;
	}
	//price属性获得器
	virtual double get_price()
	{
		return price;
	}
	//数量属性获得器
	virtual void set_num(int num)
	{
		this->num = num;
	}
	//数量属性得到器
	virtual int get_num()
	{
		return num;
	}
};
//商品折扣
class DiscountFood :public Food
{
public:
	double get_sum(double summ) {
		double sum = summ * 0.75;
		cout << "DiscountFood折扣后的价格是:\t\t" << sum << endl;
		return sum;
	}


};

void main() {
	Food * food = new DiscountFood();
	food->get_summ(10);
}