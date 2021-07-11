#include <iostream>
#include <string>
#include <functional>
#include <algorithm>
#include <limits>
#include <fstream>

namespace NewtonRaphson
{
	using DP = double;
	using REAL_FUNC = std :: function <DP(DP)>;

		
//*****Derivative function
	auto deriv (const REAL_FUNC & fun, const DP x0, const DP eps = 1.e-5)
	{
		return (fun(x0 + eps) - fun(x0))/eps;
	}
//-------------------------------------------------------
//****NewtonRaphson Algorithm*****
//-------------------------------------------------------
//Inputs: fun====> a function object
//	  start_x=> an estimated starting point
//        thresh => a convergence threshold 
//Outputs:
//	 - a root of the supplied function
//  	 - convergence condition (true or false)
//-------------------------------------------------------
	void FindRoot (const REAL_FUNC & fun, const DP start_x, const DP thresh=1e-10)
	{
		DP x_n {start_x}, answer{0.0};
		const DP eps = std::numeric_limits<DP>::epsilon();
		bool reach_converg {false};
		const size_t KMaxIters {1000};
		std::ofstream outFile;
		outFile.open("Result.txt",std::ios::app);
		for (size_t n=0; n<=KMaxIters; ++n)
		{
			const DP loc_thresh = std::max(thresh, eps*std::fabs(x_n));
			DP df_x = deriv(fun, x_n);
			if (std::fabs(df_x) <= eps)
				break;
			DP delta = -fun(x_n)/df_x;
			if (std::fabs(delta) <= loc_thresh)
			{
				reach_converg = true;
				break;
			}
			x_n+=delta;
		}
		answer=x_n;
		std::cout << "Answer is " << (reach_converg ? std::to_string(answer): "none") << std::endl;
		outFile << "Answer is " << (reach_converg ? std::to_string(answer): "none") << std::endl;
		}
	


	DP	your_function(DP x)
	{
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////
		//////////////////////////////////////////////////////////////////
		//Enter you function here//
		//for example:
		return x*x+x-6.0;
		////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////
	}
		
	void 	fun()
	{
		DP start_x;
		std:: cout << "Enter your starting value: ";
		std:: cin >> start_x;
		FindRoot (your_function, start_x );
		
	}
}


int main()
{
	NewtonRaphson::fun();
	return 0;
}
