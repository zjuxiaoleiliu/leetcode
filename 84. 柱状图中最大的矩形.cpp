题目描述:

Given n non-negative integers representing the 
histogram s bar height
where the width of each bar is 1,
find the area of largest rectangle in the histogram.

Above is a histogram where width of each bar is 1, 
given height =[2,1,5,6,2,3].
The largest rectangle is shown in the shaded area, 
which has area =10 unit.

For example,
Given height =[2,1,5,6,2,3],
return 10.

/*
栈中维护的是一个非递减序列，当遇到一个元素现在无法明确的
下结论时，先保存在一个地方，这里是保存在栈中，对于用栈解决的
问题，要注意“消去”(能明确的下结论时)，因为这类题目我们保存的
是下标位置信息，所以，并不太会会丢失影响我们解决问题所需要的信息

找个例子画个柱状图模拟一下过程就能很快地写出代码
单调递增栈
*/
class Solution {
public:
	int largestRectangleArea(vector<int> &height)
	{ 
        int ret = 0;  
		stack<int> s;  
        int i = 0;
        int n = height.size();
        while(i < n)//流式处理 
        { 
        	if(s.empty() || height[s.top()] <= height[i]) 
        		s.push(i++);  
        	else
        	{
        	    int h = height[s.top()];
                s.pop(); //s.top()前面如果有元素的话，一定比它小，如果出现              
                ret = max(ret,(s.empty()?i:i-s.top()-1)*h);//下标中断，那一定是比它高  
            }                             //因为比它高，后面遇到低的，就弹出了
        }                                 //如果比s.top()低，按照入栈的顺序，肯定
        while(!s.empty())                 //是先弹出s.top(),再弹出s.top()前面比它低的
        { 
        	int h = height[s.top()];
            s.pop(); 
            ret = max(ret,(s.empty()?n:n-s.top()-1)*h);  
        }  
        return ret; 
    } 

};

/*
用堆栈计算每一块板能延伸到的左右边界
对每一块板
堆栈顶矮，这一块左边界确定，入栈
堆栈顶高，堆栈顶右边界确定，出栈，计算面积
入栈时左边界确定
出栈时右边界确定
堆栈里元素是递增的
本质：中间的短板没有用！
复杂度 O(n)，因为有n个元素，而每个元素仅入堆栈一次，仅出堆栈一次
*/
