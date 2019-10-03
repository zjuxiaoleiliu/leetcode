题目描述:

Reverse a linked list from position m to n. 
Do it in-place and in one-pass.
For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL.

Note: 
Given m, n satisfy the following condition:
1 ≤ m ≤ n ≤ length of list.

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
    ListNode *reverseBetween(ListNode *head, int m, int n) {
                           //短路原则
    	if(head==nullptr || m>=n || n<1)
    		return head;
    	ListNode dummy = ListNode(-1);
    	dummy.next = head;
    	ListNode *pre = nullptr;
    	ListNode *p = &dummy;
    	int cnt = 0;//由于这里是从左往右的第几个节点，所以直接数出来就可以了
        //每遇到一个非空节点，更新一下计数值
        //按照前进步数的方法在m=1时不用走就到达了，会出现错误
    	while(p!=nullptr)
    	{   
            cnt++;
            if(cnt == m)
               pre = p;
            if(cnt == n+1)
               break;   
    		p = p->next;
    	} 
    	if(p==nullptr)
    		return head;
    	ListNode *next = p->next;
    	p->next = nullptr;
    	ListNode *cur = pre->next;
    	pre->next = nullptr;
    	pre->next = reverseList(cur);
    	cur->next = next;
    	return dummy.next;       
    }

    ListNode *reverseList(ListNode *head)
    {
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

