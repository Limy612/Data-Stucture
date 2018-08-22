#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

struct TreeNode
{
   int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> postorderTraversal(TreeNode *root) 
{
	
}
int main()
{
	TreeNode l1(4),l2(2),l3(1),l4(3);
	l1.left = &l2;
	l1.right = &l3;
	//l3.next = &l4;
	vector<int> vec = postorderTraversal(&l1);
}