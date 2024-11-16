/*
 * @file ModuloDigit.cpp
 * @brief Implements the ModuloDigit class methods for single digit counting
 * Created on: 15 Nov 2024
 * Author: Abhinav Kumaar Krishna Kumar
 */

#include "ModuloNDigit.h"
#include <iostream>

/*
 * @brief Parameterized Constructor for ModuloNDigit class
 *
 * @param int max		: [IN] The maximum count value
 *
 * @attention The constructor assigns
 * the base value and current_count value
 */
ModuloNDigit::ModuloNDigit(int max)
{
	base = max;
	currCount = 0;
}

/*
 * @brief Default constructor for ModuloNDigit class
 *
 * @attention The constructor assigns the
 * base value and current_count value to null
 */
ModuloNDigit::ModuloNDigit()
{
	base = 0;
	currCount = 0;
}

/*
 * @brief Counter method which increments the current count
 * and resets to 0 if the maximum count is reached
 *
 * @return True if the count overflows else false
 */
bool ModuloNDigit::counter()
{
	currCount++;
	if ((currCount % base) == 0)
	{
		currCount = 0;
		return true;
	}
	return false;
}

/*
 * @brief Getter method for the current counter value
 *
 * @return The current counter value
 */
int ModuloNDigit::getCurrCount() const
{
	return currCount;
}

/*
 * @brief Prints the current count value in the
 * respective input base (binary, hex, octal, decimal)
 */
void ModuloNDigit::print() const
{
	if (base == 16)
	{
		std::cout << std::hex << std::uppercase << currCount << std::dec;
	}
	else
	{
		std::cout << currCount;
	}
}

/*
 * @brief Destructor for ModuloNDigit class.
 */
ModuloNDigit::~ModuloNDigit()
{

}

