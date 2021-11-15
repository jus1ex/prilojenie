#include <iostream>
#include <iomanip>
#include <cmath>


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

void menu()
{
	cout << "Здравствуйте, User. Выберите нужный пункт меню:" << endl;
	cout << "1. Ввод информации с клавиатуры." << endl;
	cout << "2. Ввод информации из уже созданного текстового файла." << endl;
	cout << "3.Ввод информации из уже созданного бинарного файла." << endl;
	cout << "4.Вывод данных(распечатка) на экран." << endl;
	cout << "5. Вывод данных в файл." << endl;
	cout << "6. Распечатка данных по запросу." << endl;
	cout << "7. Перевод содержимого текстового файла в бинарный файл." << endl;
	cout << "8. Добавление записи." << endl;
	cout << "9. Изменение записи." << endl;
	cout << "10. Удаление записи." << endl;
	cout << "11. Сортировка." << endl;
	cout << "12. Выход." << endl;
}



void tabl()
{
	cout << left << setw(NUMB) << "№" << "|";
	cout << left << setw(NAME) << "Фамилия" << "|";
	cout << left << setw(NAME) << "Имя" << "|";
	cout << left << setw(NAME) << "Отчество" << "|";
	cout << left << setw(YEAR) << "Год" << "|";
	cout << left << setw(COURSE) << "Курс" << "|";
	cout << left << setw(GROUP) << "Группа" << "|";
	cout << left << setw(SUBJECT) << "Предмет 1" << "|";
	cout << left << setw(SUBJECT) << "Предмет 2" << "|";
	cout << left << setw(SUBJECT) << "Предмет 3" << "|\n";

}


void printst(int kolvo) {
	cout << left << setw(NUMB) << (kolvo + 1) << "|";
	cout << left << setw(NAME) << students[kolvo].surname << "|";
	cout << left << setw(NAME) << students[kolvo].name << "|";
	cout << left << setw(NAME) << students[kolvo].middlename << "|";
	cout << left << setw(YEAR) << students[kolvo].year << "|";
	cout << left << setw(COURSE) << students[kolvo].course << "|";
	cout << left << setw(GROUP) << students[kolvo].group << "|";
	cout << left << setw(SUBJECT) << students[kolvo].sub1 << "|";
	cout << left << setw(SUBJECT) << students[kolvo].sub2 << "|";
	cout << left << setw(SUBJECT) << students[kolvo].sub3 << "|\n";

	
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
		cout << "Ошибка\n Попробуйте еще раз." << endl;
		cout << "Ввод: ";
	}
	return value;
}

void vvod(int kolvo)
{
	for (int i{}; i < kolvo; i++)
	{
		cout << "Введите фамилию: ";
		cin >> students[i].surname;

		cout << "Введите имя: ";
		cin >> students[i].name;

		cout << "Введите отчество: ";
		cin >> students[i].middlename;

		cout << "Введите год рождения: ";
		cin >> students[i].year;

		cout << "Введите курс: ";
		cin >> students[i].course;
		
		cout << "Введите группу: ";
		cin >> students[i].group;

		cout << "Оценка за 1-ый предмет: ";
		cin >> students[i].sub1;

		cout << "Оценка за 2-й предмет: ";
		cin >> students[i].sub2;

		cout << "Оценка за 3-ий предмет: ";
		cin >> students[i].sub3;

		cout << endl;
	}
}

int main()
{
	system("chcp 1251 >> null");

	int kolvo{};
	int value{ 1 };
	while (value)
	{

		menu();
		value = get_value();

		switch (value)
		{
		case 0:
			void exit();

			break;
		case 1:
			cout << endl;
			cout << "Введите количество учеников: ";
			cin >> kolvo;
			cout << endl;
			if (cin.fail())
			{
				cout << "Ошибка: введено не число!" << endl;
				return 1;
			}
			if (kolvo < 0)
			{
				cout << "Введите положительное число учеников" << endl;
				break;
			}
			vvod(kolvo);

			break;

		case 2:
			//vvodfail();
			//break;
		case 3:
			//vvodbi();
			//break;
		case 4:
			if (kolvo > 0)
			{
				tabl();
				for (int i = 0; i < kolvo; ++i) {
					printst(i);
				}
			}
			else
			{
				cout << "Не записан ни один ученик" << endl;
			}

			break;
		case 5:
			//vivodtext();
			//break;
		case 6:
			//zapros();
			//break;
		case 7:
			//bdvtext();
			//break;
		case 8:
			//bdvtext();
			//break;
		case 9:
			//dobzapis();
			//break;
		case 10:
			//izmzapis();
			//break;
		case 11:
			//udalit();
			//break;
		case 12:
			//sort();
			break;
		}


	}
	return 0;
}
