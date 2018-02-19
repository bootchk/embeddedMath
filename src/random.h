
#pragma once



// Wrapper to platform provided std lib functions

// Get a random integer in the range [min, max] including both end points.
// depends on stdlib rand()
unsigned int randUnsignedInt(unsigned int min, unsigned int max);

// Random flip of fair coin
// depends on rand()
bool randBool();


bool randomProbability(unsigned int inverseProbability);
