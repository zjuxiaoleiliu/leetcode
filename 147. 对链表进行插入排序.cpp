题目描述:

Sort a linked list using insertion sort.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *insertionSortList(ListNode *head) {

    	ListNode dummy = ListNode(INT_MIN);//这个结点在这里相当于哨兵
    	ListNode *p = head;
    	while(p)
    	{
    		ListNode *next = p->next;
    		p->next = nullptr;
    		ListNode *pre = &dummy;
    		//插入排序，一侧已经没问题，只需要考虑如果放在这里另一侧是否会不合适
  //注意这里是链表(链表只能从前往后进行遍历)，和一般的插入排序不同，这里是从前往后进行试探
    		while(pre->next && p->val>pre->next->val)
    			pre = pre->next;
    		p->next = pre->next;
    		pre->next = p;
    		p = next;
    	}
    	return dummy.next;       
    }
};

