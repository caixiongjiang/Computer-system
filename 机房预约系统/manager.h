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

//����Ա��
class Manager : public Identity
{
public:
	//Ĭ�Ϲ���
	Manager();

	//�вι���
	Manager(string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//����˺�
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��Ϣ
	void cleanFile();

	//��ʼ������
	void initVector();

	//����ظ�  ����1  ���ѧ��/ְ����  ����2 �������
	bool checkRepeat(int id, int type);
	
	//ѧ������
	vector<Student> vStu;

	//��ʦ����
	vector<Teacher> vTea;

};