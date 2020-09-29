/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
*/
#ifndef CUSTOMERORDER_H
#define CUSTOMERORDER_H

#include <string>
#include <iostream>
#include "Item.h"


struct ItemInfo
{
	std::string m_itemName;
	unsigned int m_serialNumber = 0;
	bool m_fillState = false;

	ItemInfo(std::string src) : m_itemName(src) {};
};

class CustomerOrder {

	std::string m_name;
	std::string m_product;
	unsigned int m_cntItem;
	ItemInfo** m_lstItem;
	static size_t m_widthField;

public:

	CustomerOrder();
	CustomerOrder(std::string);
	CustomerOrder(const CustomerOrder &);
	CustomerOrder(CustomerOrder &&) noexcept;
	~CustomerOrder();
	CustomerOrder & operator=(CustomerOrder &&);
	CustomerOrder & operator=(const CustomerOrder &) = delete;
	bool getItemFillState(std::string) const;
	bool getOrderFillState() const;
	void fillItem(Item &, std::ostream &);
	void display(std::ostream &) const;

};

#endif