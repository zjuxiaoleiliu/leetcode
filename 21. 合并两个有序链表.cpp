题目描述:

Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//递归解决方案
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

    	if(l1 == nullptr)
    		return l2;
    	if(l2 == nullptr)
    		return l1;
    	if(l1->val <= l2->val)//这里必须是<=，因为归并排序是稳定排序算法
    	{
    		l1->next = mergeTwoLists(l1->next,l2);
    		return l1;
    	}
    	else
    	{
    		l2->next = mergeTwoLists(l1,l2->next);
    		returnl2;
    	}
        
    }
};

//非递归不使用辅助头结点方案

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

    	if(l1 == nullptr)
    		return l2;
    	if(l2 == nullptr)
    		return l1;
    	
        ListNode *head = nullptr;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *last = nullptr;
        while(p1!=nullptr && p2!=nullptr) 
        {
            if(p1->val <= p2->val) 
            {
                if(head == nullptr)
                {
                    head = p1;
                    last = head;
                } 
                else 
                {
                    last->next = p1;
                    last = p1;
                }

                p1 = p1->next;
            } 
            else 
            {
                if(head == nullptr) 
                {
                    head = p2;
                    last = head;
                } 
                else 
                {
                    last->next = p2;
                    last = p2;
                }

                p2 = p2->next;
            }
        }
         
        if (p1 != nullptr)
            last->next = p1;
        if (p2 != nullptr)
            last->next = p2;
         
        return head;
        
    }
};

//非递归使用辅助头结点方案
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

    	if(l1 == nullptr)
    		return l2;
    	if(l2 == nullptr)
    		return l1;
    	
        ListNode *dummy = new ListNode(-1);
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *last = dummy;
        while(p1!=nullptr && p2!=nullptr) 
        {
            if(p1->val <= p2->val) 
            {
            	last->next = p1;
                last = p1;
                p1 = p1->next;
            } 
            else 
            {
            	last->next = p2;
            	last = p2;
                p2 = p2->next;
            }
        }
         
        if (p1 != nullptr)
            last->next = p1;
        if (p2 != nullptr)
            last->next = p2;

        ListNode *ret = dummy->next;
        dummy->next = nullptr;
        delete dummy;
                
        return ret;
        
    }
};