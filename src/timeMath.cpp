
#include <cassert>
#include "timeMath.h"


/*
 * LongTime and DeltaTime math
 *
 * These return shorter uints as returned by OSClock and used by other OS methods.
 *
 * use -Wconversion to get warnings about coercions with loss
 */


DeltaTime TimeMath::clampedTimeDifference(LongTime laterTime, LongTime earlierTime) {
	//
	DeltaTime result;

	if (earlierTime > laterTime)
		result = 0;
	else {
		// convert with sanity testing (<24bits)
		result = convertLongTimeToOSTime(laterTime - earlierTime);
	}

	return result;
	// Any stronger assertions, i.e. sanity re schedule must be done by caller
}



DeltaTime TimeMath::convertLongTimeToOSTime(LongTime aTime) {
	/*
	 * Assertion must be first, before the conversion that might lose data.
	 * Assert result is an OSTime, which may be 24-bit.
	 * Comparison is less than OR equal to max value of the type DeltaTime.
	 * The coerce is only to 32-bit type.
	 */
	assert(aTime <= TimeMath::MaxDeltaTime);

	// !!! Coerce to 32-bit, with possible loss (when not asserted above)
	DeltaTime result = (DeltaTime) aTime;

	return result;
}



DeltaTime TimeMath::clampedSubtraction(DeltaTime lhs, DeltaTime rhs){
	DeltaTime result;

	// DeltaTime is unsigned
	if (rhs >= lhs)   result = 0;
	else             result = lhs - rhs;
	return result;
}



DeltaTime TimeMath::deltaSubtraction(DeltaTime lhs, DeltaTime rhs){
	assert (lhs >= rhs);
	return clampedSubtraction(lhs, rhs);
}
