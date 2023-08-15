#include<iostream>
#include<cstring>
#include<iomanip>
#include<sstream>
#include<math.h>

#include"calculate.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 4)
	{
		cout << "Error: Insufficient parameters" << endl;
		cout << "Usage: ./Calculator <Operand1> <Operator> <Operand2>" << endl; //<DecimalPlaces>
		return 1;
	}

	else if (strcmp(argv[1],"-h") == 0)
	{
		cout << "Calculator v1.0" << endl;
		cout << "Usage: ./Calculator <Operand1> <Operator> <Operand2>" << endl;
		return 0;
	}

	else
	{
		double op1 = atof(argv[1]);
		char op = argv[2][0];
		double op2 = atof(argv[3]);
		
		double result;
		try
		{
			result = calculate(op1, op, op2);
			cout << fixed;
			if (floor(result) == result)
			{
				cout << "Result is: " << static_cast<int>(result) << endl;
			}
			else
			{
				
				stringstream ss;
				ss << fixed << showpoint << setprecision(15) << result;
				string output = ss.str();
				unsigned long long pos = output.find_last_not_of('0');
				if (pos != std::string::npos) {
					output.erase(pos + 1);
				}
				cout <<"Result is: " << output << endl;
			}
		}

		catch (const exception& e)
		{
			cout << "Error: " << e.what() << endl;
		}
		
	}
	return 0;
}

//32 unsigned int decimalPlaces = atoi(argv[4]);
//44 string resultpl = to_string(result);
//45 unsigned long long decimalPos = resultpl.find('.');
//46 unsigned long long decimalPlaces = (decimalPos != string::npos) ? resultpl.length() - decimalPos - 1 : 0;
//47 decimalPlaces = min(decimalPlaces, 15ULL);
//48 resultpl.erase(decimalPos + decimalPlaces + 1);
//49 cout << setprecision(decimalPlaces);
//50 cout << "Result is: " << resultpl << endl;
//51 cout << "Result is: " << round(result * pow(10, decimalPlaces)) / pow(10, decimalPlaces) << endl;