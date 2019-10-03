题目描述:

Given a linked list, remove the n th node from the end of list and return its head.

For example,

   Given linked list: 1->2->3->4->5, and n = 2.

   After removing the second node from the end, the linked list becomes 1->2->3->5.
Note: 
Given n will always be valid.
Try to do this in one pass.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//辅助头结点(因为有可能要删除的节点是头节点)的运用  快慢两指针的运用
//我们要删除一个链表节点，我们要找到它的前一个节点
class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {

    	if(head == nullptr || n < 1)
    		return nullptr;

    	ListNode* dummy = new ListNode(-1);
    	dummy->next=head;

    	ListNode *fast = dummy;    	
    	for(int i = 0;i<n;i++)
    	{
    		fast = fast->next;
    	}
        ListNode *slow = dummy;
    	while(fast->next!=nullptr)
    	{
    		fast = fast->next;
    		slow = slow->next;

    	}

    	ListNode *temp = slow->next;
    	slow->next=temp->next;
    	delete temp;
    	ListNode *ret = dummy->next;
    	dummy->next=nullptr;
    	delete dummy;
    	return ret;
       
    }
};


