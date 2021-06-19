#include <string>
#include <iostream>
using namespace std;

#define MAX 1000

struct Person
{
	string m_Name;
	string m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};

struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size;
};

int isExist(Addressbooks* abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
	}
	return -1;
}

void showMenu()
{
	cout << "**************************" << endl;
	cout << " ***** 0.退出通讯录 *****" << endl;
	cout << " ***** 1.添加联系人 *****" << endl;
	cout << " ***** 2.显示联系人 *****" << endl;
	cout << " ***** 3.删除联系人 *****" << endl;
	cout << " ***** 4.查找联系人 *****" << endl;
	cout << " ***** 5.修改联系人 *****" << endl;
	cout << " ***** 6.清空联系人 *****" << endl;
	cout << "**************************" << endl;
	cout << "  请输入你要使用的功能：";
}

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "通讯录已满，无法添加" << endl;
		return;
	}
	else
	{
		string name;
		cout << "请输入姓名：";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		string sex = "";
		while (true)
		{
			cout << "请输入性别：";
			cin >> sex;
			if (sex == "男" || sex == "女")
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！！！" << endl;
			system("pause");
			system("cls");
		}

		int age = 0;
		cout << "请输入年龄：";
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请输入电话：";
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入住址：";
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size += 1;
		cout << "更新通讯录成功！！！" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "当前记录为空！！！" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名：" << abs->personArray[i].m_Name << "\t";
			cout << "性别：" << abs->personArray[i].m_Sex << "\t";
			cout << "年龄：" << abs->personArray[i].m_Age << "\t";
			cout << "电话：" << abs->personArray[i].m_Phone << "\t";
			cout << "住址：" << abs->personArray[i].m_Addr << endl;;
		}
	}
	system("pause");
	system("cls");
}

void deletePerson(Addressbooks* abs)
{
	string name;
	cout << "请输入你要删除的联系人：";
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
			cout << "删除成功!!!" << endl;
			abs->m_Size--;
		}
	}
	else
	{
		cout << "查无此人!!!" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入你要查找的联系人：";
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "姓名：" << abs->personArray[ret].m_Name << "\t";
		cout << "性别：" << abs->personArray[ret].m_Sex << "\t";
		cout << "年龄：" << abs->personArray[ret].m_Age << "\t";
		cout << "电话：" << abs->personArray[ret].m_Phone << "\t";
		cout << "住址：" << abs->personArray[ret].m_Addr << endl;;
	}
	else
	{
		cout << "查无此人！！！" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入你要修改的联系人：";
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "请输入姓名：";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		string sex = "";
		while (true)
		{
			cout << "请输入性别：";
			cin >> sex;
			if (sex == "男" || sex == "女")
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误，请重新输入！！！" << endl;
			system("pause");
			system("cls");
		}

		int age = 0;
		cout << "请输入年龄：";
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "请输入电话：";
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "请输入住址：";
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		cout << "修改成功！！！" << endl;
	}
	else
	{
		cout << "查无此人！！！" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "通讯录已清空！！！" << endl;
	system("pause");
	system("cls");
}

int main()
{
	Addressbooks abs;
	abs.m_Size = 0;

	int select = 0;

	while (true)
	{
		showMenu();
		cin >> select;
		switch (select)
		{
		case 0:
			system("cls");
			cout << "欢迎下次再使用！！!"<< endl;
			system("pause"); 
			return 0;
		case 1:
			system("cls");
			addPerson(&abs);
			break;
		case 2:
			system("cls");
			showPerson(&abs);
			break;
		case 3:
			system("cls");
			deletePerson(&abs);
			break;
		case 4:
			system("cls");
			findPerson(&abs);
			break;
		case 5:
			system("cls");
			modifyPerson(&abs);
			break;
		case 6:
			system("cls");
			cleanPerson(&abs);
			break;
		}
	}
}