#include <iostream>
using namespace std;

struct Date {
	short day;
	short month;
	short year;
	bool isCorrect();
	int daysBetween(Date date2);
};

int Date::daysBetween(Date date2)
{
	const float DAYS_IN_YEAR = 365.25;
	float days1 = DAYS_IN_YEAR * year + DAYS_IN_YEAR / 12. * (month - 1.) + day;
	float days2 = DAYS_IN_YEAR * date2.year + DAYS_IN_YEAR / 12. * (date2.month - 1.) + date2.day;

	return (days2 > days1 ? days2 - days1 : days1 - days2);
}

bool Date::isCorrect()
{
	bool result = false;

	if (month > 0 && month <= 12 && year <= 2021)
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
		{
			if ((day <= 31) && (day > 0))
				result = true;
			break;
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if ((day <= 30) && (day > 0))
				result = true;
			break;
		}

		case 2:
		{
			if (year % 4 != 0)
			{
				if ((day <= 28) && (day > 0))
					result = true;
			}
			else
				if (year % 400 == 0)
				{
					if ((day <= 29) && (day > 0))
						result = true;
				}
				else
					if ((year % 100 == 0) && (year % 400 != 0))
					{
						if ((day == 28) && (day > 0))
							result = true;
					}
					else
						if ((year % 4 == 0) && (year % 100 != 0))
							if ((day <= 29) && (day > 0))
								result = true;
			break;
		}

		default:
			result = false;
		}
	}
	return result;
}

struct Student
{
	char F[56];
	char I[32];
	char O[32];
	Date birthday;
	char address[256];
	short mark;
};

void task1()
{
	const int N = 2;
	Student group[N];

	for (int i = 0; i < N; i++)
	{
		cout << "\nInput F: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].F, 56);

		cout << "\nIinput I: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].I, 32);

		cout << "\nInput O: ";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].O, 32);

		do
		{
			cout << "\nInput birthday: ";
			cin.ignore(std::cin.rdbuf()->in_avail());
			cin >> group[i].birthday.day >> group[i].birthday.month >> group[i].birthday.year;
		} while (!group[i].birthday.isCorrect());

		cout << "\nInput address:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin.getline(group[i].address, 256);

		cout << "\nInput mark:";
		cin.ignore(std::cin.rdbuf()->in_avail());
		cin >> group[i].mark;

		cin.clear();
	}

	for (int i = 0; i < N; i++)
	{
		cout << "\nFIO: " << group[i].F << " " << group[i].I << " " << group[i].O;
		cout << "\nBirthday: " << group[i].birthday.day << "." << group[i].birthday.month << "." << group[i].birthday.year;
		cout << "\nAddress: " << group[i].address << endl;
		cout << "Mark: " << group[i].mark << endl;
	}

	int best = 0;
	for (int i = 0; i < N; i++)
	{
		if (group[i].mark > group[best].mark)
			best = i;
	}

	cout << "\nFIO: " << group[best].F << " " << group[best].I << " " << group[best].O << " is the best!";
}

struct Book
{
	char title[200];
	char authors[512];
	short published = 2021;
	char publisher[64];

	void printInfo();
	void readInfo();
};

void Book::printInfo()
{
	cout << endl << "Book:" << endl;
	cout << "title: " << title << endl;
	cout << "authors: " << authors << endl;
	cout << "publishing year: " << published << endl;
	cout << "publisher: " << publisher << endl;
}

void Book::readInfo()
{
	cout << "\nInput book title: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(title, sizeof(title));

	cout << "\nInput book authors: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(authors, sizeof(authors));

	cout << "\nInput book publishing year: ";
	cin >> published;

	cout << "\nInput book publisher: ";
	cin.ignore(std::cin.rdbuf()->in_avail());
	cin.getline(publisher, sizeof(publisher));
}

void task2() {
	/*
		Book book;

		book.readInfo();
		book.printInfo();
	*/
	const int N = 3;
	Book library[N];

	for (size_t i = 0; i < N; i++)
	{
		library[i].readInfo();
	}

	for (size_t i = 0; i < N; i++)
	{
		library[i].printInfo();
	}

	int indexOfOldestBook = 0;
	int averageYear = library[0].published;
	for (size_t i = 1; i < N; i++)
	{
		if (library[i].published < library[indexOfOldestBook].published)
			indexOfOldestBook = i;

		averageYear += library[i].published;
	}

	cout << endl << "Average publishing year of all books is: " << (float)averageYear / N;

	cout << endl << "The oldest book is: ";
	library[indexOfOldestBook].printInfo();
}

