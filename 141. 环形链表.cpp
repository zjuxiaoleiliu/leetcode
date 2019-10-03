题目描述:
Given a linked list, determine if it has a cycle in it.
Follow up:
Can you solve it without using extra space?

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
如果有环的话，在某一时刻fast和slow都在环上。
由于slow每次向前1步，fast每次向前两步，用相对运动的观点来看，
把slow看作静止，那么fast每次相对slow向前1步，
二者在顺时针方向上的距离每经过一个时刻就缩小1，直到变为0，
也即二者恰好相遇。
*/

class Solution {
public:
    bool hasCycle(ListNode *head) {

    	if(head==nullptr || head->next==nullptr)
    		return false;
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast->next && fast->next->next)
        {
        	fast = fast->next->next;
            slow = slow->next;            
            if(slow==fast)
                return true;
        }
        return false;        
    }
};