#pragma once
#include<iostream>
using namespace std;
#include "identity.h"
#include<fstream>
#include "globalFile.h"
#include "student.h"
#include "teacher.h"
#include <vector>
#include <algorithm>

//管理员类
class Manager : public Identity
{
public:
	//默认构造
	Manager();

	//有参构造
	Manager(string name, string pwd);

	//菜单界面
	virtual void openMenu();

	//添加账号
	void addPerson();

	//查看账号
	void showPerson();

	//查看机房信息
	void showComputer();

	//清空预约信息
	void cleanFile();

	//初始化容器
	void initVector();

	//检测重复  参数1  检测学号/职工号  参数2 检测类型
	bool checkRepeat(int id, int type);
	
	//学生容器
	vector<Student> vStu;

	//教师容器
	vector<Teacher> vTea;

};