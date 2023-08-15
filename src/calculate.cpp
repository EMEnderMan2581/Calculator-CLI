#include<stdexcept>

#include"calculate.h"

using namespace std;

double calculate(double op1, char op, double op2)
{
	double result = 0.0;
	switch (op)
	{
	case '+':
		result = op1 + op2;
		break;
	case '-':
		result = op1 - op2;
		break;
	case '*':
		result = op1 * op2;
		break;
	case '/':
		if (op2 == 0)
		{
			throw runtime_error("Error: Divided by zero");
		}
		else
		{
			result = op1 / op2;
		}
		break;
	default:
		throw runtime_error("Error: Unsupported operator");
		break;
	}
	return result;
}