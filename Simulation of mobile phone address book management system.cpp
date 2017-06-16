#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
struct  Information
{
	//数据域
	string name;  //姓名
	string  phoneName; //电话号码
	char type;   //分类（办公类，个人类，商务类）
	char email[20] = { 0 };  //电子邮件
	int up=0;    //编号
	//指针域
	Information *next;
};
class person
{
	Information *head;
public:
	person() { head = NULL; }
	void insertPerson();  //增加联系人功能
	void deletePerson();  //删除联系人功能
	void changePerson();  //修改数据功能
	void findPersong();   //查看功能，按办公类，个人类，商务类查看
	void showAll();       //显示所有联系人
	void dial();          //拨号功能
	Information *gethead() { return head; }  //取节点首地址函数
	//friend istream& operator>>(istream &in, int a[20]);
};
//istream& operator>>(istream&in, int a[20])
//{
//	int b,i=0;
//	do
//	{
//		in >> b;
//		a[i] = b;
//		i++;
//	} while (b>='0'&&b<='9'&&i>=20);
//	return a;
//}
void person::insertPerson()  //增加联系人功能
{
	Information *s;
	Information *p, *num;
	p = head; 
	int Num=1;
	s = new Information;
	cout << "你要添加联的系人的姓名是：" << endl; cin >> s->name;
	cout << "你要添加的联系人的电话号码是：" << endl; cin >> s->phoneName;
	cout << "你要添加的联系人的分类是（A—办公类，B-个人类，C—商务类）："<<endl; cin >> s->type;
	cout <<"你要添加的联系人的邮箱地址是：" << endl; cin >> s->email;
	if (head == NULL)
	{
		head = s;
		s->next = NULL;
	}
	else
	{
		while (p->next)
		{
			p = p->next;
		}    //使p指针指向链表的最后一个数，即实现将新结点放在链表的最后面
		p->next = s;
		s->next = NULL;
	}
	num = head;
	if (head == NULL)
		cout << "无此链表!"<<endl;
	else
	{
		while (num!=NULL)
		{
			num->up=Num;
			Num++;
			num = num->next;
		}
	}
	return;
}
void person::showAll()  //显示所有联系人信息
{
	Information *p = head;
	cout << '\t' << "姓名" << '\t' << "电话号码" << '\t' << '\t' << "分类" << '\t' << "邮箱" <<'\t'<<'\t'<< "编号"<<endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	if (head == NULL)
	{
		cout << "失败！" << endl;
		return;
	}
	while (p!=NULL)
	{
		cout << '\t' << p->name << '\t' << p->phoneName << '\t'<<'\t' << p->type << '\t' << p->email <<'\t'<<'\t'<<p->up<< endl;
		cout << "---------------------------------------------------------------------------------------------------------" << endl;
		p = p->next;
	}
	return;
}
//查看功能，按办公类，个人类，商务类查看
void person::findPersong()
{
	Information *p = head;
	char a = 'A'; char b = 'B'; char c = 'C';
	int  choice;
	cout << "请输入你要查看的方式（1—办公类，2-个人类，3-商务类）";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (head == NULL)
			cout << "此链表没有数据！" << endl;
		else
		{
			cout << '\t' << "姓名" << '\t' << "电话号码" << '\t' << '\t' << '\t' << "分类" << '\t' << "邮箱" << '\t' << '\t' << '\t' << "编号" << endl;
			while (p!=NULL)
			{
				if(p->type==a)
					cout << '\t' << p->name << '\t' << p->phoneName << '\t' << '\t' << '\t' << p->type << '\t' << p->email << '\t' << '\t' << '\t' << p->up << endl;
				p = p->next;
			}
		}
	}break;
	case 2:
	{
		if (head == NULL)
			cout << "此链表没有数据！" << endl;
		else
		{
			cout << '\t' << "姓名" << '\t' << "电话号码" << '\t' << '\t' << '\t' << "分类" << '\t' << "邮箱" << '\t' << '\t' << '\t' << "编号" << endl;
			while (p != NULL)
			{
				if (p->type == b)
					cout << '\t' << p->name << '\t' << p->phoneName << '\t' << '\t' << '\t' << p->type << '\t' << p->email << '\t' << '\t' << '\t' << p->up << endl;
				p = p->next;
			}
		}
	} break;
	case 3:
	{
		if (head == NULL)
			cout << "此链表没有数据！" << endl;
		else
		{
			cout << '\t' << "姓名" << '\t' << "电话号码" << '\t' << '\t' << '\t' << "分类" << '\t' << "邮箱" << '\t' << '\t' << '\t' << "编号" << endl;
			while (p != NULL)
			{
				if (p->type == c)
					cout << '\t' << p->name << '\t' << p->phoneName << '\t' << '\t' << '\t' << p->type << '\t' << p->email << '\t' << '\t' << '\t' << p->up << endl;
				p = p->next;
			}
		}
	} break;
	default:
		break;
	}

}
//修改数据功能
void person::changePerson()
{
	Information *p = head, *q = head;
	string name;
	cout << "请输入你要修改的联系人的姓名"; cin >> name;
	if (head == NULL)
		cout << "链表不存在！" << endl;
	else
		while (p != NULL)
		{
			if (p->name == name)
			{
				cout << "请输入你修改后的名字："; cin >> p->name;
				int i; cout << "请问需要修改电话号码吗（1-要，0-不要）"; cin >> i; 
				switch (i)
				{
				case 1:
				{
					cout << endl << "请输入你修改后的电话号码："; cin >> p->phoneName;
				}break;
				default:
					break;
				}
				int j; cout << "请问需要修改分类吗（1-要，0-不要）"; cin >> j;
				switch (j)
				{
				case 1:
				{
					cout << endl << "请输入你修改后的分类："; cin >> p->type;
				}break;
				default:
					break;
				}
				int k; cout << "请问需要邮箱地址吗（1-要，0-不要）"; cin >> k;
				switch (k)
				{
				case 1:
				{
					cout << endl << "请输入你修改后的邮箱地址："; cin >> p->email;
				}break;
				default:
					break;
				}
			}
			p = p->next;
		}
	//并不需要修改编号的
	return;
}

