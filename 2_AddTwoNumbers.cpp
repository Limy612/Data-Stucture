#include <iostream>
#include <vector>
using namespace std;
/*Definition for single-linked list*/
struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){};
};
/* 超出long long则不能用 */
class Solution1 {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		ListNode *p1 = l1, *p2 = l2;
		unsigned long long count = 0, tmp = 0, tmp1 = 0;
        //l1 val
        while (p1 != nullptr)
		{
			count = count * 10 + p1->val;
			p1 = p1->next;
		}
		while (count)
		{
			tmp = tmp * 10 + count % 10;
			count = count / 10;
		}
		count = tmp;
        p1 = l1;
        while (p1 != nullptr && p1->val == 0)
		{
            count *= 10;
			p1 = p1->next;
		}
        //l2 val
        while (p2 != nullptr)
		{
			tmp1 = tmp1 * 10  + p2->val;
			p2 = p2->next;
		}
		tmp = 0;
		while (tmp1)
		{
			tmp = tmp * 10 + tmp1 % 10;
			tmp1 = tmp1 / 10;
		}
        p2 = l2;
        while (p2 != nullptr && p2->val == 0)
		{
            tmp *= 10;
			p2 = p2->next;
		}
		count += tmp;

		ListNode * rp = new ListNode(0);
		ListNode *p = rp;
		while (count)
		{
			
			p->val = count % 10;
			count = count / 10;
			if (count == 0)
				break;
			ListNode * pnext = new ListNode(0);
			p->next = pnext;
			p = p->next;
		}

		return rp;
    }
};

/* 一位一位的计算 */
class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode *rp = new ListNode(0);
		ListNode *p = rp,*p1 = l1,*p2 = l2;
		int cnt = 0;
		while (p1 != nullptr || p2 != nullptr || cnt == 1)
		{
			int val = cnt;
			if (p1 != nullptr)
			{
				val += p1->val;
				p1 = p1->next;
			}
			if (p2 != nullptr)
			{
				val += p2->val;
				p2 = p2->next;
			}
			p->val = val % 10;
			
			if (val > 9) 
				cnt = 1;
			else 
				cnt = 0;
			
			if (p1 == nullptr && p2 == nullptr && cnt == 0)
				break;
			ListNode* pnext = new ListNode(0);
			p->next = pnext;
			p = p->next;
		}

		return rp;
	}
};
int main()
{
	ListNode l1(2), l2(4), l3(8);
	ListNode k1(5), k2(6), k3(4);
	l1.next = &l2;
	l2.next = &l3;
	k1.next = &k2;
	k2.next = &k3;
	
	Solution s;
	ListNode *output = s.addTwoNumbers(&l1, &k1);
	while (output)
	{
		cout << output->val << endl;
		output = output->next;
	}
} 