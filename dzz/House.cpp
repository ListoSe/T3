#include "House.h"

House::House()
{
    adress = new char[20]{"Харьков"};
    for (int i = 0; i < 20; i++)
    {
        if (i % 3 == 0)
        {
            flats[i] = new Flat(2,70);
        }
        else
        {
            flats[i] = new Flat(1, 50);
        }
    }
}

House::House(char* adress)
{
    this->adress = new char[strlen(adress) + 1];
    strcpy_s(this->adress, strlen(adress) + 1, adress);

    for (int i = 0; i < 20; i++)
    {
        if (i % 3 == 0)
        {
            flats[i] = new Flat(2, 70);
        }
        else
        {
            flats[i] = new Flat(1, 50);
        }
    }

}

House::~House()
{
    delete[]adress;
}

void House::setAdress(char* newAdress)
{
    
     delete[]adress;
     adress = new char[strlen(newAdress) + 1];
     strcpy_s(adress, strlen(newAdress) + 1, newAdress);
 
}

const char* House::getAdress()
{
    return adress;
}

void House::addPerson(Resident person, int nFlat)
{
    if (nFlat > 0 && nFlat <= 20)
    {
        flats[nFlat - 1]->addResident(person);
    }
}

void House::delPerson(char* name, int nFlat)
{
    if (nFlat > 0 && nFlat <= 20)
    {
        flats[nFlat - 1]->delResident(name);
    }
}

void House::showAllFlatsList()
{
    for (int i = 0; i < 20; i++)
    {
        flats[i]->showInfo();
    }
}

void House::showAllPersonList()
{
    for (int i = 0; i < 20; i++)
    {
        flats[i]->showResidents();
    }
}

void House::showPersonListByFlat(int n)
{
    for (int i = 0; i < 20; i++)
    {
        if (n == i)
        {
            cout << "Квартира номер: " << n << endl;
            flats[i]->showResidents();
        }
    }
}

void House::toBinFile(FILE* fp)
{
    int a = 0;
    fwrite(&a, sizeof(int), 1, fp);
    delete[]adress;
    adress = new char[a];
    fwrite(adress, sizeof(char), a, fp);
    adress[a] = '\0';
    for (int i = 0; i < 20; i++)
    {
        flats[i]->toBinFile(fp);
    }
}

void House::fromBinFile(FILE* fp)
{
    int a = 0;
    fread(&a, sizeof(int), 1, fp);
    delete[]adress;
    adress = new char[a];
    fread(adress, sizeof(char), a, fp);
    adress[a] = '\0';
    for (int i = 0; i < 20; i++)
    {
        flats[i]->fromBinFile(fp);
    }
}
