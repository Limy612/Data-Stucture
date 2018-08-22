#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;
/*
S ="ADOBECODEBANC"
T ="ABC"
Minimum window is"BANC".

1) begin开始指向0， end一直后移，直到begin - end区间包含T中所有字符。
记录窗口长度d
2) 然后begin开始后移移除元素，直到移除的字符是T中的字符则停止，此时T中有一个字符没被
包含在窗口，
3) 继续后移end，直到T中的所有字符被包含在窗口，重新记录最小的窗口d。
4) 如此循环知道end到S中的最后一个字符。
时间复杂度为O(n)
*/
string minWindow(string S, string T) 
{
	string shortestPart;
	if (S.empty() || T.empty())
		return shortestPart;
	
	int begin(0),end(S.size() - 1);
	
	
}
int main()
{
	string S ="ADOBECODEBANC";
	string T ="ABC";
	minWindow(S,T);
}