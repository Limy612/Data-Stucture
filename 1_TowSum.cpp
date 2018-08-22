#include <iostream>
#include <vector>
#include <map>

using namespace std;
/*
Brute Force:Time complexity:O(n^2)
			Space complexity:O(1)
*/
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
        for (int i = 0; i < nums.size(); ++i)
        {
            for (int j = i + 1; j < nums.size(); ++j)
            {
                if ((nums[i] + nums[j]) == target)
                {
                    output.push_back(i);
                    output.push_back(j);
                }
            }
        }
        return output;
    }
};
/*
Two-pass Hash Table:Time complexity:O(n)
			        Space complexity:O(n)
*/
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
		map<int, int> theMap;
        for (int i = 0; i < nums.size(); ++i)
        {
			// 列表形式插入 
			//theMap.insert({nums[i], i});
			
			//插入单个值，pair是一种数据类型
			theMap.insert(pair<int, int> (nums[i], i));
        }

		for (int i = 0; i < nums.size(); ++i)
		{
			int complement = target - nums[i];
	
			if (theMap.find(complement) != theMap.end())
			{
				output.push_back(i);
				output.push_back(theMap[complement]);
				return output;
			}
		}
        
    }
};
class Solution2 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> output;
		map<int, int> theMap;

		for (int i = 0; i < nums.size(); ++i)
		{
			int complement = target - nums[i];
	
			if (theMap.find(complement) != theMap.end() && theMap.find(complement)->second != i)
			{
				if (i < theMap[complement])
				{
					output.push_back(i);
					output.push_back(theMap[complement]);
				}
				else
				{
					output.push_back(theMap[complement]);
					output.push_back(i);
				}
				return output;
			}
			theMap.insert(pair<int,int> (nums[i], i));
		}
        
    }
};

int main()
{
	vector<int> num{2, 7, 11, 15}, output;
	Solution2 s;
	output = s.twoSum(num, 9);
	for (auto &i : output) cout << i;
}