#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

//Definition for a point.
struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
 
int maxPoints(vector<Point> &points) 
{
	int size = points.size();
	if (size == 0 || size== 1)
		return size;
	int ret = 0;
	for (int i = 0; i < size; ++i)
	{
		int curmax = 0;
		map<double,int> mp;
		int dpoints = 0; //chongfu
		int xcount = 0;  //xchuizhi
		for (int j = i + 1; j < size; ++j)
		{
			double x1 = points[i].x - points[j].x;
			double y1 = points[i].y - points[j].y;
			if (x1 == 0 && y1 == 0)		//chongfu
				++dpoints;	
			else if (x1 == 0)     		//垂直
			{
				if (xcount == 0)
					xcount = 2;
				else
					++xcount;
				curmax = max(xcount, curmax);
			}
			else						//斜率相等且过同一点则共线
			{
				double k = y1 / x1;
				if (mp[k] == 0)   //没有关键字k，使用[]取值会插入k
					mp[k] = 2;
				else
					++mp[k];
				curmax = max(mp[k], curmax);
			}
		}
		ret = max(ret, curmax + dpoints);
	}
	return ret;
}
int main()
{
	Point p1(1,2),p2(1,3),p3(1,3);
	vector<Point> points {p1,p2,p3};
	cout << maxPoints(points);
}