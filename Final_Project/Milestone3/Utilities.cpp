/*************************
* OOP345 - Milestone 1
* Author: Nahal Esmaeili
* Prof: John Blair
* August 02, 2017
*************************/

#include <iostream>
#include <string>
#include <algorithm> 
#include <functional> 
#include <cctype>
#include <locale>
#include "Utilities.h"

char Utilities::delimiter;
std::ofstream Utilities::logFile;

Utilities::Utilities() 
{
	field_width = 1;
}

void Utilities::setFieldWidth(size_t fw) 
{
	field_width = fw;
}

size_t Utilities::getFieldWidth() const 
{
	return this->field_width;
}

const std::string Utilities::nextToken(const std::string& str, size_t& next_pos, bool& more) 
{
	bool isValid = false;
	std::string token;
	try 
	{
		for (int i = next_pos; i < 1000; i++) 
		{
			if (str[0] == delimiter) 
			{
				if (str[i + 1] == delimiter) 
				{ 
					next_pos = i + 1;
					throw std::string(str + "<-- *** no token found before the delimiter ***");
				}
				else 
				{ 
					field_width = str.size();
					throw std::string(str + " <-- *** no token found before the delimiter ***");
				}
			}

			if (str[i] == '\0') 
			{ 
				token = str.substr(next_pos, i - next_pos);
				if (field_width < i - next_pos) 
				{
					field_width = i - next_pos;
				}
				more = false; 
				break; 
			}
			else if (str[i] == delimiter) 
			{
				token = str.substr(next_pos, i - next_pos);
				if (field_width < i - next_pos) 
				{ 
					field_width = i - next_pos;
				}
				next_pos = i + 1;
				more = true; 
				break; 
			}
		}

		while (!isValid && !token.empty()) 
		{ 
			if (token.at(0) == ' ') { token.erase(0, 1); }
			else if (token.back() == ' ') { token.erase(token.length() - 1, 1); }
			else { isValid = true; }
		}
	}

	catch (const std::string& msg) 
	{
		std::cout << msg << std::endl;
		more = false;
	}
	return token; 
}

void Utilities::setDelimiter(const char pDelim) 
{
	Utilities::delimiter = pDelim;
}

void Utilities::setLogFile(const char* logfile) 
{
	logFile.close();
	logFile.open(logfile);
}

std::ofstream& Utilities::getLogFile() 
{
	return logFile;
}