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

int Fibonacci_Search(int *a, int n, int key)
{
	int low,mid,high,i,k;
	int F[10] = {0,1,1,2,3,5,8,13,21,34};
	low = 0;
	high = n - 1;
	k = 0;
		
	while(n > F[k])   //计算n位于斐波那契数列中的位置
	{
		k++;
	}
	for(i=n; i<F[k]-1; i++) //补全斐波那契数列
	{
		a[i] = a[n];
	}
	
		while(low <= high)
	{
		//cout << k << endl;
		mid = low + F[k-1] - 1;//插值
		cout << mid << endl;
		if(a[mid] < key)
		{
			low = mid + 1;
			k = k - 2;
		}
		else if(a[mid] > key)
		{
			high = mid - 1;
			k = k - 1;
		}
		else 
		{
			if(mid <= n)
				return mid;//return a[mid]
			else
				return n;
		}
	}

	return 0;
}

int main()
{
	int a[20] = {0,1,16,24,35,47,59,62,73,88,99};
	int n = 11, key = 73, output;
	//output = BinarySearch(a,n,key);
	output = Fibonacci_Search(a,n,key);
	
	cout << a[output];
	
	return 0;
}
