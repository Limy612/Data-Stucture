#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) 
	{	
		int cnt = 0, fomer = 0;
        for (int i = 0; i < s.size(); ++i)
		{
			int cur = 0;
			if (s[i] == 'I') cur = 1;
			else if (s[i] == 'V') cur = 5;
			else if (s[i] == 'X') cur = 10;
			else if (s[i] == 'L') cur = 50;
			else if (s[i] == 'C') cur = 100;
			else if (s[i] == 'D') cur = 500;		
			else  cur = 1000;
			
			if (cur <= fomer) 
				cnt += cur;
			else 
				cnt = cnt - 2*fomer + cur;

			fomer = cur;
		}
		return cnt;
    }
};

int main ()
{
	Solution s;
	string str{"MCMXCIV"};
	int output = s.romanToInt(str);
	cout << output;
}