#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<cstdio>
#include <time.h>

//��Ʒ
struct Shopping
{
	char shopname[30];		//��Ʒ����
	char shopprice[20];		//��Ʒ�۸�
	char shopcapacity[10];	//��Ʒ����������
	char shopcount[10];		//��Ʒ����
	char shop_currentcount[10];//��Ʒ��ǰ����
};
//����Ա�ṹ��
struct  Administrator
{
	/*
	����Ա�Ĳ�����Ҫ���������롣����Ա�Ŀ�ѡ�����У� ��������Ʒ����Ϣ¼��ϵͳ�� ��
����Ʒ��Ϣ�� �޸Ļ�ɾ����Ʒ��Ϣ�� ÿ���°�ǰͳ�Ƶ������������ ���������ܶÿ����
���������� ����ϵͳ���С�

	*/
	char username[10];      //����Ա�û���     ��ǰ¼�����Ϣ			 �ṹ���ص�����Ҫ�������ʼ��
	char password[10];      //����Ա����  
	Shopping shopping[1000];		//��Ʒ
	//��ȡ�ļ�����
	void readfile();
	//д�ļ�����
	void writefile();
	//������¼��ϵͳ
	void readdata();
	//����µ���Ʒ��Ϣ
	void add_newproductions();
	//�޸���Ʒ��Ϣ
	void change_newproductions();
	//ɾ����Ʒ��Ϣ
	void delete_newproductions();
	//ͳ����Ʒ��Ϣ,ÿ���°�ǰͳ�Ƶ������������ ���������ܶÿ����Ʒ����������������ϵͳ����
	void cout_productions();

};
//�����߽ṹ��                            //��������      https://wenku.baidu.com/view/9053995fe518964bcf847cc1.html
struct   Consumer
{
	/*
	�˿Ϳ�ѡ�Ĳ����У� ��Ʒɨ��һ�����˵�һ���ˣ� ��Ʒɨ��һ�˳���
	*/
	Shopping shopping[1000];		//��Ʒ
	//ϵͳʱ����Ϊ���
	int consumernumber[30];
	//������¼��ϵͳ
	void readdata();
	//��Ʒѡ����Ʒɨ��
	void scan_productions();
	//���ɹ����˵�
	void create_bill();
	//����
	void pament();
	//�û��˳�
	void quit();

};
/////////////////////////////////////////////////////////////////////


//������ȫ�ֱ���
int shoppingcount;

//�������Ա
Administrator admin = { "����","1111" };

//����˿�����
Consumer consumer;

//�Ƿ����ɨ���ļ�
int continueshoppingscan = 1;
////////////////////////////////////////////////////////////////////

//����Ա��������
//��ȡ�ļ�����
void readfile();
//д�ļ�����
void writefile();
//������¼��ϵͳ
void readdata();
//����µ���Ʒ��Ϣ
void add_newproductions();
//�޸���Ʒ��Ϣ
void change_newproductions();
//ɾ����Ʒ��Ϣ
void delete_newproductions();
//ͳ����Ʒ��Ϣ,ÿ���°�ǰͳ�Ƶ������������ ���������ܶÿ����Ʒ����������������ϵͳ����
void cout_productions();


//�˿ͺ�������
//ϵͳʱ����Ϊ���
int consumernumber[30];
//�˿͵�½����
void consumer_login();
//������¼��ϵͳ
void readdata();

//¼���ļ�����
void read_consumerfile();
//д�ļ�����
void write_consumerfile(char shopname[30], char shopprice[20], char shopcapacity[10], char shop_currentcount[10]);

//��Ʒѡ����Ʒɨ��
void scan_productions();
//���ɹ����˵�
void create_bill();
//����
void pament();
//�û��˳�
void quit();

////////////////////////////////////////////////////////////////////

//��ȡ�ļ�����

