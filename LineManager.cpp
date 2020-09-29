/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
*/
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <deque>
#include <algorithm>
#include "CustomerOrder.h"
#include "Task.h"
#include "Utilities.h"
#include "LineManager.h"

LineManager::LineManager(const std::string & _fn, std::vector<Task *> & _tasks, std::vector<CustomerOrder> & _orders) 
{
	m_cntCustomerOrder = _orders.size();
	std::fstream file(_fn, std::fstream::in);

	if (!file)
		throw std::string("Unable to open [") + _fn + "] file.";

	std::string _tokens_str;
	while (!file.eof()) 
	{
		std::getline(file, _tokens_str);
		Utilities util;
		std::vector<std::string> tokens;
		size_t x = 0, start_pos = 0;
		bool more = false;
		util.setDelimiter('|');

		do 
		{

			tokens.push_back(util.extractToken(_tokens_str, start_pos, more));
			x++;

		} while (more);

		Task * lChain = nullptr;
		Task * rChain = nullptr;

		for (Task * task : _tasks) 
		{

			if (task->getName() == tokens[0]) 
			{

				lChain = task;

			}

			else if (tokens.size() > 1) 
			{

				if (task->getName() == tokens[1]) 
				{

					rChain = task;

				} 

			}

		}

		if (rChain != nullptr) 
		{

			lChain->setNextTask(*rChain);

		}

	}

	for (Task * task : _tasks)
		AssemblyLine.push_back(task);

	for (size_t i = 0; i < _orders.size(); i++)
		ToBeFilled.push_front(std::move(_orders[i]));

	std::vector<Task *> sorted;

	for (auto task : AssemblyLine)
	{

		if (task->getNext() == nullptr)
			sorted.push_back(task);
	}

	for (size_t i = 0; i < AssemblyLine.size(); i++) {
		for (auto task : AssemblyLine) {
			if (task->getNext() != nullptr) {
				if (task->getNext() == sorted.back())
					sorted.push_back(task);
			}
		}
	}

	std::reverse(sorted.begin(), sorted.end());
	First = sorted.front();
	Last = sorted.back();
	file.close();

}

void LineManager::validateTasks() const
{

	for (Task * task : AssemblyLine)
		task->validate(std::cout);

}

void LineManager::displayCompleted(std::ostream & os) const 
{

	for (auto & order : Completed)
		order.display(os);

}

bool LineManager::run(std::ostream & os) {
	bool finished = true;

	if (!ToBeFilled.empty())
	{

		*First += std::move(ToBeFilled.back());
		ToBeFilled.pop_back();

	}

	for (Task * task : AssemblyLine)
		task->runProcess(os);

	CustomerOrder filled_order;

	if (Last->getCompleted(filled_order))
		Completed.push_back(std::move(filled_order));

	for (Task * task : AssemblyLine)
	{

		if (task->moveTask())
			finished = false;

	}

	return finished;

}