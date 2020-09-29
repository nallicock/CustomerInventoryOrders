/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
*/
#ifndef LINEMANAGER_H
#define LINEMANAGER_H

#include <string>
#include <iostream>
#include <vector>
#include <deque>
#include "CustomerOrder.h"


class LineManager 
{
	std::vector<Task *> AssemblyLine;
	std::deque<CustomerOrder> ToBeFilled;
	std::deque<CustomerOrder> Completed;
	unsigned int m_cntCustomerOrder;
	Task * First;
	Task * Last;

public:

	LineManager(const std::string &, std::vector<Task *> &, std::vector<CustomerOrder> &);
	bool run(std::ostream &);
	void displayCompleted(std::ostream&) const;
	void validateTasks() const;

};

#endif