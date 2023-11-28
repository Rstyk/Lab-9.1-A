#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h> 

using namespace std;

enum Spec { КН, ПЗ, ФЛ, РІ };
string specStr[] = { "КН", "ПЗ", "ФЛ", "РІ" };
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
	cout << "Введіть N: "; cin >> N;
	Student* p = new Student[N];
	Create(p, N);
	Print(p, N);

	int Number1 = Physics(p, N);
	cout << "кількість оцінок відмінно з фізики:" << Number1 << endl;
	int Number2 = Math(p, N);
	cout << "кількість оцінок відмінно з математики:" << Number2 << endl;
	int Number3 = Inform(p, N);
	cout << "кількість оцінок відмінно з інформатики:" << Number3 << endl;

	int Number4 = Physics_Math(p, N);
	cout << "кількість студентів з відмінними оцінками з фіз. та мат.:" << Number4 << endl;

	return 0;
}

void Create(Student* p, const int N)
{
	int spec;
	for (int i = 0; i < N; i++)
	{
		cout << "Студент № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " прізвище: "; getline(cin, p[i].prizv);
		cout << " курс: "; cin >> p[i].kurs;
		cout << " спеціальність (0 - КН, 1 - ПЗ, 2 - ФЛ, 3 - РІ): ";
		cin >> spec;
		p[i].spec = (Spec)spec;
		cout << " оцінка з фізики: "; cin >> p[i].physics;
		cout << " оцінка з математики: "; cin >> p[i].math;
		cout << " оцінка з інформатики: "; cin >> p[i].inform;
		cout << endl;
	}
}

void Print(Student* p, const int N)
{
	cout << "========================================================================="
		<< endl;
	cout << "| № |   прізвище   | курс | спец. | фіз. | мат. | інф. |"
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

