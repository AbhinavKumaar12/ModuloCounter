/*
 * @file ModuloNCounter.h
 * @brief Declares the ModuloNCounter class for for N digits counting
 * Created on: 15 Nov 2024
 * Author: Abhinav Kumaar Krishna Kumar
 */

#ifndef MODULONCOUNTER_H_
#define MODULONCOUNTER_H_

#include "ModuloNDigit.h"

/*
 * @class ModuloNCounter
 *
 * @brief This class represents N digit counting operation
 */
class ModuloNCounter
{
private:

	/* Array of ModuloDigit objects representing individual digits in the counter*/
	ModuloNDigit *cArr;

	/* Number of digits for which the counter should run*/
	int digits;

	/* base of the counter (2, 8, 10, or 16)*/
	int base;

	/*
	 * @brief Increments the counter, checks the overflow and
	 * resets counter if there is overflow
	 */
	void count();

	/*
	 * @brief Prints the current N counter value
	 */
	void print() const;

	/*
	 * @brief Check for counter overflow
	 *
	 * @return True if no overflow else false
	 */
	bool checkOverflow() const;

public:

	/*
	 * @brief Constructor for ModuloNCounter class
	 * It initializes values for the base and digits variables
	 * Creates an array of type ModuloDigit
	 *
	 * @param int inputDigits 		: [IN] Number of digits in the counter
	 * @param int inputBase			: [IN] Base of the counter (2, 8, 10, or 16)
	 */
	ModuloNCounter(int inputDigits, int inputBase);

	/*
	 * @brief Increments the N digit counter
	 * and prints the current count
	 */
	void normCounter();

	/*
	 * @brief Prefix increment operator
	 * Increments the N digit counter and prints the current count
	 *
	 * @return Reference to the incremented ModuloNCounter object
	 */
	ModuloNCounter& operator++();

	/*
	 * @brief Postfix increment operator
	 * Post increments the N digit counter and prints the current count
	 *
	 * @param int a 		: [IN]  Unused parameter for postfix increment
	 *
	 * @return Reference to the incremented ModuloNCounter object
	 */
	ModuloNCounter& operator++(int a);

	/*
     * @brief Destructor for ModuloNCounter class
	 *
	 * @attention Deallocates memory for the array of ModuloDigit objects
	 * Reset member variables
	 */
	~ModuloNCounter();
};

#endif /* MODULONCOUNTER_H_ */
