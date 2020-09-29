/*
Name: Nicholas Allicock
Date: Dec 1 2019
Section: NFG
Email: nallicock@myseneca.ca
Student ID: 103099164
*/
#ifndef UTILITIES_H
#define UTILITIES_H
#include <string>

	class Utilities
	{
		size_t m_widthField = 1;
		static char m_delimiter;

	public:

		void setFieldWidth(size_t width);
		size_t getFieldWidth() const;
		const std::string extractToken(const std::string& str, size_t& next_pos, bool& more);
		static void setDelimiter(const char delim);
		const char getDelimiter() const;

	};

#endif