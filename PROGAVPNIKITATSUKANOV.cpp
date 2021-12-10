#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>

#define MONTH 9
#define NAME 12

using namespace std;


struct Student
{
	char surname[NAME]{};
	int date;
	char month[MONTH]{};
	int group;
	int course;
	int year;

};
const int n = 15;
Student students[n] = {};
Student Buffer_Student;
Student Udalenie_Zapisi;
Student temp;
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

	cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	cout << "|" << left << setw(14) << "Фамилия" << "|" << left << setw(14) << "День рождения" << "|" << left << setw(20) << "Месяц рождения" << "|" << left << setw(15) << "Год рождения" << "|" << left << setw(8) << "Курс" << "|" << left << setw(8) << "Группа" << "|" << endl;
	cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	for (int i = 0; i < kolvo; i++)
	{
		cout << "|" << left << setw(14) << students[i].surname << "|" << left << setw(14) << students[i].date << "|" << left << setw(20) << students[i].month << "|" << left << setw(15) << students[i].year << "|" << left << setw(8) << students[i].course << "|" << left << setw(8) << students[i].group << "|" << endl;
		cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
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

		cout << "Введите день рождения -> ";
		cin >> students[i].date;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		if (students[i].date < 1 || students[i].date >= 32)
		{
			cout << "\nОшибка: Введите корректную дату!\n" << endl;
			cout << "\nВведите день рождения -> ";
            cin >> students[i].date;
		}

		cout << "Введите месяц рождения -> ";
		cin >> students[i].month;

		cout << "Введите год рождения -> ";
		cin >> students[i].year;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		if (students[i].year > 2021 || students[i].year < 1999)
		{
			cout << "\nОшибка: Введите действительный год рождения!\n" << endl;
			cout << "\nВведите год рождения -> ";
			cin >> students[i].year;
		}

		
		cout << "Введите курс -> ";
		cin >> students[i].course;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		if (students[i].course < 1 || students[i].course > 6)
        {
			cout << "\nОшибка: Введите действительный номер курса!\n" << endl;
			cout << "\nВведите курс -> ";
			cin >> students[i].course;
		}

		cout << "Введите группу -> ";
		cin >> students[i].group;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}

		cout << endl;


	}
}


void Racpech_zapis(int kolvo, Student students[])
{
	for (int i = 0; i < kolvo; i++)
		for (int j = 0; j < kolvo - i - 1; j++)
		{
			if (students[j].group > students[j + 1].group)
			{
				Student temp = students[j];
				students[j] = students[j + 1];
				students[j + 1] = temp;
			}
		}
	for (int i = 0; i < kolvo; i++)
		for (int j = 0; j < kolvo - i - 1; j++)
			if (students[j].group == students[j + 1].group)
				if (students[j].surname[0] > students[j + 1].surname[0])
				{
					Student f = students[j];
					students[j] = students[j + 1];
					students[j + 1] = f;
				}
	cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	cout << "|" << left << setw(14) << "Фамилия" << "|" << left << setw(14) << "День рождения" << "|" << left << setw(20) << "Месяц рождения" << "|" << left << setw(15) << "Год рождения" << "|" << left << setw(8) << "Курс" << "|" << left << setw(8) << "Группа" << "|" << endl;
	cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	for (int i = 0; i < kolvo; i++)
	{
		cout << "|" << left << setw(14) << students[i].surname << "|" << left << setw(14) << students[i].date << "|" << left << setw(20) << students[i].month << "|" << left << setw(15) << students[i].year << "|" << left << setw(8) << students[i].course << "|" << left << setw(8) << students[i].group << "|" << endl;
		cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	}
}

