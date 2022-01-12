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
	
	//构造函数
	OrderFile();

	//更新预约
	void updateOrder();

	//分割字符串
	//void divideS(string& s, unordered_map<string, string>& mp);

	//记录预约条数
	int m_Size;

	//记录所有预约信息的容器  key1：记录条数  value：具体的键值对信息<属性， 值>
	unordered_map<int, unordered_map<string, string>> m_orderData;
};

