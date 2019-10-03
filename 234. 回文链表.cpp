请判断一个链表是否为回文链表。

示例 1:

输入: 1->2
输出: false
示例 2:

输入: 1->2->2->1
输出: true
进阶：
你能否用 O(n) 时间复杂度和 O(1) 空间复杂度解决此题？

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
    bool isPalindrome(ListNode* head) {
    	if(head == nullptr || head->next == nullptr)
    		return true;
    	ListNode *fast=head;
        ListNode *slow=head;//此时快慢指针对应的链表长度的状态为长度为0
        while(fast->next && fast->next->next)//循环条件为针对快指针的操作还能不能继续进行？
        {
        	slow = slow->next;
            fast = fast->next->next;
        }//循环结束后慢指针已经到达正确的位置了,
        fast = slow->next;
        slow->next = nullptr;
        slow = head;
        fast = reverseList(fast);
        while(fast!=nullptr)
        {
        	if(fast->val != slow->val)
        		return false;
        	fast = fast->next;
        	slow = slow->next;

        }
        return true;
       
    }
    ListNode* reverseList(ListNode* head) {

    	if(head==nullptr || head->next==nullptr)
    		return head;
    	ListNode *last = nullptr;
    	ListNode *cur = head;
    	while(cur!=nullptr)
    	{
    		ListNode * temp = cur->next;
    		cur->next = last;
    		last = cur;
    		cur = temp;
    	}
    	return last;
        
    }
};