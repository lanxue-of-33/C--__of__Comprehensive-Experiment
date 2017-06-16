#include<iostream>
#include<string>
 //��������
using namespace std;
#define MAX 100
#include<cstdlib>

struct Date
{
	int year;
	int month;
	int day;
};
class student
{
private:
	int StudentNum;  //ѧ��ѧ��
	string  name;  //ѧ������
	bool sex;     //ѧ���Ա�
	Date date;    //��������
	int english;  //Ӣ��
	int math;     //��ѧ
	int chinese;  //����
	int physical; //����
	int Chemistrt; //��ѧ
	int biological;//����
	int phisical_education;//����
	int political; //����
	int history;  //��ʷ
	int geography;//����
    double average_score;//ƽ���ɼ�
public:
	static int up;  //����ͳ�������ѧ������
	int getStudentNum() { return StudentNum; }
	string getName() { return name; }
	bool getSex() { return sex; }
	int getEnglish() { return english; }
	int getMath() { return math; }
	int getChinese() { return chinese; }
	int getPhysical() { return physical; }
	int getChemistrt() { return Chemistrt; }
	int getBiological() { return biological; }
	int getPhisical_education() { return phisical_education; }
	int getPolitical() { return political; }
	int getHistory() { return history; }
	int getGeography() { return geography; }
	double getAverage_score() { return average_score; }
	void inset(); //����ѧ����Ϣ
	//ѧ����Ϣ��ѯ����
	friend void name_inquiry(); //��������ѯ
	friend void StudentNum_inquiry(); //��ѧ�Ų�ѯ
	friend void boy_girl_number();  //��ѯ����Ů������
	friend void number_of_all();  //��ѯ��ǰѧ��������
	//ѧ����Ϣ�������
	friend void display();  //���ȫ��ѧ����Ϣ
	//������
	friend void sort();  //������
}stu[MAX];
int student::up = 0;//�����ĳ�ʼ��

//����ѧ����Ϣ�ĺ���
void student::inset()
{
	cout << "��������ѧ����ѧ�ţ�";  cin >> StudentNum;
	cout << "������ѧ����������";  cin >> name;
	cout << "������ѧ�����Ա�1-������0-Ů����";  cin >> sex;
	cout << "����������������ĳ������ڣ�" << endl;
	cout << "�����������Ϊ��"; cin >> date.year;
	cout << "���������·�Ϊ��"; cin >> date.month;
	cout << "������������Ϊ��"; cin >> date.day;
	cout << "��������������Ƴɼ�:" << endl;
	cout << "������Ӣ��ɼ�:";  cin >> english;
	cout << "��������ѧ�ɼ�:";  cin >> math;
	cout << "���������ĳɼ�:";  cin >> chinese;
	cout << "����������ɼ�:";  cin >> physical;
	cout << "�����뻯ѧ�ɼ�:";  cin >> Chemistrt;
	cout << "����������ɼ�:";  cin >> biological;
	cout << "�����������ɼ�:";  cin >> phisical_education;
	cout << "���������γɼ�:";  cin >> political;
	cout << "��������ʷ�ɼ�:";  cin >> history;
	cout << "���������ɼ�:";  cin >> geography;
	average_score = (english + math + chinese + physical + Chemistrt + biological + phisical_education + political + history + geography) / 10;
	cout << "�������ʮ�ſε�ƽ���ɼ�Ϊ:" << average_score << endl<<endl<<endl;
}