//删除联系人功能
void person::deletePerson()
{
	Information *p, *q; //p指针用来指向要删除的结点，q用来指向要删除的前一个结点
	string deleteName;  //deleteName是我们所要删除的结点中的数据成员
	cout << "请输入你要删除的联系人的姓名："; cin >> deleteName;
	p = head;
	if (p == NULL) //如果链表为空则直接退出
		return;
	if (p->name == deleteName) //如果要删除的是第一个联系人的话，则需要将头指针head 往后移一个结点
	{
		head = p->next;
		delete p;
	}
	else
	{
		while (p->name!=deleteName&&p->next!=NULL)
		{
			q = p;
			p = p->next;
		}
		if (p->name == deleteName)  //如果有我们所要删除的联系人的姓名的话
		{
			q->next = p->next;
			delete p;
		}
	}
	//要移动结点了
	Information *num; int number=1;
	num = head;
	while (num!=NULL)
	{
		num->up = number;
		number++;
		num = num->next;
	}
	cout << "删除成功。" << endl;
	return;
}

//拨号功能
void person::dial()
{
	//int a[20]; long b;
	//Information *p = head;
	//int len; len = strlen(p->phoneName.c_str());
	//b = atoi(p->phoneName.c_str());  //把string类型转换成char*在调用atoi函数,即将字符串变成了整形
	//for (int i = len - 1; i >= 0; i--)
	//{
	//	a[i] = b % 10;
	//	b /= 10;
	//}
	Information *p = head;
	Information *q = head;
	string Name;
	cout << "d请输入你要拨打的联系人的姓名："; cin >> Name;
	if (p == NULL)
	{
		cout << "无此联系人！" << endl;
		return;
	}
	else
	{
		while (p!=NULL)
		{
			if (p->name == Name)
			{
				cout << "现在开始拨号**************" << endl;
				cout << "你现在正在向" << p->name << "拨号******" << endl;
				Sleep(1000); //延迟1000毫秒
				cout << "恭喜你！拨号成功！****" << endl;
			}
			p = p->next;
		}
		//cout << "对不起！无此联系人！" << endl;
	}
	while (q->next)
	{
		q = q->next;
	}
	//if(q->name!=Name)
	//	 cout << "对不起！无此联系人！" << endl;
	return;
}

//测试主函数
void main()
{
	person A;
	int choice,fun;
	do
	{
		cout << "---------------------欢迎来到主菜单----------------------" << endl;
		cout << '\t' << '\t' << "1-增加联系人" << endl<<endl;
		cout << '\t' << '\t' << "2-查看功能，按办公类，个人类，商务类查看" << endl<<endl;
		cout << '\t' << '\t' << "3-修改数据功能" << endl<<endl;
		cout << '\t' << '\t' << "4-拨号功能" << endl << endl;
		cout << '\t' << '\t' << "5-删除联系人功能" << endl<<endl;
		cout << '\t' << '\t' << "6-显示所有联系人" << endl<<endl;
		cout << '\t' << '\t' << "0-退出程序" << endl<<endl;
		cout << "---------------------欢迎来到主菜单----------------------" << endl;
		cout << "请输入你的选择：";  cin >> fun;
		system(" cls");  //清屏
		switch (fun)
		{
		case 1:
		{
			A.insertPerson();
		} break;
		case 2:
		{
			A.findPersong();
		} break;
		case 3:
		{
			A.changePerson();
		} break;
		case 4:
		{
			A.dial();
		} break;
		case 5:
		{
			A.deletePerson();
		} break;
		case 6:
		{
			A.showAll();
		} break;
		default:
			break;
		}
		cout <<'\t'<< "请输入你的选择（1-回到主菜单，0-退出程序）"; cin >> choice;
		system("cls");
	} while (choice);
}