#include <iostream>
#include <vector>
#include <map>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) 
	{
		vector<int> site;
        int left = 0;
		int right = numbers.size() - 1;
		
		while (left < right)
		{
			int sum = numbers[left] + numbers[right];
			if (sum == target)
			{
				site.push_back(left);
				site.push_back(right);
				break;
			}
			else if(sum > target)
				--right;
			else
				++left;	
		}
		return site;
    }
};

int main()
{
	vector<int> num{2, 7, 11, 15}, output;
	Solution s;
	output = s.twoSum(num, 9);
	for (auto &i : output) cout << i;
}