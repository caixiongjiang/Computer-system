#pragma once
#include<iostream>
using namespace std;
#include"globalFile.h"
#include<fstream>
#include <unordered_map>
#include<string>
#include<cstdlib>

class OrderFile
{
public:
	
	//���캯��
	OrderFile();

	//����ԤԼ
	void updateOrder();

	//�ָ��ַ���
	//void divideS(string& s, unordered_map<string, string>& mp);

	//��¼ԤԼ����
	int m_Size;

	//��¼����ԤԼ��Ϣ������  key1����¼����  value������ļ�ֵ����Ϣ<���ԣ� ֵ>
	unordered_map<int, unordered_map<string, string>> m_orderData;
};

