// NormalGenerator.cpp
// 
//
//

#include "NormalGenerator.h"
#include <iostream>
#include <cmath>

// Default constructor
BoostNormal::BoostNormal() : NormalGenerator()
{
	rng = boost::lagged_fibonacci607();
	norm = boost::normal_distribution<>(0, 1);
	random = new boost::variate_generator<boost::lagged_fibonacci607&, boost::normal_distribution<> >(rng, norm);

}

// Destructor
BoostNormal::~BoostNormal()
{
	delete random;
}

// Implement the pure virtual function in derived class
double BoostNormal::getNormal() const
{
	return (*random)();
}
