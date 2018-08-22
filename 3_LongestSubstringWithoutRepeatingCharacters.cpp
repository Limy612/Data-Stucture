#include <iostream>
#include <string>
using namespace std;

class Solution1 {
public:
    int lengthOfLongestSubstring(string s) 
	{
		int max = 0;

		for (int i = 0; i < s.size(); ++i)
		{
			int len = 1;
			string noRepeats{s[i]};
			for (int j = i + 1; j < s.size(); ++j)
			{
				int k = 0;
				for ( ; s[j] != noRepeats[k] && k < noRepeats.size(); ++k) 

				if (k == noRepeats.size() && s[j] != noRepeats[k - 1])
				{					
					++len;
					noRepeats += s[j];
				}
                else 
                    break;
			}
			
			max = len > max ? len : max;
		}
        return max;
    }
};
class Solution {
public:
    int lengthOfLongestSubstring(string s) 
	{
		int max = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			int j = i + 1;
			for (; j < s.size(); ++j)
			{
				int k = i;
				while (s[j] != s[k]) ++k;
				if (k < j) 
				{
					break;
				}
			}
			max = (j - i) > max ? j - i : max;
		}
        return max;
    }
};

int main()
{
	string str{"  "};
	Solution s;
	int output = s.lengthOfLongestSubstring(str);
	cout << output;
}