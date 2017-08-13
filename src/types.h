
#include <inttypes.h>


/*
 * Restrict TimeMath results to this type.
 *
 * Difference of LongTime actually yields another LongTime (modulo math on unsigned.)
 * But the application only needs much smaller results,
 * and TimeMath enforces that.
 */
typedef uint32_t DeltaTime;


/*
 * Type that LongClock yields.  Only 56 bits are valid.
 *
 * TimeMath uses.
 */
typedef uint64_t LongTime;
