/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
:)
*/
#include <string>
#include <iostream>
#include <iomanip>
#include <vector>
#include "Item.h"
#include "Utilities.h"
#include "CustomerOrder.h"

size_t CustomerOrder::m_widthField = 1;

CustomerOrder::CustomerOrder() 
{

	m_name = "";
	m_product = "";
	m_cntItem = 0;
	m_lstItem = nullptr;

} 

CustomerOrder::CustomerOrder(std::string _tokens_str) 
{

	Utilities util;
	std::vector<std::string> tokens;
	size_t x = 0, start_pos = 0;
	bool more = false;

	do 
	{

		tokens.push_back(util.extractToken(_tokens_str, start_pos, more));
		x++;

	} while (more);

	m_cntItem = tokens.size() - 2;
	m_lstItem = new ItemInfo *[m_cntItem];

	for (size_t x = 0; x < tokens.size(); x++) {

		if (x == 0) 
		{

			m_name = tokens[x];
		}

		else if (x == 1) 
		{

			m_product = tokens[x];
		}

		else 
		{

			m_lstItem[x - 2] = new ItemInfo(tokens[x]);
		}

	}

	m_widthField = (m_widthField > util.getFieldWidth()) ? m_widthField : util.getFieldWidth();

}

CustomerOrder::CustomerOrder(const CustomerOrder & _co) 
{

	throw "ERROR";

}

CustomerOrder::CustomerOrder(CustomerOrder && _co) noexcept 
{

	*this = std::move(_co);

} 

CustomerOrder::~CustomerOrder() 
{

	delete[] m_lstItem;

}

CustomerOrder & CustomerOrder::operator=(CustomerOrder && _co) 
{

	if (this != &_co) 
	{

		m_name = _co.m_name;
		m_product = _co.m_product;
		m_cntItem = _co.m_cntItem;
		m_lstItem = _co.m_lstItem;

		_co.m_name = "";
		_co.m_product = "";
		_co.m_cntItem = 0;
		_co.m_lstItem = nullptr;

	} 

	return *this;

} 

bool CustomerOrder::getItemFillState(std::string _item_name) const 
{

	bool is_filled = false, item_found = false;

	for (size_t x = 0; x < m_cntItem; x++) 
	{

		if (m_lstItem[x]->m_itemName == _item_name) 
		{

			is_filled = m_lstItem[x]->m_fillState;
			item_found = true;

		} 

	}

	if (!item_found)
		is_filled = true;

	return is_filled;

} 

bool CustomerOrder::getOrderFillState() const 
{

	bool is_filled = true;

	for (size_t x = 0; x < m_cntItem; x++) 
	{

		if (!m_lstItem[x]->m_fillState) 
		{

			is_filled = false;

		} 

	}

	return is_filled;

}

void CustomerOrder::fillItem(Item & _item, std::ostream & os) {

	for (size_t x = 0; x < m_cntItem; x++) {

		if (m_lstItem[x]->m_itemName == _item.getName()) {

			if (_item.getQuantity() > 0) {

				_item.updateQuantity();
				m_lstItem[x]->m_serialNumber = _item.getSerialNumber();
				m_lstItem[x]->m_fillState = true;
				os << "Filled " << m_name << ", " << m_product << "[" << m_lstItem[x]->m_itemName << "]" << std::endl;

			}

			else {

				os << "Unable to fill " << m_name << ", " << m_product << "[" << m_lstItem[x]->m_itemName << "]" << std::endl;

			} 

		} 

	}

} 

void CustomerOrder::display(std::ostream & os) const {

	os << m_name << " - " << m_product << std::endl;

	for (size_t x = 0; x < m_cntItem; x++) 
	{

		os
			<< "["
			<< std::setw(6) << std::right << std::setfill('0') << m_lstItem[x]->m_serialNumber
			<< "] " << std::left
			<< std::setfill(' ') << std::setw(CustomerOrder::m_widthField) << m_lstItem[x]->m_itemName << " - "
			<< ((m_lstItem[x]->m_fillState) ? "FILLED" : "MISSING") << std::endl;

	}

}