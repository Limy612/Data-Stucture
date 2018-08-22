#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *insertionSortList(ListNode *head) 
{
	if (head == nullptr || head->next == nullptr)
		return head;
	
	ListNode *p = head->next;
	head->next = nullptr;
	while (p)
	{	
		//cout << p->val << ' ';
		ListNode *tmp = p, *pinsert = head, *pfomer = nullptr;
		p = p->next;
	
		
		if (tmp->val <= head->val)
		{
			tmp->next = head;
			head = tmp;
			continue;
		}
		while (tmp->val > pinsert->val && pinsert)
		{
			pfomer = pinsert;
			pinsert = pinsert->next;
		}
		if (pfomer->next == nullptr)
		{
			pfomer->next = tmp;
			tmp->next = nullptr;
		}
		else 
		{
			pfomer->next = tmp;
			tmp->next = pinsert;
		}
	}
	return head;
}

int main()
{
	ListNode l1(4),l2(2),l3(1),l4(3);
	l1.next = &l2;
	l2.next = &l3;
	l3.next = &l4;
	ListNode *head = insertionSortList(&l1);
	cout<<'/' << head->val;
}