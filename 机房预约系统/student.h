#pragma once
#include<iostream>
using namespace std;
#include"identity.h"
#include<string>
#include"computerRoom.h"
#include<vector>
#include<fstream>
#include"globalFile.h"
#include"orderFile.h"

//ѧ����
class Student : public Identity
{
public:
	//Ĭ�Ϲ���
	Student();

	//�вι���  ������ѧ�ţ�����������
	Student(int id, string name, string pwd);

	//�˵�����
	virtual void openMenu();

	//����ԤԼ
	void applyOrder();

	//�鿴�����ԤԼ
	void showMyOrder();

	//�鿴����ԤԼ
	void showAllOrder();

	//ȡ��ԤԼ
	void cancelOrder();

	//ѧ��ѧ��
	int m_Id;

	//��������
	vector<ComputerRoom> vCom;
};