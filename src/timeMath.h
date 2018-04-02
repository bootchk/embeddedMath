#pragma once

#include "timeTypes.h"	// DeltaTime, LongTime

/*
 * Knows math on time.
 *
 * All methods static class methods.
 *
 *
 * Calculation of DeltaTimes
 *
 * uint32 math is modulo: a delta is correct if laterTime > earlierTime
 * (even if the uint32 clock has wrapped).
 * But is incorrect if earlierTime > laterTime.
 * So if you are calculating a timeout to a future deadline time,
 * and the deadline is already in the past, simple math on uint32 is wrong.
 * Use a LongClock to avoid the issue.
 *
 * Calculating a DeltaTime by differencing LongTimes
 * does a conversion to OSTime i.e. take lower 32 bits of result.
 *
 * A sleep...(0) executes immediately without delay.
 * Thus a DeltaTime into the future (for scheduling) can be 0.
 *
 *
 * Times
 *
 * Methods returning a LongTime return future times, as long as called at appropriate instant
 * and task processing times is smaller than slotDurations.
 * When these return past times, calculation of DeltaTime clamps to zero.
 *
 * Methods returning a LongTime may be called many times during a slot (to schedule a new Timer),
 * not just at the start of a slot.
 * Thus you cannot assert they are greater than nowTime().
 */



/*
 * Arithmetic on LongTime yielding a DeltaTime (Duration) suitable for timeouts on platform.
 */
class TimeMath {

	/*
	 * DeltaTime constrained to 24-bits.
	 * So can be used to set Timer constrained to 24-bit.
	 */
	static const unsigned int MaxDeltaTime = 0xFFFFFF;

public:
	/*
	 * Not require laterTime is after earlierTime
	 * Returns forward time difference when laterTime after earlierTime.
	 * Returns zero when laterTime before earlierTime.
	 * Requires difference < MaxDeltaTime.
	 *
	 * !!!! Note the parameters are not in time order, the laterTime is first parameter
	 */
	static DeltaTime clampedTimeDifference(LongTime laterTime, LongTime earlierTime);



	/*
	 * Difference of DeltaTimes.
	 * Clamped to zero if rhs is larger than leftHandSize
	 */
	static DeltaTime clampedSubtraction(DeltaTime lhs, DeltaTime rhs);

	/*
	 * Difference of DeltaTimes.
	 * As above, but also asserts if lhs is larger than rhs (if would clamp)
	 */
	static DeltaTime deltaSubtraction(DeltaTime lhs, DeltaTime rhs);


	/*
	 * Convert LongTime (typically result of difference) to OSTime, asserting no loss of data
	 */
	static DeltaTime convertLongTimeToOSTime(LongTime givenTime);


};
