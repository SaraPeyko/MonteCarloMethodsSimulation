// TestMC.cpp
//
// C++ code to price an option
// CEV  (Constant elasticity of variance) model with a choice of parameters
// and Euler method. Given option price and number of times S hits the origin
//
//

#include "OptionData.h"
#include "NormalGenerator.h"
#include "Range.cpp"
#include <iostream>

// Defines drift + diffusion + data
namespace SDE
{
	OptionData* data;					// The data for option MC

	double drift(double t, double X)
	{
		// drift term
		return (data->r) * X;			// r*X
	}

	double diffusion(double t, double X)
	{
		// diffusion term
		double betaCEV = 1.0;
		return data->sig * pow(X, betaCEV);		// sig*X
	}
	
}

namespace Batch1
{
	double T = 0.25; 
	double K = 65; 
	double sig = 0.30; 
	double r = 0.08; 
	double S = 60;
}

namespace Batch2 
{ 
	double T = 1.0; 
	double K = 100; 
	double sig = 0.2; 
	double r = 0.0; 
	double S = 100; 
};

namespace Batch3
{	double T = 1.5; 
	double K = 120; 
	double sig = 0.40; 
	double r = 0.04; 
	double S = 100.0; 
};


int main()
{
	// Uncommented to test on different batches
	// using namespace Batch1;
	// using namespace Batch2;
	using namespace Batch3;

	std::cout << "1 factor MC with explicit Euler\n";
	OptionData option;
	option.K = K;
	option.T = T;
	option.r = r;
	option.sig = sig;
	option.type = -1;		// Put: -1, Call: 1
	double S0 = S;


	Range<double> range(0.0, option.T);				// Create the range of time t = 0 to t = T
	double Vold = S0; 								// Assign the price S0
	double Vnew = 0;

	long N;
	std::cout << "Number of subintervals in time: ";
	std::cin >> N;
	std::vector<double> x = range.mesh(N);			// create different value of time steps

	long NSim;
	std::cout << "Number of simulations: ";			// create different value of simulations
	std::cin >> NSim;

	double k = option.T / double(N);
	double sqrk = sqrt(k);

	// Normal random number
	double dW;
	double price = 0.0;		// Option price

	// Random Generator
	NormalGenerator* normal = new BoostNormal();

	SDE::data = &option;

	std::vector<double> res;
	int count = 0;			// Number of times S hits origin


	for (long i = 1; i <= NSim; ++i)
	{
		// 1. Calculate path at each iteration
		if ((i / 10000) * 10000 == i)
		{
			// Give status after each 1000th iteration
			std::cout << i << std::endl;
		}

		Vold = S0;
		for (unsigned long index = 1; index < x.size(); ++index)
		{
			// 2. Create random number
			dW = normal->getNormal();

			// The FDM (in this case explicit Euler)
			Vnew = Vold + (k * SDE::drift(x[index - 1], Vold)) +
				(sqrk * SDE::diffusion(x[index - 1], Vold) * dW);

			Vold = Vnew;

			if (Vnew <= 0.0) count++;
		}

		// Calculate the price at t = T
		double tmp = option.PayOffFunction(Vnew);
		price += (tmp) / double(NSim);
	}

	// discounting the average price
	price *= exp(-option.r * option.T);

	// cleanup scoped pointer
	delete normal;

	std::cout << "Price, after discounting: " << price;
	std::cout << "\nNumber of time origin is hit: " << count << '\n';

	return 0;
}

