题目描述:
Given a linked list, return the node 
where the cycle begins. If there is no cycle, return null.
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
思路：
先求出环中的节点个数n，然后先让快指针先走n步。然后快慢指针一起走。
*/
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head; 
        //这个循环的主要目的是为了判断是否存在环
        while(fast->next && fast->next->next)//不是环的话，会遇到nullptr结点 
        { 
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)//是环的话，快慢指针会相遇
            	break;
        }
        //好的编程习惯：当循环中有好几处能使循环中断的情况，循环中断后，
        //应该首先判断是那种情况引起的循环中断
        if(fast->next==nullptr || fast->next->next==nullptr)
            return nullptr;
        fast = fast->next; 
        int cnt = 1;//cnt为环的节点个数，也即从环中一个结点出发又回到原地需要移动的次数
        while(fast != slow) 
        {
            fast = fast->next;
            ++cnt;//每移动一次cnt的状态更新一次
        }
        fast = head;
        slow = head; 
        for(int i = 0; i < cnt; ++i)
        	fast = fast->next; 
        while(slow != fast) 
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};



/*
方法2：
如下图所示，X,Y,Z分别为链表起始位置，环开始位置和两指针相遇位置，
则根据快指针速度为慢指针速度的两倍，可以得出：
2*(a + b) = a + b + n * (b + c)；即
a=(n - 1) * b + n * c = (n - 1)(b + c) +c;
注意到b+c恰好为环的长度，故可以推出，如将此时两指针分别放在
起始位置和相遇位置，并以相同速度前进，当一个指针走完距离a时，
另一个指针恰好走出 绕环n-1圈加上c的距离。
故两指针会在环开始位置相遇。

X    a        Y
--------------ooooooo o
             o         o  b
             o          o 
             o  c         0
             o   o   o  o o Z
*/                    

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {

        if(head==nullptr || head->next==nullptr)
            return nullptr;
        ListNode *fast = head;
        ListNode *slow = head; 
        //这个循环条件只是为了保证循环的进行，如果一个链表中前进能
        //遇到nullptr结点，则一定不是环,用fast->next->next!=nullptr只是
        //为了如果不是环的话及早发现，没有什么
        //换成while(fast && fast->next)也可以，不过这样的话，不是环的话
        //得多进行一个循环次数
        while(fast->next && fast->next->next)//不是环的话，会遇到nullptr结点 
        { 
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow)//是环的话，快慢指针会相遇
                break;
        }
        //好的编程习惯：当循环中有好几处能使循环中断的情况，循环中断后，
        //应该首先判断是那种情况引起的循环中断
        if(fast->next==nullptr || fast->next->next==nullptr)
            return nullptr;
        slow = head; 
        while(slow != fast) 
        {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};
