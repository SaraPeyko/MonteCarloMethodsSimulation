// NormalGenerator.h
//
// A class hierarchy for gathering random numbers, vectors and matrices.
// The program uses the Template Method Pattern, Object-Oriented Programming
// and Polymorphism

#ifndef NormalGenerator_H
#define NormalGenerator_H

#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/normal_distribution.hpp>
#include <boost/random/variate_generator.hpp>

// Base class
class NormalGenerator
{
public:
	// Pure virtual function
	virtual double getNormal() const = 0;
};

// Derived class
class BoostNormal :public NormalGenerator
{
private:
	boost::lagged_fibonacci607 rng;
	boost::normal_distribution<> norm;
	boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<> >* random;

public:
	BoostNormal();					// Default constructor
	~BoostNormal();					// Destructor

	double getNormal() const;		// Implement this function
};
#endif // !NormalGenerator_H

