题目描述:

You are given two linked lists representing two non-negative numbers. 
The digits are stored in reverse order and each of their nodes 
contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    	if(l1 == nullptr)
    		return l2;
    	if(l2 == nullptr)
    		return l1;
        
        ListNode * dummy = new ListNode(-1);
        ListNode * last = dummy;
    	ListNode * p1 = l1;
    	ListNode * p2 = l2;
        
        int carry = 0;
    	while(p1!=nullptr && p2!=nullptr)
    	{

    		int sum = p1->val + p2->val + carry;
    		carry = sum/10;
    		sum = sum%10;
    		ListNode * temp = new ListNode(sum);
    		last->next = temp;
    		last = temp;
    		p1 = p1->next;
    		p2 = p2->next;
    	}

    	while(p1!=nullptr)
    	{
    		int sum = p1->val + carry;
    		carry = sum/10;
    		sum = sum%10;
    		ListNode * temp = new ListNode(sum);
    		last->next = temp;
    		last = temp;
    		p1 = p1->next;
    	}


    	while(p2!=nullptr)
    	{
    		int sum = p2->val + carry;
    		carry = sum/10;
    		sum = sum%10;
    		ListNode * temp = new ListNode(sum);
    		last->next = temp;
    		last = temp;
    		p2 = p2->next;
    	}

    	if(carry)
    	{
    		ListNode * temp = new ListNode(carry);
    		last->next = temp;
    		last = temp;

    	}

    	ListNode * ret = dummy->next;
    	dummy->next = nullptr;
    	delete dummy;
    	return ret;
      
    }
};

//更简练的代码风格

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

    	if(l1 == nullptr)
    		return l2;
    	if(l2 == nullptr)
    		return l1;
        
        ListNode * dummy = new ListNode(-1);
        ListNode * last = dummy;
    	ListNode * p1 = l1;
    	ListNode * p2 = l2;
        
        int carry = 0;
    	while(p1!=nullptr || p2!=nullptr || carry>0)
    	{

    		int sum = carry;
    		if(p1!=nullptr)
    		{
    			sum+=p1->val;
    			p1 = p1->next;
    		}

    		if(p2!=nullptr)
    		{
    			sum+=p2->val;
    			p2 = p2->next;
    		}

    		carry = sum/10;
    		sum = sum%10;
    		ListNode * temp = new ListNode(sum);
    		last->next = temp;
    		last = temp;    
    	}
        
    	ListNode * ret = dummy->next;
    	dummy->next = nullptr;
    	delete dummy;
    	return ret;      
    }
};