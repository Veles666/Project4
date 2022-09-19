#include <iostream>
#include <string>
#include <vector>
#include<algorithm>	
#include<fstream>
using namespace std;
class Phone
{
public:
	void SetNumberPhone();
	string GetNumberPhone();
	string NumberPhone;

private:

};


class Information :public Phone
{
public:
	Information();
	void SetLastName();
	void SetYear();
	void SetAdress();
	string GetLastName();
	short GetYear();
	string GetAdress();
	int GetId();
private:
	static int id;
	string LastName;
	short Year = 0;
	string Adress;
	int idr;
	friend istream& operator>>(istream& is, Information& inf);
	friend ostream& operator<<(ostream& os, Information& inf);

};
int Information::id = 0;


istream& operator>>(istream& is, Information& inf)
{
	is >> inf.LastName >> inf.Year >> inf.NumberPhone >> inf.Adress;
	return is;
}
ostream& operator<<(ostream& os, Information& inf)
{
	os << inf.LastName << ' ' << inf.Year << ' ' << inf.NumberPhone << ' ' << inf.Adress;
	return os;
}
typedef vector<Information> Students;
void Menu(Students& List);
void ReadFile(Students& List);
void ShowMenu();
void AddInf(Students& List);
void DeleteInf(Students& List);
void SortInf(Students& List);
void ShowList(Students& List);
void ShowNumber(Students& List);
int main()
{
	setlocale(LC_ALL, "Russian");
	Students List;
	Menu(List);

	return 0;
}

void Menu(Students& List)
{
	ReadFile(List);
	char ch = ' ';
	while (ch != '0')
	{
		ShowMenu();
		cin >> ch;
		switch (ch)
		{
		case '1':
			AddInf(List);
			break;
		case '2':
			DeleteInf(List);
			break;
		case '3':
			SortInf(List);

		case '4':
			ShowList(List);
			break;
		case '5':
			ShowNumber(List);
		}
	}
}

void ReadFile(Students& List)
{
	ifstream fin;
	fin.open("Data.txt");
	while (true)
	{
		Information a;
		fin >> a;
		if (fin.eof())
			break;
		List.push_back(a);
	}
	fin.close();
}

void ShowMenu()
{
	cout << "�������� ����� �����." << endl;
	cout << "1.��������" << endl;
	cout << "2.�������" << endl;
	cout << "3.�����������" << endl;
	cout << "4.������� ������" << endl;
	cout << "5.������� ����� ��������" << endl;
	cout << "0.�����" << endl;
}

void AddInf(Students& List)
{
	Information Temp;
	cout << "������� �������" << endl;
	Temp.SetLastName();
	cout << "������� ���" << endl;
	Temp.SetYear();
	cout << "������� �����" << endl;
	Temp.SetNumberPhone();
	cout << "������� ������" << endl;
	Temp.SetAdress();
	List.push_back(Temp);
	ofstream fout;
	fout.open("Data.txt", ios_base::app);
	fout << Temp << endl;
}

void DeleteInf(Students& List)
{
	for (auto& elem : List)
	{
		cout << elem << endl << "���� ��-�� - " << elem.GetId() << endl;
	}
	int a;
	bool flag = 1;
	while (flag and !List.empty())
	{
		cout << "������� ID ���������� ��-��" << endl;
		cin >> a;
		for (auto i = 0; i < List.size(); ++i)
		{
			if (List[i].GetId() == a)
			{
				List.erase(List.begin() + i);
				flag = 0;
			}
		}
	}
	ofstream fout;
	fout.open("Data.txt");
	for (auto& elem : List)
	{
		fout << elem << endl;
	}
	fout.close();
}

void SortInf(Students& List)
{
	cout << "�������� �� ���� �����������" << endl;
	cout << "1.�������" << endl;
	cout << "2.���" << endl;
	cout << "3.�����" << endl;
	cout << "4.������" << endl;
	char ch = ' ';
	cin >> ch;
	switch (ch)
	{
	case '1':
		sort(List.begin(), List.end(), [](Information& a, Information& b) {return a.GetLastName() > b.GetLastName(); });
		break;
	case '2':
		sort(List.begin(), List.end(), [](Information& a, Information& b) {return a.GetYear() < b.GetYear(); });
		break;
	case '3':
		sort(List.begin(), List.end(), [](Information& a, Information& b) {return a.GetNumberPhone() < b.GetNumberPhone(); });
		break;
	case '4':
		sort(List.begin(), List.end(), [](Information& a, Information& b) {return a.GetAdress() < b.GetAdress(); });
		break;
	}
	ofstream fout;
	fout.open("Data.txt");
	for (auto& elem : List)
	{
		fout << elem << endl;
	}
	fout.close();

}

void ShowList(Students& List)
{
	for (auto& elem : List)
	{
		cout << elem << endl;
	}
}

void ShowNumber(Students& List)
{
	cout << "�� ���� ����?" << endl;
	cout << "1.�������" << endl;
	cout << "2.������" << endl;
	char ch = ' ';
	string Name;
	cin >> ch;
	bool flag = 0;
	ofstream fout;
	fout.open("Result.txt");
	switch (ch)
	{
	case '1':
		cout << "������� �������" << endl;
		cin >> Name;
		for (auto i = 0; i < List.size(); ++i)
		{
			if (List[i].GetLastName() == Name)
			{
				cout << Name << '=' << List[i].GetNumberPhone() << endl;
				fout << Name << '=' << List[i].GetNumberPhone() << endl;
				flag = 1;
			}

		}
		if (flag)
			break;
		cout << "�� ������� " << Name << " ������ �� ��������" << endl;
		fout << "�� ������� " << Name << " ������ �� ��������" << endl;
		break;
	case '2':
		cout << "������� ������" << endl;
		cin >> Name;
		for (auto i = 0; i < List.size(); ++i)
		{
			if (List[i].GetAdress() == Name)
			{
				cout << Name << '=' << List[i].GetNumberPhone() << endl;
				fout << Name << '=' << List[i].GetNumberPhone() << endl;
				flag = 1;
			}
		}
		if (flag)
			break;
		cout << "�� ������� " << Name << " ������ �� ��������" << endl;
		fout << "�� ������� " << Name << " ������ �� ��������" << endl;
		break;
	}
	fout.close();
}


Information::Information()
{
	idr = id;
	++id;
}

void Information::SetLastName()
{
	cin >> this->LastName;
}

void Information::SetYear()
{
	cin >> this->Year;
}

void Phone::SetNumberPhone()
{
	cin >> this->NumberPhone;
}

void Information::SetAdress()
{
	cin >> this->Adress;
}

string Information::GetLastName()
{
	return LastName;
}

short Information::GetYear()
{
	return Year;
}

string Phone::GetNumberPhone()
{
	return NumberPhone;
}

string Information::GetAdress()
{
	return Adress;
}

int Information::GetId()
{
	return this->idr;
}
