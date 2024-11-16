/*
 * @file ModuloDigit.h
 * @brief Declares the ModuloDigit class for single digit counting
 * Created on: 15 Nov 2024
 * Author: Abhinav Kumaar Krishna Kumar
 */
#ifndef MODULONDIGIT_H_
#define MODULONDIGIT_H_

/*
 * @class ModuloNDigit
 *
 * @brief This class represents single digit counting operation
 */
class ModuloNDigit
{
private:

	/* The input type (binary, hex, octal, decimal which is the maximum count*/
	int base;

	/* The current count value*/
	int currCount;

public:

	/*
	 * @brief Parameterized Constructor for ModuloNDigit class
	 *
	 * @param int max		: [IN] The maximum count value
	 *
	 * @attention The constructor assigns
	 * the base value and currentCount value
	 */
	ModuloNDigit(int max);

	/*
	 * @brief Default constructor for ModuloNDigit class
	 *
	 * @attention The constructor assigns the
	 * base value and currentCount value to null
	 */
	ModuloNDigit();

	/*
	 * @brief Counter method which increments the current count
	 * and resets to 0 if the maximum count is reached
	 *
	 * @return True if the count overflows else false
	 */
	bool counter();

	/*
	 * @brief Getter method for the current counter value
	 *
	 * @return The current counter value
	 */
	int getCurrCount() const;

	/*
	 * @brief Prints the current count value in the
	 * respective input base (binary, hex, octal, decimal)
	 */
	void print() const;

	/*
	 * @brief Destructor for ModuloNDigit class.
	 */
	~ModuloNDigit();
};

#endif /* MODULONDIGIT_H_ */
