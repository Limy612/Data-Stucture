#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int uniquePaths(int m, int n)
{    
	vector<vector<int > > dp(m,vector<int >(n,1));
	for(int i = 1; i < m; i++)
		for(int j = 1; j<n; j++)
		{
			dp[i][j] = dp[i][j-1]+dp[i-1][j];
		}
	return dp[m-1][n-1];
}
int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) 
{
	int m = obstacleGrid.size();
	int n = (*obstacleGrid.begin()).size();
	
	vector<vector<int > > dp(m,vector<int >(n,1));
	for(int i = 0; i < m; i++)
	{	
		for(int j = 0; j < n; j++)
		{
			if (i == 0)
			{
				if (obstacleGrid[0][j] ==1)
				{
					for (int tmp = j; j < n; ++j)
						dp[0][j]  =  0;	
					continue;
				}
			}
			else 
			{
				if (obstacleGrid[i][j] == 1)
					dp[i][j]  =  0;	
				else
					dp[i][j]  =  dp[i][j-1]+dp[i-1][j];
			}			
		}
	}
	return dp[m-1][n-1];
}
int main()
{
	vector<vector<int> > gas{ {0} };
	cout << uniquePathsWithObstacles(gas);
}