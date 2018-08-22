#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
/*
	从start出发， 如果油量足够， 可以一直向后走 end++；  油量不够的时候，
	start向后退  最终 start == end的时候，如果有解一定是当前 start所在位置
*/
int canCompleteCircuit(vector<int> &gas, vector<int> &cost) 
{
	int index = -1;
	int gasRemain = 0,len = 0;
	int start = 0,end = 0;
	
	do
	{
		gasRemain = gasRemain + gas[end] - cost[end];
		++end; ++len;
		while (gasRemain < 0)
		{
			if (--start < 0) start = gas.size() - 1;
			if ((start - end) < 0) break;			//回退到了end
			gasRemain = gasRemain + gas[start] - cost[start];
			++len;
		}

	}while(len <= gas.size());
		
	//cout << gasRemain;
	if (gasRemain >= 0)
		index = start;
	return index;
}

int main()
{
	vector<int> gas{ 1,2,3,4,5 }, cost{ 3,4,5,1,2 };
	cout << canCompleteCircuit(gas, cost);
}