#include <iostream>
using namespace std;

typedef int TElemType; 

//定义二叉树的二叉链表的结点结构
typedef struct BiTNode
{
	TElemType data;
	struct BiTNode *lchild,*rchild; //左右孩子的指针
}BiTNode,*BiTree;                   //BiTNode是一个结构体类型

//构造二叉链表表示的二叉树T
void CreateBiTree(BiTree *T)
{
	TElemType data;
	cin >> data;
	if (data == 0)
		*T = nullptr;
	else
	{
 		*T = (BiTree)malloc(sizeof(BiTNode));
		if(!*T)
			exit(OVERFLOW);
		(*T)->data = data;

		CreateBiTree(&(*T)->lchild);
		CreateBiTree(&(*T)->rchild);
	}
	
}

//递归查找二叉排序树T中是否存在key
bool SearchBST()
{
	return true;
}

int main()
{
	BiTree *T;	
	CreateBiTree(T);
	
	bool output;
	output = SearchBST();
	cout << output;
	
	return 0;
}