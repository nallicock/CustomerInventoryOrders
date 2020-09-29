/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
*/
#ifndef ITEM_H
#define ITEM_H
#include <string>
#include <iostream>
#include <string>
#include <iomanip>
#include "Utilities.h"

class Item
{

	std::string m_name;
	std::string m_description;
	unsigned int m_serialNumber;
	unsigned int m_quantity = 0;
	unsigned int static m_widthField;

public:

	Item(std::string);
	const std::string& getName() const;
	const unsigned int getSerialNumber();
	const unsigned int getQuantity();
	void updateQuantity();
	void display(std::ostream &os, bool full) const;
};

#endif