#include <iostream>
#include <vector>
#include <string>
#include <stack>
//#include <algorithm>
using namespace std;

//evaluate-reverse-polish-notation逆波兰表达式，很明显，用栈求解
int evalRPN(vector<string> &tokens) 
{
	if (tokens.empty())
		return 0;
	
	stack<int> express;
	for (int i = 0; i < tokens.size(); ++ i)
	{
		int tmp1,tmp2,tmp3;
		if (tokens[i] == "+"||tokens[i] == "-" ||
			tokens[i] == "*" || tokens[i] == "/")
			{
				if (express.size() < 2)
					return 0;
				
				tmp1 = express.top();express.pop();
				tmp2 = express.top();express.pop();
				if (tokens[i] == "+")
					tmp3 = tmp2 + tmp1;
				else if(tokens[i] == "-")
					tmp3 = tmp2 - tmp1;
				else if(tokens[i] == "*")
					tmp3 = tmp2 * tmp1;
				else
					tmp3 = tmp2 / tmp1;
				express.push(tmp3);
			}
		else
		{
			express.push(stoi(tokens[i]));//string to int
		}
	}	
	return express.top();
}
int main()
{
	vector<string> vec{"2", "1", "+", "3", "*"};
	cout << evalRPN(vec);
}