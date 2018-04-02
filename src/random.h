
#pragma once


/*
 * Augment  platform provided std lib function: rand()
 *
 * Is a class so that names always mangled (cmake was wierd about that.)
 */


class Random {
public:
	/*
	 * random positive integer in the range [min, max] including both end points.
	 *
	 * !!! rand() returns int, not unsigned int.
	 */
	static unsigned int unsignedInt(unsigned int min, unsigned int max);

	/*
	 *  Random flip of fair coin
	 */
	static bool coinToss();


	static bool eventWInverseProbability(unsigned int inverseProbability);
};