void Buffern_vvod()
{
		cout << "Введите фамилию -> ";
		cin >> Buffer_Student.surname;

		cout << "Введите дату рождения -> ";
		cin >> Buffer_Student.date;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		if (Buffer_Student.date < 1 || Buffer_Student.date > 31)
		{
			cout << "\nОшибка: Введите корректную дату!\n" << endl;
			cout << "\nВведите день рождения -> ";
			cin >> Buffer_Student.date;
		}
		cout << "Введите месяц рождения -> ";
		cin >> Buffer_Student.month;

		cout << "Введите год рождения -> ";
		cin >> Buffer_Student.year;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		if (Buffer_Student.year > 2021 || Buffer_Student.year < 1999)
		{
			cout << "\nОшибка: Введите действительный год рождения!\n" << endl;
			cout << "\nВведите год рождения -> ";
			cin >> Buffer_Student.year;
		}

		cout << "Введите курс -> ";
		cin >> Buffer_Student.course;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}
		if (Buffer_Student.course < 1 || Buffer_Student.course > 6)
		{
			cout << "\nОшибка: Введите действительный номер курса!\n" << endl;
			cout << "\nВведите курс -> ";
			cin >> Buffer_Student.course;
		}

		cout << "Введите группу -> ";
		cin >> Buffer_Student.group;
		if (cin.fail())
		{
			cout << "\nОшибка: Введите число!\n" << endl;
		}

		cout << endl;
	
}


void AddBuffer_v_spisok(int&  kolvo, Student& Buffer_Student)
{
	students[kolvo++] = Buffer_Student;
}

bool Ydalit(int& kolvo, Student& Udalenie_Zapisi, int k)
{
	cout << "Введите номер строки для удаления ->" << endl;
	cin >> k;
	if (k < 0 || k > kolvo)
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
	cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	cout << "|" << left << setw(14) << "Фамилия" << "|" << left << setw(14) << "День рождения" << "|" << left << setw(20) << "Месяц рождения" << "|" << left << setw(15) << "Год рождения" << "|" << left << setw(8) << "Курс" << "|" << left << setw(8) << "Группа" << "|" << endl;
	cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	for (int i = 0; i < kolvo; i++)
	{
		cout << "|" << left << setw(14) << students[i].surname << "|" << left << setw(14) << students[i].date << "|" << left << setw(20) << students[i].month << "|" << left << setw(15) << students[i].year << "|" << left << setw(8) << students[i].course << "|" << left << setw(8) << students[i].group << "|" << endl;
		cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	}
	return true;
}

void Izm_zapis(int& kolvo, Student Izmenenie_Zapisi, int m, int l)
{
	cout << "Введите номер студента, данные которого хотите изменить -> ";
	cin >> l;
	if (l < 0 || l > kolvo)
	{
		cout << "Такой строки нет. Попробуйте еще раз." << endl;
	}

	cout << "\nВыбирете поле, которое хотите изменить ->" << endl;
	cout << "1. Фамилия" << endl;
	cout << "2. День рождения" << endl;
	cout << "3. Месяц рождения" << endl;
	cout << "4. Год рождения" << endl;
	cout << "5. Курс" << endl;
	cout << "6. Группа" << endl;
	cin >> m;
	if (cin.fail())
	{
		cout << "Ошибка: Введите число!" << endl;
	}
	if (m < 0 || m > 6)
	{
		cout << "Ошибка: Такого поля нет. Попробуйте еще раз." << endl;
		cout << "\nВыбирете поле, которое хотите изменить ->" << endl;
		cin >> m;
	}

	switch (m)
	{
	case 1:
		cout << "Изменение поля Фамилия ->" << endl;
		cin >> students[l - 1].surname;
		break;
	case 2:
		cout << "Изменение поля Дата рождения ->" << endl;
		cin >> students[l - 1].date;
		if (cin.fail())
		{
			cout << "Ошибка: Введите число!" << endl;
		}
		if (students[l - 1].date < 1 || students[l - 1].date >= 32)
		{
			cout << "\nОшибка: Введите корректную дату!\n" << endl;
			cout << "\nВведите день рождения -> ";
			cin >> students[l - 1].date;
		}
		break;
	case 3:
		cout << "Изменение поля Месяц рождения ->" << endl;
		cin >> students[l - 1].month;
		break;
	case 4:
		cout << "Изменение поля Год рождения ->" << endl;
		cin >> students[l - 1].year;
		if (cin.fail())
		{
			cout << "Ошибка: Введите число!" << endl;
		}
		if (students[l - 1].year > 2021 || students[l - 1].year < 1999)
		{
			cout << "\nОшибка: Введите действительный год рождения!\n" << endl;
			cout << "\nВведите год рождения -> ";
			cin >> students[l - 1].year;
		}
		break;
	case 5:
		cout << "Изменение поля Курс ->" << endl;
		cin >> students[l - 1].course;
		if (cin.fail())
		{
			cout << "Ошибка: Введите число!" << endl;
		}
		break;
	case 6:
		cout << "Изменение поля Группа ->" << endl;
		cin >> students[l - 1].group;
		if (cin.fail())
		{
			cout << "Ошибка: Введите число!" << endl;
		}
		break;

	}
		cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
		cout << "|" << left << setw(14) << "Фамилия" << "|" << left << setw(14) << "День рождения" << "|" << left << setw(20) << "Месяц рождения" << "|" << left << setw(15) << "Год рождения" << "|" << left << setw(8) << "Курс" << "|" << left << setw(8) << "Группа" << "|" << endl;
		cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
		for (int i = 0; i < kolvo; i++)
		{
			cout << "|" << left << setw(14) << students[i].surname << "|" << left << setw(14) << students[i].date << "|" << left << setw(20) << students[i].month << "|" << left << setw(15) << students[i].year << "|" << left << setw(8) << students[i].course << "|" << left << setw(8) << students[i].group << "|" << endl;
			cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
		}
	
}