string getRandomCountry()
{
	string countries[] = { "Россия",
"Австралия",
"Австрия",
"Азербайджан",
"Ангуилья",
"Аргентина",
"Армения",
"Арулько",
"Беларусь",
"Белиз",
"Бельгия",
"Бермуды",
"Болгария",
"Бразилия",
"Великобритания",
"Венгрия",
"Вьетнам",
"Гаити",
"Гваделупа",
"Германия",
"Голландия",
"Гондурас",
"Гонконг",
"Греция",
"Грузия",
"Дания",
"Доминиканская республика",
"Египет",
"Израиль",
"Индия",
"Индонезия",
"Иордания",
"Ирак",
"Иран",
"Ирландия",
"Испания",
"Италия",
"Казахстан",
"Камерун",
"Канада",
"Карибы",
"Кипр",
"Киргызстан",
"Китай",
"Корея",
"Коста-Рика",
"Куба",
"Кувейт",
"Латвия",
"Ливан",
"Ливан",
"Ливия",
"Литва",
"Люксембург",
"Македония",
"Малайзия",
"Мальта",
"Мексика",
"Мозамбик",
"Молдова",
"Монако",
"Монголия",
"Морокко",
"Нидерланды",
"Новая Зеландия",
"Норвегия",
"О.А.Э.",
"Остров Мэн",
"Пакистан",
"Перу",
"Польша",
"Португалия",
"Реюньон",
"Румыния",
"США",
"Сальвадор",
"Сингапур",
"Сирия",
"Словакия",
"Словения",
"Суринам",
"Таджикистан",
"Тайвань",
"Тайланд",
"Тунис",
"Туркменистан",
"Туркмения",
"Туркс и Кейкос",
"Турция",
"Уганда",
"Узбекистан",
"Украина",
"Финляндия",
"Франция",
"Хорватия",
"Чехия",
"Чили",
"Швейцария",
"Швеция",
"Эквадор",
"Эстония",
"ЮАР",
"Югославия",
"Южная Корея",
"Ямайка",
"Япония"
	};
	return countries[rand()%105];
}

string getRandomCar()
{
	string cars[] = {
	"Mazda RX4",
		"Mazda RX4 Wag",
		"Datsun 710",
		"Hornet 4 Drive",
		"Hornet Sportabout",
		"Valiant",
		"Duster 360",
		"Merc 240D",
		"Merc 230",
		"Merc 280",
		"Merc 280C",
		"Merc 450SE",
		"Merc 450SL",
		"Merc 450SLC",
		"Cadillac Fleetwood",
		"Lincoln Continental",
		"Chrysler Imperial",
		"Fiat 128",
		"Honda Civic",
		"Toyota Corolla",
		"Toyota Corona",
		"Dodge Challenger",
		"AMC Javelin",
		"Camaro Z28",
		"Pontiac Firebird",
		"Fiat X1-9",
		"Porsche 914-2",
		"Lotus Europa",
		"Ford Pantera L",
		"Ferrari Dino",
		"Maserati Bora",
		"Volvo 142E" };

		return cars[rand() % cars->size()];
}

int main()
{
	srand(time(0));
	srand(time(0));
	setlocale(0, "ru");
	cout << endl<< getRandomCountry();
	cout << endl<< getRandomCountry();
	cout << endl<< getRandomCountry();
	cout << endl<< getRandomCountry();
	cout << endl;
	
	cout << endl << getRandomCar();
	cout << endl << getRandomCar();
	cout << endl << getRandomCar();
	cout << endl << getRandomCar();
	cout << endl << getRandomCar();

	cout << endl;
	// task1();
	// task2();


	Date date1, date2, date3;
	date1.day = 26; date1.month = 2; date1.year = 2021;
	date2.day = 16; date2.month = 7; date2.year = 2017;
	int days = date1.daysBetween(date2);
	cout << days << endl;
	date3.year = days / 365.25;
	days = days - date3.year * 365.25;
	date3.month = days / (365.25 / 12);
	date3.day = days - (date3.month) * (365.25 / 12);
	cout << date3.day << "\t" << date3.month << "\t" << date3.year << "\t";

	return 0;
}
