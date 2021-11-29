#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>


#define YEAR 6
#define NAME 12
#define COURSE 6
#define SUBJECT 9
#define NUMB 2
#define GROUP 6
using namespace std;


struct Student
{
	char surname[NAME]{};
	char name[NAME]{};
	char middlename[NAME]{};
	char group[GROUP]{};
	int course;
	int year;
	int sub1;
	int sub2;
	int sub3;

};
const int n = 15;
Student students[n] = {};
Student Buffer_Student;
Student Udalenie_Zapisi;
Student temp;
Student tmp;
Student tm;
Student Izmenenie_Zapisi;

void menu()
{
	cout << "Здравствуйте, User. Выберите нужный пункт меню ->" << endl;
	cout << "1. Ввод информации с клавиатуры." << endl;
	cout << "2. Ввод информации из уже созданного текстового файла." << endl;
	cout << "3. Ввод информации из уже созданного бинарного файла." << endl;
	cout << "4. Вывод данных(распечатка) на экран." << endl;
	cout << "5. Вывод данных в файл." << endl;
	cout << "6. Распечатка данных по запросу." << endl;
	cout << "7. Перевод содержимого текстового файла в бинарный файл." << endl;
	cout << "8. Добавление записи." << endl;
	cout << "9. Изменение записи." << endl;
	cout << "10. Удаление записи." << endl;
	cout << "11. Сортировка." << endl;
	cout << "12. Выход." << endl;
}



void tabl(int kolvo)
{

	cout << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
	cout << "|" << left << setw(14) << "Фамилия" << "|" << left << setw(14) << "Имя" << "|" << left << setw(20) << "Отчество" << "|" << left << setw(15) << "Год рождения" << "|" << left << setw(8) << "Курс" << "|" << left << setw(8) << "Группа" << "|" << left << setw(30) << "Оценка по первому предмету" << "|" << left << setw(30) << "Оценка по второму предмету" << "|" << left << setw(30) << "Оценка по третьему предмету" << "|" << endl;
	cout << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
	for (int i = 0; i < kolvo; i++)
	{
		cout << "|" << left << setw(14) << students[i].surname << "|" << left << setw(14) << students[i].name << "|" << left << setw(20) << students[i].middlename << "|" << left << setw(15) << students[i].year << "|" << left << setw(8) << students[i].course << "|" << left << setw(8) << students[i].group << "|" << left << setw(30) << students[i].sub1 << "|" << left << setw(30) << students[i].sub2 << "|" << left << setw(30) << students[i].sub3 << "|" << endl;
		cout << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
	}

}

int get_value()
{
	int kolvo = 12;

	int value{ -1 };
	while (not (cin >> value) or (value < 0) or (value > kolvo))
	{
		cin.clear();
		cin.ignore();
		cout << endl;
		cout << "\nОшибка\n Попробуйте еще раз.\n" << endl;
		cout << "Ввод: ";
	}
	return value;
}

void vvod(int kolvo)
{
	for (int i{}; i < kolvo; i++)
	{
		cout << "Введите фамилию -> ";
		cin >> students[i].surname;

		cout << "Введите имя -> ";
		cin >> students[i].name;

		cout << "Введите отчество -> ";
		cin >> students[i].middlename;

		cout << "Введите год рождения -> ";
		cin >> students[i].year;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		cout << "Введите курс -> ";
		cin >> students[i].course;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		cout << "Введите группу -> ";
		cin >> students[i].group;

		cout << "Оценка за 1-ый предмет -> ";
		cin >> students[i].sub1;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		cout << "Оценка за 2-й предмет -> ";
		cin >> students[i].sub2;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;

		}
		cout << "Оценка за 3-ий предмет -> ";
		cin >> students[i].sub3;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;

		}

		cout << endl;
	}
}

void racpechzapis(Student students[], int kolvo)
{
	int o = 1;
	for (int j = 0; j < kolvo; j++)
		for (int i = j; i < kolvo; i++)
		{
			o = students[i].surname[0] < students[o].surname[0];
			tmp = students[j];
			students[j] = students[o];
			students[o] = tmp;
			for (int i = 0; i < kolvo; i++)
				for (int j = 0; j < kolvo - i - 1; j++)
					if (strcmp(students[j].group, students[j + 1].group) > 0)
					{
						temp = students[j];
						students[j] = students[j + 1];
						students[j + 1] = temp;
					}
		}
			cout << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
			cout << "|" << left << setw(14) << "Фамилия" << "|" << left << setw(14) << "Имя" << "|" << left << setw(20) << "Отчество" << "|" << left << setw(15) << "Год рождения" << "|" << left << setw(8) << "Курс" << "|" << left << setw(8) << "Группа" << "|" << left << setw(30) << "Оценка по первому предмету" << "|" << left << setw(30) << "Оценка по второму предмету" << "|" << left << setw(30) << "Оценка по третьему предмету" << "|" << endl;
			cout << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
		    for (int i = 0; i < kolvo; i++)
			{
				cout << "|" << left << setw(14) << students[i].surname << "|" << left << setw(14) << students[i].name << "|" << left << setw(20) << students[i].middlename << "|" << left << setw(15) << students[i].year << "|" << left << setw(8) << students[i].course << "|" << left << setw(8) << students[i].group << "|" << left << setw(30) << students[i].sub1 << "|" << left << setw(30) << students[i].sub2 << "|" << left << setw(30) << students[i].sub3 << "|" << endl;
				cout << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
			}	
}

