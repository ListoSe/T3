#include "Flat.h"

Flat::Flat()
{
    rooms = 0;
    square = 0;
    amountOfResidents = 0;
    arr = nullptr;
}

Flat::Flat(int rooms, float square)
{
    this->rooms = rooms;
    this->square = square;
    amountOfResidents = 0;
    arr = nullptr;
}

Flat::Flat(const Flat& obj)
{
	this->rooms = obj.rooms;
	this->square = obj.square;
	this->amountOfResidents = obj.amountOfResidents;
	this->arr = new Resident*[this->amountOfResidents];
	for (int i = 0; i < amountOfResidents; i++)
	{
		this->arr[i] = new Resident(*obj.arr[i]);
	}
}

Flat& Flat::operator=(const Flat& obj)
{
	this->rooms = obj.rooms;
	this->square = obj.square;
	this->amountOfResidents = obj.amountOfResidents;
	this->arr = new Resident * [this->amountOfResidents];
	for (int i = 0; i < amountOfResidents; i++)
	{
		this->arr[i] = new Resident(*obj.arr[i]);
	}
	return*this;
}

Flat::~Flat()
{
}

void Flat::setRooms(int rooms)
{
    if (rooms > 0)
    {
        this->rooms = rooms;
    }
}

int Flat::getRooms()const
{
    return rooms;
}

void Flat::setSquare(float square)
{
    if (square > 0)
    {
        this->square = square;
    }
}

float Flat::getSquare()const
{
    return square;
}

int Flat::getAmountOfResidents()const
{
    return amountOfResidents;
}


void Flat::addResident(Resident person)
{
    ++amountOfResidents;
    Resident** tmp = new Resident * [++amountOfResidents];
    for (int i = 0; i < amountOfResidents - 1; i++)
    {
        tmp[i] = arr[i];
    }
    if (arr != NULL)
    {
        delete[]arr;
    }
    tmp[amountOfResidents - 1] = new Resident(person);
    arr = tmp;

		/*amountOfResidents++;
		Resident* tmp = new Resident[amountOfResidents];//конструктор  по умолчанию
		for (int i = 0; i < amountOfResidents - 1;i++)
		{
			tmp[i] = arr[i];//присвоение cbrrency
		}
		tmp[amountOfResidents - 1] = person;
		if (arr != nullptr)
		{
			delete[]arr;
		}
		arr = tmp;
		*/
		
}

void Flat::delResident(char* name)
{
	int Id = -1;
	for (int i = 0; i < amountOfResidents; i++)
	{
		if (strcmp(name, arr[i]->getName()) == 0)
		{
			Id = i;
		}
	}
	if (Id == -1)
	{
		cout << "Не найден: " << endl;
	}
	else
	{
		Resident** tmp = new Resident* [--amountOfResidents];
		for (int i = 0; i < amountOfResidents; i++)
		{
			if (i < Id)
			{
				tmp[i] = arr[i];

			}
			else
			{
				tmp[i] = arr[i + 1];
			}
		}
		if (arr != NULL)
		{
			delete[] arr;
		}
		arr = tmp;
		cout << "Аккаунт успешно удалён: " << endl;
	}
}

void Flat::showResidents()
{
	for (int i = 0; i < amountOfResidents; i++)
	{
		cout << arr[i]->getName() << endl; 
	}
}

void Flat::showInfo()const
{
	cout << rooms << " " << square << " " << amountOfResidents << " " << arr << endl;
}

void Flat::toBinFile(FILE* fp)
{
	fwrite(&rooms, sizeof(int), 1, fp);
	fwrite(&square, sizeof(int), 1, fp);
	fwrite(&amountOfResidents, sizeof(int), 1, fp);
	for (int i = 0; i < amountOfResidents; i++)
	{
		arr[i]->toBinFile(fp);
	}
}

void Flat::fromBinFile(FILE* fp)
{
	fread(&rooms, sizeof(int), 1, fp);
	fread(&square, sizeof(int), 1, fp);
	fread(&amountOfResidents, sizeof(int), 1, fp);
	arr = new Resident * [amountOfResidents];
	for (int i = 0; i < amountOfResidents; i++)
	{
		arr[i]->fromBinFile(fp);
	}
}
