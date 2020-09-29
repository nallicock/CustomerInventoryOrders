/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
*/
#include <string>
#include <iostream>
#include <deque>
#include "CustomerOrder.h"
#include "Task.h"

bool Task::moveTask()
{

	bool is_moved = false;

	if (m_pNextTask != nullptr)
	{

		if (!m_orders.empty())
		{

			if (m_orders.back().getItemFillState(getName()))
			{

				*m_pNextTask += std::move(m_orders.back());
				m_orders.pop_back();
				is_moved = true;

			}

		}

	}

	return is_moved;

}

Task & Task::operator+=(CustomerOrder && _co)
{

	m_orders.push_front(std::move(_co));

	return *this;

}

void Task::runProcess(std::ostream & os)
{

	if (!m_orders.empty())
	{

		if (!m_orders.back().getOrderFillState())
			m_orders.back().fillItem(*this, os);

	}

}

Task::Task(const std::string str_tokens) : Task::Item(str_tokens) 
{

	m_pNextTask = nullptr;

}

void Task::setNextTask(Task & next_task) 
{

	m_pNextTask = &next_task;

} 



bool Task::getCompleted(CustomerOrder & _co) 
{

	bool is_completed = false;

	if (!m_orders.empty()) 
	{
		_co = std::move(m_orders.back());
		m_orders.pop_back();
		is_completed = true;

	} 

	return is_completed;

}

void Task::validate(std::ostream & os) 
{

	os << getName() << " --> ";

	if (m_pNextTask != nullptr)
		os << m_pNextTask->getName();

	else
		os << "END OF LINE";

	os << std::endl;

}
Task * Task::getNext()
{

	return m_pNextTask;

}

