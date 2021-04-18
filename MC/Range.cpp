// Range.cpp
//
//

#ifndef Range_CPP
#define Range_CPP

#include "Range.h"
#include <vector>

// Default constructor
template<typename Type>
Range<Type>::Range()
{
	Type def(0);
	lo = def;
	hi = def;
}

// Constructor with low and high value
template<typename Type>
Range<Type>::Range(const Type& l, const Type& h)
{
	if (l < h)
	{
		lo = l;
		hi = h;
	}
	else
	{
		hi = l;
		lo = h;
	}
}

// Copy constructor
template<typename Type>
Range<Type>::Range(const Range<Type>& rng)
{
	lo = rng.lo;
	hi = rng.hi;
}

// Destructor
template<typename Type>
Range<Type>::~Range() {}

// Getters
template<typename Type>
Type Range<Type>::low() const
{
	return lo;
}

template<typename Type>
Type Range<Type>::high() const
{
	return hi;
}

// Setters
template<typename Type>
void Range<Type>::low(const Type& l)
{
	lo = l;
}

template<typename Type>
void Range<Type>::high(const Type& h)
{
	hi = h;
}

// Boolean Functions
template<typename Type>
bool Range<Type>::left(const Type& val) const
{
	// Check if current value is to the left of the range
	if (val < lo)
		return true;

	return false;
}

template<typename Type>
bool Range<Type>::right(const Type& val) const
{
	// Check if current value is to the right of the range
	if (val > hi)
		return true;

	return false;
}

template<typename Type>
bool Range<Type>::contains(const Type& val) const
{
	// Does range contain t
	if ((lo <= val) && (hi >= val))
		return true;

	return false;
}

// Utility function
// The mesh size is constant
template<typename Type>
std::vector<Type> Range<Type>::mesh(long nSteps) const
{
	Type h = (hi - lo) / Type(nSteps);

	std::vector<Type> result(nSteps + 1);

	Type val = lo;

	for (long i = 0; i < nSteps + 1; i++)
	{
		result[i] = val;
		val += h;
	}

	return result;
}

// Assignment operator
template <typename Type>
Range<Type>& Range<Type>::operator = (const Range<Type>& rng)
{
	hi = rng.hi;
	lo = rng.low;

	return *this;
}

#endif // !Range_CPP
