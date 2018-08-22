#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

/*
  考点：
  1. 快慢指针；2. 归并排序。
  此题经典，需要消化吸收。
  复杂度分析:
             T(n)            拆分 n/2, 归并 n/2 ，一共是n/2 + n/2 = n
            /    \           以下依此类推：
          T(n/2) T(n/2)      一共是 n/2*2 = n
         /    \  /     \
        T(n/4) ...........   一共是 n/4*4 = n
 
       一共有logn层，故复杂度是 O(nlogn)
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *merge(ListNode *left, ListNode *right)
{
	ListNode head(0);
	ListNode *p = &head;
	while (left && right)
	{
		if (left->val < right->val)
		{
			p->next = left;
			left = left->next;
		}
		else
		{
			p->next = right;
			right = right->next;
		}
		p = p->next;
	}
	if (left) p->next = left;
	if (right) p->next = right;
	
	return head.next;
}

ListNode *sortList(ListNode *head) 
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode *p = head,*q = head->next;
	while (q && q->next)
	{
		p = p->next;	   //慢指针
		q = q->next->next; //快指针
	}
	
	ListNode * left = sortList(p->next);
	p->next = nullptr;
	ListNode * right = sortList(head);
	
	return merge(left,right);
}

int main()
{
	ListNode l1(4),l2(3),l3(2),l4(1);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	ListNode *head = sortList(&l1);
}