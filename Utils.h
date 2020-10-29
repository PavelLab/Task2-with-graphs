#pragma once

#include <functional>
#include <cmath>
#include <vector>

struct parametr
{
	double a, b, c;
};

namespace utils
{
	//
	// User defined functions
	//
	double function_1(double x, double y = 0.0);
	/*double function_1_derivative(double x, double y = 0.0);*/
	double calc_func_1(double x, double y1, double y2, parametr param /* =0 */);
	double calc_func_2(double x, double y1, double y2, parametr param /* =0 */);

	//
	// Numerical methods
	//

	std::vector<double> runge_kutta_4_system(
		std::function<double(double, double, double, parametr)> calc_func_1,
		std::function<double(double, double, double, parametr)> calc_func_2,
		double step, double x, double y1, double y2, parametr param);
}
