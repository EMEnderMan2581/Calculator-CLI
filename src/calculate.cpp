#include"calculate.h"

using namespace std;

double calculate(double operand1, char op, double operand2)
{
	double result = 0.0;
	switch (op)
	{
	case '+':
		result = operand1 + operand2;
		break;
	case '-':
		result = operand1 - operand2;
		break;
	case 'x':
		result = operand1 * operand2;
		break;
	case '/':
		if (operand2 == 0)
		{
			throw runtime_error("Divided by zero");
		}
		else
		{
			result = operand1 / operand2;
		}
		break;
	default:
		throw runtime_error("Unsupported operator");
		break;
	}
	return result;
}