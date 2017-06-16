#include<iostream>
#include<string.h>
#include"Company personnel information management.h"
using namespace std;
int employee::employeeNo = 1000;  //Ա����Ż���Ϊ1000

employee::employee()
{
	char namestr[20];  //�����Ա����ʱ������ʱ�����namestr��
	cout << "�����뱾��Ա��������";
	cin >> namestr;
	name = new char[strlen(namestr) + 1];  //��̬�������ڴ���������ڴ�ռ�
	strcpy(name, namestr);  //����ʱ��ŵ��������Ƶ�name
	individualEmpNo = employeeNo++;  //�������Ա�������Ϊ��ǰ�����ֵ��1
	grade = 1;  //�����ֵΪ1
	accumPay = 0.0;//��н�ܶ��ֵΪ0
}
employee::~employee()
{
	delete[]name;  //������������ɾ��Ϊ���������̬������ڴ�ռ�
}
void employee::promote(int increment)  //��������
{
	grade += increment;  //�����ļ�����increment����
}

technician::technician()  ////��ְ������Ա��
{
	hourlyRate = 100;  //ÿСʱн��Ϊ100Ԫ
}
void technician::pay()
{
	cout << "������" << name << "���µĹ���ʱ��";
	cin >> workHours;  //������н����Сʱ�Ƴ�
	accumPay = hourlyRate*workHours;
	cout << "��ְ ������Ա" << name << "���" << individualEmpNo << "���¹���" << accumPay << endl;
}
void technician::displayStatus()
{
	cout << "��ְ������Ա" << name << "���" << individualEmpNo << "����Ϊ" << grade << "�����Ѹ����¹���" << accumPay << endl;
}
salesman::salesman()  //��ְ����Ա��
{
	CommRate = 0.04;  //������ɱ���4%
}
void salesman::pay()
{
	cout << "������" << name << "���µ����۶";
	cin >> sales;
	accumPay = sales*CommRate;  //��н=�������
	cout << "����Ա" << name << "���" << individualEmpNo << "���¹���" << accumPay << endl;
}
void salesman::displayStatus()
{
	cout << "����Ա" << name << "���" << individualEmpNo << "����Ϊ" << grade << "�����Ѹ����¹���" << accumPay << endl;
}
manager::manager()   //������
{
	monthlyPay = 8000;  //�̶���нΪ8000Ԫ
}
void manager::pay()
{
	accumPay = monthlyPay;  //��н�ܶΪ�̶���н��
	cout << "����" << name << "���" << individualEmpNo << "���¹���" << accumPay << endl;
}
void manager::displayStatus()
{
	cout << "����" << name << "���" << individualEmpNo << "����Ϊ" << grade << "����һ�����¹���" << accumPay << endl;
}
salesmanager::salesmanager()   //���۾�����
{
	monthlyPay = 5000;
	CommRate = 0.05;
}
void salesmanager::pay()
{
	cout << "������" << employee::name << "���ܲ��ű��µ��ܶ�:";
	cin >> sales;
	accumPay = monthlyPay + CommRate*sales;  //��н=�̶���н+�������
	cout << "���۾���" << name << "���" << individualEmpNo << "���¹���" << accumPay << endl;
}
void salesmanager::displayStatus()
{
	cout << "���۾���" << name << "���" << individualEmpNo << "����Ϊ" << grade << "�����Ѹ����¹���" << accumPay << endl;
}

//������
void main()
{
	cout << "����һ������:";
	manager m1;
	m1.promote(3); //��������3��
	m1.pay();
	m1.displayStatus();

	cout << "\n����һ����ְ��������Ա��";
	technician t1;
	t1.promote(2);  //t1����2��
	t1.pay();
	t1.displayStatus();

	cout << "\n����һ�����۾���";
	salesmanager sm1;
	sm1.promote(2);  //sm1����2��
	sm1.pay();
	sm1.displayStatus();

	cout << "\n����һ����ְ����Ա��";
	salesman s1;
	s1.pay();
	s1.displayStatus();
}