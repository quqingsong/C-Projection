#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
#include <time.h>

//商品
struct Shopping
{
	char shopname[30];		//商品名称
	char shopprice[20];		//商品价格
	char shopcapacity[10];	//商品重量或容量
	char shopcount[10];		//商品数量
	char shop_currentcount[10];//商品当前数量
};
//管理员结构体
struct  Administrator
{
	/*
	管理员的操作需要先输人密码。管理员的可选操作有： 将超市商品的信息录人系统， 添
新商品信息， 修改或删除商品信息； 每天下班前统计当天销售情况， 包括销售总额、每种商
销售数量； 结束系统运行。

	*/
	char username[10];      //管理员用户名     提前录入的信息			 结构体重的数据要在外面初始化
	char password[10];      //管理员密码  
	Shopping shopping[1000];		//商品
	//读取文件函数
	void readfile();
	//写文件函数
	void writefile();
	//将数据录入系统
	void readdata();
	//添加新的商品信息
	void add_newproductions();
	//修改商品信息
	void change_newproductions();
	//删除商品信息
	void delete_newproductions();
	//统计商品信息,每天下班前统计当天销售情况， 包括销售总额、每种商品的销售数量，结束系统运行
	void cout_productions();

};
//消费者结构体                            //数据链接      https://wenku.baidu.com/view/9053995fe518964bcf847cc1.html
struct   Consumer
{
	/*
	顾客可选的操作有： 商品扫码一生成账单一付账； 商品扫码一退出。
	*/
	Shopping shopping[1000];		//商品
	//系统时间作为编号
	int consumernumber[30];
	//将数据录入系统
	void readdata();
	//商品选择，商品扫码
	void scan_productions();
	//生成购物账单
	void create_bill();
	//付款
	void pament();
	//用户退出
	void quit();

};
/////////////////////////////////////////////////////////////////////


//这里是全局变量
int shoppingcount;

//定义管理员
Administrator admin = { "李明","1111" };

//定义顾客数量
Consumer consumer;

//是否继续扫描文件
int continueshoppingscan = 1;
////////////////////////////////////////////////////////////////////

//管理员函数声明
//读取文件函数
void readfile();
//写文件函数
void writefile();
//将数据录入系统
void readdata();
//添加新的商品信息
void add_newproductions();
//修改商品信息
void change_newproductions();
//删除商品信息
void delete_newproductions();
//统计商品信息,每天下班前统计当天销售情况， 包括销售总额、每种商品的销售数量，结束系统运行
void cout_productions();


//顾客函数声明
//系统时间作为编号
int consumernumber[30];
//顾客登陆界面
void consumer_login();
//将数据录入系统
void readdata();

//录入文件数据
void read_consumerfile();
//写文件函数
void write_consumerfile(char shopname[30], char shopprice[20], char shopcapacity[10], char shop_currentcount[10]);

//商品选择，商品扫码
void scan_productions();
//生成购物账单
void create_bill();
//付款
void pament();
//用户退出
void quit();

////////////////////////////////////////////////////////////////////

//读取文件函数

