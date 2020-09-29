/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
*/
#include "Item.h"
#include "Utilities.h"
#include <iomanip>
#include <iostream>

size_t Item::m_widthField = 1;

Item::Item(std::string str) {

	Utilities utilities;
	char delim = utilities.getDelimiter();
	bool check = false;
	size_t begin = 0;
	size_t end = str.find(delim);

	this->m_name = str.substr(begin, end);
	begin = end + 1;
	end = str.find(delim, begin);

	this->m_serialNumber = std::stoi(utilities.extractToken(str, begin, check));
	begin = end + 1;
	end = str.find(delim, begin);

	this->m_quantity = std::stoi(utilities.extractToken(str, begin, check));
	begin = end + 1;

	this->m_description = utilities.extractToken(str, begin, check);

	if (m_widthField < m_name.length())
	{
		m_widthField = m_name.length();
	}
}

void Item::display(std::ostream& os, bool full) const
{
	os << std::setw(m_widthField) << std::left << getName() << " ["
		<< std::setw(6) << std::right << std::setfill('0') << m_serialNumber << std::setfill(' ') << "]";

	if (full)
		os << " Quantity: " << std::setw(m_widthField) << std::left << m_quantity << " Description: " <<
		m_description;

	os << std::endl;
}

const std::string& Item::getName() const
{
	return m_name;
}

const unsigned int Item::getSerialNumber()
{
	return m_serialNumber++;
}

const unsigned int Item::getQuantity()
{
	return m_quantity;
}

void Item::updateQuantity()
{
	if (m_quantity > 0)
	{
		m_quantity--;
	}
}