#include <iostream>
using namespace std;

//binary search
int BinarySearch(int *a, int n, int key)
{
	int low,mid,high;
	low = 0;
	high = n-1;
	while(low <= high)
	{
		//mid = (low + high) / 2;//二分
		mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);//插值
		cout << mid << endl;
		if(a[mid] < key)
			low = mid + 1;
		else if(a[mid] > key)
			high = mid - 1;
		else 
			return mid;//return a[mid]
	}
	
	return 0;
}

int FibonacciSearch(int *a, int n, int key)
{
	return 0;
}

int main()
{
	int a[20] = {0,1,16,24,35,47,59,62,73,88,99};
	int n = 11, key = 1, output;
	//output = BinarySearch(a,n,key);
	output = FibonacciSearch(int *a, int n, int key);
	
	cout << output;
	
	return 0;
}
