/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
*/
#ifndef TASK_H
#define TASK_H

#include <string>
#include <iostream>
#include <deque>
#include "CustomerOrder.h"


class Task : public Item 
{

	std::deque<CustomerOrder> m_orders;
	Task * m_pNextTask;

public:

	Task(const std::string);
	Task(Task &) = delete;
	Task(Task &&) = delete;
	Task & operator=(Task &) = delete;
	Task & operator=(Task &&) = delete;
	void runProcess(std::ostream &);
	bool moveTask();
	void setNextTask(Task &);
	bool getCompleted(CustomerOrder &);
	void validate(std::ostream &);
	Task * getNext();
	Task & operator+=(CustomerOrder &&);

};

#endif