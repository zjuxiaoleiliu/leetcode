题目描述:

Sort a linked list in O(nlogn) time using constant space complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//对于链表的归并排序，不需要额外的辅助空间(链表通过指针达到逻辑上相邻，而不像数组
//是物理上相邻，所以针对两个有序链表的合并可以只改动指针，原地进行)，
//这一点不像数组，因为我们可以就地
//合并两个有序的链表，这一点对于排序两个有序的数组则需要一个辅助的数组来
//存放结果
/*
快慢指针：
O->O->O,长度为2，从头结点开始，需移动2次方能到达最后一个结点，此时长度为2
O->O->O->O,长度为3，从头结点开始，需移动3次方能到达最后一个结点，此时长度为3
所谓链表的结点，即可以从链表结点的个数角度方面来考虑，也可以从链表的长度角度方面
来考虑问题，因为本问题我们涉及到移动指针(每进行一次移动指针的操作，长度增加1).
所以我们这里从长度角度来理解链表的中间结点，中间结点将链表分为两部分，两部分的
长度之差至多为1，我们这里针对快慢指针，右边长度顶多比左边长度大1
总长度length=2*x+r(r=0,或者r=1)
//节点个数=长度+1，所以，这种分割方式得到的前半部分的节点个数为：x+1
//后半部分的节点个数为：length+1-(x+1)=2*x+r+1-(x+1)=x+r
//这样分割得到的前半部分或者和后半部分的节点个数相等，或者前半部分比后半部分的节点个数多1
所以运用快慢指针，就是需要知道针对快指针，我们能进行的合法操作的次数(即式子中的x
x也即此时慢指针所对应的链表的长度x,此时快指针多对应的链表长度为2*x)
(针对快指针的操作每进行一次，快指针此时所对应链表的长度增加2)
*/
class Solution {
public:
    ListNode *merge(ListNode *l1, ListNode *l2) {  	                                        
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
            if(p1->val <= p2->val)//这里必须是<=,因为归并排序是稳定的排序算法 
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
    ListNode *sortList(ListNode *head)//主函数，此递归函数的设计类似于树的后序遍历
    {
        if(head==nullptr || (head->next)==nullptr)
        	return head;//递归终止条件
        ListNode *fast=head;
        ListNode *slow=head;//此时快慢指针对应的链表长度的状态为长度为0
        //快指针还能不能再走两步？
        while(fast->next && fast->next->next)//循环条件为针对快指针的操作还能不能继续进行？
        {
        	slow = slow->next;
            fast = fast->next->next;
        }//循环结束后慢指针已经到达正确的位置了,
        fast = slow->next;//得出的slow为分割点
        slow->next = nullptr;
        slow = head;
        ListNode *l1 = sortList(slow);
        ListNode *l2 = sortList(fast);
        return merge(l1,l2);
    }
};

