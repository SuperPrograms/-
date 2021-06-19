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
	cout << " ***** 0.�˳�ͨѶ¼ *****" << endl;
	cout << " ***** 1.�����ϵ�� *****" << endl;
	cout << " ***** 2.��ʾ��ϵ�� *****" << endl;
	cout << " ***** 3.ɾ����ϵ�� *****" << endl;
	cout << " ***** 4.������ϵ�� *****" << endl;
	cout << " ***** 5.�޸���ϵ�� *****" << endl;
	cout << " ***** 6.�����ϵ�� *****" << endl;
	cout << "**************************" << endl;
	cout << "  ��������Ҫʹ�õĹ��ܣ�";
}

void addPerson(Addressbooks* abs)
{
	if (abs->m_Size == MAX)
	{
		cout << "ͨѶ¼�������޷����" << endl;
		return;
	}
	else
	{
		string name;
		cout << "������������";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		string sex = "";
		while (true)
		{
			cout << "�������Ա�";
			cin >> sex;
			if (sex == "��" || sex == "Ů")
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡����" << endl;
			system("pause");
			system("cls");
		}

		int age = 0;
		cout << "���������䣺";
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "������绰��";
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "������סַ��";
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		abs->m_Size += 1;
		cout << "����ͨѶ¼�ɹ�������" << endl;
		system("pause");
		system("cls");
	}
}

void showPerson(Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "��ǰ��¼Ϊ�գ�����" << endl;
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "������" << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�" << abs->personArray[i].m_Sex << "\t";
			cout << "���䣺" << abs->personArray[i].m_Age << "\t";
			cout << "�绰��" << abs->personArray[i].m_Phone << "\t";
			cout << "סַ��" << abs->personArray[i].m_Addr << endl;;
		}
	}
	system("pause");
	system("cls");
}

void deletePerson(Addressbooks* abs)
{
	string name;
	cout << "��������Ҫɾ������ϵ�ˣ�";
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		for (int i = ret; i < abs->m_Size; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
			cout << "ɾ���ɹ�!!!" << endl;
			abs->m_Size--;
		}
	}
	else
	{
		cout << "���޴���!!!" << endl;
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks* abs)
{
	string name;
	cout << "��������Ҫ���ҵ���ϵ�ˣ�";
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		cout << "������" << abs->personArray[ret].m_Name << "\t";
		cout << "�Ա�" << abs->personArray[ret].m_Sex << "\t";
		cout << "���䣺" << abs->personArray[ret].m_Age << "\t";
		cout << "�绰��" << abs->personArray[ret].m_Phone << "\t";
		cout << "סַ��" << abs->personArray[ret].m_Addr << endl;;
	}
	else
	{
		cout << "���޴��ˣ�����" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs)
{
	string name;
	cout << "��������Ҫ�޸ĵ���ϵ�ˣ�";
	cin >> name;

	int ret = isExist(abs, name);
	if (ret != -1)
	{
		string name;
		cout << "������������";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;

		string sex = "";
		while (true)
		{
			cout << "�������Ա�";
			cin >> sex;
			if (sex == "��" || sex == "Ů")
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "�����������������룡����" << endl;
			system("pause");
			system("cls");
		}

		int age = 0;
		cout << "���������䣺";
		cin >> age;
		abs->personArray[abs->m_Size].m_Age = age;

		cout << "������绰��";
		string phone = "";
		cin >> phone;
		abs->personArray[abs->m_Size].m_Phone = phone;

		cout << "������סַ��";
		string address;
		cin >> address;
		abs->personArray[abs->m_Size].m_Addr = address;

		cout << "�޸ĳɹ�������" << endl;
	}
	else
	{
		cout << "���޴��ˣ�����" << endl;
	}
	system("pause");
	system("cls");
}

void cleanPerson(Addressbooks* abs)
{
	abs->m_Size = 0;
	cout << "ͨѶ¼����գ�����" << endl;
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
			cout << "��ӭ�´���ʹ�ã���!"<< endl;
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