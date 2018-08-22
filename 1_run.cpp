#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

//minimum-depth-of-binary-tree
int run(TreeNode *root) 
{
 	if (root == nullptr)
		return 0;
	
	int left = run(root->left);
	int right = run(root->right);
	
	if (left == 0 || right == 0)
		return 1 + left + right;
	return 1 + min(left, right); 	
}
int main()
{
	TreeNode t1(10),t2(5),t3(12),t4(4),t5(7);
	t1.left = &t2;
	t1.right ;
	t2.left = &t4;
	t2.right = &t5;	
	
	cout << run(&t1);
}