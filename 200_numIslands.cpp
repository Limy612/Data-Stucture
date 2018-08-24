#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility> //pair

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) 
    {
		int cnt = 0;
        for (int i = 0; i < grid.size(); ++i)
		{
			for (int j = 0; j < grid[i].size(); ++j)
				if (grid[i][j] == '1')
				{
					++cnt;
					//dfs(grid, i, j);
					bfs(grid, i, j);
				}
		}
		return cnt;
    }
	//dfs until all '1' connect to [i][j] change to '0'
	void dfs(vector<vector<char>>& grid, int i, int j)
	{
		if (i < 0 || j < 0 || i >= grid.size() || j >= grid[i].size() || grid[i][j] == '0')
			return;
		grid[i][j] = '0';
		dfs(grid, i+1, j);
		dfs(grid, i-1, j);
		dfs(grid, i, j+1);
		dfs(grid, i, j-1);
	}
	//bfs
	void bfs(vector<vector<char>>& grid, int i, int j)
	{
		int dirs[4][4] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
		pair<int, int> init(i,j);
		queue<pair<int, int>> iqueue;
		
		grid[i][j] = '0';
		iqueue.push(init);
		while (!iqueue.empty())
		{
			pair<int, int> cur = iqueue.front();
			iqueue.pop();
			for (auto arr : dirs)
			{
				int nexti = arr[0] + cur.first;
				int nextj = arr[1] + cur.second;
				
				if (nexti >= 0 && nextj >= 0 && nexti < grid.size() && nextj < grid[i].size() && grid[nexti][nextj] == '1')
				{
					iqueue.push(make_pair(nexti, nextj));
					grid[nexti][nextj] = '0';
				}
			}
		}
	}

};

int main ()
{
	Solution s;
	vector<vector<char>> grid{{'1','1','1','1','0'},
							  {'1','1','0','1','0'}, 
							  {'1','1','0','0','0'}, 
							  {'0','0','0','0','0'}};
	vector<vector<char>> grid1{
								{'1','0','1'},
							    {'0','1','0'}, 
							    {'1','0','1'}, 
							  };
	int output = s.numIslands(grid);
	cout << output;
}