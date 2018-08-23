#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
	{	//find Kth Sorted Arrays,k = half(m + n)
        int m = nums1.size();
		int n = nums2.size();
		vector<int> &A = nums1, &B = nums2;
		if (m > n)			// to ensure m <= n
		{
			int tmp = m;m = n;n = tmp;
			vector<int> tmp1 = A; A = nums2; B = tmp1;
		}
		
		int iMin = 0, iMax = m, halfLen = (m + n +1) / 2;
		while (iMin <= iMax)
		{
			int i = (iMin + iMax) / 2;
			int j = halfLen - i;
			cout << i << j;
			if (i < iMax && A[i] < B[j-1])
			{
				iMin = i + 1;	//i is too small
			}
			else if (i > iMin && A[i-1] > B[j])
			{
				iMax = i - 1;	//i is too big
			}
			else		// i is perfect and i == iMax or iMin
			{
				int maxLeft = 0;
				if (i == 0)	maxLeft = B[j-1];
				else if (j == 0) maxLeft= A[i-1];
				else maxLeft = max(A[i-1], B[j-1]);
				if ((m + n) % 2 == 1)
					return maxLeft;
				
				int minRight = 0;
				if (i == m) minRight = B[j];
				else if (j == n) minRight = A[i];
				else minRight = min(A[i], B[j]);
				
				return (maxLeft + minRight) / 2.0;
			}
		}
		return 0.0;
    }
};

int main()
{
	vector<int> nums1{4,5}, nums2{1,2,3};
	Solution s;
	double output = s.findMedianSortedArrays(nums1, nums2);
	cout << output;
}