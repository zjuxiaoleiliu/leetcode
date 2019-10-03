题目描述:

Merge k sorted linked lists and return it as one sorted list.
Analyze and describe its complexity.

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//方法1：合并两个链表的扩展，两个两个的合并
class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n == 0)
        	return nullptr;
        if(n == 1)
        	return lists[0];
        ListNode *ret = lists[0];
        for(int i = 1;i<n;i++)
        	ret = mergeTwoLists(ret,lists[i]);
        return ret;
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {

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
            if(p1->val <= p2->val) 
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
};

//方法2：使用最小堆
class Solution {
public://cmp函数含义：元素l1是否比元素l2的优先级小？
	static bool cmp(ListNode* l1,ListNode* l2)//堆中各元素优先级大小的确定准则
	{
       return l1->val >= l2->val;//因为要建的是最小堆，元素对应的值越小，它的优先级越大
	}                           //元素对应的值越大，它的优先级越小
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n == 0)
        	return nullptr;
        if(n == 1)
        	return lists[0];
        ListNode dummy = ListNode(-1);
        ListNode *last = &dummy;
        vector<ListNode *> vec;
        for(int i=0;i<n;i++)
        {
        	if(lists[i])//要确保堆中要比较的元素非空
        		vec.push_back(lists[i]);
        }
        //make_heap Defined in header <algorithm>
        make_heap(vec.begin(),vec.end(),cmp);//建堆
        while(!vec.empty())
        {

        	ListNode *temp = vec.front();//堆第一个节点first为最小值节点
        	ListNode *next = temp->next;
        	temp->next = nullptr;
            last->next = temp;                       
            last = temp;
            pop_heap(vec.begin(),vec.end(),cmp);//它把vec[0]和vec[vec.size()-1]交换，然后重新将位置[0,vec.size()-2]调整成一个堆
            vec.pop_back();//容器弹出最后一个节点
            if(next!=nullptr)//要确保堆中要比较的元素非空                                 
            {
            	vec.push_back(next);                
                push_heap(vec.begin(),vec.end(),cmp);//[0,vec.size()-2]已经是一个有效堆
            }                                       //在末尾位置vec.size()-1新加入元素后，重新调整成一个堆
        }

        return dummy.next;
    }
   
};


//解法3:和上面使用最小堆的思路一样，不过我们这里直接使用C++的优先队列数据结构
/*
priority_queue本质是一个堆。
1. 头文件是#include<queue>
2. 关于priority_queue中元素的比较
模板申明带3个参数：priority_queue<Type, Container, Functional>，其中Type 为数据类型，
Container为保存数据的容器，Functional 为元素比较方式。
Container必须是用数组实现的容器，比如vector,deque等等，但不能用 list。STL里面默认用的是vector。
比较方式默认用operator<，所以如果把后面2个参数缺省的话，优先队列就是大顶堆（降序），队头元素最大。
如果要用到小顶堆，则一般要把模板的3个参数都带进去。STL里面定义了一个仿函数greater<>，
基本类型可以用这个仿函数声明小顶堆。如greater<int>
对于自定义类型，则必须重载operator<或者重写仿函数。

*/
class Solution {
public:
	struct cmp//定义一个可调用类型functional
	{
	    bool operator()(ListNode* l1,ListNode* l2)//优先队列中各元素优先级大小的确定准则
	    {
	        return l1->val >= l2->val;//因为要建的是最小优先队列，元素对应的值越小，它的优先级越大
	    }                           //元素对应的值越大，它的优先级越小
    };
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int n = lists.size();
        if(n == 0)
        	return nullptr;
        if(n == 1)
        	return lists[0];
        ListNode dummy = ListNode(-1);
        ListNode *last = &dummy;
        priority_queue<ListNode *, vector<ListNode *>,cmp> q;
        for(int i=0;i<n;i++)
        {
        	if(lists[i])
        		q.push(lists[i]);
        }
        while(!q.empty())
        {

        	ListNode *temp = q.top();
        	ListNode *next = temp->next;
        	temp->next = nullptr;
            last->next = temp;                       
            last = temp;
            q.pop();
            if(next!=nullptr)
            	q.push(next);                          
        }

        return dummy.next;
    }
   
};



