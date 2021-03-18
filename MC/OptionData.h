// OptionData.h
//
// Encapsulate option data

#ifndef OptionData_H
#define OptionData_H

#include <algorithm>

// Encapsulate all data in one place
struct OptionData
{
	double K;
	double T;
	double r;
	double sig;

	double H;		// down and out barrier
	double D;		// dividend
	double betaCEV;	// elasticity factor (CEV model)
	double scale;	// scale factor in CEV model

	int type;		// 1 == call, -1 == put

	double PayOffFunction(double S)
	{
		// Payoff function
		if (type == 1)
		{
			// Call
			return std::max(S - K, 0.0);
		}
		else
		{
			// Put
			return std::max(K - S, 0.0);
		}
	}
};

#endif // !OptionData_H