void readfile()
{
	FILE* file;

	int i = 0;				//商品标记
	if ((file = fopen("mydata.txt", "r")) == NULL)                 //以2进制方式读取文件信息//  
	{
		printf("该文件无法打开或者文件不存在!\n\n\n");
	}
	while (fscanf(file, "%s\t%s\t%s\t%s\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount) != EOF)
		//printf("%s\t%s\t%s\t%s\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount);
	{
		i++;
	}
	shoppingcount = i;
	for (int j = 0; j < i; j++)
	{
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n", admin.shopping[j].shopname, admin.shopping[j].shopprice, admin.shopping[j].shopcapacity, admin.shopping[j].shopcount);
	}
	printf("\n\n");
	fclose(file);
}

//写文件函数
void writefile()
{
	FILE* file;

	int i = 0;				//商品标记
	if ((file = fopen("mydata.txt", "w")) == NULL)                 //以2进制方式读取文件信息//  
	{
		printf("该文件无法打开或者文件不存在!\n\n\n");
	}
	//数据写入文本
	for (int j = 0; j < shoppingcount; j++)
	{
		//fprintf()写入数据到文本
		fprintf(file, "%s\t%s\t%s\t%s\n", admin.shopping[j].shopname, admin.shopping[j].shopprice, admin.shopping[j].shopcapacity, admin.shopping[j].shopcount);
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n", admin.shopping[j].shopname, admin.shopping[j].shopprice, admin.shopping[j].shopcapacity, admin.shopping[j].shopcount);


	}
	fclose(file);
}
//将数据录入系统
void readdata()
{
	readfile();

}
//添加新的商品信息
void add_newproductions()
{
	FILE* file;


	//添加数据
	int datecount;
	//char name[20];
	//char price[10];
	//char capacity[20];
	//char shopcount[10];
	//Administrator admintemp[1000];

	printf("请输入你想添加的数据条数:\n");
	scanf("%d", &datecount);
	for (int i = shoppingcount; i < shoppingcount + datecount; i++)
	{
		printf("请输入你要添加的商品名:\n");
		scanf("%s", &admin.shopping[i].shopname);					//&是一个取地址运算符，&a是一个表达式，其功能是求变量的地址。
		printf("请输入你要添加的商品价格:\n");
		scanf("%s", &admin.shopping[i].shopprice);
		printf("请输入你要添加的商品重量或容量:\n");
		scanf("%s", &admin.shopping[i].shopcapacity);
		printf("请输入你要添加的商品数量:\n");
		scanf("%s", &admin.shopping[i].shopcount);
		printf("************************************************************************************\n");

	}
	if ((file = fopen("mydata.txt", "a")) == NULL)                 //以2进制方式读取文件信息，数据追加  
	{
		printf("该文件无法打开或者文件不存在!\n\n\n");
	}

	//数据写入文本
	for (int j = shoppingcount; j < shoppingcount + datecount; j++)
	{
		//水平制表（Tab=4个空格）
		fprintf(file, "%s\t\t%s\t\t%s\t\t%s\n", admin.shopping[j].shopname, admin.shopping[j].shopprice, admin.shopping[j].shopcapacity, admin.shopping[j].shopcount);
	}
	fclose(file);
	readfile();


}
//修改商品信息
void change_productions()
{
	int temp = 0;
	char shoppingname[20];
	printf("请输入你要修改商品的商品名:\n");
	scanf("%s", &shoppingname);
	for (int i = 0; i < shoppingcount; i++)
	{
		if (!strcmp(shoppingname, admin.shopping[i].shopname))
		{
			printf("%s\t%s\t%s\t%s\n\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount);
			printf("************************************************************************************\n");
			printf("请输入你要修改的商品名:\n");
			scanf("%s", &admin.shopping[i].shopname);
			printf("请输入你要修改的商品价格:\n");
			scanf("%s", &admin.shopping[i].shopprice);
			printf("请输入你要修改的商品重量或容量:\n");
			scanf("%s", &admin.shopping[i].shopcapacity);
			printf("请输入你要修改的商品数量:\n");
			scanf("%s", &admin.shopping[i].shopcount);
			printf("************************************************************************************\n");

			writefile();
		}
		if (strcmp(shoppingname, admin.shopping[i].shopname))
		{
			temp = 1;


		}
		/*	else
			{

			}*/
	}
	//	if (temp == 1)
	//	{
	//		printf("无该商品相关信息!\n\n");
	//	}

}
//删除商品信息
void delete_productions()
{
	int temp = 0;
	char shoppingname[20];
	printf("请输入你要删除商品的商品名:\n");
	scanf("%s", &shoppingname);

	//外循环做比较
	for (int i = 0; i < shoppingcount; i++)
	{
		if (!strcmp(shoppingname, admin.shopping[i].shopname))
		{
			printf("%s\t%s\t%s\t%s\n\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount);
			printf("开始删除商品相关信息!\n\n");
			for (i; i < shoppingcount; i++)
			{
				//后面数据前移覆盖前面数据
				strcpy(admin.shopping[i].shopname, admin.shopping[i + 1].shopname);
				strcpy(admin.shopping[i].shopprice, admin.shopping[i + 1].shopprice);
				strcpy(admin.shopping[i].shopcapacity, admin.shopping[i + 1].shopcapacity);
				strcpy(admin.shopping[i].shopcount, admin.shopping[i + 1].shopcount);
			}
			shoppingcount--;
			writefile();
		}

	}

}
//统计商品信息,每天下班前统计当天销售情况， 包括销售总额、每种商品的销售数量，结束系统运行
void cout_productions()
{
	FILE* file;

	int i = 0;				//商品标记
	if ((file = fopen("mydata.txt", "r")) == NULL)                 //以2进制方式读取文件信息//  
	{
		printf("该文件无法打开或者文件不存在!\n\n\n");
	}
	while (fscanf(file, "%s\t%s\t%s\t%s\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount) != EOF)
	{
		i++;
	}
	shoppingcount = i;
	fclose(file);

	FILE* confile;

	int j = 0;				//商品标记
	if ((confile = fopen("consumerdata.txt", "r")) == NULL)                 //以2进制方式读取文件信息//  
	{
		printf("该文件无法打开或者文件不存在!\n\n\n");
	}
	while (fscanf(confile, "%s\t%s\t%s\t%s\n", consumer.shopping[j].shopname, consumer.shopping[j].shopprice, consumer.shopping[j].shopcapacity, consumer.shopping[j].shopcount) != EOF)
	{
		j++;
	}
	fclose(confile);
	for (int ii = 0; ii < shoppingcount; ii++)
	{
		int a,b,c;
		char s[12];
		a = atof(admin.shopping[ii].shopcount);
			
		b=atof(consumer.shopping[ii].shopcount);
		c = a - b;
		sprintf(s, "%d", c);
		//printf("%s\n",s);
		strcpy(admin.shopping[ii].shopcount, s);
	}

	FILE* file2;

	int k = 0;				//商品标记
	if ((file2 = fopen("mydatacurrent.txt", "w")) == NULL)                 //以2进制方式读取文件信息//  
	{
		printf("该文件无法打开或者文件不存在!\n\n\n");
	}
	for (int jj = 0; jj < shoppingcount; jj++)
	{
		//fprintf()写入数据到文本
		fprintf(file, "%s\t%s\t%s\t%s\n", admin.shopping[jj].shopname, admin.shopping[jj].shopprice, admin.shopping[jj].shopcapacity, admin.shopping[jj].shopcount);
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n", admin.shopping[jj].shopname, admin.shopping[jj].shopprice, admin.shopping[jj].shopcapacity, admin.shopping[jj].shopcount);


	}
	//shoppingcount = k;
	fclose(file2);
}

//员工编号
//char consumerId() {
//	time_t t;
//	struct tm* lt;
//	time(&t);//获取Unix时间戳。
//	lt = localtime(&t);//转为时间结构。
//	//long int id = lt->tm_year + 1900 + lt->tm_mon + lt->tm_mday + lt->tm_hour + lt->tm_min + lt->tm_sec;
//	//printf("%s", id);
//	printf("%d%d%d%d%d%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//输出结果
//	return 0;
//}
void read_consumerfile()
{
	for (int j = 0; j < 1000; j++)
	{
		strcpy(admin.shopping[j].shop_currentcount, "1");
	}
	FILE* file;

	int i = 0;				//商品标记
	if ((file = fopen("mydata.txt", "r")) == NULL)                 //以2进制方式读取文件信息//  
	{
		printf("该文件无法打开或者文件不存在!\n\n\n");
	}
	while (fscanf(file, "%s\t%s\t%s\t%s\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount) != EOF)
	{
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%s\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount);
		i++;
		shoppingcount = i;
	}
	/*for (int j = 0; j < i; j++)
	{
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n", consumer.shopping[j].shopname, consumer.shopping[j].shopprice, consumer.shopping[j].shopcapacity, consumer.shopping[j].shopcount);
	}*/
	printf("\n\n");
	fclose(file);
}

//生成顾客账单
void create_bill()
{
	FILE* file;

	int i = 0;				//商品标记
	double calculate_price = 0;
	if ((file = fopen("consumerdata.txt", "r")) == NULL)                 //以2进制方式读取文件信息//  
	{
		printf("该文件无法打开或者文件不存在!\n\n\n");
	}
	printf("生成账单\n");
	printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n", "商品名", "单价", "重量(体积)", "数量");
	while (fscanf(file, "%s\t%s\t%s\t%s\n", consumer.shopping[i].shopname, consumer.shopping[i].shopprice, consumer.shopping[i].shopcapacity, consumer.shopping[i].shopcount) != EOF)
	{
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%s\n", consumer.shopping[i].shopname, consumer.shopping[i].shopprice, consumer.shopping[i].shopcapacity, consumer.shopping[i].shopcount);
		//总价结算
		calculate_price += atof(consumer.shopping[i].shopprice);
		i++;
	}
	printf("\n");
	printf("合计支出:\t%f", calculate_price);
	printf("\n\n");
	fclose(file);
}
//char shopname[30];		//商品名称
//char shopprice[20];		//商品价格
//char shopcapacity[10];	//商品重量或容量
//char shop_currentcount[10];		//商品数量
//写文件函数
void write_consumerfile(char shopname[30], char shopprice[20], char shopcapacity[10], char shop_currentcount[10])
{
	FILE* file;

	int i = 0;				//商品标记
	//这里采用文件追加方法
	if ((file = fopen("consumerdata.txt", "a")) == NULL)                 //以2进制方式读取文件信息//  
	{
		printf("该文件无法打开或者文件不存在!\n\n\n");
	}

	//数据写入文本

		//fprintf()写入数据到文本
	fprintf(file, "%s\t%s\t%s\t%s\n", shopname, shopprice, shopcapacity, shop_currentcount);
	//printf("%-10s\t\t%-10s\t\t%-10s\t\t%s\n", consumer.shopping[j].shopname, consumer.shopping[j].shopprice, consumer.shopping[j].shopcapacity, consumer.shopping[j].shop_currentcount);
	//printf("%-10s\t\t%-10s\t\t%-10s\t\t%s\n", consumer.shopping[j].shopname, consumer.shopping[j].shopprice, consumer.shopping[j].shopcapacity, consumer.shopping[j].shop_currentcount);

	fclose(file);
	//create_bill();
}
//商品扫码
void scan_productions()
{
	char shoppingscan[20];


	char shopname[30];		//商品名称
	char shopprice[20];		//商品价格
	char shopcapacity[10];	//商品重量或容量
	char shop_currentcount[10];		//商品数量
	printf("商品开始扫码\n\n");
	//scanf("%d", &shoppingscan);

	do {
		printf("请开始扫描商品名:\n\n");
		scanf("%s", &shoppingscan);
		printf("\n");//&是一个取地址运算符，&a是一个表达式，其功能是求变量的地址
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n\n", "商品名", "单价", "重量(体积)", "数量");
		for (int i = 0; i < shoppingcount; i++)
		{
			if (!strcmp(shoppingscan, admin.shopping[i].shopname))
			{
				printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shop_currentcount);
				strcpy(shopname, admin.shopping[i].shopname);
				strcpy(shopprice, admin.shopping[i].shopprice);
				strcpy(shopcapacity, admin.shopping[i].shopcapacity);
				strcpy(shop_currentcount, admin.shopping[i].shop_currentcount);
				write_consumerfile(shopname, shopprice, shopcapacity, shop_currentcount);

			}
		}
		printf("继续扫描输入 1   停止扫描请输入  0   \n");
		scanf("%d", &continueshoppingscan);
		//支付账单

	} while (continueshoppingscan);
	if (!continueshoppingscan)
	{
		create_bill();
		printf("顾客可以离开！\n");
		//exit(0);

	}

	//write_consumerfile();
}
void adminface()
{
	printf("*****************************************************************************\n");
	printf("请输入你的选择:\n\n");
	printf("1.商品信息录入\n");
	printf("2.添加商品信息\n");
	printf("3.修改商品信息\n");
	printf("4.删除商品信息\n");
	printf("5.统计商品信息\n");
	printf("0.退出系统界面\n");
	printf("*****************************************************************************\n");
	//录入超市数据
	int admin_judge = 1;
	do {
		int admin_selector;
		scanf("%d", &admin_selector);
		switch (admin_selector)
		{
		default:
			admin_judge = 0;
			break;
		case 0:
			admin_judge = 0;
			break;
		case 1:
			readdata();
			adminface();
			break;
		case 2:
			add_newproductions();
			adminface();
			break;
		case 3:
			change_productions();
			adminface();
			break;
		case 4:
			delete_productions();
			adminface();
			break;
		case 5:
			cout_productions();
			adminface();
			break;
		}
	} while (admin_judge);

}

//管理员登陆
void admin_login()
{
	int login = 0;
	do
	{

		printf("〓〓〓〓			   管理员界面			     〓〓〓〓\n");
		printf("请输入管理员密码:");
		char password[20];
		scanf("%s", &password);
		if (!strcmp(admin.password, password))			//strcmp()字符串比较函数，密码正确，返回0
		{
			printf("密码输入正确，欢迎管理员来访！\n\n");
			adminface();

			login = 0;
		}
		else
		{
			printf("密码输入错误，请重新输入密码！\n\n");
			login = 1;
		}
	} while (login);
}

//顾客登陆界面
void consumer_login()
{
	int login = 1;
	do
	{

		printf("〓〓〓〓			    顾客界面			     〓〓〓〓\n");
		printf("*****************************************************************************\n");
		read_consumerfile();
		scan_productions();
		system("pause");
		//system("cls");
	} while (login);
}

//这里是显示窗口函数
void show_view()
{
	int allow = 1;
	while (allow)
	{

		printf("****************************************************************************\n\n\n");
		printf("〓〓〓〓  ☆                 超市购物管理系统                    ☆  〓〓〓〓\n");
		printf("*****************************************************************************\n");
		printf("\n\n请选择下面的数字进行操作：\n");
		printf("*****************************************************************************\n");
		printf("1.请选择你的身份\n");
		printf("\n");
		printf(" 1.管理员			2.顾客\n");
		printf("*****************************************************************************\n");
		//consumerId();
		printf("请输入你的选择:\n");
		int switch_on;
		scanf("%d", &switch_on);
		switch (switch_on)
		{
		default:
			break;
		case 1:
			admin_login();
			//system("cls");
			break;
		case 2:
			consumer_login();
			//system("cls");
			break;



		}

		system("cls");
	}
}
int main() {
	show_view();
	return 0;
}