#include "Resident.h"

Resident::Resident()
{
    name = new char[20]{ "No name" };
}

Resident::Resident(char* name)
{
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

Resident::Resident(const Resident& obj)
{
    this->name = new char[strlen(obj.name) + 1];
    strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
}

Resident& Resident::operator=(const Resident& obj)
{
    this->name = new char[strlen(obj.name) + 1];
    strcpy_s(this->name, strlen(obj.name) + 1, obj.name);
    return*this;
}

Resident::~Resident()
{
    delete[]name;
}

void Resident::setName(char* newName)
{
    if (name != NULL)
    {
        delete[] name;
    }
    name = new char[strlen(newName) + 1];
    strcpy(name, newName);
}

char* Resident::getName()const
{
    return name;
}

void Resident::toBinFile(FILE* fp)
{
    int a = strlen(name);
    fwrite(&a, sizeof(int), 1, fp);
    fwrite(name, sizeof(char), strlen(name), fp);
}

void Resident::fromBinFile(FILE* fp)
{
    int a = 0;
    fread(&a, sizeof(int), 1, fp);
    delete[]name;
    name = new char[a + 1];
    fread(name, sizeof(char), a, fp);
    name[a] = '\0';
}
