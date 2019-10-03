题目描述:

Given n non-negative integers representing an elevation map 
where the width of each bar is 1,
compute how much water it is able to trap after raining.

For example, 
Given[0,1,0,2,1,0,1,3,2,1,2,1], return 6.



The above elevation map is represented by array 
[0,1,0,2,1,0,1,3,2,1,2,1]. 
In this case, 6 units of rain water (blue section) 
are being trapped. 
Thanks Marcos for contributing this image!



/*第一种方法：
原理：一个位置处能存储的水的多少与这个位置左、右边的最大值
中的最小值有关(木桶原理)，如果这个最小值大于当前的高度，
则当前位置能存储的雨水为这个高度差
基于动态规划Dynamic Programming的，
我们维护一个一维的dp数组，这个DP算法需要遍历两遍数组，
第一遍遍历,dp[i]中存入i位置左边的最大值，然后开始第二遍遍历数组，
第二次遍历时找右边最大值，然后和左边最大值比较取其中的较小值，
然后跟当前值A[i]相比，如果大于当前值，则将差值存入结果
*/
class Solution {
public:
    int trap(vector<int>& height) {

    	int n = height.size();
    	if(n < 3)
    		return 0;
        int ret = 0;
        vector<int> dp(n, 0);
        for(int i = 1; i < n; ++i) 
            dp[i] = max(dp[i-1], height[i-1]);
        int rightMax = 0;
        for(int i = n-2; i >= 0; --i) 
        {
            rightMax = max(rightMax, height[i+1]);
            int temp = min(dp[i], rightMax);
            if(temp > height[i]) 
            	ret += temp-height[i];            
        }
        return ret;
    }
};

/*方法2：基于上面每一个位置能否存储雨水的原理，我们不必
额外的开辟一个数组存储两边的最大值信息，我们可以先找出数组
中的最大值，这样一个位置一侧的最大值就确定(固定)住了，另
一侧的最大值，根据上面动态规划中的递推公式，只需要一个变量
进行记录更新就行了
*/
class Solution {
public:
    int trap(vector<int>& height) {

    	int n = height.size();
    	if(n < 3)
    		return 0;
        int ret = 0;
        int theMax = height[0];
        int index = 0;
        for(int i = 1;i<n;i++)
        {
        	if(height[i]>theMax)
        	{
        		theMax = height[i];
        		index = i;
        	}
        }
        int leftMax = 0;
        for(int i = 1; i < index; ++i) 
        {
            leftMax = max(leftMax, height[i-1]);
        	int temp = min(leftMax, theMax);
            if(temp > height[i]) 
            	ret += temp-height[i];
            
        }
        int rightMax = 0;
        for(int i = n - 2; i > index; --i) 
        {
            rightMax = max(rightMax, height[i+1]);
            int temp = min(theMax, rightMax);
            if(temp > height[i]) 
                ret += temp-height[i]; 
        }
        return ret;
    }
};


/*
方法3：双指针法,对于位置i如果能确定
这个位置处的储水情况(不能储水，能储水)，就可以将指针越过这个位置
对于可能存在的潜在的能储水的左右两个位置，
现在还不能肯定的下结论，就只能保持不动,能肯定的下结论的，移动这个指针
*/


class Solution {
public:
    int trap(vector<int>& height) {

    	int n = height.size();
    	if(n <3)
    		return 0;
        int ret = 0;
        int leftMax = 0;
        int rightMax = 0;
        int l = 0;
        int r = n-1;
        while(l <= r)//遍历计算每一个柱子能接水的多少 
        {
        	while(l<=r && leftMax<=height[l])
        	{
        		leftMax = height[l];
        		l++;
        	}
            if(l > r)
                return ret;
        	while(l<=r && height[r]>=rightMax)
        	{
        		rightMax = height[r];
        		r--;
        	}
            if(r < l)
                return ret;
        	else
        	{   //height[l] < leftMax < rightMax
        		if(leftMax<rightMax)
        		{
        			ret+=leftMax-height[l];
        			l++;
        		}
        		else
        		{   //leftMax >= rightMax > height[r]
        			ret+=rightMax-height[r];
        			r--;
        		}
        	}
        }
        return ret;
   }
};

/*
利用了栈的结构，通过维护一个非递增栈来得到答案。
本质思想还是利用了要存水必须是“两高夹一矮”这个特点，
只不过这里是用非递增栈来实现。

这个算法是一层一层地计算存储的雨水量的
用例子模拟整个过程就可以写出完整的代码(不要技巧化，根据例子直接模拟写代码)
栈里保存的是下标位置，遍历元素时当我们无法肯定的确信它对于后面
的操作无用时，先找个地方存放起来，这里是放在栈里，对于使用栈
来解决的问题，遇到能消去元素时消去(已经可以确信它没用了)，
因为我们保存的是下标，所以
不太会丢失我们解决问题需要的信息
*/
class Solution {
public:
    int trap(vector<int>& height) {

    	int n = height.size();
    	if(n <3)
    		return 0;
        int ret = 0;
        stack<int> s;
        int i = 0;
        while(i < n) 
        {   //为维护非递增栈的结构,不能将比栈顶元素大的元素压栈
            if(s.empty() || height[i] <= height[s.top()])
            {
            	s.push(i);
            	i++;
            }
            else 
            {
                int index = s.top(); 
                s.pop();
                if(s.empty()) 
                {
                	s.push(i);
                	i++;
                }
                else 
                	ret += (min(height[i], height[s.top()]) - height[index])*(i-s.top()-1);
            }
        }
        return ret;
    }
};



























class Solution {
public:
    int trap(int A[], int n) {

        int ret=0;
    	stack<int> s;        
        for(int i=0;i<n;i++)
        {    
            /*如果新的高度比保存的s.top()高，证明找到右边界，可以计算，此处应为while
            因为一次只能处理一层，如 2 1 0 2 ，先处理1 0 2 部分 填充1，然后继续计算2112计算2
           */ 

        	while(!s.empty() && A[s.top()]<A[i]) 
            {
                int t =s.top();
                s.pop();
                while(!s.empty() && A[s.top()]<=A[t])
                	s.pop();
                if(!s.empty())
                	ret+= (min(A[s.top()],A[i])-A[t])*(i-s.top()-1);
            }
            s.push(i);
        }

        return ret; 
    }
};