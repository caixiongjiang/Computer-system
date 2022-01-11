#include"orderFile.h"

//构造函数
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;//日期
	string interval;//时间段
	string stuId;//学生编号
	string stuName;//学生姓名
	string roomId;//机房id号
	string status;//预约状态

	this->m_Size = 0;//预约条数

	while (ifs >> date && ifs >> interval && ifs >> stuId 
		&& ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*测试代码
		cout << date << endl;
		cout << interval << endl;
		cout << stuId << endl;
		cout << stuName << endl;
		cout << roomId << endl;
		cout << status << endl;
		cout << endl;
		*/


		string key;
		string value;
		unordered_map<string, string> mp;

		//divideS(date, mp);  //日期
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);//从位置0开始截取pos长度的字符串
			value = date.substr(pos + 1);//截取从pos+1的位置到末尾

			mp.insert(make_pair(key, value));
		}
		//divideS(interval, mp);  //时间段
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);//从位置0开始截取pos长度的字符串
			value = interval.substr(pos + 1);//截取从pos+1的位置到末尾

			mp.insert(make_pair(key, value));
		}
		//divideS(stuId, mp);  //学生号
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);//从位置0开始截取pos长度的字符串
			value = stuId.substr(pos + 1);//截取从pos+1的位置到末尾

			mp.insert(make_pair(key, value));
		}
		//divideS(stuName, mp);  //学生姓名
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);//从位置0开始截取pos长度的字符串
			value = stuName.substr(pos + 1);//截取从pos+1的位置到末尾

			mp.insert(make_pair(key, value));
		}
		//divideS(roomId, mp);  //机房号
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);//从位置0开始截取pos长度的字符串
			value = roomId.substr(pos + 1);//截取从pos+1的位置到末尾

			mp.insert(make_pair(key, value));
		}
		//divideS(status, mp); //状态信息 
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);//从位置0开始截取pos长度的字符串
			value = status.substr(pos + 1);//截取从pos+1的位置到末尾

			mp.insert(make_pair(key, value));
		}

		//将小map容器放入到大的map容器中
		this->m_orderData.insert(make_pair(this->m_Size, mp));
		this->m_Size++;
	}
	ifs.close();

	/*测试最大的map容器
	for (unordered_map<int, unordered_map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "条数 = " << it->first << " value =" << endl;
		for (unordered_map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			cout << " key = " << mit->first << " value =" << mit->second << " ";
		}
		cout << endl;
	}
	*/
	
}

//更新预约
void OrderFile::updateOrder()
{
	
}

//分割字符串
//void OrderFile::divideS(string& s, unordered_map<string, string>& mp)
//{
//	string key;
//	string value;
//
//	int pos = -1;
//	for (int i = 0; i < s.size(); i++)
//	{
//		if (s[i] == ':') pos = i;
//	}
//	key = s.substr(0, pos);
//	value = s.substr(pos + 1, s.size() - pos - 1);
//
//	mp.insert(key, value);
//}
