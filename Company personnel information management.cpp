#include<iostream>
#include<string.h>
#include"Company personnel information management.h"
using namespace std;
int employee::employeeNo = 1000;  //员工编号基数为1000

employee::employee()
{
	char namestr[20];  //输入雇员姓名时首先临时存放在namestr中
	cout << "请输入本雇员的姓名：";
	cin >> namestr;
	name = new char[strlen(namestr) + 1];  //动态申请用于存放姓名的内存空间
	strcpy(name, namestr);  //将临时存放的姓名复制到name
	individualEmpNo = employeeNo++;  //新输入的员工，编号为当前的最大值加1
	grade = 1;  //级别初值为1
	accumPay = 0.0;//月薪总额初值为0
}
employee::~employee()
{
	delete[]name;  //在析构函数中删除为存放姓名动态分配的内存空间
}
void employee::promote(int increment)  //升级函数
{
	grade += increment;  //升级的级数由increment决定
}

technician::technician()  ////兼职技术人员类
{
	hourlyRate = 100;  //每小时薪金为100元
}
void technician::pay()
{
	cout << "请输入" << name << "本月的工作时数";
	cin >> workHours;  //计算月薪，按小时计酬
	accumPay = hourlyRate*workHours;
	cout << "兼职 技术人员" << name << "编号" << individualEmpNo << "本月工资" << accumPay << endl;
}
void technician::displayStatus()
{
	cout << "兼职技术人员" << name << "编号" << individualEmpNo << "级别为" << grade << "级，已付本月工资" << accumPay << endl;
}
salesman::salesman()  //兼职推销员类
{
	CommRate = 0.04;  //销售提成比例4%
}
void salesman::pay()
{
	cout << "请输入" << name << "本月的销售额：";
	cin >> sales;
	accumPay = sales*CommRate;  //月薪=销售提成
	cout << "推销员" << name << "编号" << individualEmpNo << "本月工资" << accumPay << endl;
}
void salesman::displayStatus()
{
	cout << "推销员" << name << "编号" << individualEmpNo << "级别为" << grade << "级，已付本月工资" << accumPay << endl;
}
manager::manager()   //经理类
{
	monthlyPay = 8000;  //固定月薪为8000元
}
void manager::pay()
{
	accumPay = monthlyPay;  //月薪总额即为固定月薪数
	cout << "经理" << name << "编号" << individualEmpNo << "本月工资" << accumPay << endl;
}
void manager::displayStatus()
{
	cout << "经理" << name << "编号" << individualEmpNo << "级别为" << grade << "级，一付本月工资" << accumPay << endl;
}
salesmanager::salesmanager()   //销售经理类
{
	monthlyPay = 5000;
	CommRate = 0.05;
}
void salesmanager::pay()
{
	cout << "请输入" << employee::name << "所管部门本月的总额:";
	cin >> sales;
	accumPay = monthlyPay + CommRate*sales;  //月薪=固定月薪+销售提成
	cout << "销售经理" << name << "编号" << individualEmpNo << "本月工资" << accumPay << endl;
}
void salesmanager::displayStatus()
{
	cout << "销售经理" << name << "编号" << individualEmpNo << "级别为" << grade << "级，已付本月工资" << accumPay << endl;
}

//主函数
void main()
{
	cout << "这是一个经理:";
	manager m1;
	m1.promote(3); //经理提升3级
	m1.pay();
	m1.displayStatus();

	cout << "\n这是一个兼职技术类人员：";
	technician t1;
	t1.promote(2);  //t1提升2级
	t1.pay();
	t1.displayStatus();

	cout << "\n这是一个销售经理：";
	salesmanager sm1;
	sm1.promote(2);  //sm1提升2级
	sm1.pay();
	sm1.displayStatus();

	cout << "\n这是一个兼职推销员：";
	salesman s1;
	s1.pay();
	s1.displayStatus();
}