#include"orderFile.h"

//���캯��
OrderFile::OrderFile()
{
	ifstream ifs;
	ifs.open(ORDER_FILE, ios::in);

	string date;//����
	string interval;//ʱ���
	string stuId;//ѧ�����
	string stuName;//ѧ������
	string roomId;//����id��
	string status;//ԤԼ״̬

	this->m_Size = 0;//ԤԼ����

	while (ifs >> date && ifs >> interval && ifs >> stuId 
		&& ifs >> stuName && ifs >> roomId && ifs >> status)
	{
		/*���Դ���
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

		//divideS(date, mp);  //����
		int pos = date.find(":");
		if (pos != -1)
		{
			key = date.substr(0, pos);//��λ��0��ʼ��ȡpos���ȵ��ַ���
			value = date.substr(pos + 1);//��ȡ��pos+1��λ�õ�ĩβ

			mp.insert(make_pair(key, value));
		}
		//divideS(interval, mp);  //ʱ���
		pos = interval.find(":");
		if (pos != -1)
		{
			key = interval.substr(0, pos);//��λ��0��ʼ��ȡpos���ȵ��ַ���
			value = interval.substr(pos + 1);//��ȡ��pos+1��λ�õ�ĩβ

			mp.insert(make_pair(key, value));
		}
		//divideS(stuId, mp);  //ѧ����
		pos = stuId.find(":");
		if (pos != -1)
		{
			key = stuId.substr(0, pos);//��λ��0��ʼ��ȡpos���ȵ��ַ���
			value = stuId.substr(pos + 1);//��ȡ��pos+1��λ�õ�ĩβ

			mp.insert(make_pair(key, value));
		}
		//divideS(stuName, mp);  //ѧ������
		pos = stuName.find(":");
		if (pos != -1)
		{
			key = stuName.substr(0, pos);//��λ��0��ʼ��ȡpos���ȵ��ַ���
			value = stuName.substr(pos + 1);//��ȡ��pos+1��λ�õ�ĩβ

			mp.insert(make_pair(key, value));
		}
		//divideS(roomId, mp);  //������
		pos = roomId.find(":");
		if (pos != -1)
		{
			key = roomId.substr(0, pos);//��λ��0��ʼ��ȡpos���ȵ��ַ���
			value = roomId.substr(pos + 1);//��ȡ��pos+1��λ�õ�ĩβ

			mp.insert(make_pair(key, value));
		}
		//divideS(status, mp); //״̬��Ϣ 
		pos = status.find(":");
		if (pos != -1)
		{
			key = status.substr(0, pos);//��λ��0��ʼ��ȡpos���ȵ��ַ���
			value = status.substr(pos + 1);//��ȡ��pos+1��λ�õ�ĩβ

			mp.insert(make_pair(key, value));
		}

		//��Сmap�������뵽���map������
		this->m_orderData.insert(make_pair(this->m_Size, mp));
		this->m_Size++;
	}
	ifs.close();

	/*��������map����
	for (unordered_map<int, unordered_map<string, string>>::iterator it = m_orderData.begin(); it != m_orderData.end(); it++)
	{
		cout << "���� = " << it->first << " value =" << endl;
		for (unordered_map<string, string>::iterator mit = it->second.begin(); mit != it->second.end(); mit++)
		{
			cout << " key = " << mit->first << " value =" << mit->second << " ";
		}
		cout << endl;
	}
	*/
	
}

//����ԤԼ
void OrderFile::updateOrder()
{
	
}

//�ָ��ַ���
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