void Sortirovka(int p, int kolvo, Student students[])
{
	cout << "Выберите фильтр, по которому хотите отсортировать список -> " << endl;
	cout << "\n1. По фамилии в алфавитном порядке(А-Я)." << endl;
	cout << "2. По фамилии в порядке, обратном алфавитному(Я-А)." << endl;
	cout << "3. По дате рождения в порядке возрастания." << endl;
	cout << "4. По дате рождения в порядке убывания." << endl;
	cout << "5. По году рождения в порядке возрастания." << endl;
	cout << "6. По группе в порядке возрастания." << endl;
	cout << "7. По группе в порядке убывания." << endl;
	cout << "8. По курсу в порядке возрастания." << endl;
	cout << "9. По курсу в порядке убывания." << endl;
	
	
	cin >> p;
	if (cin.fail())
	{
		cout << "Введите число!" << endl;
	}
	if (p < 0 || p > 10)
	{
		cout << "Такого фильтра нет. Попробуйте еще раз." << endl;
	}

	switch (p)
	{
	case 1:

		cout << endl;
		cout << "Сортировка по фамилии в алфавитном порядке(А-Я)." << endl;
		for (int i = 0; i < kolvo; i++)
			for (int j = 0; j < kolvo - i - 1; j++)
			{
				if (students[j].surname[0] > students[j + 1].surname[0])
				{
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}
			
		}
		break;
	case 2:
		
		cout << endl;
		cout << "Сортировка по фамилии в порядке, обратном алфавитному(Я-А)" << endl;
		for (int i = 0; i < kolvo; i++)
			for (int j = 0; j < kolvo - i - 1; j++)
			{
				if (students[j].surname[0] < students[j + 1].surname[0])
				{
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}

			}
		break;
	case 3:
		cout << endl;
		cout << "Сортировка по дате рождения в порядке возрастания." << endl;
		for (int i = 0; i < kolvo; i++)
			for (int j = 0; j < kolvo - i - 1; j++)
			{
				if (students[j].date > students[j + 1].date)
				{
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}

			}
		break;
	case 4:
		cout << endl;
		cout << "Сортировка по дате рождения в порядке убывания." << endl;
		for (int i = 0; i < kolvo; i++)
			for (int j = 0; j < kolvo - i - 1; j++)
			{
				if (students[j].date < students[j + 1].date)
				{
					temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}

			}
		break;

	case 5:
		cout << endl;
		cout << "Сортировка по году рождения в порядке возрастания." << endl;
		for (int i = 0; i < kolvo; i++)
			for (int j = 0; j < kolvo - i - 1; j++)
			{
				if (students[j].year > students[j + 1].year)
				{
					Student temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}

			}
			break;
	case 6:
		cout << endl;
		cout << "Сортировка по группе в порядке возрастания." << endl;
		for (int i = 0; i < kolvo; i++)
			for (int j = 0; j < kolvo - i - 1; j++)
			{
				if (students[j].group > students[j + 1].group)
				{
					Student temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}

			}
		break;
	case 7:
		cout << endl;
		cout << "Сортировка по группе в порядке убывания." << endl;
		for (int i = 0; i < kolvo; i++)
			for (int j = 0; j < kolvo - i - 1; j++)
			{
				if (students[j].group < students[j + 1].group)
				{
					Student temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}

			}
		break;
	case 8:
		cout << endl;
		cout << "Сортировка по курсу в порядке возрастания." << endl;
		for (int i = 0; i < kolvo; i++)
			for (int j = 0; j < kolvo - i - 1; j++)
			{
				if (students[j].course > students[j + 1].course)
				{
					Student temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}

			}
		break;
	case 9:
		cout << endl;
		cout << "Сортировка по курсу в порядке убывания." << endl;
		for (int i = 0; i < kolvo; i++)
			for (int j = 0; j < kolvo - i - 1; j++)
			{
				if (students[j].course < students[j + 1].course)
				{
					Student temp = students[j];
					students[j] = students[j + 1];
					students[j + 1] = temp;
				}

			}
		break;
	}

	cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	cout << "|" << left << setw(14) << "Фамилия" << "|" << left << setw(14) << "День рождения" << "|" << left << setw(20) << "Месяц рождения" << "|" << left << setw(15) << "Год рождения" << "|" << left << setw(8) << "Курс" << "|" << left << setw(8) << "Группа" << "|" << endl;
	cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	for (int i = 0; i < kolvo; i++)
	{
		cout << "|" << left << setw(14) << students[i].surname << "|" << left << setw(14) << students[i].date << "|" << left << setw(20) << students[i].month << "|" << left << setw(15) << students[i].year << "|" << left << setw(8) << students[i].course << "|" << left << setw(8) << students[i].group << "|" << endl;
		cout << "—————————————————————————————————————————————————————————————————————————————————————" << endl;
	}
}

