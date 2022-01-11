#include<iostream>
using namespace std;
#include "identity.h"
#include<fstream>
#include<string>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include "manager.h"


//进入学生的子菜单界面
void studentMenu(Identity* & student)
{
	while (true)
	{
		//调用学生子菜单
		student->openMenu();
		//强制转化子类对象的指针
		Student* stu = (Student *)student;

		int select = 0;
		cin >> select;//接收用户的选择

		if (select == 1)//申请预约
		{
			stu->applyOrder();
		}
		else if (select == 2)//查看自身预约
		{
			stu->showMyOrder();
		}
		else if (select == 3)//查看所有人的预约
		{
			stu->showAllOrder();
		}
		else if (select == 4)//取消预约
		{
			stu->cancelOrder();
		}
		else 
		{
			//注销登录
			delete student;
			cout << "注销成功！" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


//进入管理员的子菜单界面
void managerMenu(Identity*& manager)
{
	while (true)
	{
		//调用管理员的子菜单
		manager->openMenu();

		//将父类的指针 转为子类的指针，调用子类里其他接口
		Manager* man = (Manager*)manager;

		int select = 0;
		//接受用户的选择
		cin >> select;

		if (select == 1)//添加账号
		{
			man->addPerson();
		}
		else if (select == 2)//查看账号
		{
			man->showPerson();
		}
		else if (select == 3)//查看机房
		{
			man->showComputer();
		}
		else if (select == 4)//清空预约
		{
			cout << "是否清空预约" << endl;
			cout << "请按1确认" << endl;
			int isOrNot = -1;
			cin >> isOrNot;

			if (isOrNot == 1)
			{
				man->cleanFile();
			}
			cout << "清空失败" << endl;
			system("pause");
			system("cls");
		}
		else
		{
			//注销
			delete manager;//销毁掉堆区对象
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}

//登录功能 参数1：  操作文件名  参数2：操作身份类型
void Loginin(string fileName, int type) 
{
	//父类指针 用于指向子类对象
	Identity *person = NULL;

	//读文件
	ifstream ifs;
	ifs.open(fileName, ios::in);

	//判断文件是否存在
	if (!ifs.is_open())
	{
		cout << "文件不存在" << endl;
		ifs.close();
		return;
	}

	//准备接收用户的信息
	int id = 0;
	string name;
	string pwd;

	//判断身份
	if (type == 1)//学生身份
	{
		cout << "请输入你的学号：" << endl;
		cin >> id;
	}
	else if (type == 2)
	{
		cout << "请输入您的职工号：" << endl;
		cin >> id;
	}

	cout << "请输入用户名：" << endl;
	cin >> name;

	cout << "请输入密码：" << endl;
	cin >> pwd;

	if (type == 1)
	{
		//学生身份验证
		int fId;//从文件中读取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取密码

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{
			/* 测试代码
			cout << fId << endl;
			cout << fName << endl;
			cout << fPwd << endl;
			cout << endl;
			*/
			
			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "学生验证登录成功！" << endl;
				
				system("pause");
				system("cls");
				person = new Student(id, name, pwd);

				//进入学生身份的子菜单
				studentMenu(person);
				return;
			}
		}
	}
	else if (type == 2)
	{
		//教师身份验证
		int fId;//从文件中读取的id号
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取密码

		while (ifs >> fId && ifs >> fName && ifs >> fPwd)
		{

			//与用户输入的信息做对比
			if (fId == id && fName == name && fPwd == pwd)
			{
				cout << "教师验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Teacher(id, name, pwd);

				//进入教师身份的子菜单

				return;
			}
		}
	}
	else if (type == 3)
	{
		//管理员身份验证
		string fName;//从文件中获取的姓名
		string fPwd;//从文件中获取密码

		while (ifs >> fName && ifs >> fPwd)
		{

			//与用户输入的信息做对比
			if (fName == name && fPwd == pwd)
			{
				cout << "管理员验证登录成功！" << endl;
				system("pause");
				system("cls");
				person = new Manager(name, pwd);

				//进入管理员身份的子菜单
				managerMenu(person);
				return;
			}
		}
	}

	cout << "验证登录失败！" << endl;
	system("pause");
	system("cls");

	return;
}

int main()
{
	int select = 0;//用于接收用户的选择

	while (true) 
	{
		cout << "==================欢迎来到机房预约系统======================"
			<< endl;
		cout << endl << "请输入您的身份" << endl;
		cout << "\t\t ----------------------------------\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            1.学生代表            |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            2.老    师            |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            3.管 理 员            |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t|            0.退    出            |\n";
		cout << "\t\t|                                  |\n";
		cout << "\t\t ----------------------------------\n";
		cout << "请输入您的选择：";

		cin >> select;

		switch (select)//根据用户的选择 实现不同的接口
		{
		case 1://学生身份
			Loginin(STUDENT_FILE, 1);
			break;
		case 2://老师身份
			Loginin(TEACHER_FILE, 2);
			break;
		case 3://管理远身份
			Loginin(ADMIN_FILE, 3);
			break;
		case 0://退出系统
			cout << "欢迎下次使用！" << endl;
			system("pause");
			return 0;
			break;
		default:
			cout << "输入有误，请重新选择！" << endl;
			system("pause");
			system("cls");
			break;
		}
	}
	

	system("pause");
	return 0;
}