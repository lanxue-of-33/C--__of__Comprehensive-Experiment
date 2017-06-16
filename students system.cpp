#include<iostream>
#include<string>
 //清屏函数
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
	int StudentNum;  //学生学号
	string  name;  //学生姓名
	bool sex;     //学生性别
	Date date;    //出生日期
	int english;  //英语
	int math;     //数学
	int chinese;  //语文
	int physical; //物理
	int Chemistrt; //化学
	int biological;//生物
	int phisical_education;//体育
	int political; //政治
	int history;  //历史
	int geography;//地理
    double average_score;//平均成绩
public:
	static int up;  //用于统计输入的学生人数
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
	void inset(); //输入学生信息
	//学生信息查询函数
	friend void name_inquiry(); //按姓名查询
	friend void StudentNum_inquiry(); //按学号查询
	friend void boy_girl_number();  //查询男生女生人数
	friend void number_of_all();  //查询当前学生总人数
	//学生信息输出函数
	friend void display();  //输出全部学生信息
	//排序函数
	friend void sort();  //排序函数
}stu[MAX];
int student::up = 0;//人数的初始化

//输入学生信息的函数
void student::inset()
{
	cout << "情请输入学生的学号：";  cin >> StudentNum;
	cout << "请输入学生的姓名：";  cin >> name;
	cout << "请输入学生的性别（1-男生，0-女生）";  cin >> sex;
	cout << "接下来请输入该生的出生日期：" << endl;
	cout << "该生出生年份为："; cin >> date.year;
	cout << "该生出生月份为："; cin >> date.month;
	cout << "该生出生日期为："; cin >> date.day;
	cout << "接下来请输入各科成绩:" << endl;
	cout << "请输入英语成绩:";  cin >> english;
	cout << "请输入数学成绩:";  cin >> math;
	cout << "请输入语文成绩:";  cin >> chinese;
	cout << "请输入物理成绩:";  cin >> physical;
	cout << "请输入化学成绩:";  cin >> Chemistrt;
	cout << "请输入生物成绩:";  cin >> biological;
	cout << "请输入体育成绩:";  cin >> phisical_education;
	cout << "请输入政治成绩:";  cin >> political;
	cout << "请输入历史成绩:";  cin >> history;
	cout << "请输入地理成绩:";  cin >> geography;
	average_score = (english + math + chinese + physical + Chemistrt + biological + phisical_education + political + history + geography) / 10;
	cout << "计算后其十门课的平均成绩为:" << average_score << endl<<endl<<endl;
}

