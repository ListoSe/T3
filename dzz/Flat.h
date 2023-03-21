#pragma once
#include <iostream>
#include <cstring>
#include "Resident.h"
using namespace std;

class Flat
{
	int rooms;
	float square;
	int amountOfResidents;
	Resident** arr;
	FILE* fp;
public:
	Flat();
	Flat(int rooms, float square);
	Flat(const Flat& obj);//Конструктор копирования, D = this, B = obj
	Flat& operator = (const Flat& obj);//Оператор присвоения
	~Flat();

	void setRooms(int rooms);
	int getRooms()const;
	void setSquare(float square);
	float getSquare()const;
	int getAmountOfResidents()const;
	int isAvailableCurrency(int rooms, float square, int amountOfResidents, Resident** arr);

	void addResident(Resident person);
	void delResident(char* name);
	void showResidents();
	void showInfo()const;

	void toBinFile(FILE* fp);
	void fromBinFile(FILE* fp);
};

