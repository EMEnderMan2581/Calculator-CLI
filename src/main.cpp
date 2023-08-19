#include"calculate.h"

using namespace std;

int main(int argc, char* argv[])
{
	if (argc < 4 && (strcmp(argv[1], "-h") == 1 || strcmp(argv[1], "-h") == -1))
	{
		cout << "Error: Insufficient parameters" << endl;
		cout << "Usage: ./Calculator <Operand1> <Operator> <Operand2>" << endl; //<DecimalPlaces>
		//cout << "Available operators: +, -, x and /" << endl;
		//cout << "Note: If you want to Multiply Operand1 by Operand2, please enter 'c'" << endl;
		return 1;
	}

	else if (argc == 2 && strcmp(argv[1], "-h") == 0)
	{
		cout << "Calculator version 1.1" << endl;
		cout << "Usage: ./Calculator <Operand1> <Operator> <Operand2>" << endl;
		cout << "Available operators: +, -, x and /" << endl;
		//cout << "Note: If you want to Multiply Operand1 by Operand2, please enter 'c'" << endl;
		return 0;
	}

	else
	{
		/*char op1 = argv[2][0];

		switch (op1)
		{
		case '+':
			op1 = '+';
			break;
		case '-':
			op1 = '-';
			break;
		case 'c':
			op1 = '*';
			break;
		case '/':
			op1 = '/';
			break;
		default:
			op1 = '+';
			break;
		}*/

		double value1 = atof(argv[1]);
		//char op = op1;
		char op = argv[2][0];
		double value2 = atof(argv[3]);

		//Test
		//cout << value1 << endl << op << endl << op1 << endl << value2 << endl;
		
		double result;
		try
		{
			result = calculate(value1, op, value2);
			cout << fixed;
			if (floor(result) == result)
			{
				cout << "Result is: " << static_cast<int>(result) << endl;
			}
			else
			{
				//Decimal places
				stringstream ss0;
				ss0 << fixed << showpoint << setprecision(15) << result;
				string output = ss0.str();
				unsigned long long pos = output.find_last_not_of('0');
				if (pos != std::string::npos) {
					output.erase(pos + 1);
				}
				cout <<"Result is: " << output << endl;
			}
		}

		catch (const exception& error)
		{
			cout << "Error: " << error.what() << endl;
			//cout << "Usage: ./Calculator <Operand1> <Operator> <Operand2>" << endl;
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