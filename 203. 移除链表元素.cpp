删除链表中等于给定值 val 的所有节点。

示例:

输入: 1->2->6->3->4->5->6, val = 6
输出: 1->2->3->4->5


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
    ListNode* removeElements(ListNode* head, int val) {

    	if(head == nullptr)
    		return nullptr;
    	ListNode *dummy = new ListNode(-1);
    	ListNode *last = dummy;
    	ListNode *cur = head;
    	while(cur!=nullptr)
    	{
    		ListNode *next = cur->next;
    		cur->next = nullptr;
    		if(cur->val == val)
    			delete cur;
    		else
    		{
                last->next = cur;
                last =cur;
            }
    		cur = next;
    	}
    	ListNode *ret = dummy->next;
    	dummy->next = nullptr;
    	delete dummy;
    	return ret;       
    }
};