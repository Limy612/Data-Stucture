#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) 
	{
		if (x < 0 || (x % 10 == 0 && x != 0))
			return false;
		
		int rev = 0;
		while (x > rev)
		{
			rev = rev * 10 + x % 10;
			x /= 10;
		}
		cout << rev << endl;
		return x == rev || x == rev / 10; 
    }
};

int main ()
{
	Solution s;
	bool output = s.isPalindrome(12221);
	cout << output;
}