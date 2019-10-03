题目描述:

Given a linked list, swap every two adjacent nodes and return its head.

For example,
Given1->2->3->4, you should return the list as 2->1->4->3.

Your algorithm should use only constant space. 
You may not modify the values in the list, only nodes itself can be changed.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//解法1：递归方法
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {

    	if(head==nullptr || head->next==nullptr)
    		return head;
    	ListNode *next = swapPairs(head->next->next);
    	ListNode *newHead = head->next;
    	newHead->next = head;
    	head->next = next;
    	return newHead;        
    }
};

//解法2：直接方法
class Solution {
public:
    ListNode *swapPairs(ListNode *head) {

    	if(head==nullptr || head->next==nullptr)
    		return head;

    	ListNode dummy = ListNode(-1);
    	ListNode *last = &dummy;
    	ListNode *cur = head;
    	while(cur!=nullptr && cur->next!=nullptr)
    	{
    		ListNode *next = cur->next->next;
    		last->next = cur->next;
    		last->next->next = cur;
    		last->next->next->next = nullptr;
    		last = last->next->next;
    		cur = next;
    	}
    	if(cur!=nullptr)
    		last->next = cur;
    	return dummy.next;       
    }
};