//学生信息查询函数
void name_inquiry()  //按学生姓名来查询
{
	string name;
	int i, num;
	cout << "请输入你要查询的姓名："; cin >> name;
	num = student::up;
	for ( i = 1; i <= num; i++)
	{
		if (stu[i].name==name) break;
	}
	if (i > num)
	{
		cout << "查无此人！" << endl << endl;
		return;
	}
	//查到了，显示学生信息
	cout << "你查找的该生基本信息如下："<< endl;
	cout << "姓名：" << stu[i].name << endl;
	cout << "学号：" << stu[i].StudentNum << endl;
	cout << "性别：";
	if (stu[i].sex)
		cout << "男" << endl;
	else
		cout << "女" << endl;
	cout << "生日：" << stu[i].date.year << "年" << stu[i].date.month << "月" << stu[i].date.day <<"日"<< endl;
	cout << "请问你需要查看该生的具体成绩吗？" << endl;
	int choice;
	cout << "请输入你的选择（1-要，0-不要）："; cin >> choice;
	if (choice)
	{
		cout << "英语成绩为：" << stu[i].english << endl;
		cout << "数学成绩为：" << stu[i].math << endl;
		cout << "语文成绩为：" << stu[i].chinese<< endl;
		cout << "物理成绩为：" << stu[i].physical << endl;
		cout << "化学成绩为：" << stu[i].Chemistrt<< endl;
		cout << "生物成绩为：" << stu[i].biological<< endl;
		cout << "体育成绩为：" << stu[i].phisical_education<< endl;
		cout << "政治成绩为：" << stu[i].political << endl;
		cout << "历史成绩为：" << stu[i].history<< endl;
		cout << "地理成绩为：" << stu[i].geography << endl;
		cout << "平均成绩为:" << stu[i].average_score << endl;
	}
}
void StudentNum_inquiry() //按学号查询学生
{
	int i, num,find;
	num = student::up;
	cout << "请输入你要查找的学号：";  cin >> find;
	for (i = 1; i <= num; i++)
	{
		if (stu[i].getStudentNum() == find) break;
	}
	if (i > num)
	{
		cout << "查无此人！" << endl;
		return;
	}
	//查到了，显示学生信息
	cout << "你查找该生的信息如下：" << endl;
	cout << "姓名：" << stu[i].getName() << endl;
	cout << "学号：" << stu[i].getStudentNum() << endl;
	cout << "性别：";
	if (stu[i].getSex())
		cout << "男" << endl;
	else
		cout << "女" << endl;
	cout << "生日：" << stu[i].date.year << "年" << stu[i].date.month << "月" << stu[i].date.day << "日" << endl;
	cout << "请问你需要查看该生的具体成绩吗？" << endl;
	int choice;
	cout << "请输入你的选择（1-要，0-不要）："; cin >> choice;
	if (choice)
	{
		cout << "英语成绩为：" << stu[i].english << endl;
		cout << "数学成绩为：" << stu[i].math << endl;
		cout << "语文成绩为：" << stu[i].chinese << endl;
		cout << "物理成绩为：" << stu[i].physical << endl;
		cout << "化学成绩为：" << stu[i].Chemistrt << endl;
		cout << "生物成绩为：" << stu[i].biological << endl;
		cout << "体育成绩为：" << stu[i].phisical_education << endl;
		cout << "政治成绩为：" << stu[i].political << endl;
		cout << "历史成绩为：" << stu[i].history << endl;
		cout << "地理成绩为：" << stu[i].geography << endl;
		cout << "平均成绩为:" << stu[i].average_score << endl;
	}
}
void boy_girl_number()  //查询男生女生人数
{
	int i, num;
	num = student::up;
	int s1 = 0, s2 = 0; //分别存储男生，女生人数
	for (i = 1; i <= num; i++)
	{
		if (stu[i].getSex())
			s1++;
		else
			s2++;
	}
	cout << "\t\t\t男生人数为：" << s1 << endl;
	cout << "\t\t\t女生人数为：" << s2 << endl;
}
void number_of_all()
{
	cout << "\t\t\t当前录入的学生总人数为：" << student::up << endl;
}
//输出全部学生信息
void display()
{
	int i, num,choice;
	num = student::up;
	cout << "请问需要输出成绩吗？（1-要，0-不要）" << endl;
	cout << "请输入你的选择："; cin >> choice;
	for (i = 1; i <= num; i++)
	{
		cout << "第" << i << "个学生的基本信息：" << endl;
		cout << "姓名：" << stu[i].name << endl;
		cout << "学号：" << stu[i].getStudentNum() << endl;
		cout << "性别：" ;
		if (stu[i].getSex())
			cout << "男" << endl;
		else
			cout << "女" << endl;
		if (choice)
		{
			cout << "英语成绩为：" << stu[i].english << endl;
			cout << "数学成绩为：" << stu[i].math << endl;
			cout << "语文成绩为：" << stu[i].chinese << endl;
			cout << "物理成绩为：" << stu[i].physical << endl;
			cout << "化学成绩为：" << stu[i].Chemistrt << endl;
			cout << "生物成绩为：" << stu[i].biological << endl;
			cout << "体育成绩为：" << stu[i].phisical_education << endl;
			cout << "政治成绩为：" << stu[i].political << endl;
			cout << "历史成绩为：" << stu[i].history << endl;
			cout << "地理成绩为：" << stu[i].geography << endl;
			cout << "平均成绩为:" << stu[i].average_score << endl;
		}
	}
}
//排序函数
void sort()
{
	int i,p,j, num; //j是用来交换数组的小标的
	string tName; //用来交换的名字
	int tStudentNum; //用来交换学号
	bool tSex; //用来交换性别
	int tYear, tMonth, tDay; //交换出生日期
	int tEnglish, tMath, tChinese, tPhysical, tChemistrt, tBiological,tPhisical_education, tPolitical, tHistory, tGeography, tAverage_score;
	int choice;
	num = student::up;
	cout << "----------------------排序方式选择菜单---------------------" << endl;
	cout << "---\t\t\t1.按英语成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t2.按数学成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t3.按语文成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t4.按物理成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t5.按化学成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t6.按生物成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t7.按体育成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t8.按政治成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t9.按历史成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t10.按地理成绩排序\t\t\t---" << endl;
	cout << "---\t\t\t11.按平均成绩排序\t\t\t---" << endl;
	cout << "----------------------排序方式选择菜单---------------------" << endl;
	cout << "请输入你的选择："; cin >> choice;
	system("cls");
	switch (choice)
	{
	case 1:
	{
		for (i = 1; i <= num; i++)
		{
			p = i;
			for (j = p + 1; j <= num; j++)
				if (stu[i].getEnglish() < stu[j].getEnglish())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex=tSex; //交换性别
			//交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay= stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getMath() < stu[j].getMath())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getChinese() < stu[j].getChinese())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getPhysical() < stu[j].getPhysical())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getChemistrt() < stu[j].getChemistrt())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getBiological() < stu[j].getBiological())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getPhisical_education() < stu[j].getPhisical_education())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getPolitical() < stu[j].getPolitical())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getHistory() < stu[j].getHistory())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getGeography() < stu[j].getGeography())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
				if (stu[i].getAverage_score() < stu[j].getAverage_score())  //找到当前为排序元素中成绩最小的对象的下标
					p = j;
			if (p == i) continue;
			//下面交换两个人的信息
			tName = stu[i].name; stu[i].name = stu[p].name; stu[p].name = tName;  //交换姓名
			tStudentNum = stu[i].getStudentNum(); stu[i].StudentNum = stu[p].getStudentNum(); stu[p].StudentNum = tStudentNum; //交换学号
			tSex = stu[i].sex; stu[i].sex = stu[p].sex; stu[p].sex = tSex; //交换性别
																		   //交换出生日期
			tYear = stu[i].date.year; stu[i].date.year = stu[p].date.year; stu[p].date.year = tYear;
			tMonth = stu[i].date.month; stu[i].date.month = stu[p].date.month; stu[p].date.month = tMonth;
			tDay = stu[i].date.day; stu[i].date.day = stu[p].date.day; stu[p].date.day = tDay;
			//交换成绩
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
	cout << "交换成功！" << endl;
}
int main()
{
	int choice;
	int fun;
	do
	{
		cout << "\t\t\t--------欢迎来到主功能菜单界面-------\t\t\t" << endl<<endl;
		cout << "\t\t\t-\t请输入要选择的功能:         -\t\t\t"<<endl<<endl;
		cout << "\t\t\t-\t1-录入学生信息              -\t\t\t\t"<<endl<<endl;
		cout << "\t\t\t-\t2-查询学生信息              -\t\t\t\t" << endl<<endl;
		cout << "\t\t\t-\t3-排序                      -\t\t\t\t\t"<<endl<<endl;
		cout << "\t\t\t-\t4-输出全部学生信息          -\t\t\t\t"<<endl<<endl;
		cout << "\t\t\t-\t0-退出                      -\t\t\t\t\t" << endl << endl;
		cout << "\t\t\t-------欢迎来到主功能菜单界面--------\t\t\t" << endl << endl;
		cout << "\t\t\t"; cin >> fun;
		system("cls");//清屏
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
				cout << "\t\t\t-------欢迎来到查询功能界面-----------------" << endl << endl;
				cout << "\t\t\t-\t请输入你要查询的方式：             -" << endl << endl;
				cout << "\t\t\t-\t\t1-按姓名查询                   -" << endl << endl;
				cout << "\t\t\t-\t\t2-按学号查询                   -" << endl << endl;
				cout << "\t\t\t-\t\t3-查询男女人数                 -" << endl << endl;
				cout << "\t\t\t-\t\t4-查询总人数                   -" << endl << endl;
				cout << "\t\t\t-\t\t0-退出                         -" << endl << endl;
				cout << "\t\t\t-------欢迎来到查询功能界面---------------" << endl << endl;
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
				cout <<endl<<endl<< "\t\t\t你要继续查询学生信息吗？（1-是，0-不是）" << endl;
				cout << "\t\t\t请输入你的选择："; cin >> continue_choice;
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
		cout << "\t\t\t请输入你的选择（1-回到主功能菜单，0-退出程序）：";
		cin >> choice;//清屏
		system("cls");
	} while (choice);
}