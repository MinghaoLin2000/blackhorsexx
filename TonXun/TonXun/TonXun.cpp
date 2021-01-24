#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//�����ϵ�˵Ľṹ��
struct Person {
	//����
	string m_Name;
	//�Ա� 1�� 2Ů
	int m_Sex;
		//����
		int m_Age;
	//�绰
		string m_Phone;
	//סַ
		string m_Addr;
};
//���ͨѶ¼�Ľṹ��
struct Addressbooks {
	//ͨѶ¼�б������ϵ������
	struct Person personArray[MAX];
	//���ڵı��������
	int m_Size;
};
//1.�����ϵ��
void addPerson(Addressbooks *abs)
{
	//�ж�ͨѶ¼�Ƿ�����
	if (abs->m_Size==MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		//��Ӿ�����ϵ��
		//����
		string name;
		cout << "����������: " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�Ա�
		cout << "�������Ա�: " << endl;
		cout << "1 --- ��" << endl;
		cout << "2 --- Ů" << endl;
		int sex = 0;
		while (true)
		{
			//����������1��2�����˳�ѭ�����������Ҫ���½���ѭ��
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		
		//����
		cout << "����������: " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//�绰
		cout << "��������ϵ�绰:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//����ͨѶ¼����
		abs->m_Size++;
		cout << "��ӳɹ�!" << endl;
		system("pause"); //�밴���������
		system("cls");//����
	}
}
void showPerson(Addressbooks *abs)
{
	//�ж�ͨѶ¼�������Ƿ�Ϊ0�����Ϊ0����ʾ��¼Ϊ��
	//�����Ϊ0����ʾ��¼����ϵ����Ϣ
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ��" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����: " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�: " << (abs->personArray[i].m_Sex == 1 ? "��" : "Ů") << "\t";
			cout << "����: " << abs->personArray[i].m_Age << "\t";
			cout << "�绰: " << abs->personArray[i].m_Phone << "\t";
			cout << "סַ: " << abs->personArray[i].m_Addr << "\t";
		}
	}
	system("pause");
	system("cls");
}
//�����ϵ���Ƿ����,������ڣ�������ϵ����������ľ���λ�ã������ڷ���-1
int isExist(Addressbooks *abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//�ҵ��û����������
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	//���û�ҵ��ͷ���-1
	return -1;

}
//3.ɾ��ָ����ϵ��
void deletePerson(Addressbooks* abs)
{
	cout << "������Ҫɾ���˵�����" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		//���ҵ��ˣ�Ҫ����ɾ������
		for (int i = ret; i < abs->m_Size - 1; i++)
		{
			//����Ǩ��
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //��������
		cout << "ɾ���ɹ�" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//4.����ָ����ϵ����Ϣ
void findPerson(Addressbooks* abs)
{
	cout << "��������Ҫ���ҵ���ϵ��r" << endl;
	string name;
	cin >> name;
	//�ж�ָ������ϵ���Ƿ������ϵ����
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "����: " << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�: " << (abs->personArray[ret].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "����: " << abs->personArray[ret].m_Age << "\t";
		cout << "�绰: " << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ: " << abs->personArray[ret].m_Addr << "\t";
	}
	else
	{
		cout << "���޴���" << endl;
	}
	//��������º�����
	system("pause");
	system("cls");
}
//5.�޸�ָ����ϵ����Ϣ
void modifyPerson(Addressbooks* abs)
{
	cout << "������Ҫ�޸ĵ���ϵ��" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1) //�ҵ�ָ������ϵ��
	{
		//����
		string name;
		cout << "����������: " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//�Ա�
		cout << "�������Ա�" << endl;
		cout << "1 -- ��" << endl;
		cout << "2 -- Ů" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "������������������" << endl;
		}
		//����
		cout << "����������" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//�绰
		cout << "��������ϵ��ʽ:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//סַ
		cout << "�������ͥסַ" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "�޸ĳɹ�" << endl;

	}
	else //δ�ҵ�ָ����ϵ��
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//�����ϵ��
void cleanPerson(Addressbooks *abs)
{
	abs->m_Size = 0; //����ǰ��¼����ϵ����Ϊ0
	cout << "ͨѶ¼�Ѿ������" << endl;
	system("pause");
	system("cls");
}
//�˵�����
void showMenu()
{
	cout << "*****  1. �����ϵ��  *****" << endl;
	cout << "*****  2. ��ʾ��ϵ��  *****" << endl;
	cout << "*****  3. ɾ����ϵ��  *****" << endl;
	cout << "*****  4.	������ϵ��  *****" << endl;
	cout << "*****  5. �޸���ϵ��  *****" << endl;
	cout << "*****  6. �����ϵ��  *****" << endl;
	cout << "*****  0. �˳�ͨѶ¼  *****" << endl;
}
int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;
	//ͨѶ¼��ǰ����Ϊ0
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		//�˵�����
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  //�����ϵ��
			addPerson(&abs); //���õ�ַ���ݣ���������ʵ��
			break;
		case 2:  //��ʾ��ϵ��
			showPerson(&abs);
			break;
		case 3: //ɾ����ϵ��
			deletePerson(&abs);
			break;
		case 4: //������ϵ��
			findPerson(&abs);
			break;
		case 5: //�޸���ϵ��
			modifyPerson(&abs);
			break;
		case 6: //�����ϵ��
			break;
		case 0: //�˳�ͨѶ¼
			cout << "��ӭ�´�ʹ��" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	};


}