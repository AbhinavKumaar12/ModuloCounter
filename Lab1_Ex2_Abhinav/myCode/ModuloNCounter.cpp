/*
 * @file ModuloNCounter.cpp
 * @brief Implements the ModuloNCounter class methods for N digits counting
 * Created on: 15 Nov 2024
 * Author: Abhinav Kumaar Krishna Kumar
 */

#include "ModuloNCounter.h"
#include <iostream>

/*
 * @brief Constructor for ModuloNCounter class
 * It initializes values for the base and digits variables
 * Creates an array of type ModuloDigit
 *
 * @param int inputDigits 		: [IN] Number of digits in the counter
 * @param int inputBase			: [IN] Base of the counter (2, 8, 10, or 16)
 */
ModuloNCounter::ModuloNCounter(int inputDigits, int inputBase)
{
	digits = inputDigits;
	base = inputBase;
	cArr = new ModuloNDigit[digits];

	for (int i = 0; i < digits; i++)
	{
		cArr[i] = ModuloNDigit(base);
	}
}

/*
 * @brief Increments the counter, checks the overflow and
 * resets counter if there is overflow
 */
void ModuloNCounter::count()
{
	bool carry = false;
	for (int i = 0; i < digits; i++)
	{
		carry = cArr[i].counter();
		if (!carry)
		{
			break;
		}
	}
}

/*
 * @brief Prints the current N counter value
 */
void ModuloNCounter::print() const
{
	for (int i = digits - 1; i >= 0; i--)
	{
		cArr[i].print();
	}
}

/*
 * @brief Check for counter overflow
 *
 * @return True if no overflow else false
 */
bool ModuloNCounter::checkOverflow() const
{
	bool flag;
	for (int i = 0; i < digits; i++)
	{
		if (cArr[i].getCurrCount() != 0)
		{
			flag = false;
			return flag;
		}
		else
		{
			flag = true;
		}
	}
	return flag;
}

/*
 * @brief Prefix increment operator
 * Increments the N digit counter and prints the current count
 *
 * @return Reference to the incremented ModuloNCounter object
 */
ModuloNCounter& ModuloNCounter::operator++()
{
	int temp = 0;
	do
	{
		count();
		print();
		std::cout << " ";
		++temp;
		if (temp % base == 0)
		{
			std::cout << std::endl;
		}
	} while (!checkOverflow());
	return *this;
}

/*
 * @brief Increments the N digit counter
 * and prints the current count
 */
void ModuloNCounter::normCounter()
{
	int temp = 0;
	do
	{
		print();
		count();
		std::cout << " ";
		++temp;
		if (temp % base == 0)
		{
			std::cout << std::endl;
		}
	} while (!checkOverflow());
}

/*
 * @brief Postfix increment operator
 * Post increments the N digit counter and prints the current count
 *
 * @param int a 		: [IN]  Unused parameter for postfix increment
 *
 * @return Reference to the incremented ModuloNCounter object
 */
ModuloNCounter& ModuloNCounter::operator++(int a)
		{
			normCounter();
			return *this;
		}

/*
 * @brief Destructor for ModuloNCounter class
 *
 * @attention Deallocates memory for the array of ModuloDigit objects
 * Reset member variables
 */
ModuloNCounter::~ModuloNCounter()
{
	delete[] cArr;
	digits = 0;
	base = 0;
}

