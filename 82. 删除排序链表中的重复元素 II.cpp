题目描述:

Given a sorted linked list, delete all nodes that have duplicate numbers, 
leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//不使用辅助头结点的解决方案
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {

    	if(head == nullptr)
    		return nullptr;
    	ListNode * ret = nullptr;
    	ListNode * last = nullptr;
    	ListNode * p = head;

    	while(p!=nullptr)
    	{
   
    		if(p->next==nullptr || p->val!=(p->next)->val)
    		{
    			if(last == nullptr)
    				ret = p;
    			last = p;
    			p  = p->next;

    		}
    		else
    		{
    			int val = p->val;
    			ListNode *next = p;
    			while(next!=nullptr && next->val == val)
    			{
    				ListNode *temp = next;
    				next = next->next;
    				temp->next = nullptr;
    				delete temp;
    			}

    			if(last!=nullptr)
    				last->next = next;
    			p = next;

    		}

    	}

    	return ret;
        
    }
};

//上面思路的使用辅助头结点的解决方案
class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) {

    	if(head == nullptr)
    		return nullptr;
    	ListNode *dummy = new ListNode(-1);
    	dummy->next = head;//这里是直接连好了
    	ListNode * last = dummy;
    	ListNode * p = head;
    	while(p!=nullptr)//变量p的含义：当前要试探的结点
    	{  
    		if(p->next==nullptr || p->val!=(p->next)->val)
    		{
    			last = p;
    			p  = p->next;
    		}
    		else
    		{
    			int val = p->val;
    			ListNode *next = p;//next变量的含义：下一轮要试探的结点
    			while(next!=nullptr && next->val == val)
    			{
    				ListNode *temp = next;
    				next = next->next;
    				temp->next = nullptr;
    				delete temp;
    			}

    			last->next = next;
    			p = next;
    		}
    	}       
        ListNode *ret = dummy->next;
        dummy->next = nullptr;
        delete dummy;
    	return ret        ;
    }
};

//递归解决方案

class Solution {
public:
    ListNode *deleteDuplicates(ListNode *head) 
    {
        if(head==nullptr || (head->next)==nullptr)
            return head;
        if (head->val != head->next->val)
        {   //巧妙的利用函数返回值携带的信息进行自动的连接，而不像循环解决方案中的手动连接
            head->next = deleteDuplicates(head->next);
            return head;
        }
        else
        {
            int val = head->val;
            ListNode *next = head;
            while (next!=nullptr && next->val==val)
            {
            	ListNode *temp = next;
    			next = next->next;
    			temp->next = nullptr;
    			delete temp;    
            }

            return deleteDuplicates(next);
        }
    }
};