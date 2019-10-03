题目描述:

Given a sorted linked list, delete all duplicates such that 
each element appear only once.

For example,
Given 1->1->2, return1->2.
Given 1->1->2->3->3, return1->2->3.

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
    ListNode *deleteDuplicates(ListNode *head) {

    	if(head == nullptr)
    		return nullptr;

    	ListNode *last = head;
    	ListNode * p = head->next;
    	while(p!=nullptr)
    	{
    		if(p->val!=last->val)
    		{
    			last = p;
    			p = p->next;
    		}
    		else
    		{
    			last->next = p->next;
    			ListNode *temp = p;
    			p = p->next;
    			temp->next = nullptr;
    			delete temp;

    		}
    	}

    	return head;



        
    }
};