// Range.h
//
// A class that represents a closed interval [low, high].
// 

#ifndef Range_H
#define Range_H

#include <vector>

template <typename Type>
class Range
{
private:
	Type lo;
	Type hi;

public:
	Range();										// Default constructor
	Range(const Type& l, const Type& h);			// Constructor with Low and high value
	Range(const Range<Type>& rng);					// Copy constructor
	~Range();										// Destructor

	// Getters
	Type low() const;
	Type high() const;

	// Setters
	void low(const Type& l);
	void high(const Type& h);

	// Boolean functions
	bool left(const Type& val) const;				// Is the value to the left  of the range?
	bool right(const Type& val) const;				// Is the value to the right of the range?
	bool contains(const Type& val) const;			// Does range contain value?

	// Utility function
	std::vector<Type> mesh(long nSteps) const;

	// Assignment operator
	Range<Type>& operator = (const Range<Type>& rng);

};
#endif // !Range_H

