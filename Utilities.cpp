/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
*/

#include "Utilities.h"
#include <complex.h>

char Utilities::m_delimiter = '\0';

const std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
{
	const auto new_pos = str.find(getDelimiter(), next_pos);
	auto token = str.substr(next_pos, new_pos - next_pos);

	more = new_pos != std::string::npos;

	if (new_pos == next_pos)
	{
		std::string err = "ERROR - two delimiters with no token between them";
		throw err;
	}

	if (token.length() > getFieldWidth())
	{

		this->setFieldWidth(token.length());
	}

	next_pos = new_pos + 1u;

	return token;
}

void Utilities::setFieldWidth(size_t widthField)
{

	this->m_widthField = widthField;
}

size_t Utilities::getFieldWidth() const
{
	return this->m_widthField;
}

void Utilities::setDelimiter(const char delim)
{
	m_delimiter = delim;
}

const char Utilities::getDelimiter() const
{
	return this->m_delimiter;
}