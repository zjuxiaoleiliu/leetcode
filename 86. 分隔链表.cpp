题目描述:

Given a linked list and a value x, partition it 
such that all nodes less than x come before nodes 
greater than or equal to x.

You should preserve the original relative order 
of the nodes in each of the two partitions.

For example,
Given 1->4->3->2->5->2 and x = 3,
return 1->2->2->4->3->5.


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
    ListNode *partition(ListNode *head, int x) {

    	if(head == nullptr)
    		return head;
    	ListNode dummy1 = ListNode(-1);
    	ListNode dummy2 = ListNode(1);
    	ListNode *last1 = &dummy1;
    	ListNode *last2 = &dummy2;
    	ListNode *p = head;
    	while(p!=nullptr)
    	{
    		ListNode *next = p->next;
    		p->next = nullptr;
    		if(p->val<x)
    		{
    			last1->next = p;
    			last1 = p;
    		}
    		else
    		{
    			last2->next = p;
    			last2 = p;
    		}
    		p = next;
    	}
    	last1->next = dummy2.next;
    	return dummy1.next;       
    }
};