//ѧ����Ϣ��ѯ����
void name_inquiry()  //��ѧ����������ѯ
{
	string name;
	int i, num;
	cout << "��������Ҫ��ѯ��������"; cin >> name;
	num = student::up;
	for ( i = 1; i <= num; i++)
	{
		if (stu[i].name==name) break;
	}
	if (i > num)
	{
		cout << "���޴��ˣ�" << endl << endl;
		return;
	}
	//�鵽�ˣ���ʾѧ����Ϣ
	cout << "����ҵĸ���������Ϣ���£�"<< endl;
	cout << "������" << stu[i].name << endl;
	cout << "ѧ�ţ�" << stu[i].StudentNum << endl;
	cout << "�Ա�";
	if (stu[i].sex)
		cout << "��" << endl;
	else
		cout << "Ů" << endl;
	cout << "���գ�" << stu[i].date.year << "��" << stu[i].date.month << "��" << stu[i].date.day <<"��"<< endl;
	cout << "��������Ҫ�鿴�����ľ���ɼ���" << endl;
	int choice;
	cout << "���������ѡ��1-Ҫ��0-��Ҫ����"; cin >> choice;
	if (choice)
	{
		cout << "Ӣ��ɼ�Ϊ��" << stu[i].english << endl;
		cout << "��ѧ�ɼ�Ϊ��" << stu[i].math << endl;
		cout << "���ĳɼ�Ϊ��" << stu[i].chinese<< endl;
		cout << "����ɼ�Ϊ��" << stu[i].physical << endl;
		cout << "��ѧ�ɼ�Ϊ��" << stu[i].Chemistrt<< endl;
		cout << "����ɼ�Ϊ��" << stu[i].biological<< endl;
		cout << "�����ɼ�Ϊ��" << stu[i].phisical_education<< endl;
		cout << "���γɼ�Ϊ��" << stu[i].political << endl;
		cout << "��ʷ�ɼ�Ϊ��" << stu[i].history<< endl;
		cout << "����ɼ�Ϊ��" << stu[i].geography << endl;
		cout << "ƽ���ɼ�Ϊ:" << stu[i].average_score << endl;
	}
}
void StudentNum_inquiry() //��ѧ�Ų�ѯѧ��
{
	int i, num,find;
	num = student::up;
	cout << "��������Ҫ���ҵ�ѧ�ţ�";  cin >> find;
	for (i = 1; i <= num; i++)
	{
		if (stu[i].getStudentNum() == find) break;
	}
	if (i > num)
	{
		cout << "���޴��ˣ�" << endl;
		return;
	}
	//�鵽�ˣ���ʾѧ����Ϣ
	cout << "����Ҹ�������Ϣ���£�" << endl;
	cout << "������" << stu[i].getName() << endl;
	cout << "ѧ�ţ�" << stu[i].getStudentNum() << endl;
	cout << "�Ա�";
	if (stu[i].getSex())
		cout << "��" << endl;
	else
		cout << "Ů" << endl;
	cout << "���գ�" << stu[i].date.year << "��" << stu[i].date.month << "��" << stu[i].date.day << "��" << endl;
	cout << "��������Ҫ�鿴�����ľ���ɼ���" << endl;
	int choice;
	cout << "���������ѡ��1-Ҫ��0-��Ҫ����"; cin >> choice;
	if (choice)
	{
		cout << "Ӣ��ɼ�Ϊ��" << stu[i].english << endl;
		cout << "��ѧ�ɼ�Ϊ��" << stu[i].math << endl;
		cout << "���ĳɼ�Ϊ��" << stu[i].chinese << endl;
		cout << "����ɼ�Ϊ��" << stu[i].physical << endl;
		cout << "��ѧ�ɼ�Ϊ��" << stu[i].Chemistrt << endl;
		cout << "����ɼ�Ϊ��" << stu[i].biological << endl;
		cout << "�����ɼ�Ϊ��" << stu[i].phisical_education << endl;
		cout << "���γɼ�Ϊ��" << stu[i].political << endl;
		cout << "��ʷ�ɼ�Ϊ��" << stu[i].history << endl;
		cout << "����ɼ�Ϊ��" << stu[i].geography << endl;
		cout << "ƽ���ɼ�Ϊ:" << stu[i].average_score << endl;
	}
}
void boy_girl_number()  //��ѯ����Ů������
{
	int i, num;
	num = student::up;
	int s1 = 0, s2 = 0; //�ֱ�洢������Ů������
	for (i = 1; i <= num; i++)
	{
		if (stu[i].getSex())
			s1++;
		else
			s2++;
	}
	cout << "\t\t\t��������Ϊ��" << s1 << endl;
	cout << "\t\t\tŮ������Ϊ��" << s2 << endl;
}
void number_of_all()
{
	cout << "\t\t\t��ǰ¼���ѧ��������Ϊ��" << student::up << endl;
}
//���ȫ��ѧ����Ϣ
void display()
{
	int i, num,choice;
	num = student::up;
	cout << "������Ҫ����ɼ��𣿣�1-Ҫ��0-��Ҫ��" << endl;
	cout << "���������ѡ��"; cin >> choice;
	for (i = 1; i <= num; i++)
	{
		cout << "��" << i << "��ѧ���Ļ�����Ϣ��" << endl;
		cout << "������" << stu[i].name << endl;
		cout << "ѧ�ţ�" << stu[i].getStudentNum() << endl;
		cout << "�Ա�" ;
		if (stu[i].getSex())
			cout << "��" << endl;
		else
			cout << "Ů" << endl;
		if (choice)
		{
			cout << "Ӣ��ɼ�Ϊ��" << stu[i].english << endl;
			cout << "��ѧ�ɼ�Ϊ��" << stu[i].math << endl;
			cout << "���ĳɼ�Ϊ��" << stu[i].chinese << endl;
			cout << "����ɼ�Ϊ��" << stu[i].physical << endl;
			cout << "��ѧ�ɼ�Ϊ��" << stu[i].Chemistrt << endl;
			cout << "����ɼ�Ϊ��" << stu[i].biological << endl;
			cout << "�����ɼ�Ϊ��" << stu[i].phisical_education << endl;
			cout << "���γɼ�Ϊ��" << stu[i].political << endl;
			cout << "��ʷ�ɼ�Ϊ��" << stu[i].history << endl;
			cout << "����ɼ�Ϊ��" << stu[i].geography << endl;
			cout << "ƽ���ɼ�Ϊ:" << stu[i].average_score << endl;
		}
	}
}
//������
void sort()
{
	int i,p,j, num; //j���������������С���
	string tName; //��������������
	int tStudentNum; //��������ѧ��
	bool tSex; //���������Ա�
	int tYear, tMonth, tDay; //������������
	int tEnglish, tMath, tChinese, tPhysical, tChemistrt, tBiological,tPhisical_education, tPolitical, tHistory, tGeography, tAverage_score;
	int choice;
	num = student::up;
	cout << "----------------------����ʽѡ��˵�---------------------" << endl;
	cout << "---\t\t\t1.��Ӣ��ɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t2.����ѧ�ɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t3.�����ĳɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t4.������ɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t5.����ѧ�ɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t6.������ɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t7.�������ɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t8.�����γɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t9.����ʷ�ɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t10.������ɼ�����\t\t\t---" << endl;
	cout << "---\t\t\t11.��ƽ���ɼ�����\t\t\t---" << endl;
	cout << "----------------------����ʽѡ��˵�---------------------" << endl;
	cout << "���������ѡ��"; cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getEnglish() < stu[j].getEnglish())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex=tSex; //�����Ա�
			//������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay= stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese=tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical=tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt=tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 2:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getMath() < stu[j].getMath())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 3:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getChinese() < stu[j].getChinese())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 4:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getPhysical() < stu[j].getPhysical())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 5:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getChemistrt() < stu[j].getChemistrt())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 6:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getBiological() < stu[j].getBiological())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 7:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getPhisical_education() < stu[j].getPhisical_education())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 8:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getPolitical() < stu[j].getPolitical())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 9:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getHistory() < stu[j].getHistory())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 10:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getGeography() < stu[j].getGeography())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	case 11:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getAverage_score() < stu[j].getAverage_score())  //�ҵ���ǰΪ����Ԫ���гɼ���С�Ķ�����±�
					p = j;
			if (p == i) continue;
			//���潻�������˵���Ϣ
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //��������
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //����ѧ��
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //�����Ա�
																		   //������������
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//�����ɼ�
			tEnglish = stu[i].english; stu[i].english = stu[p].english; stu[p].english = tEnglish;
			tMath = stu[i].math; stu[i].math = stu[p].math; stu[p].math = tMath;
			tChinese = stu[i].chinese; stu[i].chinese = stu[p].chinese; stu[p].chinese = tChinese;
			tPhysical = stu[i].physical; stu[i].physical = stu[p].physical; stu[p].physical = tPhysical;
			tChemistrt = stu[i].Chemistrt; stu[i].Chemistrt = stu[p].Chemistrt; stu[p].Chemistrt = tChemistrt;
			tBiological = stu[i].biological; stu[i].biological = stu[p].biological; stu[p].biological = tBiological;
			tPhisical_education = stu[i].phisical_education; stu[i].phisical_education = stu[p].phisical_education; stu[p].phisical_education = tPhisical_education;
			tPolitical = stu[i].political; stu[i].political = stu[p].political; stu[p].political = tPolitical;
			tHistory = stu[i].history; stu[i].history = stu[p].history; stu[p].history = tHistory;
			tGeography = stu[i].geography; stu[i].geography = stu[p].geography; stu[p].geography = tGeography;
			tAverage_score = stu[i].average_score; stu[i].average_score = stu[p].average_score; stu[p].average_score = tAverage_score;
		}
	}
	default:
		break;
	}
	cout << "�����ɹ���" << endl;
}
int main()
{
	int choice;
	int fun;
	do
	{
		cout << "\t\t\t--------��ӭ���������ܲ˵�����-------\t\t\t" << endl<<endl;
		cout << "\t\t\t-\t������Ҫѡ��Ĺ���:         -\t\t\t"<<endl<<endl;
		cout << "\t\t\t-\t1-¼��ѧ����Ϣ              -\t\t\t\t"<<endl<<endl;
		cout << "\t\t\t-\t2-��ѯѧ����Ϣ              -\t\t\t\t" << endl<<endl;
		cout << "\t\t\t-\t3-����                      -\t\t\t\t\t"<<endl<<endl;
		cout << "\t\t\t-\t4-���ȫ��ѧ����Ϣ          -\t\t\t\t"<<endl<<endl;
		cout << "\t\t\t-\t0-�˳�                      -\t\t\t\t\t" << endl << endl;
		cout << "\t\t\t-------��ӭ���������ܲ˵�����--------\t\t\t" << endl << endl;
		cout << "\t\t\t"; cin >> fun;
		system("cls");//����
		switch (fun)
		{
		case 1:
			student::up++;
			stu[student::up].inset(); break;
		case 2:
		{
			int continue_choice;
			do
			{
				int choice_inquiry;
				cout << "\t\t\t-------��ӭ������ѯ���ܽ���-----------------" << endl << endl;
				cout << "\t\t\t-\t��������Ҫ��ѯ�ķ�ʽ��             -" << endl << endl;
				cout << "\t\t\t-\t\t1-��������ѯ                   -" << endl << endl;
				cout << "\t\t\t-\t\t2-��ѧ�Ų�ѯ                   -" << endl << endl;
				cout << "\t\t\t-\t\t3-��ѯ��Ů����                 -" << endl << endl;
				cout << "\t\t\t-\t\t4-��ѯ������                   -" << endl << endl;
				cout << "\t\t\t-\t\t0-�˳�                         -" << endl << endl;
				cout << "\t\t\t-------��ӭ������ѯ���ܽ���---------------" << endl << endl;
				cout << "\t\t\t"; cin >> choice_inquiry;
				system("cls");
				switch (choice_inquiry)
				{
				case 1:
					name_inquiry(); break;
				case 2:
					StudentNum_inquiry(); break;
				case 3:
					boy_girl_number(); break;
				case 4:
					number_of_all(); break;
				default:
					break;
				}
				cout <<endl<<endl<< "\t\t\t��Ҫ������ѯѧ����Ϣ�𣿣�1-�ǣ�0-���ǣ�" << endl;
				cout << "\t\t\t���������ѡ��"; cin >> continue_choice;
				system("cls");
			} while (continue_choice);
		}break;
		case 3:
			sort(); break;
		case 4:
			display(); break;
		default:
			exit(1); break;
		}
		cout << "\t\t\t���������ѡ��1-�ص������ܲ˵���0-�˳����򣩣�";
		cin >> choice;//����
		system("cls");
	} while (choice);
}