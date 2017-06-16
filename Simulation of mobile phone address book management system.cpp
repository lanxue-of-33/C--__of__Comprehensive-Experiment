#include<iostream>
#include<string>
#include<Windows.h>
using namespace std;
struct  Information
{
	//������
	string name;  //����
	string  phoneName; //�绰����
	char type;   //���ࣨ�칫�࣬�����࣬�����ࣩ
	char email[20] = { 0 };  //�����ʼ�
	int up=0;    //���
	//ָ����
	Information *next;
};
class person
{
	Information *head;
public:
	person() { head = NULL; }
	void insertPerson();  //������ϵ�˹���
	void deletePerson();  //ɾ����ϵ�˹���
	void changePerson();  //�޸����ݹ���
	void findPersong();   //�鿴���ܣ����칫�࣬�����࣬������鿴
	void showAll();       //��ʾ������ϵ��
	void dial();          //���Ź���
	Information *gethead() { return head; }  //ȡ�ڵ��׵�ַ����
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
void person::insertPerson()  //������ϵ�˹���
{
	Information *s;
	Information *p, *num;
	p = head; 
	int Num=1;
	s = new Information;
	cout << "��Ҫ�������ϵ�˵������ǣ�" << endl; cin >> s->name;
	cout << "��Ҫ��ӵ���ϵ�˵ĵ绰�����ǣ�" << endl; cin >> s->phoneName;
	cout << "��Ҫ��ӵ���ϵ�˵ķ����ǣ�A���칫�࣬B-�����࣬C�������ࣩ��"<<endl; cin >> s->type;
	cout <<"��Ҫ��ӵ���ϵ�˵������ַ�ǣ�" << endl; cin >> s->email;
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
		}    //ʹpָ��ָ����������һ��������ʵ�ֽ��½���������������
		p->next = s;
		s->next = NULL;
	}
	num = head;
	if (head == NULL)
		cout << "�޴�����!"<<endl;
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
void person::showAll()  //��ʾ������ϵ����Ϣ
{
	Information *p = head;
	cout << '\t' << "����" << '\t' << "�绰����" << '\t' << '\t' << "����" << '\t' << "����" <<'\t'<<'\t'<< "���"<<endl;
	cout << "---------------------------------------------------------------------------------------------------------" << endl;
	if (head == NULL)
	{
		cout << "ʧ�ܣ�" << endl;
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
//�鿴���ܣ����칫�࣬�����࣬������鿴
void person::findPersong()
{
	Information *p = head;
	char a = 'A'; char b = 'B'; char c = 'C';
	int  choice;
	cout << "��������Ҫ�鿴�ķ�ʽ��1���칫�࣬2-�����࣬3-�����ࣩ";
	cin >> choice;
	switch (choice)
	{
	case 1:
	{
		if (head == NULL)
			cout << "������û�����ݣ�" << endl;
		else
		{
			cout << '\t' << "����" << '\t' << "�绰����" << '\t' << '\t' << '\t' << "����" << '\t' << "����" << '\t' << '\t' << '\t' << "���" << endl;
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
			cout << "������û�����ݣ�" << endl;
		else
		{
			cout << '\t' << "����" << '\t' << "�绰����" << '\t' << '\t' << '\t' << "����" << '\t' << "����" << '\t' << '\t' << '\t' << "���" << endl;
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
			cout << "������û�����ݣ�" << endl;
		else
		{
			cout << '\t' << "����" << '\t' << "�绰����" << '\t' << '\t' << '\t' << "����" << '\t' << "����" << '\t' << '\t' << '\t' << "���" << endl;
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
//�޸����ݹ���
void person::changePerson()
{
	Information *p = head, *q = head;
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ�˵�����"; cin >> name;
	if (head == NULL)
		cout << "�������ڣ�" << endl;
	else
		while (p != NULL)
		{
			if (p->name == name)
			{
				cout << "���������޸ĺ�����֣�"; cin >> p->name;
				int i; cout << "������Ҫ�޸ĵ绰������1-Ҫ��0-��Ҫ��"; cin >> i; 
				switch (i)
				{
				case 1:
				{
					cout << endl << "���������޸ĺ�ĵ绰���룺"; cin >> p->phoneName;
				}break;
				default:
					break;
				}
				int j; cout << "������Ҫ�޸ķ�����1-Ҫ��0-��Ҫ��"; cin >> j;
				switch (j)
				{
				case 1:
				{
					cout << endl << "���������޸ĺ�ķ��ࣺ"; cin >> p->type;
				}break;
				default:
					break;
				}
				int k; cout << "������Ҫ�����ַ��1-Ҫ��0-��Ҫ��"; cin >> k;
				switch (k)
				{
				case 1:
				{
					cout << endl << "���������޸ĺ�������ַ��"; cin >> p->email;
				}break;
				default:
					break;
				}
			}
			p = p->next;
		}
	//������Ҫ�޸ı�ŵ�
	return;
}

//ɾ����ϵ�˹���
void person::deletePerson()
{
	Information *p, *q; //pָ������ָ��Ҫɾ���Ľ�㣬q����ָ��Ҫɾ����ǰһ�����
	string deleteName;  //deleteName��������Ҫɾ���Ľ���е����ݳ�Ա
	cout << "��������Ҫɾ������ϵ�˵�������"; cin >> deleteName;
	p = head;
	if (p == NULL) //�������Ϊ����ֱ���˳�
		return;
	if (p->name == deleteName) //���Ҫɾ�����ǵ�һ����ϵ�˵Ļ�������Ҫ��ͷָ��head ������һ�����
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
		if (p->name == deleteName)  //�����������Ҫɾ������ϵ�˵������Ļ�
		{
			q->next = p->next;
			delete p;
		}
	}
	//Ҫ�ƶ������
	Information *num; int number=1;
	num = head;
	while (num!=NULL)
	{
		num->up = number;
		number++;
		num = num->next;
	}
	cout << "ɾ���ɹ���" << endl;
	return;
}

//���Ź���
void person::dial()
{
	//int a[20]; long b;
	//Information *p = head;
	//int len; len = strlen(p->phoneName.c_str());
	//b = atoi(p->phoneName.c_str());  //��string����ת����char*�ڵ���atoi����,�����ַ������������
	//for (int i = len - 1; i >= 0; i--)
	//{
	//	a[i] = b % 10;
	//	b /= 10;
	//}
	Information *p = head;
	Information *q = head;
	string Name;
	cout << "d��������Ҫ�������ϵ�˵�������"; cin >> Name;
	if (p == NULL)
	{
		cout << "�޴���ϵ�ˣ�" << endl;
		return;
	}
	else
	{
		while (p!=NULL)
		{
			if (p->name == Name)
			{
				cout << "���ڿ�ʼ����**************" << endl;
				cout << "������������" << p->name << "����******" << endl;
				Sleep(1000); //�ӳ�1000����
				cout << "��ϲ�㣡���ųɹ���****" << endl;
			}
			p = p->next;
		}
		//cout << "�Բ����޴���ϵ�ˣ�" << endl;
	}
	while (q->next)
	{
		q = q->next;
	}
	//if(q->name!=Name)
	//	 cout << "�Բ����޴���ϵ�ˣ�" << endl;
	return;
}

//����������
void main()
{
	person A;
	int choice,fun;
	do
	{
		cout << "---------------------��ӭ�������˵�----------------------" << endl;
		cout << '\t' << '\t' << "1-������ϵ��" << endl<<endl;
		cout << '\t' << '\t' << "2-�鿴���ܣ����칫�࣬�����࣬������鿴" << endl<<endl;
		cout << '\t' << '\t' << "3-�޸����ݹ���" << endl<<endl;
		cout << '\t' << '\t' << "4-���Ź���" << endl << endl;
		cout << '\t' << '\t' << "5-ɾ����ϵ�˹���" << endl<<endl;
		cout << '\t' << '\t' << "6-��ʾ������ϵ��" << endl<<endl;
		cout << '\t' << '\t' << "0-�˳�����" << endl<<endl;
		cout << "---------------------��ӭ�������˵�----------------------" << endl;
		cout << "���������ѡ��";  cin >> fun;
		system(" cls");  //����
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
		cout <<'\t'<< "���������ѡ��1-�ص����˵���0-�˳�����"; cin >> choice;
		system("cls");
	} while (choice);
}