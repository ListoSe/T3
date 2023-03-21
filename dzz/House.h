#pragma once
#include <iostream>
#include <cstring>
#include "Flat.h"
#include "Resident.h"
class House
{
	char* adress;
	Flat* flats[20];
	//Resident** arr;

public:
	House();
	House(char* adress);
	~House();

	void setAdress(char* newAdress);
	const char* getAdress();

	void addPerson(Resident person, int nFlat);
	void delPerson(char* name, int nFlat);
	void showAllFlatsList();
	void showAllPersonList();
	void showPersonListByFlat(int n);

	void toBinFile(FILE* fp);
	void fromBinFile(FILE* fp);
	
};

