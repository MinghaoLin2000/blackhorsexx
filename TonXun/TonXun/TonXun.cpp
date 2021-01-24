#include<iostream>
#include<string>
using namespace std;
#define MAX 1000
//设计联系人的结构体
struct Person {
	//姓名
	string m_Name;
	//性别 1男 2女
	int m_Sex;
		//年龄
		int m_Age;
	//电话
		string m_Phone;
	//住址
		string m_Addr;
};
//设计通讯录的结构体
struct Addressbooks {
	//通讯录中保存的联系人数组
	struct Person personArray[MAX];
	//现在的保存的人数
	int m_Size;
};
//1.添加联系人
void addPerson(Addressbooks *abs)
{
	//判断通讯录是否已满
	if (abs->m_Size==MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		//添加具体联系人
		//姓名
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//性别
		cout << "请输入性别: " << endl;
		cout << "1 --- 男" << endl;
		cout << "2 --- 女" << endl;
		int sex = 0;
		while (true)
		{
			//如果输入的是1或2可以退出循环，输入错误要重新进入循环
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		
		//年龄
		cout << "请输入年龄: " << endl;
		int age = 0;
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;
		//电话
		cout << "请输入联系电话:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;
		//住址
		cout << "请输入家庭住址:" << endl;
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;
		//更新通讯录人数
		abs->m_Size++;
		cout << "添加成功!" << endl;
		system("pause"); //请按任意键继续
		system("cls");//清屏
	}
}
void showPerson(Addressbooks *abs)
{
	//判断通讯录中人数是否为0，如果为0，提示记录为空
	//如果不为0，显示记录的联系人信息
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名: " << abs->personArray[i].m_Name << "\t";
			cout << "性别: " << (abs->personArray[i].m_Sex == 1 ? "男" : "女") << "\t";
			cout << "年龄: " << abs->personArray[i].m_Age << "\t";
			cout << "电话: " << abs->personArray[i].m_Phone << "\t";
			cout << "住址: " << abs->personArray[i].m_Addr << "\t";
		}
	}
	system("pause");
	system("cls");
}
//检测联系人是否存在,如果存在，返回联系人所在数组的具体位置，不存在返回-1
int isExist(Addressbooks *abs,string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		//找到用户输入的姓名
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	//如果没找到就返回-1
	return -1;

}
//3.删除指定联系人
void deletePerson(Addressbooks* abs)
{
	cout << "请输入要删除人的名称" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		//查找到人，要进行删除操作
		for (int i = ret; i < abs->m_Size - 1; i++)
		{
			//数据迁移
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--; //更新人数
		cout << "删除成功" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//4.查找指定联系人信息
void findPerson(Addressbooks* abs)
{
	cout << "请输入您要查找的联系人r" << endl;
	string name;
	cin >> name;
	//判断指定的联系人是否存在联系人中
	int ret=isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名: " << abs->personArray[ret].m_Name << "\t";
		cout << "性别: " << (abs->personArray[ret].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄: " << abs->personArray[ret].m_Age << "\t";
		cout << "电话: " << abs->personArray[ret].m_Phone << "\t";
		cout << "住址: " << abs->personArray[ret].m_Addr << "\t";
	}
	else
	{
		cout << "查无此人" << endl;
	}
	//任意键按下后，清屏
	system("pause");
	system("cls");
}
//5.修改指定联系人信息
void modifyPerson(Addressbooks* abs)
{
	cout << "请输入要修改的联系人" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1) //找到指定的联系人
	{
		//姓名
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[ret].m_Name = name;
		//性别
		cout << "请输入性别" << endl;
		cout << "1 -- 男" << endl;
		cout << "2 -- 女" << endl;
		int sex = 0;
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[ret].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入" << endl;
		}
		//年龄
		cout << "请输入年龄" << endl;
		int age = 0;
		cin >> age;
		abs->personArray[ret].m_Age = age;
		//电话
		cout << "请输入联系方式:" << endl;
		string phone;
		cin >> phone;
		abs->personArray[ret].m_Phone = phone;
		//住址
		cout << "请输入家庭住址" << endl;
		string address;
		cin >> address;
		abs->personArray[ret].m_Addr = address;
		cout << "修改成功" << endl;

	}
	else //未找到指定联系人
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//清空联系人
void cleanPerson(Addressbooks *abs)
{
	abs->m_Size = 0; //将当前记录人联系人置为0
	cout << "通讯录已经被清空" << endl;
	system("pause");
	system("cls");
}
//菜单界面
void showMenu()
{
	cout << "*****  1. 添加联系人  *****" << endl;
	cout << "*****  2. 显示联系人  *****" << endl;
	cout << "*****  3. 删除联系人  *****" << endl;
	cout << "*****  4.	查找联系人  *****" << endl;
	cout << "*****  5. 修改联系人  *****" << endl;
	cout << "*****  6. 清空联系人  *****" << endl;
	cout << "*****  0. 退出通讯录  *****" << endl;
}
int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;
	//通讯录当前个数为0
	abs.m_Size = 0;

	int select = 0;
	while (true)
	{
		//菜单调用
		showMenu();
		cin >> select;
		switch (select)
		{
		case 1:  //添加联系人
			addPerson(&abs); //利用地址传递，可以修饰实参
			break;
		case 2:  //显示联系人
			showPerson(&abs);
			break;
		case 3: //删除联系人
			deletePerson(&abs);
			break;
		case 4: //查找联系人
			findPerson(&abs);
			break;
		case 5: //修改联系人
			modifyPerson(&abs);
			break;
		case 6: //清空联系人
			break;
		case 0: //退出通讯录
			cout << "欢迎下次使用" << endl;
			system("pause");
			return 0;
			break;
		default:
			break;
		}
	};


}