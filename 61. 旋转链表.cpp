题目描述:

Given a list, rotate the list to the right by k places, 
where k is non-negative.

For example:
Given 1->2->3->4->5->NULL and k =2,
return 4->5->1->2->3->NULL.

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
    ListNode *rotateRight(ListNode *head, int k) {

    	if(head==nullptr || k==0)
    		return head;
        ListNode *p = head;
        int len = 0;
        while(p!=nullptr)
        {
        	len++;
            p = p->next;
        }
        k = k%len;
        if(k == 0)//头节点情况，不用旋转 
        	return head;
        ListNode *fast = head;
        ListNode *slow = head;    //快慢指针
        for(int i = 0; i < k; i++)//fast指针先走k步 
        {                //以便找到要找的结点的前一个结点
        	fast = fast->next;
        }
        while(fast->next != nullptr)
        {
        	fast = fast->next;
            slow = slow->next;
        }
        ListNode *newHead = slow->next;
        slow->next = nullptr;   //变成最后一个
        fast->next = head;   //连上head
        return newHead;       
    }
};