void readfile()
{
	FILE* file;

	int i = 0;				//��Ʒ���
	if ((file = fopen("mydata.txt", "r")) == NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//  
	{
		printf("���ļ��޷��򿪻����ļ�������!\n\n\n");
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

//д�ļ�����
void writefile()
{
	FILE* file;

	int i = 0;				//��Ʒ���
	if ((file = fopen("mydata.txt", "w")) == NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//  
	{
		printf("���ļ��޷��򿪻����ļ�������!\n\n\n");
	}
	//����д���ı�
	for (int j = 0; j < shoppingcount; j++)
	{
		//fprintf()д�����ݵ��ı�
		fprintf(file, "%s\t%s\t%s\t%s\n", admin.shopping[j].shopname, admin.shopping[j].shopprice, admin.shopping[j].shopcapacity, admin.shopping[j].shopcount);
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n", admin.shopping[j].shopname, admin.shopping[j].shopprice, admin.shopping[j].shopcapacity, admin.shopping[j].shopcount);


	}
	fclose(file);
}
//������¼��ϵͳ
void readdata()
{
	readfile();

}
//����µ���Ʒ��Ϣ
void add_newproductions()
{
	FILE* file;


	//�������
	int datecount;
	//char name[20];
	//char price[10];
	//char capacity[20];
	//char shopcount[10];
	//Administrator admintemp[1000];

	printf("������������ӵ���������:\n");
	scanf("%d", &datecount);
	for (int i = shoppingcount; i < shoppingcount + datecount; i++)
	{
		printf("��������Ҫ��ӵ���Ʒ��:\n");
		scanf("%s", &admin.shopping[i].shopname);					//&��һ��ȡ��ַ�������&a��һ�����ʽ���书����������ĵ�ַ��
		printf("��������Ҫ��ӵ���Ʒ�۸�:\n");
		scanf("%s", &admin.shopping[i].shopprice);
		printf("��������Ҫ��ӵ���Ʒ����������:\n");
		scanf("%s", &admin.shopping[i].shopcapacity);
		printf("��������Ҫ��ӵ���Ʒ����:\n");
		scanf("%s", &admin.shopping[i].shopcount);
		printf("************************************************************************************\n");

	}
	if ((file = fopen("mydata.txt", "a")) == NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ������׷��  
	{
		printf("���ļ��޷��򿪻����ļ�������!\n\n\n");
	}

	//����д���ı�
	for (int j = shoppingcount; j < shoppingcount + datecount; j++)
	{
		//ˮƽ�Ʊ�Tab=4���ո�
		fprintf(file, "%s\t\t%s\t\t%s\t\t%s\n", admin.shopping[j].shopname, admin.shopping[j].shopprice, admin.shopping[j].shopcapacity, admin.shopping[j].shopcount);
	}
	fclose(file);
	readfile();


}
//�޸���Ʒ��Ϣ
void change_productions()
{
	int temp = 0;
	char shoppingname[20];
	printf("��������Ҫ�޸���Ʒ����Ʒ��:\n");
	scanf("%s", &shoppingname);
	for (int i = 0; i < shoppingcount; i++)
	{
		if (!strcmp(shoppingname, admin.shopping[i].shopname))
		{
			printf("%s\t%s\t%s\t%s\n\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount);
			printf("************************************************************************************\n");
			printf("��������Ҫ�޸ĵ���Ʒ��:\n");
			scanf("%s", &admin.shopping[i].shopname);
			printf("��������Ҫ�޸ĵ���Ʒ�۸�:\n");
			scanf("%s", &admin.shopping[i].shopprice);
			printf("��������Ҫ�޸ĵ���Ʒ����������:\n");
			scanf("%s", &admin.shopping[i].shopcapacity);
			printf("��������Ҫ�޸ĵ���Ʒ����:\n");
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
	//		printf("�޸���Ʒ�����Ϣ!\n\n");
	//	}

}
//ɾ����Ʒ��Ϣ
void delete_productions()
{
	int temp = 0;
	char shoppingname[20];
	printf("��������Ҫɾ����Ʒ����Ʒ��:\n");
	scanf("%s", &shoppingname);

	//��ѭ�����Ƚ�
	for (int i = 0; i < shoppingcount; i++)
	{
		if (!strcmp(shoppingname, admin.shopping[i].shopname))
		{
			printf("%s\t%s\t%s\t%s\n\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount);
			printf("��ʼɾ����Ʒ�����Ϣ!\n\n");
			for (i; i < shoppingcount; i++)
			{
				//��������ǰ�Ƹ���ǰ������
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
//ͳ����Ʒ��Ϣ,ÿ���°�ǰͳ�Ƶ������������ ���������ܶÿ����Ʒ����������������ϵͳ����
void cout_productions()
{
	FILE* file;

	int i = 0;				//��Ʒ���
	if ((file = fopen("mydata.txt", "r")) == NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//  
	{
		printf("���ļ��޷��򿪻����ļ�������!\n\n\n");
	}
	while (fscanf(file, "%s\t%s\t%s\t%s\n", admin.shopping[i].shopname, admin.shopping[i].shopprice, admin.shopping[i].shopcapacity, admin.shopping[i].shopcount) != EOF)
	{
		i++;
	}
	shoppingcount = i;
	fclose(file);

	FILE* confile;

	int j = 0;				//��Ʒ���
	if ((confile = fopen("consumerdata.txt", "r")) == NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//  
	{
		printf("���ļ��޷��򿪻����ļ�������!\n\n\n");
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

	int k = 0;				//��Ʒ���
	if ((file2 = fopen("mydatacurrent.txt", "w")) == NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//  
	{
		printf("���ļ��޷��򿪻����ļ�������!\n\n\n");
	}
	for (int jj = 0; jj < shoppingcount; jj++)
	{
		//fprintf()д�����ݵ��ı�
		fprintf(file, "%s\t%s\t%s\t%s\n", admin.shopping[jj].shopname, admin.shopping[jj].shopprice, admin.shopping[jj].shopcapacity, admin.shopping[jj].shopcount);
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n", admin.shopping[jj].shopname, admin.shopping[jj].shopprice, admin.shopping[jj].shopcapacity, admin.shopping[jj].shopcount);


	}
	//shoppingcount = k;
	fclose(file2);
}

//Ա�����
//char consumerId() {
//	time_t t;
//	struct tm* lt;
//	time(&t);//��ȡUnixʱ�����
//	lt = localtime(&t);//תΪʱ��ṹ��
//	//long int id = lt->tm_year + 1900 + lt->tm_mon + lt->tm_mday + lt->tm_hour + lt->tm_min + lt->tm_sec;
//	//printf("%s", id);
//	printf("%d%d%d%d%d%d\n", lt->tm_year + 1900, lt->tm_mon, lt->tm_mday, lt->tm_hour, lt->tm_min, lt->tm_sec);//������
//	return 0;
//}
void read_consumerfile()
{
	for (int j = 0; j < 1000; j++)
	{
		strcpy(admin.shopping[j].shop_currentcount, "1");
	}
	FILE* file;

	int i = 0;				//��Ʒ���
	if ((file = fopen("mydata.txt", "r")) == NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//  
	{
		printf("���ļ��޷��򿪻����ļ�������!\n\n\n");
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

//���ɹ˿��˵�
void create_bill()
{
	FILE* file;

	int i = 0;				//��Ʒ���
	double calculate_price = 0;
	if ((file = fopen("consumerdata.txt", "r")) == NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//  
	{
		printf("���ļ��޷��򿪻����ļ�������!\n\n\n");
	}
	printf("�����˵�\n");
	printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n", "��Ʒ��", "����", "����(���)", "����");
	while (fscanf(file, "%s\t%s\t%s\t%s\n", consumer.shopping[i].shopname, consumer.shopping[i].shopprice, consumer.shopping[i].shopcapacity, consumer.shopping[i].shopcount) != EOF)
	{
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%s\n", consumer.shopping[i].shopname, consumer.shopping[i].shopprice, consumer.shopping[i].shopcapacity, consumer.shopping[i].shopcount);
		//�ܼ۽���
		calculate_price += atof(consumer.shopping[i].shopprice);
		i++;
	}
	printf("\n");
	printf("�ϼ�֧��:\t%f", calculate_price);
	printf("\n\n");
	fclose(file);
}
//char shopname[30];		//��Ʒ����
//char shopprice[20];		//��Ʒ�۸�
//char shopcapacity[10];	//��Ʒ����������
//char shop_currentcount[10];		//��Ʒ����
//д�ļ�����
void write_consumerfile(char shopname[30], char shopprice[20], char shopcapacity[10], char shop_currentcount[10])
{
	FILE* file;

	int i = 0;				//��Ʒ���
	//��������ļ�׷�ӷ���
	if ((file = fopen("consumerdata.txt", "a")) == NULL)                 //��2���Ʒ�ʽ��ȡ�ļ���Ϣ//  
	{
		printf("���ļ��޷��򿪻����ļ�������!\n\n\n");
	}

	//����д���ı�

		//fprintf()д�����ݵ��ı�
	fprintf(file, "%s\t%s\t%s\t%s\n", shopname, shopprice, shopcapacity, shop_currentcount);
	//printf("%-10s\t\t%-10s\t\t%-10s\t\t%s\n", consumer.shopping[j].shopname, consumer.shopping[j].shopprice, consumer.shopping[j].shopcapacity, consumer.shopping[j].shop_currentcount);
	//printf("%-10s\t\t%-10s\t\t%-10s\t\t%s\n", consumer.shopping[j].shopname, consumer.shopping[j].shopprice, consumer.shopping[j].shopcapacity, consumer.shopping[j].shop_currentcount);

	fclose(file);
	//create_bill();
}
//��Ʒɨ��
void scan_productions()
{
	char shoppingscan[20];


	char shopname[30];		//��Ʒ����
	char shopprice[20];		//��Ʒ�۸�
	char shopcapacity[10];	//��Ʒ����������
	char shop_currentcount[10];		//��Ʒ����
	printf("��Ʒ��ʼɨ��\n\n");
	//scanf("%d", &shoppingscan);

	do {
		printf("�뿪ʼɨ����Ʒ��:\n\n");
		scanf("%s", &shoppingscan);
		printf("\n");//&��һ��ȡ��ַ�������&a��һ�����ʽ���书����������ĵ�ַ
		printf("%-10s\t\t%-10s\t\t%-10s\t\t%-10s\n\n", "��Ʒ��", "����", "����(���)", "����");
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
		printf("����ɨ������ 1   ֹͣɨ��������  0   \n");
		scanf("%d", &continueshoppingscan);
		//֧���˵�

	} while (continueshoppingscan);
	if (!continueshoppingscan)
	{
		create_bill();
		printf("�˿Ϳ����뿪��\n");
		//exit(0);

	}

	//write_consumerfile();
}
void adminface()
{
	printf("*****************************************************************************\n");
	printf("���������ѡ��:\n\n");
	printf("1.��Ʒ��Ϣ¼��\n");
	printf("2.�����Ʒ��Ϣ\n");
	printf("3.�޸���Ʒ��Ϣ\n");
	printf("4.ɾ����Ʒ��Ϣ\n");
	printf("5.ͳ����Ʒ��Ϣ\n");
	printf("0.�˳�ϵͳ����\n");
	printf("*****************************************************************************\n");
	//¼�볬������
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

//����Ա��½
void admin_login()
{
	int login = 0;
	do
	{

		printf("��������			   ����Ա����			     ��������\n");
		printf("���������Ա����:");
		char password[20];
		scanf("%s", &password);
		if (!strcmp(admin.password, password))			//strcmp()�ַ����ȽϺ�����������ȷ������0
		{
			printf("����������ȷ����ӭ����Ա���ã�\n\n");
			adminface();

			login = 0;
		}
		else
		{
			printf("������������������������룡\n\n");
			login = 1;
		}
	} while (login);
}

//�˿͵�½����
void consumer_login()
{
	int login = 1;
	do
	{

		printf("��������			    �˿ͽ���			     ��������\n");
		printf("*****************************************************************************\n");
		read_consumerfile();
		scan_productions();
		system("pause");
		//system("cls");
	} while (login);
}

//��������ʾ���ں���
void show_view()
{
	int allow = 1;
	while (allow)
	{

		printf("****************************************************************************\n\n\n");
		printf("��������  ��                 ���й������ϵͳ                    ��  ��������\n");
		printf("*****************************************************************************\n");
		printf("\n\n��ѡ����������ֽ��в�����\n");
		printf("*****************************************************************************\n");
		printf("1.��ѡ��������\n");
		printf("\n");
		printf(" 1.����Ա			2.�˿�\n");
		printf("*****************************************************************************\n");
		//consumerId();
		printf("���������ѡ��:\n");
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