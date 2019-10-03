题目描述:

给定一个单链表 L：L0→L1→…→Ln-1→Ln ，
将其重新排列后变为： L0→Ln→L1→Ln-1→L2→Ln-2→…

你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。

示例 1:

给定链表 1->2->3->4, 重新排列为 1->4->2->3.
示例 2:

给定链表 1->2->3->4->5, 重新排列为 1->5->2->4->3.



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//方法1：递归解法
class Solution {
public:
    void reorderList(ListNode *head) {

    	if(head==nullptr || (head->next)==nullptr || (head->next->next)==nullptr)
    		return;
    	ListNode *pre = head;
    	while((pre->next->next)!=nullptr)
    		pre=pre->next;
    	ListNode *temp = pre->next;
    	pre->next=nullptr;
    	ListNode *next = head->next;
    	head->next=temp;
    	temp->next=next;
    	reorderList(next);
       
    }
};

//方法2：利用栈的解决方案

class Solution {
public:
    void reorderList(ListNode *head) {

    	if(head==nullptr || (head->next)==nullptr || (head->next->next)==nullptr)
    		return;
        stack<ListNode *> s;
        ListNode *cur=head;
    	while(cur!=nullptr)
    	{
    		s.push(cur);
    		cur = cur->next;
    	}
    	cur=head;
    	//每次操作减少2个节点，
    	    //3-->1            //4-->2
    	while(cur!=s.top() && (cur->next)!=s.top())//当剩下1个节点或者两个节点时就不需要操作了
    	{                                          //否则会出错(自己连自己)
    		ListNode *temp = s.top();
    		s.pop();
    		(s.top())->next=nullptr;
    		ListNode *next = cur->next;
    		cur->next=temp;
    		temp->next=next;
    		cur=next;
    	}
        
    }
};

//方法3:利用快慢指针，找到中间结点(以长度为准)，前半部分的
//每一个结点后面都需要连接后半部分对应的从末尾开始的结点
//为了操作的方便，我们需要反转后半部分的结点
//
class Solution {
public:
    void reorderList(ListNode *head) {

    	if(head==nullptr || (head->next)==nullptr || (head->next->next)==nullptr)
    		return;
    	//寻找中间结点
    	ListNode *fast=head;
        ListNode *slow=head;
        while(fast->next && fast->next->next)
        {
        	slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;       
        ListNode *second = reverseList(fast);
        //进行连接操作
        ListNode *p1 = head;
        ListNode *p2 = second;
        while(p2!=nullptr)//后半部分的结点数量小于等于前半部分的结点数量(相差0或1)
        {
        	ListNode *next1 = p1->next;
        	ListNode *next2 = p2->next;
        	p1->next = p2;
        	p2->next = next1;
        	p1 = next1;
        	p2 = next2;
        }      
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

