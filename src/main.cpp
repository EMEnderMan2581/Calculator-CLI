#include"calculate.h"

using namespace std;

int main(int argc, char* argv[])
{
	//cout << sizeof(long double) << endl;
	if (argc == 2 && strcmp(argv[1], "-h") == 0 && !(argc > 2))
	{
		cout << "Calculator version 1.2" << endl;
		cout << "Usage: ./Calculator <Operand1> <Operator> <Operand2>" << endl;
		cout << "Available operators: +, -, x and /" << endl;
		return 0;
	}

	else if (argc == 4 && !(strcmp(argv[1], "-h") == 0))
	{
		long double value1 = stold(argv[1]);
		char op = argv[2][0];
		long double value2 = stold(argv[3]);

		//Test
		//cout << value1 << endl << op << endl << op1 << endl << value2 << endl;
		
		long double result;
		try
		{
			result = calculate(value1, op, value2);
			cout << fixed;
			//Decimal places
			stringstream ss0;
			ss0 << fixed << showpoint << setprecision(15) << result;
			string output = ss0.str();
			unsigned long long pos = output.find_last_not_of('0');
			if (pos != std::string::npos)
			{
				unsigned long long dotPos = output.find(".");
				if (dotPos != std::string::npos)
				{
					if (pos == dotPos)
					{
						output.erase(dotPos);
					}
					else
					{
						output.erase(pos + 1);
					}
				}
			}
			else
			{
				output.erase();
			}
				cout <<"Result is: " << output << endl;
		}

		catch (const exception& error)
		{
			cout << "Error: " << error.what() << endl;
		}
		
	}

	else
	{
		cout << "Error: Insufficient or excessive parameters" << endl;
		cout << "Usage: ./Calculator <Operand1> <Operator> <Operand2>" << endl;
		return 1;
	}
	return 0;
}