void Buffern_vvod()
{
	{
		cout << "Введите фамилию -> ";
		cin >> Buffer_Student.surname;

		cout << "Введите имя -> ";
		cin >> Buffer_Student.name;

		cout << "Введите отчество -> ";
		cin >> Buffer_Student.middlename;

		cout << "Введите год рождения -> ";
		cin >> Buffer_Student.year;

		cout << "Введите курс -> ";
		cin >> Buffer_Student.course;

		cout << "Введите группу -> ";
		cin >> Buffer_Student.group;

		cout << "Оценка за 1-ый предмет -> ";
		cin >> Buffer_Student.sub1;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		cout << "Оценка за 2-й предмет -> ";
		cin >> Buffer_Student.sub2;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		cout << "Оценка за 3-ий предмет: ";
		cin >> Buffer_Student.sub3;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}

		cout << endl;
	}
}

void AddBuffer_v_spisok(int& kolvo, Student& Buffer_Student)
{
	students[kolvo++] = Buffer_Student;
}

bool ydalit(int& kolvo, Student& Udalenie_Zapisi, int k)
{
	cout << "Введите номер строки для удаления ->" << endl;
	cin >> k;
	if (k < 0)
	{
		cout << "\nТакой строки нет. Попробуйте еще раз.\n" << endl;
		return false;
	}
		
	for (int i = k; i < kolvo; i++)
	{
	   tm = students[i - 1];
	   students[i - 1] = students[i];
	   students[i] = tm;
	}
	
	kolvo--;	
	cout << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
	cout << "|" << left << setw(14) << "Фамилия" << "|" << left << setw(14) << "Имя" << "|" << left << setw(20) << "Отчество" << "|" << left << setw(15) << "Год рождения" << "|" << left << setw(8) << "Курс" << "|" << left << setw(8) << "Группа" << "|" << left << setw(30) << "Оценка по первому предмету" << "|" << left << setw(30) << "Оценка по второму предмету" << "|" << left << setw(30) << "Оценка по третьему предмету" << "|" << endl;
	cout << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
	for (int i = 0; i < kolvo; i++)
	{
		cout << "|" << left << setw(14) << students[i].surname << "|" << left << setw(14) << students[i].name << "|" << left << setw(20) << students[i].middlename << "|" << left << setw(15) << students[i].year << "|" << left << setw(8) << students[i].course << "|" << left << setw(8) << students[i].group << "|" << left << setw(30) << students[i].sub1 << "|" << left << setw(30) << students[i].sub2 << "|" << left << setw(30) << students[i].sub3 << "|" << endl;
		cout << "——————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————————" << endl;
	}
	return true;
}

void izmzapis(int& kolvo, Student Izmenenie_Zapisi, int l, int m)
{
	
	cout << "Введите номер строки, которую хотите редактировать ->" << endl;
	cin >> l;
	if (l < 0 || l > kolvo)
	{
		cout << "\nТакой строки нет. Попробуйте еще раз." << endl;
	}
	cout << "\nВыбирете поле, которое хотите изменить ->" << endl;
	cout << "1. Фамилия" << endl;
	cout << "2. Имя" << endl;
	cout << "3. Отчество" << endl;
	cout << "4. Год рождения" << endl;
	cout << "5. Курс" << endl;
	cout << "6. Группа" << endl;
	cout << "7. Оценка за 1-ый предмет" << endl;
	cout << "8. Оценка за 2-й предмет" << endl;
	cout << "9. Оценка за 3-ий предмет" << endl;
	cin >> m;
	switch(m)
		case 1:
			

}

int main()
{
	system("mode 650");
	system("chcp 1251 >> null");
	int k{};
	int kol{};
	int kolvo{};
	int value{ 1 };
	while (value)
	{

		menu();
		value = get_value();

		switch (value)
		{
		case 1:
			system("cls");
			cout << endl;
			cout << "Введите количество учеников -> ";
			cin >> kolvo;
			cout << endl;
			if (cin.fail())
			{
				cout << "Ошибка: введено не число!" << endl;
				return 1;
			}
			if (kolvo < 0)
			{
				cout << "\nВведите положительное число учеников\n" << endl;
				break;
			}
			if (kolvo > n)
			{
				cout << "\nНевозможно ввести количество учеников, большее 15. Введите корректное число учеников\n" << endl;
				return 1;
			}
			vvod(kolvo);

			break;

		case 2:
			//vvodtf();
			//break;
		case 3:
			//vvodbif();
			//break;
		case 4:
			system("cls");
			if (kolvo > 0)
			{
				tabl(kolvo);
			}
			else
			{
				cout << "\nНе записан ни один ученик.\n" << endl;
			}

			break;
		case 5:
			//vivoddanvfail();
			//break;
		case 6:
			racpechzapis(students, kolvo);
		    break;
		case 7:
			//tvbtext();
			//break;
		case 8:
			system("cls");
			Buffern_vvod();
			AddBuffer_v_spisok(kolvo, Buffer_Student);
			break;
		case 9:
			//izmzapis();
			//break;
		case 10:
			system("cls");
			ydalit(kolvo, Udalenie_Zapisi, k);
			break;
		case 11:
			//void sortirovka();
			//break;
		case 12:
			system("cls");
			void exit();
			break;
		}


	}
	return 0;
}
