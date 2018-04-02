
#include <cassert>

#include <cstdlib>	// rand() etc

#include "random.h"	// Our random.h, not from libstdc++


// FUTURE class and namespace to hide

/*
 * Utility routines, assuming platform only provides rand()
 *
 * Notes:
 *
 * Std C rand() yields value in range [0, RAND_MAX].
 * !!! rand() returns signed type, but guaranteed to be positive (MSB == 0)
 *
 * Here we assume that int is 32 bits and RAND_MAX is 2^31
 *
 * Some sources say RAND_MAX >= 32767 (2^15)
 * i.e. result fits in, but does not uniformly fill uint_16!!!
 *
 * (!!! The shell command rand() yields random bytes i.e. uint8_t.)
 *
 * See below, we don't use %.
 * % is remainder operator.
 * With signed operands, % may yield negative result on some implementations.
 * Here we explicitly use unsigned operands.
 */

unsigned int randUnsignedInt(unsigned int min, unsigned int max) {
	/*
	 * Typical implementation with slight flaws in uniform distribution:
	 * Unless max-min divides int without a remainder, binning means some bins receive more
	 * values, i.e. non-uniform distribution.
	 */
	assert( max >= min);
	assert((max - min) < RAND_MAX);	// else not uniformly distributed
	/*
	 * This poor solution is biased because % uses low order bits which are non-random:
	 * int intResult = rand() % ( max + 1 - min) + min;
	 */

	/*
	 * This solution does NOT use floating point.
	 */
	int intResult = min + rand() / (RAND_MAX / (max - min + 1) + 1);

	/*
	 * The C compiler does NOT complain about conversion from unsigned int to int,
	 * because it is so common?
	 */
	unsigned int result = intResult;

	// ensure result as specified
	assert (result >= min && result <= max);
	return result;
}

/*
 * Random flip of a fair coin.
 * Depends on rand()
 */
bool randBool(void) {
	unsigned int result = rand() % 2;
	assert( result == 0 || result == 1);
	return result;	// coerce to bool
}

bool randomProbability(unsigned int inverseProbability) {
	// 0 is arbitrary, could be any positive integer less than inverseProbability
	bool result = (rand() % inverseProbability) == 0;
	return result;
}


