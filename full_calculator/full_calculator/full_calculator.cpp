#include<iostream>
#include<string>
#include "arraystack.h"

using namespace std;

bool isDigit(char c)
{
	return (c >= '0' && c <= '9');
}

bool isOp(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')');
}

int getPrio(char c)
{
	switch (c)
	{
	case '+': return 1;
	case '-': return 1;
		
	case '*': return 2;
	case '/': return 2;
		
	case '(': return 3;
	case ')': return 3;
		
	default: return -1;

    }
}
int operate(int val1, int val2, char op)
{
	if (op == '+')return (val1 + val2);
	if (op == '-')return (val1 - val2);
	if (op == '*')return (val1 * val2);
	if (op == '/')return val1 / val2;
	

}

int evaluate(string s)
{
	stack<int> vals;
	stack<char> ops;
	int val = 0;
	int pos = 0;
	
	while (pos <= s.length())
	{
		char spot = s[pos];
		if (isDigit(spot))
		{
			val = (val * 10) + (int)(spot - '0');
		}
		else if (isOp(spot))
		{
			if (spot == '(')
			{
				ops.push(spot);
				val = 0;
			}
			else if (vals.isEmpty())
			{
				vals.push(val);
				ops.push(spot);
				val = 0;
			}
			else if (spot == ')')
			{
				vals.push(val);
				while (ops.peek() != '(')
				{
					spot = ops.pop();
					val = vals.pop();
					int prev = vals.pop();
					val = operate(prev, val, spot);
					vals.push(val);
				}
				ops.pop();
				vals.pop(); //fk this took a while

			}
			else
			{
				char prev = ops.peek();
				if (getPrio(spot) > getPrio(prev))
				{
					vals.push(val);
					ops.push(spot);
					val = 0;
				}
				else //finally you get to do the work xd
				{
					int preval = vals.pop();
					int preop = ops.pop();
					preval = operate(preval, val, preop);
					vals.push(preval);
					ops.push(spot);
					val = 0;
				}
			}
		}
		pos++;
	}
	while (!ops.isEmpty())
	{
		int prev = vals.pop();
		char spot = ops.pop();
		val = operate(prev, val, spot);
	}
	return val;
}

int main()
{
	cout << "enter the equation : ";
	string equation;
		cin >> equation;
	cout << endl;
	cout << evaluate(equation) << endl;
}

