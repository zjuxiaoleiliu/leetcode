题目描述:

A linked list is given such that 
each node contains an additional 
random pointer which could point to 
any node in the list or nullptr.

Return a deep copy of the list.
/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {

    	if(head == nullptr)
    		return head;
    	RandomListNode *p = head;
    	while(p!=nullptr)
    	{
    		RandomListNode *next = p->next;
    		RandomListNode *temp = new RandomListNode(p->label);
    		p->next = temp;
    		temp->next = next;
    		p = next;
    	}
    	p = head;
    	while(p!=nullptr)
    	{
    		RandomListNode *next = p->next->next;
    		if(p->random!=nullptr)
    			p->next->random = p->random->next;
    		p = next;
    	}
    	RandomListNode *newHead = head->next;
    	p = head->next;
    	RandomListNode *last = head;
    	//根据本题的特点，复制的结点在原结点的前面，所以选择
    	//复制的结点为当前循环的遍历元素p
    	//循环的结束条件为：当原链表没有元素时，它自然不会再复制结点
    	//而原链表新的结点在当前复制结点p之后,即p->next处
    	while(p->next!=nullptr)//当原链表还有新结点时
    	{
    		RandomListNode *next = p->next->next;//当原链表还有新结点时
    		last->next = p->next;//它一定能产生新的复制结点，所以这里的next变量非空
    		p->next = next;
    		p = next;
    	}
    	last->next = p->next;
    	return newHead;       
    }
};