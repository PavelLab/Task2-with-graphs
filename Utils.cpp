#include "Utils.h"

//
// User defined functions
//

//double utils::function_1(double x, double y /* =0 */)
//{
//	return exp(2 * x);
//}

double utils::calc_func_1(double x, double y1, double y2, parametr param /* =0 */)
{
	return y2;
}

double utils::calc_func_2(double x, double y1, double y2, parametr param /* =0 */)
{
	return (-param.a*y2*abs(y2) - param.b*y2 - param.c*y1);
}

//double utils::function_1_derivative(double x, double y /* =0 */)
//{
//	return 2 * y;
//}


//
// Numerical methods
//

std::vector<double> utils::runge_kutta_4_system(std::function<double(double, double, double, parametr)> calc_func_1,
	std::function<double(double, double, double, parametr)> calc_func_2,
	double step, double x, double y1, double y2, parametr param)
{
	double k1_1 = calc_func_1(x, y1, y2, param);
	double k1_2 = calc_func_2(x, y1, y2, param);
	
	double k2_1 = calc_func_1(x + step / 2.0, y1 + 0.5 * step * k1_1, y2 + 0.5 * step * k1_2, param);
	double k2_2 = calc_func_2(x + step / 2.0, y1 + 0.5 * step * k1_1, y2 + 0.5 * step * k1_2, param);
	
	double k3_1 = calc_func_1(x + step / 2.0, y1 + 0.5 * step * k2_1, y2 + 0.5 * step * k2_2, param);
	double k3_2 = calc_func_2(x + step / 2.0, y1 + 0.5 * step * k2_1, y2 + 0.5 * step * k2_2, param);

	double k4_1 = calc_func_1(x + step, y1 + step * k3_1, y2 + step * k3_2, param);
	double k4_2 = calc_func_2(x + step, y1 + step * k3_1, y2 + step * k3_2, param);

	double y1_next = y1 + (step / 6.0) * (k1_1 + 2.0 * k2_1 + 2.0 * k3_1 + k4_1);
	double y2_next = y2 + (step / 6.0) * (k1_2 + 2.0 * k2_2 + 2.0 * k3_2 + k4_2);

	std::vector<double> y_next = { y1_next, y2_next };
	return y_next;
}
