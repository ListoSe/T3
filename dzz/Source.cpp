#include <iostream>
#include <cstring>
#include "House.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int menu = 0;
	FILE* fp;
	fopen_s(&fp, "Building.bin", "wb");

	House* a = new House();
	char ch[100];
	int in = 0;

	do
	{
		cout << "0 - Выход" << endl;
		cout << "1 - сменить адресс" << endl;
		cout << "2 - узнать адресс" << endl;
		cout << "3 - список квартир" << endl;
		cout << "4 - список жильцов" << endl;
		cout << "5 - список жильцов по номеру квартиры" << endl;
		cout << "6 - добавить жильца" << endl;
		cout << "7 - удалить жильца" << endl;
		cout << "8 - сохранить в файл" << endl;
		cout << "9 - выгрузить из файла" << endl;
		cin >> menu;

		switch (menu)
		{
		case 0: break;
		case 1: cout << "Введите адресс: "; cin.ignore();
			cin.getline(ch, 100); a->setAdress(ch); break;
		case 2: cout << a->getAdress(); break;
		case 3: a->showAllFlatsList(); break;
		case 4: a->showAllPersonList(); break;
		case 5: cout << "Введите номер квартиры: "; cin >> in; a->showPersonListByFlat(in); break;
		case 6: cout << "Введите имя жильца: "; cin.ignore();
			cin.getline(ch, 100);cout << "Введите номер квартиры: "; cin >> in;
			a->addPerson(ch, in); break;
		case 7: cout << "Введите имя жильца: "; cin.ignore();
			cin.getline(ch, 100);cout << "Введите номер квартиры: "; cin >> in;
			a->delPerson(ch, in); break;
		case 8: a->toBinFile(fp); break;
		case 9: a->fromBinFile(fp); break;
		}

	}
	while (menu != 0);
}