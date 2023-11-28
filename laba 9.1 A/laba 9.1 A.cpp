#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Spec { ��, ��, ��, в };
string specStr[] = { "��", "��", "��", "в" };
struct Student
{
	string prizv;
	unsigned physics;
	unsigned math;
	unsigned inform;
	unsigned kurs;
	Spec spec;
	union
	{
		double taryf;
		int stavka;
	};
};
void Create(Student* p, const int N);
void Print(Student* p, const int N);
int Physics(Student* p, const int N);
int Math(Student* p, const int N);
int Inform(Student* p, const int N);
int Physics_Math(Student* p, const int N);

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "������ N: "; cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);

	int Number1 = Physics(p, N);
	cout << "������� ������ ������ � ������:" << Number1 << endl;
	int Number2 = Math(p, N);
	cout << "������� ������ ������ � ����������:" << Number2 << endl;
	int Number3 = Inform(p, N);
	cout << "������� ������ ������ � �����������:" << Number3 << endl;

	int Number4 = Physics_Math(p, N);
	cout << "������� �������� � �������� �������� � ���. �� ���.:" << Number4 << endl;

	return 0;
}

void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "������� � " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " �������: "; getline(cin, p[i].prizv);
		cout << " ����: "; cin >> p[i].kurs;
		cout << " ������������ (0 - ��, 1 - ��, 2 - ��, 3 - в): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		cout << " ������ � ������: "; cin >> p[i].physics;
		cout << " ������ � ����������: "; cin >> p[i].math;
		cout << " ������ � �����������: "; cin >> p[i].inform;
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| � |   �������   | ���� | ����. | ���. | ���. | ���. |"
		<< endl;
	cout << "-------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++)
	{
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(13) << right << p[i].prizv
			<< "| " << setw(4) << right << p[i].kurs << " "
			<< "| " << setw(6) << right << specStr[p[i].spec]
			<< "| " << setw(4) << right << p[i].physics << " "
			<< "| " << setw(4) << right << p[i].math << " "
			<< "| " << setw(4) << right << p[i].inform << " " << "|";
		cout << endl;
	}
	cout << "========================================================================="
		<< endl;
	cout << endl;
}

int Physics(Student* p, const int N)
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].physics == 5)
			n++;
	}
	return n;
}
int Math(Student* p, const int N)
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].math == 5)
			n++;
	}
	return n;
}
int Inform(Student* p, const int N)
{
	int n = 0;
	for (int i = 0; i < N; i++)
	{
		if (p[i].inform == 5)
			n++;
	}
	return n;
}
int Physics_Math(Student* p, const int N)
{
	int students = 0;

	for (int i = 0; i < N; i++) {
		if (p[i].physics == 5 && p[i].math == 5) {
			students++;
		}
	}
	return students;
}

