#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include <iostream>
#include <cstring>
class Resident
{
	char* name;
	FILE* fp;

public:
	Resident();
	Resident(char* name);
	Resident(const Resident& obj);//Конструктор копирования, D = this, B = obj
	Resident& operator = (const Resident& obj);//Оператор присвоения
	~Resident();

	void setName(char* newName);
	char* getName()const;

	void toBinFile(FILE* fp);
	void fromBinFile(FILE* fp);
};