void Vivod_v_fail(int &kolvo, Student* students)
{
	ofstream out;
	out.open("pr.txt");
	for (int i = 0; i < kolvo; i++)
	{
		out << students[i].surname << endl;
		out << students[i].date << endl;
		out << students[i].month << endl;
		out << students[i].year << endl;
		out << students[i].course << endl;
		out << students[i].group << endl;

	}
		out.close();
}

void Vvod_t_f(int &kolvo)
{
	
	ifstream in;
	in.open("pr.txt");
	while (!in.eof())
	{
		in >> students[kolvo].surname;
		in >> students[kolvo].date;
		in >> students[kolvo].month;
		in >> students[kolvo].year;
		in >> students[kolvo].course;
		in >> students[kolvo].group;
		kolvo++;
		
	}
	kolvo--;
	in.close();
}

void Vivod_bif(Student* students, int kolvo)
{
    Vivod_v_fail(kolvo, students);
	ofstream fout("pr.bin", ios::binary | ios::out);
	if (fout.is_open())
	{
		for (int i = 0; i < kolvo; i++)
		{
			fout.write((char*)&students[i], sizeof(students[i]));
		}
	}
	fout.close();
}

void Vvod_bif(Student* students, int kolvo)
{
	int i = 0;
	ifstream fin("pr.bin", ios::binary | ios::in);
	if (fin.is_open())
	{
		while (!fin.eof())
		{
			fin.read((char*)&students[i], sizeof(students[i]));
			i++;
			kolvo++;
		}
		i--;
		kolvo--;
	}
	fin.close();
}

int main()
{
	system("mode 650");
	system("chcp 1251 >> null");
	int i{};
	int p{};
	int k{};
	int m{};
	int l{};
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
			system("cls");
			Vvod_t_f(kolvo);
			break;
		case 3:
			system("cls");
			Vivod_bif(students, kolvo);
			break;
			
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
			system("cls");
			Vivod_v_fail(kolvo, students);
			break;
		case 6:
			system("cls");
			Racpech_zapis(kolvo, students);
		    break;
		case 7:
			system("cls");
			Vvod_bif(students, kolvo);
			break;
		case 8:
			system("cls");
			Buffern_vvod();
			AddBuffer_v_spisok(kolvo, Buffer_Student);
			break;
		case 9:
			system("cls");
			Izm_zapis(kolvo, Izmenenie_Zapisi, m, l);
			break;
		case 10:
			system("cls");
			Ydalit(kolvo, Udalenie_Zapisi, k);
			break;
		case 11:
			system("cls");
			Sortirovka(p, kolvo, students);
			break;
		case 12:
			system("cls"); 
			void exit();
			break;
		}


	}
	return 0;
}
